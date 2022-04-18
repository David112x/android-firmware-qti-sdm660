/*! \file pm_sbl_pon_target.c
*  \n
*  \brief This file contains PMIC device initialization function where initial PMIC
*  \n SBL settings are configured through the PDM auto-generated code.
*  \n
*  \n &copy; Copyright 2015 Qualcomm Technologies Inc, All Rights Reserved
*/
/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
05/29/17   ks      Updated the Drax GP1 Reset configuration(CR-2032480)
05/10/16   ps      Added support for PM660 and PM660L PMICs (CR-1074489)
05/04/16   aab     Removed Resin and KeyCombo tables since its content is the same as Keypad power table. 
                    Also, removed PMK from all tables as it is not supported in this target
                     Change all PM8005 configuation to NO Config needed
04/29/16   aab     Updated to support GP1 configuration for kpad/resin/key combo PON reset configuration
03/28/16   aab     Added pm_tgt_get_gp1_cfg() and updated config tables for 8998 target
10/08/15   aab     Created
========================================================================== */
/*===========================================================================

                     INCLUDE FILES

===========================================================================*/
#include "pm_sbl_pon_target.h"
#include "pm_app_pon.h"


/*===========================================================================

                     Global Variables

===========================================================================*/
//PSHOlD config:  PON PS Hold config
static const pm_pon_reset_cfg_type
pm_app_pon_pshold_reset_cfg_arr[PM_APP_PON_CFG_MAX][PM_MAX_NUM_PMICS] =
{  //  PM660                  PM660L                    
   {PON_WARM_RST,        PON_NO_CFG_NEEDED, 0, 0,0,0,0}, //Warm Reset
   {PON_HARD_RST,        PON_NO_CFG_NEEDED, 0, 0,0,0,0}, //Hard Reset
   {PON_SHDN,            PON_NO_CFG_NEEDED, 0, 0,0,0,0}, //Shutdown
   {PON_DVDD_HARD_RST,   PON_NO_CFG_NEEDED, 0, 0,0,0,0}, //Dvdd hard reset
   {PON_DVDD_SHDN,       PON_NO_CFG_NEEDED, 0, 0,0,0,0}  //DVDD Shutdown
};


//PSHOlD config:  PON GP1 config
static const pm_pon_reset_cfg_type
pm_app_pon_pshold_gp1_reset_cfg_arr[PM_APP_PON_CFG_MAX][PM_MAX_NUM_PMICS] =
{  //   PM660             PM660L    
   {PON_NO_CFG_NEEDED, PON_NO_CFG_NEEDED,           0, 0,0,0,0}, //Warm Reset
   {PON_NO_CFG_NEEDED, PON_NO_CFG_NEEDED,           0, 0,0,0,0}, //Hard Reset
   {PON_NO_CFG_NEEDED, PON_NO_CFG_NEEDED,           0, 0,0,0,0}, //Shutdown
   {PON_NO_CFG_NEEDED, PON_DVDD_SHDN,               0, 0,0,0,0}, //DVDD Shutdown  
   {PON_NO_CFG_NEEDED, PON_WARM_RST_THEN_DVDD_SHDN, 0, 0,0,0,0}  //Dvdd hard reset
};


//Kpdpwr / Resin /Key Combo(Resin_and_Kpdpwr):  PON Keypad Power S2 Config
static const pm_pon_reset_cfg_type
pm_app_pon_kpdpwr_reset_cfg_arr[PM_APP_PON_CFG_MAX][PM_MAX_NUM_PMICS] =
{  //   PM660                PM660L                      
   {PON_WARM_RST,       PON_NO_CFG_NEEDED,  0, 0,0,0,0}, //Warm Reset     
   {PON_HARD_RST,       PON_NO_CFG_NEEDED,  0, 0,0,0,0}, //Hard Reset     
   {PON_SHDN,           PON_NO_CFG_NEEDED,  0, 0,0,0,0}, //Shutdown       
   {PON_DVDD_HARD_RST,  PON_NO_CFG_NEEDED,  0, 0,0,0,0}, //DVDD Hard Reset
   {PON_DVDD_SHDN,      PON_NO_CFG_NEEDED,  0, 0,0,0,0}  //DVDD Shutdown  
};



//S3 reset Timer Config
static const uint8
pm_app_pon_s3_reset_timer_multiplier_arr[PM_APP_PON_RESET_SOURCE_MAX][PM_MAX_NUM_PMICS] =
{  //PM660, PM660L 
   { 1,          1,      0,      0,     0,  0,  0},    //KPDPWR_N
   { 1,          1,      0,      0,     0,  0,  0},    //RESIN_N
   { 1,          1,      0,      0,     0,  0,  0},    //KPDPWR_AND_RESIN
   { 1,          1,      0,      0,     0,  0,  0}     //KPDPWR_OR_RESIN
};



/*===========================================================================

                        FUNCTION Prototypes

===========================================================================*/
pm_err_flag_type 
pm_tgt_get_pshold_gp1_reset_cfg( uint32                      pmic_index,
                                 pm_app_pon_reset_cfg_type   app_pshold_gp1_cfg,
                                 pm_pon_reset_cfg_type*      pshold_gp1_cfg);


/*===========================================================================

                        FUNCTION DEFINITIONS

===========================================================================*/
pm_err_flag_type 
pm_tgt_get_pshold_reset_cfg( uint32                      pmic_index,
                             pm_app_pon_reset_cfg_type   app_pshold_cfg,
                             pm_pon_reset_cfg_type*      pshold_cfg)
{
  if( (pmic_index         >=  PM_MAX_NUM_PMICS)   ||  
      (app_pshold_cfg     >=  PM_APP_PON_CFG_MAX) ||
      (pshold_cfg         ==  NULL) )
  {
    return PM_ERR_FLAG__PAR_OUT_OF_RANGE;
  }

  *pshold_cfg = pm_app_pon_pshold_reset_cfg_arr[app_pshold_cfg][pmic_index];

  return PM_ERR_FLAG__SUCCESS;
}



pm_err_flag_type 
pm_tgt_get_pshold_gp1_reset_cfg( uint32                      pmic_index,
                                 pm_app_pon_reset_cfg_type   app_pshold_gp1_cfg,
                                 pm_pon_reset_cfg_type*      pshold_gp1_cfg)
{
  if( (pmic_index           >=  PM_MAX_NUM_PMICS)   ||  
      (app_pshold_gp1_cfg   >=  PM_APP_PON_CFG_MAX) ||
      (pshold_gp1_cfg       ==  NULL) )
  {
    return PM_ERR_FLAG__PAR_OUT_OF_RANGE;
  }

  *pshold_gp1_cfg = pm_app_pon_pshold_gp1_reset_cfg_arr[app_pshold_gp1_cfg][pmic_index];

  return PM_ERR_FLAG__SUCCESS;
}




pm_err_flag_type
pm_tgt_get_kpdpwr_reset_cfg( uint32                        pmic_index,
                             pm_app_pon_reset_cfg_type     app_kpdpwr_reset_cfg,
                             pm_pon_reset_cfg_type*        kpdpwr_reset_cfg)
{
    pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;

    if( (pmic_index             >= PM_MAX_NUM_PMICS)   || 
        (app_kpdpwr_reset_cfg   >= PM_APP_PON_CFG_MAX) ||
        (kpdpwr_reset_cfg       == NULL) )
    {
       return PM_ERR_FLAG__PAR_OUT_OF_RANGE;
    }

    *kpdpwr_reset_cfg = pm_app_pon_kpdpwr_reset_cfg_arr[app_kpdpwr_reset_cfg][pmic_index];

    return err_flag;
}



pm_err_flag_type
pm_pon_tgt_specific_pshold_cfg(uint32 pmic_index, pm_app_pon_reset_cfg_type app_pshold_cfg)
{
   pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;
   pm_pon_reset_cfg_type       pshold_gp1_cfg  = PM_PON_RESET_CFG_INVALID;

   if( (pmic_index >=  PM_MAX_NUM_PMICS ) || (app_pshold_cfg >=  PM_APP_PON_CFG_MAX))
   {
     return PM_ERR_FLAG__PAR_OUT_OF_RANGE;
   }

   //GP1 Reset Config
   err_flag |= pm_tgt_get_pshold_gp1_reset_cfg(pmic_index, app_pshold_cfg,  &pshold_gp1_cfg); 
   if (pshold_gp1_cfg != PON_NO_CFG_NEEDED) 
   { 
       err_flag |= pm_pon_gp_reset_cfg( pmic_index, PM_PON_RESET_SOURCE_GP1, pshold_gp1_cfg);
   }
   
   return err_flag;
}


pm_err_flag_type 
pm_pon_tgt_specific_kpd_reset_cfg(uint32 pmic_index, pm_app_pon_reset_cfg_type app_pon_reset_cfg) 
{ 
   pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS; 
   //Add target specific config
   return err_flag; 
} 





pm_err_flag_type
pm_tgt_get_pon_s3_reset_timer_multiplier( uint32                        pmic_index,
                                          pm_app_pon_reset_source_type  app_pon_s3_reset_source,
                                          uint32*                       pm_s3_reset_timer_multiplier )
{
    pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;

    if( (pmic_index                   >= PM_MAX_NUM_PMICS)           || 
        (app_pon_s3_reset_source      >= PM_APP_PON_RESET_SOURCE_MAX)||
        (pm_s3_reset_timer_multiplier == NULL) )
    {
       return PM_ERR_FLAG__PAR_OUT_OF_RANGE;
    }

    *pm_s3_reset_timer_multiplier = pm_app_pon_s3_reset_timer_multiplier_arr[app_pon_s3_reset_source][pmic_index];

    return err_flag;
}

