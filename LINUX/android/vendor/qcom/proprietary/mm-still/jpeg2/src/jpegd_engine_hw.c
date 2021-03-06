/* Copyright (c) 2012, Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#include <stdlib.h>
#include <media/msm_mercury.h>
#include "jpeg_buffer_private.h"
#include "jpeg_common.h"
#include "jpegd_engine_hw.h"
#include "jpegd.h"
#include "jpegerr.h"
#include "jpeglog.h"
#include "os_timer.h"



/* Forward Declarations*/
/* Function prototypes of jpegd_engine_obj_t interface functions */
static void jpegd_engine_hw_create  (jpegd_engine_obj_t *p_obj,
    jpegd_obj_t decoder);
static int  jpegd_engine_hw_init    (jpegd_engine_obj_t*,
    jpegd_engine_event_handler_t,
    jpegd_engine_input_req_handler_t);
static int  jpegd_engine_hw_start   (jpegd_engine_obj_t*);
static int  jpegd_engine_hw_abort   (jpegd_engine_obj_t*);
static void jpegd_engine_hw_destroy (jpegd_engine_obj_t*);
static int  jpegd_engine_hw_configure (jpegd_engine_obj_t*,
    jpegd_engine_src_t*,
    jpegd_engine_dst_t*,
    jpegd_dst_t*,
    uint32_t*,
    uint32_t*);
/* Function prototypes of helper functions */
static int  jpegd_engine_hw_configure_baseline(jpegd_engine_hw_t *);
static OS_THREAD_FUNC_RET_T OS_THREAD_FUNC_MODIFIER
    jpegd_engine_hw_decode_thread(OS_THREAD_FUNC_ARG_T arg);
static jpeg_event_t jpegd_engine_hw_decode_baseline(jpegd_engine_hw_t *);

/* Extern functions */
extern int  jpegd_engine_hw_check_qtable   (jpegd_engine_hw_t *);
extern int  jpegd_engine_hw_check_htable   (jpegd_engine_hw_t *);
extern int jpegd_engine_hw_init_bit_buffer(jpegd_engine_hw_t *);
extern int jpegd_engine_hw_get_buf_in_use(jpegd_engine_hw_t *,
    jpeg_buf_t *);

/* -----------------------------------------------------------------------
** Global Object Definitions
** -----------------------------------------------------------------------*/
#define INTERNAL_BUFFER_SIZE   8192 /* in bytes */
#define MAX_MCU_SIZE           384  /* in bytes */
static const char jpegd_engine_hw_name[] = "Jpeg Hardware Decode Engine";
jpegd_engine_profile_t jpegd_engine_hw_profile = {jpegd_engine_hw_create,
    jpegd_engine_hw_name,
    1};

static jpegd_engine_hw_t  *p_engine_local;

/* =======================================================================
**                       Macro/Constant Definitions
** ======================================================================= */
#define BYTES_PER_FETCH   0x2000
#define MAX_NUM_OUTPUT_BUF 2

/* =======================================================================
**                          Function Definitions
** ======================================================================= */

/* output buf processing */
static struct mercury_buf dec_output_buf[MAX_NUM_OUTPUT_BUF] = {
    /*
    * type; fd; vaddr; y_off; y_len; framedone_len;
    * cbcr_off; cbcr_len; NumOfMCURows
    */
    {0, -1, (void *) 0x0, 0, 0, 0, 0, 0, 0},
    {0, -1, (void *) 0x0, 0, 0, 0, 0, 0, 0},
};



int jpegd_engine_hw_free_output_buf (void)
{
    unsigned int i;

    JPEG_DBG_MED("%s: num buffers %d", __func__,
        p_engine_local->num_output_buffers);

    for (i = 0; i < p_engine_local->num_output_buffers; i++) {
        JPEG_DBG_MED("%s: fd %d", __func__, dec_output_buf[i].fd);
        if (dec_output_buf[i].fd <= 0) {
            continue;
        }


        int rc = do_munmap (dec_output_buf[i].fd, dec_output_buf[i].vaddr,
            dec_output_buf[i].y_len,
            dec_output_buf[i].ion_fd_main, &dec_output_buf[i].fd_ion_map);
        if (rc) {
            JPEG_DBG_ERROR ("%s:%d] fail to free PMEM for mercury output\n",
                __func__, __LINE__);
            return JPEGERR_EFAILED;
        }
        dec_output_buf[i].y_len = 0;
        JPEG_DBG_MED ("%s: free PMEM for mercury output %d\n", __func__,
            dec_output_buf[i].y_len);
    }
    return JPEGERR_SUCCESS;
}



static void jpegd_engine_hw_create(jpegd_engine_obj_t *p_obj,
    jpegd_obj_t p_decoder)
{
    JPEG_DBG_LOW("--(%d)%s() \n", __LINE__, __func__);

    if (p_obj) {
        /* Destroy previous engine if it exists*/
        if (p_obj->destroy) {
            p_obj->destroy(p_obj);
        }
        p_obj->create        = &jpegd_engine_hw_create;
        p_obj->init          = &jpegd_engine_hw_init;
        p_obj->configure     = &jpegd_engine_hw_configure;
        p_obj->start         = &jpegd_engine_hw_start;
        p_obj->abort         = &jpegd_engine_hw_abort;
        p_obj->destroy       = &jpegd_engine_hw_destroy;
        p_obj->p_engine      = NULL;
        p_obj->decoder       = p_decoder;
        p_obj->is_intialized = false;
        p_obj->skip_pp       = false;
    }
}

int jpegd_engine_hw_event_handler (mcr_obj_t mcr_obj,
    struct msm_mercury_ctrl_cmd *pMcrCtrlCmd,
    int event)
{

    JPEG_DBG_LOW("--(%d)%s() \n", __LINE__, __func__);

    os_mutex_lock(&p_engine_local->frame_done_mutex);
    if (MSM_MERCURY_EVT_FRAMEDONE == event) {
        p_engine_local->output_done = true;
    } else if (MSM_MERCURY_EVT_ERR == event) {
        p_engine_local->error_flag = true;
    }
    os_cond_signal(&p_engine_local->frame_done_cond);
    os_mutex_unlock(&p_engine_local->frame_done_mutex);

    return 0;
}

int jpegd_engine_hw_output_handler (mcr_obj_t mcr_obj,
    struct mercury_buf *buf)
{
    uint32_t size;
    uint32_t i = 0;

    JPEG_DBG_MED ("%s:%d] buf->vaddr = %p, buf->y_len = %d, "
        "framedone_len %d\n",
        __func__, __LINE__, buf->vaddr, buf->y_len, buf->framedone_len);
    return 0;
}


static int jpegd_engine_hw_init(jpegd_engine_obj_t              *p_obj,
    jpegd_engine_event_handler_t     p_event_handler,
    jpegd_engine_input_req_handler_t p_input_req_handler)
{
    jpegd_engine_hw_t *p_engine;
    mcr_obj_t mcr_obj = 0;
    int mcrfd = -1;

    JPEG_DBG_LOW("--(%d)%s() \n", __LINE__, __func__);

    /* Validate input arguments*/
    if (!p_obj || !p_event_handler || !p_input_req_handler) {
        return JPEGERR_ENULLPTR;
    }

    /* Allocate memory for the engine structure*/
    p_engine = (jpegd_engine_hw_t *)JPEG_MALLOC(sizeof(jpegd_engine_hw_t));
    if (!p_engine) {
        return JPEGERR_EMALLOC;
    }
    /* Initialize the fields inside the engine structure below*/
    STD_MEMSET(p_engine, 0, sizeof(jpegd_engine_hw_t));
    /* Initialize the pointer to the wrapper*/
    p_engine->p_wrapper               = p_obj;
    /* Initialize the pointer to the wrapper*/
    p_engine->input_fetcher.p_wrapper = p_obj;
    /* Initialize the event handler*/
    p_engine->p_event_handler         = p_event_handler;
    /* Initialize the input request handler*/
    p_engine->input_fetcher.p_input_req_handler = p_input_req_handler;
    /* Initialize source pointer of fetcher*/
    p_engine->input_fetcher.p_source  = &p_engine->source;
    os_mutex_init(&(p_engine->mutex));
    os_cond_init(&(p_engine->cond));

    /* Initialize the mutex */
    os_mutex_init(&(p_engine->frame_done_mutex));
    /* Initialize the condition variable */
    os_cond_init(&(p_engine->frame_done_cond));

    mcrfd = mercury_lib_init(&mcr_obj, jpegd_engine_hw_event_handler);
    if (mcrfd < 0) {
        JPEG_DBG_ERROR("jpege_engine_hw_init: mercury_lib_init failed\n");
        JPEG_FREE(p_engine);
        return JPEGERR_EFAILED;
    }

    p_engine->mcr_fd = mcrfd;
    p_engine->mcr_obj = mcr_obj;

    /* Assign allocated engine structure to p_obj*/
    p_obj->p_engine = (void *)p_engine;
    p_obj->is_intialized = true;
    return JPEGERR_SUCCESS;
}


static int jpegd_engine_hw_start(jpegd_engine_obj_t *p_obj)
{
    int rc;
    jpegd_engine_hw_t *p_engine;
    os_thread_t thread;

    JPEG_DBG_LOW("--(%d)%s() \n", __LINE__, __func__);

    /* Validate input arguments*/
    if (!p_obj || !p_obj->p_engine)
        return JPEGERR_ENULLPTR;

    /* Cast p_obj->obj as jpegd_engine_hw_t object*/
    p_engine = p_obj->p_engine;

    /* Make sure no threads are running*/
    os_mutex_lock(&(p_engine->mutex));
    if (p_engine->is_active || !p_engine->is_configured) {
        os_mutex_unlock(&(p_engine->mutex));
        JPEG_DBG_HIGH("jpegd_engine_hw_start: bad state\n");
        return JPEGERR_EBADSTATE;
    }

    /* Reset abort flag*/
    p_engine->abort_flag = false;
    /* Set engine to be active*/
    p_engine->is_active = true;

    /* Join previously created decode thread if needed*/
    if (p_engine->is_dthread_need_join) {
        (void)os_thread_join(&p_engine->decode_thread, NULL);
    }
    p_engine->is_dthread_need_join = true;

    /* Start Jpeg Decoding as a new thread*/
    rc = os_thread_create(&p_engine->decode_thread,
        jpegd_engine_hw_decode_thread, (void *)p_engine);

    JPEG_DBG_HIGH("--(%d)%s() jpegd_engine_hw_decode_thread: rc = %d\n",
        __LINE__, __func__, rc);

    /* If there is a failure in creating the thread, clean up and exit*/
    if (rc) {
        /* Reset engine to be inactive*/
        p_engine->is_active = false;
        /* Reset thread needs join flag*/
        p_engine->is_dthread_need_join = false;

        os_mutex_unlock(&p_engine->mutex);
        JPEG_DBG_HIGH("jpegd_engine_hw_start: os_thread_create() failed: %d\n",
            rc);
        return JPEGERR_EFAILED;
    }

    os_mutex_unlock(&(p_engine->mutex));

    return JPEGERR_SUCCESS;
}

static int jpegd_engine_hw_abort(jpegd_engine_obj_t *p_obj)
{
    jpegd_engine_hw_t *p_engine;

    JPEG_DBG_LOW("--(%d)%s() \n", __LINE__, __func__);

    /* Validate input arguments*/
    if (!p_obj || !p_obj->p_engine)
        return JPEGERR_ENULLPTR;

    /* Cast p_obj->obj as jpegd_engine_hw_t object*/
    p_engine = p_obj->p_engine;

    /* Abort if engine is actively decoding*/
    os_mutex_lock(&(p_engine->mutex));
    if (p_engine->is_active) {
        p_engine->abort_flag = true;
        while (p_engine->abort_flag) {
            os_cond_wait(&(p_engine->cond), &(p_engine->mutex));
        }
    }
    os_mutex_unlock(&(p_engine->mutex));
    return JPEGERR_SUCCESS;
}

static void jpegd_engine_hw_destroy(jpegd_engine_obj_t *p_obj)
{
    JPEG_DBG_LOW("--(%d)%s() \n", __LINE__, __func__);

    if (p_obj) {
        uint32_t i;
        jpegd_engine_hw_t *p_engine = (jpegd_engine_hw_t *)(p_obj->p_engine);
        /* Abort and wait until engine is done with current decoding*/
        (void)jpegd_engine_hw_abort(p_obj);

        /* Join decode thread if necessary*/
        if (p_engine->is_dthread_need_join) {
            (void)os_thread_join(&p_engine->decode_thread, NULL);
        }

        for (i = 0; i < JPEGD_MAXHUFFTABLES; i++) {
            JPEG_FREE(p_engine->pDerivedHuffTable[i]);
        }
        /* Free pDeQuantTable*/
        for (i = 0; i < JPEGD_MAXQUANTTABLES; i++) {
            JPEG_FREE(p_engine->pDeQuantTable[i]);
        }
        /* Free pCompCoeffBuf*/
        for (i = 0; i < JPEGD_MAXCOMPONENTS; i++) {
            JPEG_FREE(p_engine->pCompCoeffBuf[i]);
        }
        /* Release allocated memory*/
        if (p_engine) {
            os_mutex_destroy(&(p_engine->mutex));
            os_cond_destroy(&(p_engine->cond));
            JPEG_FREE(p_obj->p_engine);
            p_obj->p_engine = NULL;
        }
    }
}

static int jpegd_engine_hw_configure_baseline(jpegd_engine_hw_t *p_engine)
{
    uint8_t  j;
    uint32_t i,qt;
    int cnt = 0;
    uint8_t  componentId;
    int32_t  blockCount;
    uint32_t numOfBlocks;

    uint8_t  hSample[JPEGD_MAXCOMPONENTS];
    uint8_t  vSample[JPEGD_MAXCOMPONENTS];

    uint32_t numOfHBlocksInComp[JPEGD_MAXCOMPONENTS];
    uint32_t numOfVBlocksInComp[JPEGD_MAXCOMPONENTS];

    jpeg_rectangle_t region;

    jpeg_frame_info_t *p_frame_info = p_engine->source.p_frame_info;
    jpeg_scan_info_t  *p_scan_info  = p_frame_info->pp_scan_infos[0];

    uint8_t  maxHSample  = 1;
    uint8_t  maxVSample  = 1;

    uint32_t nRowsPerMCU = 0;
    uint32_t nColsPerMCU = 0;

    int rc,k;

    mercury_cmd_quant_cfg_t  dqt_cfg = {
        p_frame_info->qtable_present_flag,
        {0,0,0,0},
    };

    JPEG_DBG_LOW("%s:%d, p_frame_info->qtable_present_flag= 0x%x\n",
        __func__,__LINE__,p_frame_info->qtable_present_flag);
    /* Allocate qtable*/
    for (qt = 0; qt < 4; qt++) {
        if (!(p_frame_info->qtable_present_flag & 1<<qt)) {
            continue;
        }
        dqt_cfg.p_qtables[qt] = (jpeg_quant_table_t)JPEG_MALLOC(64 *
            sizeof(uint16_t));
        if (!dqt_cfg.p_qtables[qt])
            return JPEGERR_EMALLOC;
        STD_MEMSET(dqt_cfg.p_qtables[qt],0,64 * sizeof(uint16_t));
        STD_MEMMOVE(dqt_cfg.p_qtables[qt],p_frame_info->p_qtables[qt],64 *
            sizeof(uint16_t));
    }

    mercury_cmd_sof_cfg_t  sof_cfg;
    sof_cfg.num_comps = p_frame_info->num_comps;
    sof_cfg.width = p_frame_info->width;
    sof_cfg.height = p_frame_info->height;
    sof_cfg.precision = p_frame_info->precision;

    sof_cfg.p_comp_infos = (mer_comp_info_t *)JPEG_MALLOC(p_frame_info->num_comps *
        sizeof(jpeg_comp_info_t));
    if (!sof_cfg.p_comp_infos) {
        return JPEGERR_EMALLOC;
    }
    STD_MEMSET(sof_cfg.p_comp_infos, 0, p_frame_info->num_comps *
        sizeof(mer_comp_info_t));
    for (i = 0; i < p_frame_info->num_comps; i++) {
        sof_cfg.p_comp_infos[i].comp_id = p_frame_info->p_comp_infos[i].comp_id;
        sof_cfg.p_comp_infos[i].sampling_h = p_frame_info->p_comp_infos[i].sampling_h;
        sof_cfg.p_comp_infos[i].sampling_v = p_frame_info->p_comp_infos[i].sampling_v;
        sof_cfg.p_comp_infos[i].qtable_sel = p_frame_info->p_comp_infos[i].qtable_sel;
    }
    /*Huffman*/
    mercury_cmd_huff_cfg_t huff_cfg;
    huff_cfg.htable_present_flag = p_frame_info->htable_present_flag;

    for (qt = 0; qt < 8; qt++) {
        if (!(p_frame_info->htable_present_flag & 1<<qt)) {
            continue;
        }
        for (k = 1; k<17; k++) {
            huff_cfg.p_htables[qt].bits[k] = p_frame_info->p_htables[qt].bits[k];
        }
        for (k = 0; k<256; k++) {
            huff_cfg.p_htables[qt].values[k] = p_frame_info->p_htables[qt].values[k];
        }

    }

    mercury_cmd_sos_cfg_t  sos_cfg;
    /* Allocate a new scan info*/

    /* Resize the scan info array*/

    sos_cfg.pp_scan_infos = (mecury_scan_info_t **)JPEG_MALLOC((p_frame_info->num_scans) *
        sizeof(jpeg_scan_info_t *));
    if (!sos_cfg.pp_scan_infos) {
            JPEG_FREE(sof_cfg.p_comp_infos);
            return JPEGERR_EMALLOC;
        }

    for (i = 0;i < p_frame_info->num_scans;i++) {
        sos_cfg.pp_scan_infos[i] = (mecury_scan_info_t *)JPEG_MALLOC(sizeof(mecury_scan_info_t));
        if (!sos_cfg.pp_scan_infos[i]) {
            JPEG_FREE(sof_cfg.p_comp_infos);
            return JPEGERR_EMALLOC;
        }

        sos_cfg.pp_scan_infos[i]->offset =
         p_frame_info->pp_scan_infos[i]->offset;
        sos_cfg.pp_scan_infos[i]->num_selectors =
         p_frame_info->pp_scan_infos[i]->num_selectors;
        sos_cfg.pp_scan_infos[i]->spec_start =
         p_frame_info->pp_scan_infos[i]->spec_start;
        sos_cfg.pp_scan_infos[i]->spec_end =
         p_frame_info->pp_scan_infos[i]->offset;
        sos_cfg.pp_scan_infos[i]->succ_approx_h =
         p_frame_info->pp_scan_infos[i]->succ_approx_h;
        sos_cfg.pp_scan_infos[i]->succ_approx_l =
          p_frame_info->pp_scan_infos[i]->succ_approx_l;
        sos_cfg.pp_scan_infos[i]->p_selectors =
         (mercury_comp_entropy_sel_t *)JPEG_MALLOC(sos_cfg.pp_scan_infos[i]->num_selectors *
            sizeof(mercury_comp_entropy_sel_t));
        if (!sos_cfg.pp_scan_infos[i]->p_selectors) {
            JPEG_FREE(sof_cfg.p_comp_infos);
            return JPEGERR_EMALLOC;
        }
        STD_MEMMOVE(sos_cfg.pp_scan_infos[i]->p_selectors,
                     p_frame_info->pp_scan_infos[i]->p_selectors,
            sos_cfg.pp_scan_infos[i]->num_selectors *
                    sizeof(mercury_comp_entropy_sel_t));
    }
    rc = mercury_lib_configure_baseline(dqt_cfg, sof_cfg, huff_cfg, sos_cfg);

    if (rc) {
        return JPEGERR_EFAILED;
    }
    /**********************************************************************
    * First convert jpeg header related info in the p_engine->decodeSpec into
    * local variables
    * 1. image size
    * 2. restart interval
    * 3. components in frame and scan (for now only 1 scan is allowed)
    * 4. set components info (id, sampling, quant table) in sof marker
    * 5. set components info (huff table) in sos (scan 1 only)
    *    as well as spectrum selection.
    *********************************************************************/
    p_engine->nImageWidth               = p_frame_info->width;
    p_engine->nImageHeight              = p_frame_info->height;

    p_engine->nOutputWidth              = p_engine->dest.width;
    p_engine->nOutputHeight             = p_engine->dest.height;

    p_engine->nRestartInterval          = p_frame_info->restart_interval;
    p_engine->nNumberOfComponentsInScan = p_scan_info->num_selectors;

    /* component id, sampling, quant info*/
    for (j = 0; j < p_frame_info->num_comps; j++) {
        p_engine->compId[j]  = p_frame_info->p_comp_infos[j].comp_id;
        hSample[j]           = p_frame_info->p_comp_infos[j].sampling_h;
        vSample[j]           = p_frame_info->p_comp_infos[j].sampling_v;
        p_engine->quantId[j] = p_frame_info->p_comp_infos[j].qtable_sel;
    }

    /* scan info, for baseline it is only 1 scan.*/
    p_engine->nNumberOfComponentsInScan = p_scan_info->num_selectors;
    p_engine->currentScanProgressiveInfo.ss = (uint32_t)(p_scan_info->spec_start);
    p_engine->currentScanProgressiveInfo.se = (uint32_t)(p_scan_info->spec_end);

    /* component huffman info*/
    for (j = 0; j < p_engine->nNumberOfComponentsInScan; j++) {
        /* get component id*/
        componentId = p_scan_info->p_selectors[j].comp_id;
        /* dc table index*/
        p_engine->dcHuffTableId[componentId] = p_scan_info->p_selectors[j].dc_selector;

        /* since only one set of huff table index is used,*/
        /* ac table is appened to dc table with index starting from*/
        /* JPEGD_MAXHUFFTABLES/2.*/
        p_engine->acHuffTableId[componentId] = p_scan_info->p_selectors[j].ac_selector +
            (uint8_t)(JPEGD_MAXHUFFTABLES >> 1);
        /* get components list in a MCU in one scan*/
        p_engine->compListInScan[j] = componentId;
    }

    /**********************************************************************
    *  If no region information is specified, then set the region to      *
    *  the whole image.                                                   *
    **********************************************************************/
    region = p_engine->dest.region;
    if (region.right == 0 && region.bottom == 0) {
        region.right  = p_engine->nImageWidth  - 1;
        region.bottom = p_engine->nImageHeight - 1;
    }

    /**********************************************************************
    * Validate the region:
    * 0 <= left < right  < Input Image Width
    * 0 <= top  < bottom < Input Image Height
    *********************************************************************/
    if (0 > region.left || region.left >= region.right  || region.right  >=
        (int32_t)(p_engine->nImageWidth) ||
        0 > region.top  || region.top  >= region.bottom || region.bottom >=
        (int32_t)(p_engine->nImageHeight)) {
        return JPEGERR_EFAILED;
    }


    /**********************************************************************
    * Here we check the color format. Also set up MCU related settings
    * 1. color format
    * 2. numbers of blocks in a MCU
    * 3. numbers of pixels in a row in one MCU
    * 4. numbers of pixels in a column in one MCU
    **********************************************************************/
    if (p_frame_info->num_comps == 1) {
        /********************************************************
        * grey scale, only 1 (Y) 8x8 block per MCU
        ********************************************************/
        p_engine->jpegdFormat   = JPEG_GRAYSCALE;
        p_engine->nBlocksPerMCU = 1;
        nRowsPerMCU     = 8;
        nColsPerMCU     = 8;

        /***********************************************************
        * Compute the # of MCUs outside of the Region.
        *
        * left_mcu_num   is the # of MCU before the Region MCU Row.
        * top_mcu_num    is the # of MCU above  the Region MCU Row.
        * right_mcu_num  is the # of MCU after  the Region MCU Row.
        * bottom_mcu_num is the # of MCU below  the Region MCU Row.
        *
        * Right shift by 3 is equivalent to integer divide by 8.
        *************************************************************/
        p_engine->left_mcu_num   = region.left >> 3;
        p_engine->top_mcu_num    = region.top  >> 3;
        p_engine->right_mcu_num  = (ROUND_TO_8(p_engine->nImageWidth)  -
                                    (uint32_t)(region.right)  - 1) >> 3;
        p_engine->bottom_mcu_num = (ROUND_TO_8(p_engine->nImageHeight) -
                                    (uint32_t)(region.bottom) - 1) >> 3;
    } else if (p_frame_info->num_comps == 3) {
        if (hSample[1]!=1 || vSample[1]!=1 ||
            hSample[2]!=1 || vSample[2]!=1) {
            return JPEGERR_EUNSUPPORTED;
        }
        if (hSample[0] == 1 && vSample[0] == 1) {
            /**************************************************************
            * H1V1, 3 (Y, Cb, Cr) blocks per MCU
            *************************************************************/
            p_engine->jpegdFormat   = JPEG_H1V1;
            p_engine->nBlocksPerMCU = 3;
            nRowsPerMCU     = 8;
            nColsPerMCU     = 8;

            /**************************************************************************
            * Compute the # of MCUs outside of the Region.
            *************************************************************************/
            p_engine->left_mcu_num   = region.left >> 3;
            p_engine->top_mcu_num    = region.top  >> 3;
            p_engine->right_mcu_num  = (ROUND_TO_8(p_engine->nImageWidth)  -
                                         (uint32_t)(region.right)  - 1) >> 3;
            p_engine->bottom_mcu_num = (ROUND_TO_8(p_engine->nImageHeight) -
                                         (uint32_t)(region.bottom) - 1) >> 3;
        } else if (hSample[0] == 2 && vSample[0] == 1) {
            /**************************************************************
* H2V1, 4 (Yx2, Cb, Cr) blocks per MCU
*************************************************************/
            p_engine->jpegdFormat   = JPEG_H2V1;
            p_engine->nBlocksPerMCU = 4;
            nRowsPerMCU     = p_engine->nImageHeight;       /* 8*/
            nColsPerMCU     = 16;

            /*********************************************************
            * Compute the # of MCUs outside of the Region.
            ********************************************************/
            p_engine->left_mcu_num   = region.left >> 4;
            p_engine->top_mcu_num    = region.top  >> 3;
            p_engine->right_mcu_num  = (ROUND_TO_16(p_engine->nImageWidth) -
                                        (uint32_t)(region.right)  - 1) >> 4;
            p_engine->bottom_mcu_num = (ROUND_TO_8(p_engine->nImageHeight) -
                                        (uint32_t)(region.bottom) - 1) >> 3;
        } else if (hSample[0] == 1 && vSample[0] == 2) {


          /*H1V2, 4 (Yx2, Cb, Cr) blocks per MCU*/

            p_engine->jpegdFormat   = JPEG_H1V2;
            p_engine->nBlocksPerMCU = 4;
            nRowsPerMCU     = p_engine->nImageHeight;                                   /* 16*/
            nColsPerMCU     = 8;


            /* Compute the # of MCUs outside of the Region.*/

            p_engine->left_mcu_num   = region.left >> 3;
            p_engine->top_mcu_num    = region.top  >> 4;
            p_engine->right_mcu_num  = (ROUND_TO_8(p_engine->nImageWidth)   -
                                        (uint32_t)(region.right)  - 1) >> 3;
            p_engine->bottom_mcu_num = (ROUND_TO_16(p_engine->nImageHeight) -
                                         (uint32_t)(region.bottom) - 1) >> 4;
        } else if (hSample[0] == 2 && vSample[0] == 2) {
            /** H2V2, 6 (Yx4, Cb, Cr) blocks per
                            MCU*/
            p_engine->jpegdFormat   = JPEG_H2V2;
            p_engine->nBlocksPerMCU = 6;
            /* 16*/
            nRowsPerMCU     = p_engine->nImageHeight;
            nColsPerMCU     = 16;


            /* Compute the # of MCUs outside of the Region.*/

            p_engine->left_mcu_num   = region.left >> 4;
            p_engine->top_mcu_num    = region.top  >> 4;
            p_engine->right_mcu_num  = (ROUND_TO_16(p_engine->nImageWidth)  -
                                         (uint32_t)(region.right)  - 1) >> 4;
            p_engine->bottom_mcu_num = (ROUND_TO_16(p_engine->nImageHeight) -
                                         (uint32_t)(region.bottom) - 1) >> 4;
        } else {
            /**if none of these format, we can not decode this, never
 * should go here.*/

            return JPEGERR_EUNSUPPORTED;
        }
        /* end if ( hSample[0] == 1 &&  vSample[0] == 1 )*/
    } else {
        return JPEGERR_EUNSUPPORTED;
    }           /* end if ( p_frame_info->num_comps == 1 )*/

    /**********************************************************************
    * here we find out how many lines and coloumns of MCUs in a component
    * 1. find out the maximum sampling factor for all components
    * 2. calculate number of blocks in verticle and horizontal direction
    *    for each component.
    **********************************************************************/
    /* first figure out the maximum sample for rols and cols*/
    for (j = 0; j < p_frame_info->num_comps; j++) {
        if (hSample[j] > maxHSample) {
            maxHSample = hSample[j];
        }
        if (vSample[j] > maxVSample) {
            maxVSample = vSample[j];
        }
    }
    /* then use the maximum sample to determine the largest block per line*/
    /* and block per col.*/
    for (j = 0; j < p_frame_info->num_comps; j++) {
        numOfHBlocksInComp[j] = (uint32_t) ( (7+ (p_engine->nImageWidth * maxHSample
            + maxHSample-1) /maxHSample) /8);
        numOfVBlocksInComp[j] = (uint32_t) ( (7+ (p_engine->nImageHeight * maxVSample
            + maxVSample-1) / maxVSample) /8);
    }
    /**********************************************************************
    * also need to calculate the number of MCUs per row and col
    * This is determind by the color format and number of blocks in image
    * For each mcu, the type of block need to be labeled also
    *********************************************************************/
    if (p_engine->nNumberOfComponentsInScan == 1) {
        /* grey image*/
        p_engine->nMCUPerRow = numOfHBlocksInComp[p_engine->compListInScan[0]];
        p_engine->nMCUPerCol = numOfVBlocksInComp[p_engine->compListInScan[0]];
        p_engine->MCUBlockCompList[0] = p_engine->compListInScan[0];
    } else {
        /*color image.*/
        p_engine->nMCUPerRow = ( (p_engine->nImageWidth  + 7) / 8 +
                                 maxHSample - 1) / maxHSample;
        p_engine->nMCUPerCol = ( (p_engine->nImageHeight + 7) / 8 +
                                 maxVSample - 1) / maxVSample;

        blockCount = 0;
        for (j = 0; j < p_engine->nNumberOfComponentsInScan; j++) {
            /* using color format information, we can get number of blocks*/
            /* per MCU. we can assume that blocks in MCU is Y first*/
            /* followed by cb and cr.*/
            componentId = p_engine->compListInScan[j];
            numOfBlocks = hSample[componentId] * vSample[componentId];

            while (numOfBlocks--) {
                p_engine->MCUBlockCompList[blockCount++] = componentId;
            }
        }
    }

    /**************************************************************************
    *  Calculate the Region Start MCU index and Region End MCU index.         *
    **************************************************************************/
    p_engine->region_start_mcu_id =
        p_engine->top_mcu_num * p_engine->nMCUPerRow +
     p_engine->left_mcu_num;

    p_engine->region_end_mcu_id   =
        (p_engine->nMCUPerCol - p_engine->bottom_mcu_num) *
     p_engine->nMCUPerRow -
        p_engine->right_mcu_num;

    /* Adjust the # of MCUs in a MCU Row for Region decoding*/
    p_engine->nMCUPerRow -= (p_engine->right_mcu_num + p_engine->left_mcu_num);

    /* Adjust the image width/height to be the Region dimensions.*/
    p_engine->nImageWidth  = region.right  - region.left + 1;
    p_engine->nImageHeight = region.bottom - region.top  + 1;

    /**********************************************************************
* Calculate the Resize factor for IDCT according to input/output size
* ratio
*********************************************************************/
    p_engine->nResizeFactor = 3;
    while ((p_engine->nResizeFactor >= 0) &&
        ((p_engine->nOutputWidth > (p_engine->nImageWidth  >>
                                     p_engine->nResizeFactor)) ||
        (p_engine->nOutputHeight > (p_engine->nImageHeight >>
                                     p_engine->nResizeFactor)))) {
        p_engine->nResizeFactor--;
    }
    if (p_engine->nResizeFactor < 0) {
        return JPEGERR_EFAILED;
    }
    nRowsPerMCU >>= p_engine->nResizeFactor;
    nColsPerMCU >>= p_engine->nResizeFactor;

    if (p_engine->nRestartInterval != 0) {
        p_engine->nRestartLeft    = p_engine->nRestartInterval;
        p_engine->nNextRestartNum = 0xD0;
    }

    /**********************************************************************
    * check/make quantization table, huffman table
    *********************************************************************/
    if (JPEG_FAILED(jpegd_engine_hw_check_qtable(p_engine))) {
        return JPEGERR_EFAILED;
    }

    if (JPEG_FAILED(jpegd_engine_hw_check_htable(p_engine))) {
        return JPEGERR_EFAILED;
    }

    /**************************************************************************
    * Paddings are added to Jpeg image to round it up to multiple of blocks,
    * but actual image size be less than the round up.
    *
    * Calculate the Row Increment for the MCU Row buffer that holds the
    * rounded up lines.
*
    * Also set which JpegdOutputOneMCU method to use according to format.
            *
            * The output size is changed proportionally to the input size, unlike
    * the output buffer size, which is rounded to multiple of cols per MCU.

    * This will be used for postprocess to unpad the image.
    *************************************************************************/
    if (p_engine->jpegdFormat == JPEG_GRAYSCALE) {
        /* gray-scale*/
        p_engine->nYLinesPerMCU      = nRowsPerMCU;
        p_engine->nCbCrLinesPerMCU   = 0;
        p_engine->nOutputRowIncrY    = nColsPerMCU * p_engine->nMCUPerRow;
        p_engine->nOutputRowIncrCbCr = 0;
        /*      p_engine->mcu_output_func    = &jpegd_engine_hw_output_gray_mcu;*/
    } else if (p_engine->jpegdFormat == JPEG_H1V1) {
        /* H1V1*/
        p_engine->nYLinesPerMCU      = nRowsPerMCU;
        p_engine->nCbCrLinesPerMCU   = nRowsPerMCU;
        p_engine->nOutputRowIncrY    = nColsPerMCU * p_engine->nMCUPerRow;
        p_engine->nOutputRowIncrCbCr = p_engine->nOutputRowIncrY*2;
        /*      p_engine->mcu_output_func    = &jpegd_engine_hw_output_h1v1_mcu;*/
    } else if (p_engine->jpegdFormat == JPEG_H2V1) {
        /* H2V1*/
        p_engine->nYLinesPerMCU      = nRowsPerMCU;
        p_engine->nCbCrLinesPerMCU   = nRowsPerMCU;
        p_engine->nOutputRowIncrY    = nColsPerMCU * p_engine->nMCUPerRow;
        p_engine->nOutputRowIncrCbCr = p_engine->nOutputRowIncrY;
        /*      p_engine->mcu_output_func    = &jpegd_engine_hw_output_h2v1_mcu;*/
    } else if (p_engine->jpegdFormat == JPEG_H1V2) {
        /* H1V2*/
        p_engine->nYLinesPerMCU      = nRowsPerMCU;
        p_engine->nCbCrLinesPerMCU   = nRowsPerMCU >> 1;
        p_engine->nOutputRowIncrY    = nColsPerMCU * p_engine->nMCUPerRow;
        p_engine->nOutputRowIncrCbCr = p_engine->nOutputRowIncrY*2;
        /*      p_engine->mcu_output_func    = &jpegd_engine_hw_output_h1v2_mcu;*/
    } else if (p_engine->jpegdFormat == JPEG_H2V2) {
        /* H2V2*/
        p_engine->nYLinesPerMCU      = nRowsPerMCU;
        p_engine->nCbCrLinesPerMCU   = nRowsPerMCU >> 1;
        p_engine->nOutputRowIncrY    = nColsPerMCU * p_engine->nMCUPerRow;
        p_engine->nOutputRowIncrCbCr = p_engine->nOutputRowIncrY;
        /*      p_engine->mcu_output_func    = &jpegd_engine_hw_output_h2v2_mcu;*/
    }

    /* Set output dimension*/
    p_engine->nOutputWidth  = (uint32_t)(p_engine->nImageWidth >>
                                         p_engine->nResizeFactor);
    p_engine->nOutputHeight = (uint32_t)(p_engine->nImageHeight >>
                                         p_engine->nResizeFactor);

    p_engine->nOutputBufferSizeY     = p_engine->nOutputRowIncrY *
     p_engine->nYLinesPerMCU;
    p_engine->nOutputBufferSizeCbCr  = p_engine->nOutputRowIncrCbCr *
      p_engine->nCbCrLinesPerMCU;



    return JPEGERR_SUCCESS;
}


static int jpegd_engine_hw_configure(jpegd_engine_obj_t *p_obj,
    jpegd_engine_src_t *p_source,
    jpegd_engine_dst_t *p_engine_dst,
    jpegd_dst_t        *p_dest,
    uint32_t           *p_output_chunk_width,
    uint32_t           *p_output_chunk_height)
{
    jpeg_frame_info_t *p_frame_info;
    jpegd_engine_hw_t *p_engine;
    int                rc;

    JPEG_DBG_LOW("--(%d)%s() \n", __LINE__, __func__);

    /* Input validation*/
    if (!p_obj || !p_obj->p_engine ||
        !p_source || !p_engine_dst || !p_source->p_frame_info ||
        !p_source->p_input_req_handler ||
        !p_engine_dst->p_luma_buffers[0] ||
        !p_engine_dst->p_chroma_buffers[0] ||
        !p_engine_dst->p_luma_buffers[1] ||
        !p_engine_dst->p_chroma_buffers[1] ||
        !p_engine_dst->width || !p_engine_dst->height) {
        JPEG_DBG_ERROR("jpegd_engine_hw_configure: bad param\n");
        return JPEGERR_EBADPARM;
    }

    /* Support baseline & progressive decoding*/
    p_frame_info = p_source->p_frame_info;
    if (p_frame_info->process != JPEG_PROCESS_BASELINE) {
        JPEG_DBG_ERROR("jpegd_engine_hw_configure: unsupported coding process %d\n",
            p_frame_info->process);
        return JPEGERR_EUNSUPPORTED;
    }

    /* Cast p_obj->p_engine as jpegd_engine_hw_t object*/
    p_engine = (jpegd_engine_hw_t *)p_obj->p_engine;

    /* Initialize engine input*/
    p_engine->source = *p_source;
    jpeg_buffer_mark_empty(p_engine->source.p_buffers[0]);
    jpeg_buffer_mark_empty(p_engine->source.p_buffers[1]);
    p_engine->input_fetcher.buffer_in_use = 0;

    /* Initialize engine output dimensions*/
    p_engine->dest = *p_engine_dst;

    /* Initialize engine output MCU line buffer pointers*/
    p_engine->pMCULineBufPtrY    = NULL;
    p_engine->pMCULineBufPtrCbCr = NULL;

    /* Initialize engine internal data*/
    (void)STD_MEMSET(p_engine->MCUBlockCompList,0, sizeof(p_engine->MCUBlockCompList));
    (void)STD_MEMSET(p_engine->compId,          0, sizeof(p_engine->compId));
    (void)STD_MEMSET(p_engine->quantId,         0, sizeof(p_engine->quantId));
    (void)STD_MEMSET(p_engine->compListInScan,  0, sizeof(p_engine->compListInScan));
    (void)STD_MEMSET(p_engine->dcHuffTableId,   0, sizeof(p_engine->dcHuffTableId));
    (void)STD_MEMSET(p_engine->acHuffTableId,   0, sizeof(p_engine->acHuffTableId));
    (void)STD_MEMSET(p_engine->hSample,         0, sizeof(p_engine->hSample));
    (void)STD_MEMSET(p_engine->vSample,         0, sizeof(p_engine->vSample));
    (void)STD_MEMSET(p_engine->compEntropySelectors, 0, sizeof(p_engine->compEntropySelectors));
    (void)STD_MEMSET(p_engine->compCoeffHBlocks,  0, sizeof(p_engine->compCoeffHBlocks));
    (void)STD_MEMSET(p_engine->compCoeffVBlocks,  0, sizeof(p_engine->compCoeffVBlocks));

    /* Initialize restart interval*/
    p_engine->nRestartInterval = 0;

    /* Initialize engine internal function pointers*/
    /*  p_engine->idct_func = NULL;*/
    /*  p_engine->mcu_output_func = NULL;*/

    switch (p_dest->output_format) {
    case YCRCBLP_H2V2:
        /* 0x2 = 4:2:0 H2V2 (2x2 chroma subsampling)*/
        p_engine->output_format = 2;
        p_engine->output_crcb_order = 1;
        p_engine->wr_buf_format = 1;
        p_engine->out_luma_size = (p_dest->width * p_dest->height);
        p_engine->out_chroma_size = (p_dest->width * p_dest->height)>>1;
        break;
    case YCBCRLP_H2V2:
        /* 0x2 = 4:2:0 H2V2 (2x2 chroma subsampling)*/
        p_engine->output_format = 2;
        p_engine->output_crcb_order = 0;
        p_engine->wr_buf_format = 1;
        p_engine->out_luma_size = (p_dest->width * p_dest->height);
        p_engine->out_chroma_size = (p_dest->width * p_dest->height)>>1;
        break;
    case YCRCBLP_H2V1:
        /* 0x3 = 4:2:2 H2V1 (2x1 chroma subsampling)*/
        p_engine->output_format = 3;
        p_engine->output_crcb_order = 1;
        p_engine->wr_buf_format = 0;
        p_engine->out_luma_size = (p_dest->width * p_dest->height);
        p_engine->out_chroma_size = (p_dest->width * p_dest->height);
        break;
    case YCBCRLP_H2V1:
        /* 0x3 = 4:2:2 H2V1 (2x1 chroma subsampling)*/
        p_engine->output_format = 3;
        p_engine->output_crcb_order = 0;
        p_engine->wr_buf_format = 0;
        p_engine->out_luma_size = (p_dest->width * p_dest->height);
        p_engine->out_chroma_size = (p_dest->width * p_dest->height);
        break;
    }

    p_engine->back_to_back_count = p_dest->back_to_back_count;

    if (p_frame_info->process == JPEG_PROCESS_BASELINE) {
        /* Initialized engine in baseline mode*/
        p_engine->is_progressive = false;
        rc = jpegd_engine_hw_configure_baseline(p_engine);
        if (JPEG_FAILED(rc))
         return rc;
    } else {
        JPEG_DBG_ERROR("jpegd_engine_hw_configure: unsupported coding process %d\n",
            p_frame_info->process);
        return JPEGERR_EUNSUPPORTED;
    }

    /* Set engine output dimensions, may get changed by resize factor*/
    p_engine_dst->width       = p_engine->nOutputWidth;
    p_engine_dst->height      = p_engine->nOutputHeight;
    p_engine_dst->subsampling = p_engine->jpegdFormat;

    /* Set engine output MCU line buffer sizes*/
    *p_output_chunk_width  = p_engine->nOutputRowIncrY;
    *p_output_chunk_height = p_engine->nYLinesPerMCU;

    p_engine->is_configured = true;
    p_engine->fInputError = 0;
    return JPEGERR_SUCCESS;

}

static jpeg_event_t jpegd_engine_hw_decode_baseline(jpegd_engine_hw_t *p_engine)
{
    int rc;
    int use_pmem = 1;
    os_timer_t os_timer;
    int diff;
    uint32_t mercury_hw_irq_status;

    int i, j;
    int buffer_in_use;
    int bitstream_size;
    uint8_t num_of_planes  = 1;     /*defaut to two-plane*/
    uint8_t scale_ratio = 0;

    uint8_t    *p_buf;
    uint8_t    *y_buf;
    uint8_t    *uv_buf;
    int y_offset, uv_offset;

    uint32_t nColsToProcess = p_engine->nOutputRowIncrY;
    uint32_t nRowsToProcess = p_engine->nYLinesPerMCU;

    uint32_t file_size              = p_engine->source.total_length;
    jpeg_frame_info_t *p_frame_info = p_engine->source.p_frame_info;

    uint32_t height      = p_frame_info->height;
    uint32_t width       = p_frame_info->width;
    uint32_t offset      = p_frame_info->pp_scan_infos[0]->offset;
    uint32_t luma_size   = p_engine->out_luma_size;
    uint32_t chroma_size = p_engine->out_chroma_size;

    static struct mercury_buf output_buf =  {0, -1, (void *) 0x0, 0,
      0, 0, 0, 0, 0};
    static struct mercury_buf in_buf =  {0, -1, (void *) 0x0, 0, 0,
      0, 0, 0, 0};
    static jpeg_buf_t *p_out_y_buf;
    static jpeg_buf_t *p_out_uv_buf;
    static jpeg_buf_t *p_bitstream_buf;
    static jpeg_buf_t *saved_source_buf;
    static int buffers_initialized = false;

    /* bit_buf_length is actually at least two bytes less */
    bitstream_size = file_size - offset;

    if (!buffers_initialized) {
        JPEG_DBG_HIGH("\n(%d)%s()  *** Initializing decoder buffers ***\n",
                      __LINE__, __func__);

        /* Initialize output buffers*/
        in_buf.alloc_ion.len = bitstream_size;
        in_buf.alloc_ion.flags = ION_FLAG_CACHED;
        in_buf.alloc_ion.heap_id_mask = 0x1 << ION_IOMMU_HEAP_ID;
        in_buf.alloc_ion.align = 4096;
        in_buf.vaddr = do_mmap (bitstream_size, &in_buf.fd, MERCURY_PMEM_ADSP,
                                &in_buf.ion_fd_main, &in_buf.alloc_ion,
            &in_buf.fd_ion_map);
        if (!in_buf.vaddr) {
            JPEG_DBG_ERROR("\n(%d)%s()  Error mapping bitstream buffer!!!\n",
                            __LINE__, __func__);
            return JPEG_EVENT_ERROR;
        }
        JPEG_DBG_LOW("\n(%d)%s()",__LINE__,__func__);

        /* Initialize output buffers*/
        output_buf.alloc_ion.len = luma_size+chroma_size;
        output_buf.alloc_ion.flags = ION_FLAG_CACHED;
        output_buf.alloc_ion.heap_id_mask = 0x1 << ION_IOMMU_HEAP_ID;
        output_buf.alloc_ion.align = 4096;
        output_buf.vaddr = do_mmap (luma_size+chroma_size, &output_buf.fd,
                                     MERCURY_PMEM_ADSP,&output_buf.ion_fd_main,
                                     &output_buf.alloc_ion,
            &output_buf.fd_ion_map);
        if (!output_buf.vaddr) {
            JPEG_DBG_ERROR("\n(%d)%s()  Error mapping output buffer!!!\n",
                            __LINE__, __func__);
            return JPEG_EVENT_ERROR;
        }
        JPEG_DBG_LOW("\n(%d)%s()",__LINE__,__func__);

        /* Initialize output buffers*/
        if (jpeg_buffer_init(&p_bitstream_buf) ||
            jpeg_buffer_init(&p_out_y_buf) ||
            jpeg_buffer_init(&p_out_uv_buf)) {
            JPEG_DBG_ERROR("\n(%d)%s()  Error init. output buffer!!!\n",
                           __LINE__, __func__);
            return JPEG_EVENT_ERROR;
        }
        buffers_initialized = true;
    }

    in_buf.type = 0;
    in_buf.offset = 0;
    in_buf.y_off = 0;
    in_buf.y_len = bitstream_size;

    output_buf.type = 0;
    output_buf.offset = 0;
    output_buf.y_off = 0;
    output_buf.y_len = luma_size;
    output_buf.cbcr_off = luma_size;
    output_buf.cbcr_len = chroma_size;

    p_out_y_buf->size = nRowsToProcess*width;
    p_out_uv_buf->size = (nRowsToProcess*width)>>1;

    buffer_in_use = p_engine->input_fetcher.buffer_in_use;
    saved_source_buf = p_engine->input_fetcher.p_source->p_buffers[1-buffer_in_use];
    p_engine->source.p_buffers[1-buffer_in_use] = (jpeg_buf_t *)p_bitstream_buf;

    p_bitstream_buf->ptr = (uint8_t *)in_buf.vaddr;
    p_bitstream_buf->size = bitstream_size;
    p_buf = p_bitstream_buf->ptr;
    if(!p_buf) {
        JPEG_DBG_ERROR("\n(%d)%s() Error jpegd_engine_hw_init_bit_buffer!!!\n",
        __LINE__, __func__);
        return JPEG_EVENT_ERROR;
    }

/* first is to make sure input and output pointer are valid and ready*/

    p_engine->input_fetcher.next_byte_to_fetch_offset = offset;

    /**********************************************************************
    then load up the input buffer and bit buffer
********************************************************************/
    rc = jpegd_engine_hw_init_bit_buffer(p_engine);
    if (JPEG_FAILED(rc)) {
        JPEG_DBG_ERROR("\n(%d)%s() Error jpegd_engine_hw_init_bit_buffer!!!\n",
            __LINE__, __func__);
        rc = JPEG_EVENT_ERROR;
        goto decode_error;
    }

    /* set output - MCU line buffers*/
    p_engine->pOutputBufferY = p_engine->dest.p_luma_buffers[0]->ptr;
    p_engine->pOutputBufferCbCr = p_engine->dest.p_chroma_buffers[0]->ptr;
    p_engine->curr_dest_buf_index = 0;

    p_engine->pMCULineBufPtrY    = p_engine->pOutputBufferY;
    p_engine->pMCULineBufPtrCbCr = p_engine->pOutputBufferCbCr;

    for (j=0, i=bitstream_size-1; i; i--) {
        if ((p_buf[i-1]==0xFF) && (p_buf[i]==0xD9)                      /*M_EOI*/) {
            bitstream_size = i-1;
            JPEG_DBG_LOW("\n  M_EOI detected.  Bitstream size = %d\n\n",
                          bitstream_size);
            break;
        }
    }

    if (!i) {
        JPEG_DBG_ERROR("\n(%d)%s()  Error getting bitstream content!!!\n",
                       __LINE__, __func__);
        rc = JPEG_EVENT_ERROR;
        goto decode_error;
    }

    mercury_cmd_readbus_cfg_t bus_read_cfg = {
        p_frame_info->width,
        p_frame_info->height,
        0,
        bitstream_size,
    };
    mercury_cmd_writebus_cfg_t bus_write_cfg = {
        p_frame_info->width,
        p_frame_info->height,
        p_frame_info->subsampling,
        p_engine->wr_buf_format,
        0,
        0,
        0,
        num_of_planes,
        scale_ratio,
    };
    mercury_cmd_control_cfg_t bus_ctrl_cfg = {
        p_engine->source.p_frame_info->subsampling,
        p_engine->output_format,
        p_engine->output_crcb_order,
        p_engine->jpegdFormat,
        scale_ratio,
        num_of_planes,
    };
    if (mercury_lib_decode_config(bus_read_cfg, bus_write_cfg, bus_ctrl_cfg)) {
        JPEG_DBG_ERROR("\n(%d)%s() -- Error Configuring JPEGD HW \n",
                       __LINE__, __func__);
        rc = JPEG_EVENT_ERROR;
        goto decode_error;
    }

    mercury_lib_input_buf_cfg(&in_buf);
    mercury_lib_output_buf_cfg(&output_buf);

    rc = mercury_lib_decode();
    if (rc) {
        JPEG_DBG_ERROR("\n(%d)%s() -- Error Decoding \n", __LINE__,
                        __func__);
        rc = JPEG_EVENT_ERROR;
        goto decode_error;
    }

    JPEG_DBG_MED("\n(%d)%s() -- waiting for frame done event \n",
                  __LINE__, __func__);
    os_mutex_lock(&(p_engine->frame_done_mutex));
    if (!p_engine->output_done) {
        rc = os_cond_timedwait(&p_engine->frame_done_cond,
                               &(p_engine->frame_done_mutex), 5000);
    }
    os_mutex_unlock(&(p_engine->frame_done_mutex));


    mercury_lib_input_buf_get(&output_buf);
    mercury_lib_output_buf_get(&output_buf);

    if (rc || !p_engine->output_done) {
        JPEG_DBG_ERROR("%s(): os_cond_timedwait failed\n", __func__);
        p_engine->error_flag = true;
        mercury_hw_irq_status = mercury_lib_check_rd_ack_irq();
        mercury_hw_irq_status = mercury_lib_check_wr_ack_irq();
        mercury_hw_irq_status = mercury_lib_check_jpeg_status();

        rc = JPEG_EVENT_ERROR;
        p_engine->source.p_buffers[1-buffer_in_use] = (jpeg_buf_t *)saved_source_buf;
        goto decode_error;
    }

    /* send output to engine user*/
    for (i = 0; i < (height/nRowsToProcess); i++) {

        y_offset = (nRowsToProcess*width*i);
        uv_offset = (nRowsToProcess*width*i) >> 1;

        p_out_y_buf->ptr = (uint8_t *)(output_buf.vaddr + y_offset);
        p_out_uv_buf->ptr = (uint8_t *)(output_buf.vaddr +
                                        luma_size+uv_offset);

        /* jpegd_engine_output_handler()*/
        rc = p_engine->dest.p_output_handler(p_engine->p_wrapper,
                                              p_out_y_buf, p_out_uv_buf);

        /* if something goes wrong when sending the output, bail out from the loop and return event error.*/
        if (JPEG_FAILED(rc)) {
            rc = JPEG_EVENT_ERROR;
            goto decode_error;
        }

        /* Wait for the now current set of buffer to be ready*/
        jpeg_buffer_wait_until_empty(p_out_y_buf);
        jpeg_buffer_wait_until_empty(p_out_uv_buf);
    }

    p_engine->source.p_buffers[1-buffer_in_use] = (jpeg_buf_t *)saved_source_buf;

    rc = JPEG_EVENT_DONE;

    decode_error:
    if (p_engine->back_to_back_count == 1) {

        JPEG_DBG_LOW ("%s:%d] *** Freeing output buffers ***\n", __func__, __LINE__);
        buffers_initialized = false;
        jpeg_buffer_destroy(&p_bitstream_buf);
        jpeg_buffer_destroy(&p_out_y_buf);
        jpeg_buffer_destroy(&p_out_uv_buf);

        if (do_munmap (in_buf.fd, in_buf.vaddr, in_buf.y_len,
                       in_buf.ion_fd_main, &in_buf.fd_ion_map)) {
            JPEG_DBG_ERROR ("%s:%d] fail to free PMEM for mercury output\n", __func__, __LINE__);
            return JPEG_EVENT_ERROR;
        }
        in_buf.y_len = 0;

        if (do_munmap (output_buf.fd, output_buf.vaddr, output_buf.y_len,
                        output_buf.ion_fd_main, &output_buf.fd_ion_map)) {
            JPEG_DBG_ERROR ("%s:%d] fail to free PMEM for mercury output\n",
                        __func__, __LINE__);
            return JPEG_EVENT_ERROR;
        }
        output_buf.y_len = 0;
    }
    return rc;
}



static OS_THREAD_FUNC_RET_T OS_THREAD_FUNC_MODIFIER
    jpegd_engine_hw_decode_thread(OS_THREAD_FUNC_ARG_T arg)
{
    /* Cast input argument as the engine object*/
    jpegd_engine_hw_t *p_engine = (jpegd_engine_hw_t *)arg;
    jpeg_event_t       event;
    int rc;

    p_engine_local = p_engine;
    mcr_obj_t mcr_obj = p_engine->mcr_obj;

    JPEG_DBG_LOW("\n--(%d)%s() p_engine->back_to_back_count = %d\n\n",
        __LINE__, __func__, p_engine->back_to_back_count);

    if (p_engine->back_to_back_count > 1) {
        mercury_lib_set_sequential_op(mcr_obj);
    } else {
        mercury_lib_clear_sequential_op(mcr_obj);
    }

    if (!p_engine->is_progressive) {
        /*      if(p_engine->back_to_back_count > 1) {*/
        JPEG_DBG_LOW("--(%d)%s()",__LINE__,__func__);
        event = jpegd_engine_hw_decode_baseline(p_engine);
        /*      }*/
        /*      else {*/
        /*          event = jpegd_engine_hw_decode_baseline(p_engine);*/
        /*      }*/
        if (JPEG_EVENT_ERROR == event) {
            JPEG_DBG_LOW("--(%d)%s()",__LINE__,__func__);
            p_engine->error_flag = true;
            mercury_lib_clear_sequential_op(mcr_obj);
            goto err;
        }
    } else {
        JPEG_DBG_HIGH("%s: progressive decode not supported!!!\n", __func__);
        event = JPEG_EVENT_ERROR;
    }

    rc = mercury_lib_wait_done(mcr_obj);
    if (rc) {
        JPEG_DBG_ERROR("jpegd_engine_hw_decode_thread: mercury_lib_wait_done failed\n");
        p_engine->error_flag = true;
        mercury_lib_clear_sequential_op(mcr_obj);
        goto err;
    }

    err:
    mercury_lib_release(mcr_obj);

    /* Set the active flag to inactive*/
    os_mutex_lock(&(p_engine->mutex));
    p_engine->is_active = false;
    if (p_engine->abort_flag) {
        p_engine->abort_flag = false;
        os_cond_signal(&p_engine->cond);
        os_mutex_unlock(&(p_engine->mutex));
    } else {
        if (p_engine->error_flag) {
            p_engine->error_flag = false;
            os_mutex_unlock(&(p_engine->mutex));
            /* Notify event jpegd_engine_event_handler()*/
            p_engine->p_event_handler(p_engine->p_wrapper, JPEG_EVENT_ERROR, NULL);
        } else {
            os_mutex_unlock(&(p_engine->mutex));
            /* Notify event jpegd_engine_event_handler()*/
            p_engine->p_event_handler(p_engine->p_wrapper, JPEG_EVENT_DONE, NULL);
        }
    }

    JPEG_DBG_LOW("--(%d)%s()  Event = %d\n", __LINE__, __func__, event);
    return OS_THREAD_FUNC_RET_SUCCEEDED;
}
