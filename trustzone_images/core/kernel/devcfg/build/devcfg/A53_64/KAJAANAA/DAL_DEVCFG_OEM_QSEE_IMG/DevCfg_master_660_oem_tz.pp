# 1 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/kernel/devcfg/build/devcfg/A53_64/KAJAANAA/DAL_DEVCFG_OEM_QSEE_IMG/DevCfg_master_660_oem_tz.xml"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 334 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/kernel/devcfg/build/devcfg/A53_64/KAJAANAA/DAL_DEVCFG_OEM_QSEE_IMG/DevCfg_master_660_oem_tz.xml" 2
# 1 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/api/dal/DALPropDef.h" 1
# 2 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/kernel/devcfg/build/devcfg/A53_64/KAJAANAA/DAL_DEVCFG_OEM_QSEE_IMG/DevCfg_master_660_oem_tz.xml" 2
# 1 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/api/dal/DALDeviceId.h" 1
# 3 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/kernel/devcfg/build/devcfg/A53_64/KAJAANAA/DAL_DEVCFG_OEM_QSEE_IMG/DevCfg_master_660_oem_tz.xml" 2
<?xml version="1.0"?>
<dal>
<module name="devcfg">
enum_header_path "DALStdDef.h"
enum_header_path "Tlmm.h"
enum_header_path "com_dtypes.h"
enum_header_path "I2cPlatSvc.h"
enum_header_path "I2cTypes.h"
enum_header_path "I2cError.h"
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef signed int int32;
typedef signed short int16;
typedef signed char int8;
typedef unsigned long long uint64;
typedef long long int64;
typedef unsigned char byte;
typedef unsigned long UINTN;
typedef uint32 DALBOOL;
typedef uint32 DALDEVICEID;
typedef uint32 DalPowerCmd;
typedef uint32 DalPowerDomain;
typedef uint32 DalSysReq;
typedef UINTN DALHandle;
typedef int DALResult;
typedef void * DALEnvHandle;
typedef void * DALSYSEventHandle;
typedef uint32 DALMemAddr;
typedef UINTN DALSYSMemAddr;
typedef uint32 DALInterfaceVersion;
typedef unsigned char * DALDDIParamPtr;
typedef struct DALEventObject DALEventObject;
struct DALEventObject
{
    uint32 obj[8];
};
typedef DALEventObject * DALEventHandle;
typedef struct _DALMemObject
{
   uint32 memAttributes;
   uint32 sysObjInfo[2];
   uint32 dwLen;
   uint32 ownerVirtAddr;
   uint32 virtAddr;
   uint32 physAddr;
}
DALMemObject;
typedef struct _DALDDIMemBufDesc
{
   uint32 dwOffset;
   uint32 dwLen;
   uint32 dwUser;
}
DALDDIMemBufDesc;
typedef struct _DALDDIMemDescList
{
   uint32 dwFlags;
   uint32 dwNumBufs;
   DALDDIMemBufDesc bufList[1];
}
DALDDIMemDescList;
typedef struct DALSysMemDescBuf DALSysMemDescBuf;
struct DALSysMemDescBuf
{
   DALSYSMemAddr VirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   uint32 size;
   uint32 user;
};
typedef struct DALSysMemDescList DALSysMemDescList;
struct DALSysMemDescList
{
   uint32 dwObjInfo; uint32 hOwnerProc; DALSYSMemAddr thisVirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   DALSYSMemAddr VirtualAddr;
   uint32 dwCurBufIdx;
   uint32 dwNumDescBufs;
   DALSysMemDescBuf BufInfo[1];
};
typedef unsigned long uintptr_t;
typedef long intptr_t;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef long intmax_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned long uintmax_t;
typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef unsigned char boolean;
typedef uint32_t bool32;
typedef uintptr_t uintnt;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned char uint1;
typedef unsigned short uint2;
typedef unsigned int uint4;
typedef signed char int1;
typedef signed short int2;
typedef long int int4;
typedef signed int sint31;
typedef signed short sint15;
typedef signed char sint7;
typedef uint16 UWord16 ;
typedef uint32 UWord32 ;
typedef int32 Word32 ;
typedef int16 Word16 ;
typedef uint8 UWord8 ;
typedef int8 Word8 ;
typedef int32 Vect32 ;
typedef enum
{
   TLMM_GPIO_MODE_PRIMARY,
   TLMM_GPIO_MODE_IO,
   TLMM_PLACEHOLDER_TLMMGpioModeType = 0x7fffffff
}TLMMGpioModeType;
typedef enum
{
  TLMM_GPIO_INPUT = 0,
  TLMM_GPIO_OUTPUT = 1,
  TLMM_PLACEHOLDER_TLMMGpioDirectionType = 0x7fffffff
}TLMMGpioDirectionType;
typedef enum
{
  TLMM_GPIO_NO_PULL = 0,
  TLMM_GPIO_PULL_DOWN = 0x1,
  TLMM_GPIO_KEEPER = 0x2,
  TLMM_GPIO_PULL_UP = 0x3,
  TLMM_PLACEHOLDER_TLMMGpioPullType = 0x7fffffff
}TLMMGpioPullType;
typedef enum
{
  TLMM_GPIO_2MA = 0,
  TLMM_GPIO_4MA = 0x1,
  TLMM_GPIO_6MA = 0x2,
  TLMM_GPIO_8MA = 0x3,
  TLMM_GPIO_10MA = 0x4,
  TLMM_GPIO_12MA = 0x5,
  TLMM_GPIO_14MA = 0x6,
  TLMM_GPIO_16MA = 0x7,
  TLMM_PLACEHOLDER_TLMMGpioDriveType = 0x7fffffff
}TLMMGpioDriveType;
typedef enum
{
  TLMM_GPIO_LOW_VALUE,
  TLMM_GPIO_HIGH_VALUE,
  TLMM_PLACEHOLDER_TLMMGpioValueType = 0x7fffffff
}TLMMGpioValueType;
typedef uint32 TLMMGpioIdKeyType;
typedef enum
{
  TLMM_GPIO_DISABLE,
  TLMM_GPIO_ENABLE,
  TLMM_PLACEHOLDER_TLMMGpioEnableType = 0x7fffffff
}TLMMGpioEnableType;
typedef struct
{
  TLMMGpioDirectionType eDirection;
  TLMMGpioPullType ePull;
  TLMMGpioDriveType eDriveStrength;
}TLMMGpioConfigIdType;
typedef struct
{
  uint32 nGpioNumber;
  uint32 nFunctionSelect;
  TLMMGpioConfigIdType Settings;
  TLMMGpioValueType eOutputDrive;
}TLMMGpioIdSettingsType;
DALResult Tlmm_GetGpioId(const char* pszGpio, TLMMGpioIdKeyType* pnGpioId);
DALResult Tlmm_ConfigGpioId(TLMMGpioIdKeyType nGpioId, TLMMGpioConfigIdType* pUserSettings);
DALResult Tlmm_ConfigGpioIdInactive(TLMMGpioIdKeyType nGpioId);
DALResult Tlmm_GpioIdOut(TLMMGpioIdKeyType nGpioId, TLMMGpioValueType eValue);
DALResult Tlmm_GpioIdIn(TLMMGpioIdKeyType nGpioId, TLMMGpioValueType *eValue);
DALResult Tlmm_ReleaseGpioId(TLMMGpioIdKeyType nGpioId);
DALResult Tlmm_SelectGpioIdMode(TLMMGpioIdKeyType nGpioId, TLMMGpioModeType eMode, TLMMGpioConfigIdType* pUserSettings);
DALResult Tlmm_GetGpioIdSettings(TLMMGpioIdKeyType nGpioId, TLMMGpioIdSettingsType* pGpioSettings);
int Tlmm_Init(void);
typedef enum I2cResult
{
   I2C_RES_SUCCESS =0,
   I2C_RES_ERROR_CLS_I2C_CORE = (int32)0x10000000,
   I2C_RES_ERROR_CLS_QUP_DEV_TIMEOUT = (int32)0x20000000,
   I2C_RES_ERROR_CLS_QUP_DEV = (int32)0x30000000,
   I2C_RES_ERROR_CLS_I2C_DRV = (int32)0x40000000,
   I2C_RES_ERROR_CLS_DEV_PLATFORM = (int32)0xE0000000,
   I2C_RES_ERROR_CLS_DEV_OS = (int32)0xF0000000,
} I2cResult;
typedef struct I2CPLATDEV_PropertyType
{
   uint8 *virtBlockAddr;
   uint32 uI2cInputClkKhz;
   boolean bInterruptBased;
} I2CPLATDEV_PropertyType;
typedef void* I2CPLATDEV_HANDLE;
typedef void (*IST_HOOK)(void *pdata);
typedef void (*ISR_HOOK)(void *pdata);
int32
I2CPLATDEV_DeInitTarget
(
   I2CPLATDEV_HANDLE hPlatDev
);
int32
I2CPLATDEV_InitTarget
(
   uint32 uPlatDevId,
   I2CPLATDEV_HANDLE *phPlatDev
);
int32
I2CPLATDEV_ResetTarget
(
   I2CPLATDEV_HANDLE hPlatDev
);
int32
I2CPLATDEV_SetPowerState
(
   I2CPLATDEV_HANDLE hPlatDev,
   uint32 state
);
int32
I2CPLATDEV_GetPowerState
(
   I2CPLATDEV_HANDLE hPlatDev,
   uint32 *pState
);
int32 I2CPLATDEV_ReadProperties
(
   I2CPLATDEV_HANDLE hPlatDev,
   I2CPLATDEV_PropertyType *pDevProp
);
void
I2CPLATDEV_AcquireIntLock
(
   I2CPLATDEV_HANDLE hPlatDev
);
void
I2CPLATDEV_ReleaseIntLock
(
   I2CPLATDEV_HANDLE hPlatDev
);
boolean
I2CPLATDEV_IsBamEnabled
(
   I2CPLATDEV_HANDLE hPlatDev
);
int32
I2CSYS_RegisterISTHooks
(
   I2CPLATDEV_HANDLE hPlatDev,
   ISR_HOOK IsrHook,
   void* pIsrData,
   IST_HOOK IstHook,
   void* pIstData
);
int32
I2CSYS_UnRegisterISTHooks
(
   I2CPLATDEV_HANDLE hPlatDev
);
<driver name="I2C">
    <global_def>
       <string name="blsp1_i2c_qup1_appsclk" type=0x00000001> gcc_blsp1_qup1_i2c_apps_clk </string>
       <string name="blsp1_i2c_qup2_appsclk" type=0x00000001> gcc_blsp1_qup2_i2c_apps_clk </string>
       <string name="blsp1_i2c_qup3_appsclk" type=0x00000001> gcc_blsp1_qup3_i2c_apps_clk </string>
       <string name="blsp1_i2c_qup4_appsclk" type=0x00000001> gcc_blsp1_qup4_i2c_apps_clk </string>
       <string name="blsp2_i2c_qup1_appsclk" type=0x00000001> gcc_blsp2_qup1_i2c_apps_clk </string>
       <string name="blsp2_i2c_qup2_appsclk" type=0x00000001> gcc_blsp2_qup2_i2c_apps_clk </string>
       <string name="blsp2_i2c_qup3_appsclk" type=0x00000001> gcc_blsp2_qup3_i2c_apps_clk </string>
       <string name="blsp2_i2c_qup4_appsclk" type=0x00000001> gcc_blsp2_qup4_i2c_apps_clk </string>
       <string name="blsp1_i2c_qup_ahb_clk" type=0x00000001> gcc_blsp1_ahb_clk </string>
       <string name="blsp2_i2c_qup_ahb_clk" type=0x00000001> gcc_blsp2_ahb_clk </string>
       <string name="blsp1_i2c_qup1_gpio_sda" type=0x00000001> blsp_i2c_sda[1] </string>
       <string name="blsp1_i2c_qup1_gpio_scl" type=0x00000001> blsp_i2c_scl[1] </string>
       <string name="blsp1_i2c_qup2_gpio_sda" type=0x00000001> blsp_i2c_sda[2] </string>
       <string name="blsp1_i2c_qup2_gpio_scl" type=0x00000001> blsp_i2c_scl[2] </string>
       <string name="blsp1_i2c_qup3_gpio_sda" type=0x00000001> blsp_i2c_sda[3] </string>
       <string name="blsp1_i2c_qup3_gpio_scl" type=0x00000001> blsp_i2c_scl[3] </string>
       <string name="blsp1_i2c_qup4_gpio_sda" type=0x00000001> blsp_i2c_sda[4] </string>
       <string name="blsp1_i2c_qup4_gpio_scl" type=0x00000001> blsp_i2c_scl[4] </string>
       <string name="blsp2_i2c_qup1_gpio_sda" type=0x00000001> blsp_i2c_sda[5] </string>
       <string name="blsp2_i2c_qup1_gpio_scl" type=0x00000001> blsp_i2c_scl[5] </string>
       <string name="blsp2_i2c_qup2_gpio_sda" type=0x00000001> blsp_i2c_sda[6] </string>
       <string name="blsp2_i2c_qup2_gpio_scl" type=0x00000001> blsp_i2c_scl[6] </string>
       <string name="blsp2_i2c_qup3_gpio_sda" type=0x00000001> blsp_i2c_sda[7] </string>
       <string name="blsp2_i2c_qup3_gpio_scl" type=0x00000001> blsp_i2c_scl[7] </string>
       <string name="blsp2_i2c_qup4_gpio_sda" type=0x00000001> blsp_i2c_sda[8] </string>
       <string name="blsp2_i2c_qup4_gpio_scl" type=0x00000001> blsp_i2c_scl[8] </string>
    </global_def>
    <device id="/dev/buses/i2c_1">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 0 </props>
        <props name="CHIP_IRQ_NUM" type=0x00000002> 127 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC175000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
        <props name="CHIP_BLSP_NUM" type=0x00000002> 1 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp1_i2c_qup1_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp1_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp1_i2c_qup1_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp1_i2c_qup1_gpio_scl </props>
  <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
    <device id="/dev/buses/i2c_2">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 1 </props>
        <props name="CHIP_IRQ_NUM" type=0x00000002> 128 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC176000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
        <props name="CHIP_BLSP_NUM" type=0x00000002> 1 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp1_i2c_qup2_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp1_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp1_i2c_qup2_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp1_i2c_qup2_gpio_scl </props>
        <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
    <device id="/dev/buses/i2c_3">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 2 </props>
        <props name="CHIP_IRQ_NUM" type=0x00000002> 129 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC177000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
        <props name="CHIP_BLSP_NUM" type=0x00000002> 1 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp1_i2c_qup3_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp1_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp1_i2c_qup3_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp1_i2c_qup3_gpio_scl </props>
  <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
    <device id="/dev/buses/i2c_4">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 3 </props>
        <props name="CHIP_IRQ_NUM" type=0x00000002> 130 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC178000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
  <props name="CHIP_BLSP_NUM" type=0x00000002> 1 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp1_i2c_qup4_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp1_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp1_i2c_qup4_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp1_i2c_qup4_gpio_scl </props>
        <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
    <device id="/dev/buses/i2c_5">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 4 </props>
  <props name="CHIP_IRQ_NUM" type=0x00000002> 133 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC1B5000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
  <props name="CHIP_BLSP_NUM" type=0x00000002> 2 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp2_i2c_qup1_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp2_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp2_i2c_qup1_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp2_i2c_qup1_gpio_scl </props>
        <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
    <device id="/dev/buses/i2c_6">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 5 </props>
  <props name="CHIP_IRQ_NUM" type=0x00000002> 134 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC1B6000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
  <props name="CHIP_BLSP_NUM" type=0x00000002> 2 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp2_i2c_qup2_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp2_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp2_i2c_qup2_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp2_i2c_qup2_gpio_scl </props>
        <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
    <device id="/dev/buses/i2c_7">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 6 </props>
  <props name="CHIP_IRQ_NUM" type=0x00000002> 135 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC1B7000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
        <props name="CHIP_BLSP_NUM" type=0x00000002> 2 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp2_i2c_qup3_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp2_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp2_i2c_qup3_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp2_i2c_qup3_gpio_scl </props>
  <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
    <device id="/dev/buses/i2c_8">
        <props name="CHIP_BUS_INDEX" type=0x00000002> 7 </props>
  <props name="CHIP_IRQ_NUM" type=0x00000002> 136 </props>
        <props name="CHIP_QUP_BASE_ADDR" type=0x00000002> 0xC1B8000 </props>
        <props name="CHIP_APPS_CLK_FREQ_KHZ" type=0x00000002> 19200 </props>
  <props name="CHIP_BLSP_NUM" type=0x00000002> 2 </props>
        <props name="SW_ENABLE_INTERRUPTS" type=0x00000002> 0 </props>
        <props name="I2CQUP_APPS_CLK" type=0x00000011> blsp2_i2c_qup4_appsclk </props>
        <props name="I2CQUP_AHB_CLK" type=0x00000011> blsp2_i2c_qup_ahb_clk </props>
        <props name="I2CQUP_GPIO_SDA" type=0x00000011> blsp2_i2c_qup4_gpio_sda </props>
        <props name="I2CQUP_GPIO_SCL" type=0x00000011> blsp2_i2c_qup4_gpio_scl </props>
  <props name="I2CQUP_GPIO_SDA_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
  <props name="I2CQUP_GPIO_SCL_CFG" type="TLMMGpioConfigIdType"> {TLMM_GPIO_OUTPUT, TLMM_GPIO_PULL_UP, TLMM_GPIO_2MA} </props>
    </device>
</driver>

enum_header_path "QupACCommonIds.h"
enum_header_path "comdef.h"
enum_header_path "target.h"
enum_header_path "customer.h"
enum_header_path "custkajaanaaa.h"
enum_header_path "targkajaanaaa.h"
enum_header_path "custremoteapis.h"
enum_header_path "custtarget.h"
enum_header_path "custsdcc.h"
enum_header_path "custsurf.h"
enum_header_path "custdiag.h"
enum_header_path "custefs.h"
enum_header_path "custpmic.h"
enum_header_path "custsio_8660.h"
enum_header_path "custsec.h"
enum_header_path "custsfs.h"
enum_header_path "armasm.h"
typedef unsigned long uintptr_t;
typedef long intptr_t;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef long intmax_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned long uintmax_t;
typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef unsigned char boolean;
typedef uint32_t bool32;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;
typedef int32_t int32;
typedef int16_t int16;
typedef int8_t int8;
typedef uintptr_t uintnt;
typedef uint8_t byte;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned char uint1;
typedef unsigned short uint2;
typedef unsigned int uint4;
typedef signed char int1;
typedef signed short int2;
typedef long int int4;
typedef signed int sint31;
typedef signed short sint15;
typedef signed char sint7;
typedef uint16 UWord16 ;
typedef uint32 UWord32 ;
typedef int32 Word32 ;
typedef int16 Word16 ;
typedef uint8 UWord8 ;
typedef int8 Word8 ;
typedef int32 Vect32 ;
      typedef long long int64;
      typedef unsigned long long uint64;
        typedef struct __attribute__((packed))
        { uint16 x; }
        unaligned_uint16;
        typedef struct __attribute__((packed))
        { uint32 x; }
        unaligned_uint32;
        typedef struct __attribute__((packed))
        { uint64 x; }
        unaligned_uint64;
        typedef struct __attribute__((packed))
        { int16 x; }
        unaligned_int16;
        typedef struct __attribute__((packed))
        { int32 x; }
        unaligned_int32;
        typedef struct __attribute__((packed))
        { int64 x; }
        unaligned_int64;
  extern dword rex_int_lock(void);
  extern dword rex_int_free(void);
    extern dword rex_fiq_lock(void);
    extern void rex_fiq_free(void);
   extern void rex_task_lock( void);
   extern void rex_task_free( void);
typedef enum {
   PERIPH_ENUM_MIN = 0,
   BLSP_QUPID_START = PERIPH_ENUM_MIN,
   BLSP_QUP1 = BLSP_QUPID_START,
   BLSP_QUP2,
   BLSP_QUP3,
   BLSP_QUP4,
   BLSP_QUP5,
   BLSP_QUP6,
   BLSP_QUP7,
   BLSP_QUP8,
   BLSP_QUP9,
   BLSP_QUP10,
   BLSP_QUP11,
   BLSP_QUP12,
   SENSOR_QUPID_START,
   SENSOR_QUP1 = SENSOR_QUPID_START,
   SENSOR_QUP2,
   SENSOR_QUP3,
   SENSOR_QUP4,
   SENSOR_QUP5,
   SENSOR_QUP6,
   BLSP_UARTID_START,
   BLSP_UART1 = BLSP_UARTID_START,
   BLSP_UART2,
   BLSP_UART3,
   BLSP_UART4,
   BLSP_UART5,
   BLSP_UART6,
   BLSP_UART7,
   BLSP_UART8,
   BLSP_UART9,
   BLSP_UART10,
   BLSP_UART11,
   BLSP_UART12,
   SENSOR_UARTID_START,
   SENSOR_UART1 = SENSOR_UARTID_START,
   SENSOR_UART2,
   SENSOR_UART3,
   SENSOR_UART4,
   SENSOR_UART5,
   SENSOR_UART6,
   PERIPH_MAX_ID
} BLSP_PERIPHID;
typedef enum {
   PERIPH_BLSP1 = 1,
   PERIPH_BLSP2 = 2,
   SENSOR_BLSP = 3
}QUPAC_BLSPID;
<driver name="NULL">
   <global_def>
      <var_seq name = "SENSOR_QUP1_GPIO_ADDR" type=0x00000003> 0x15075000, 0x15075010, 0x15075020, 0x15075030, end </var_seq>
      <var_seq name = "SENSOR_UART1_GPIO_ADDR" type=0x00000003> 0x15076000, 0x15076010, end </var_seq>
      <var_seq name = "SENSOR_QUP2_GPIO_ADDR" type=0x00000003> 0x15073000, 0x15073010, 0x15074000, 0x15074010, end </var_seq>
      <var_seq name = "SENSOR_UART2_GPIO_ADDR" type=0x00000003> 0x15077000, 0x15077010, end </var_seq>
      <var_seq name = "SENSOR_QUP3_GPIO_ADDR" type=0x00000003> 0x15076000, 0x15076010, 0x15077000, 0x15077010, end </var_seq>
      <var_seq name = "SENSOR_UART3_GPIO_ADDR" type=0x00000003> 0x15074000, 0x15074010, end </var_seq>
      <var_seq name = "SENSOR_UART4_GPIO_ADDR" type=0x00000003> 0x15075040, 0x15075050, end </var_seq>
   </global_def>
   <device id="/dev/buses/qup/blsp_qup1">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP1 </props>
   <props name="GPIO range" type=0x00000008> 0, 1, 2, 3, end </props>
   <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 1, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/blsp_uart1">
      <props name="PERIPH ID" type=0x00000002> BLSP_UART1 </props>
      <props name="GPIO range" type=0x00000008> 0, 1, 2, 3, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 0xFF, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/blsp_qup2">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP2 </props>
      <props name="GPIO range" type=0x00000008> 6, 7, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 3, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/blsp_uart2">
      <props name="PERIPH ID" type=0x00000002> BLSP_UART2 </props>
      <props name="GPIO range" type=0x00000008> 4, 5, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 3, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/blsp_qup3">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP3 </props>
      <props name="GPIO range" type=0x00000008> 8, 9, 10, 11, end </props>
   <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 1, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/blsp_qup4">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP4 </props>
      <props name="GPIO range" type=0x00000008> 14, 15, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 3, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/blsp_qup5">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP5 </props>
      <props name="GPIO range" type=0x00000008> 16, 17, 18, 19, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 0xFF, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/blsp_uart3">
      <props name="PERIPH ID" type=0x00000002> BLSP_UART3 </props>
      <props name="GPIO range" type=0x00000008> 16, 17, 18, 19, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 3, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/blsp_qup6">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP6 </props>
      <props name="GPIO range" type=0x00000008> 22, 23, end </props>
   <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 3, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/blsp_uart4">
      <props name="PERIPH ID" type=0x00000002> BLSP_UART4 </props>
      <props name="GPIO range" type=0x00000008> 24, 25, 26, 27, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 0xFF, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/blsp_qup7">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP7 </props>
      <props name="GPIO range" type=0x00000008> 24, 25, 26, 27, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 3, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/blsp_qup8">
      <props name="PERIPH ID" type=0x00000002> BLSP_QUP8 </props>
      <props name="GPIO range" type=0x00000008> 28, 29, 30, 31, end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 1 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 0xFF, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/sensor_qup1">
      <props name="PERIPH ID" type=0x00000002> SENSOR_QUP1 </props>
      <props name="GPIO_ADDR" type=0x00000014> SENSOR_QUP1_GPIO_ADDR </props>
      <props name="SENSOR_Q6_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="SENSOR_CFG_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 0 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 22, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/sensor_uart1">
      <props name="PERIPH ID" type=0x00000002> SENSOR_UART1 </props>
      <props name="GPIO_ADDR" type=0x00000014> SENSOR_UART1_GPIO_ADDR </props>
      <props name="SENSOR_Q6_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="SENSOR_CFG_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 0 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 22, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/sensor_qup2">
      <props name="PERIPH ID" type=0x00000002> SENSOR_QUP2 </props>
      <props name="GPIO_ADDR" type=0x00000014> SENSOR_QUP2_GPIO_ADDR </props>
      <props name="SENSOR_Q6_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="SENSOR_CFG_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 0 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 22, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/sensor_uart2">
      <props name="PERIPH ID" type=0x00000002> SENSOR_UART2 </props>
      <props name="GPIO_ADDR" type=0x00000014> SENSOR_UART2_GPIO_ADDR </props>
      <props name="SENSOR_Q6_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="SENSOR_CFG_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 0 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 22, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/qup/sensor_qup3">
      <props name="PERIPH ID" type=0x00000002> SENSOR_QUP3 </props>
      <props name="GPIO_ADDR" type=0x00000014> SENSOR_QUP3_GPIO_ADDR </props>
      <props name="SENSOR_Q6_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="SENSOR_CFG_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 0 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 22, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/sensor_uart3">
      <props name="PERIPH ID" type=0x00000002> SENSOR_UART3 </props>
      <props name="GPIO_ADDR" type=0x00000014> SENSOR_UART3_GPIO_ADDR </props>
      <props name="SENSOR_Q6_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="SENSOR_CFG_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 0 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 22, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
   <device id="/dev/buses/uart/sensor_uart4">
      <props name="PERIPH ID" type=0x00000002> SENSOR_UART4 </props>
      <props name="GPIO_ADDR" type=0x00000014> SENSOR_UART4_GPIO_ADDR </props>
      <props name="SENSOR_Q6_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="SENSOR_CFG_MPU_RG_INDEX" type=0x00000008> end </props>
      <props name="IS_GPIO_PROTECTED" type=0x00000002> 0 </props>
      <props name="RW_ACCESS_LIST" type=0x00000008> 22, end </props>
      <props name="IS_PERSISTENT" type=0x00000002> 0 </props>
   </device>
</driver>

<!--
===================================================================================== -->
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef signed int int32;
typedef signed short int16;
typedef signed char int8;
typedef unsigned long long uint64;
typedef long long int64;
typedef unsigned char byte;
typedef unsigned long UINTN;
typedef uint32 DALBOOL;
typedef uint32 DALDEVICEID;
typedef uint32 DalPowerCmd;
typedef uint32 DalPowerDomain;
typedef uint32 DalSysReq;
typedef UINTN DALHandle;
typedef int DALResult;
typedef void * DALEnvHandle;
typedef void * DALSYSEventHandle;
typedef uint32 DALMemAddr;
typedef UINTN DALSYSMemAddr;
typedef uint32 DALInterfaceVersion;
typedef unsigned char * DALDDIParamPtr;
typedef struct DALEventObject DALEventObject;
struct DALEventObject
{
    uint32 obj[8];
};
typedef DALEventObject * DALEventHandle;
typedef struct _DALMemObject
{
   uint32 memAttributes;
   uint32 sysObjInfo[2];
   uint32 dwLen;
   uint32 ownerVirtAddr;
   uint32 virtAddr;
   uint32 physAddr;
}
DALMemObject;
typedef struct _DALDDIMemBufDesc
{
   uint32 dwOffset;
   uint32 dwLen;
   uint32 dwUser;
}
DALDDIMemBufDesc;
typedef struct _DALDDIMemDescList
{
   uint32 dwFlags;
   uint32 dwNumBufs;
   DALDDIMemBufDesc bufList[1];
}
DALDDIMemDescList;
typedef struct DALSysMemDescBuf DALSysMemDescBuf;
struct DALSysMemDescBuf
{
   DALSYSMemAddr VirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   uint32 size;
   uint32 user;
};
typedef struct DALSysMemDescList DALSysMemDescList;
struct DALSysMemDescList
{
   uint32 dwObjInfo; uint32 hOwnerProc; DALSYSMemAddr thisVirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   DALSYSMemAddr VirtualAddr;
   uint32 dwCurBufIdx;
   uint32 dwNumDescBufs;
   DALSysMemDescBuf BufInfo[1];
};
typedef unsigned long uintptr_t;
typedef long intptr_t;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef long intmax_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned long uintmax_t;
typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef unsigned char boolean;
typedef uint32_t bool32;
typedef uintptr_t uintnt;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned char uint1;
typedef unsigned short uint2;
typedef unsigned int uint4;
typedef signed char int1;
typedef signed short int2;
typedef long int int4;
typedef signed int sint31;
typedef signed short sint15;
typedef signed char sint7;
typedef uint16 UWord16 ;
typedef uint32 UWord32 ;
typedef int32 Word32 ;
typedef int16 Word16 ;
typedef uint8 UWord8 ;
typedef int8 Word8 ;
typedef int32 Vect32 ;
typedef enum
{
   TLMM_GPIO_MODE_PRIMARY,
   TLMM_GPIO_MODE_IO,
   TLMM_PLACEHOLDER_TLMMGpioModeType = 0x7fffffff
}TLMMGpioModeType;
typedef enum
{
  TLMM_GPIO_INPUT = 0,
  TLMM_GPIO_OUTPUT = 1,
  TLMM_PLACEHOLDER_TLMMGpioDirectionType = 0x7fffffff
}TLMMGpioDirectionType;
typedef enum
{
  TLMM_GPIO_NO_PULL = 0,
  TLMM_GPIO_PULL_DOWN = 0x1,
  TLMM_GPIO_KEEPER = 0x2,
  TLMM_GPIO_PULL_UP = 0x3,
  TLMM_PLACEHOLDER_TLMMGpioPullType = 0x7fffffff
}TLMMGpioPullType;
typedef enum
{
  TLMM_GPIO_2MA = 0,
  TLMM_GPIO_4MA = 0x1,
  TLMM_GPIO_6MA = 0x2,
  TLMM_GPIO_8MA = 0x3,
  TLMM_GPIO_10MA = 0x4,
  TLMM_GPIO_12MA = 0x5,
  TLMM_GPIO_14MA = 0x6,
  TLMM_GPIO_16MA = 0x7,
  TLMM_PLACEHOLDER_TLMMGpioDriveType = 0x7fffffff
}TLMMGpioDriveType;
typedef enum
{
  TLMM_GPIO_LOW_VALUE,
  TLMM_GPIO_HIGH_VALUE,
  TLMM_PLACEHOLDER_TLMMGpioValueType = 0x7fffffff
}TLMMGpioValueType;
typedef uint32 TLMMGpioIdKeyType;
typedef enum
{
  TLMM_GPIO_DISABLE,
  TLMM_GPIO_ENABLE,
  TLMM_PLACEHOLDER_TLMMGpioEnableType = 0x7fffffff
}TLMMGpioEnableType;
typedef struct
{
  TLMMGpioDirectionType eDirection;
  TLMMGpioPullType ePull;
  TLMMGpioDriveType eDriveStrength;
}TLMMGpioConfigIdType;
typedef struct
{
  uint32 nGpioNumber;
  uint32 nFunctionSelect;
  TLMMGpioConfigIdType Settings;
  TLMMGpioValueType eOutputDrive;
}TLMMGpioIdSettingsType;
DALResult Tlmm_GetGpioId(const char* pszGpio, TLMMGpioIdKeyType* pnGpioId);
DALResult Tlmm_ConfigGpioId(TLMMGpioIdKeyType nGpioId, TLMMGpioConfigIdType* pUserSettings);
DALResult Tlmm_ConfigGpioIdInactive(TLMMGpioIdKeyType nGpioId);
DALResult Tlmm_GpioIdOut(TLMMGpioIdKeyType nGpioId, TLMMGpioValueType eValue);
DALResult Tlmm_GpioIdIn(TLMMGpioIdKeyType nGpioId, TLMMGpioValueType *eValue);
DALResult Tlmm_ReleaseGpioId(TLMMGpioIdKeyType nGpioId);
DALResult Tlmm_SelectGpioIdMode(TLMMGpioIdKeyType nGpioId, TLMMGpioModeType eMode, TLMMGpioConfigIdType* pUserSettings);
DALResult Tlmm_GetGpioIdSettings(TLMMGpioIdKeyType nGpioId, TLMMGpioIdSettingsType* pGpioSettings);
int Tlmm_Init(void);
<driver name="NULL">
   <global_def>
     <string name="gpio_spi1_clk_str" type=0x00000001>blsp_spi_clk[1]</string>
  <string name="gpio_spi1_cs_str" type=0x00000001>blsp_spi_cs_n[1]</string>
  <string name="gpio_spi1_cs1_str" type=0x00000001>blsp_spi_cs1_n[1]</string>
  <string name="gpio_spi1_mosi_str" type=0x00000001>blsp_spi_mosi[1]</string>
  <string name="gpio_spi1_miso_str" type=0x00000001>blsp_spi_miso[1]</string>
  <string name="gpio_spi2_clk_str" type=0x00000001>blsp_spi_clk[2]</string>
  <string name="gpio_spi2_cs_str" type=0x00000001>blsp_spi_cs_n[2]</string>
   <string name="gpio_spi2_mosi_str" type=0x00000001>blsp_spi_mosi[2]</string>
  <string name="gpio_spi2_miso_str" type=0x00000001>blsp_spi_miso[2]</string>
  <string name="gpio_spi3_clk_str" type=0x00000001>blsp_spi_clk[3]</string>
  <string name="gpio_spi3_cs_str" type=0x00000001>blsp_spi_cs_n[3]</string>
  <string name="gpio_spi3_cs1_str" type=0x00000001>blsp_spi_cs1_n[3]</string>
  <string name="gpio_spi3_cs2_str" type=0x00000001>blsp_spi_cs2_n[3]</string>
  <string name="gpio_spi3_mosi_str" type=0x00000001>blsp_spi_mosi[3]</string>
  <string name="gpio_spi3_miso_str" type=0x00000001>blsp_spi_miso[3]</string>
  <string name="gpio_spi4_clk_str" type=0x00000001>blsp_spi_clk[4]</string>
  <string name="gpio_spi4_cs_str" type=0x00000001>blsp_spi_cs_n[4]</string>
  <string name="gpio_spi4_mosi_str" type=0x00000001>blsp_spi_mosi[4]</string>
  <string name="gpio_spi4_miso_str" type=0x00000001>blsp_spi_miso[4]</string>
  <string name="gpio_spi5_clk_str" type=0x00000001>blsp_spi_clk[5]</string>
  <string name="gpio_spi5_cs_str" type=0x00000001>blsp_spi_cs_n[5]</string>
  <string name="gpio_spi5_mosi_str" type=0x00000001>blsp_spi_mosi[5]</string>
  <string name="gpio_spi5_miso_str" type=0x00000001>blsp_spi_miso[5]</string>
  <string name="gpio_spi6_clk_str" type=0x00000001>blsp_spi_clk[6]</string>
  <string name="gpio_spi6_cs_str" type=0x00000001>blsp_spi_cs_n[6]</string>
  <string name="gpio_spi6_mosi_str" type=0x00000001>blsp_spi_mosi[6]</string>
  <string name="gpio_spi6_miso_str" type=0x00000001>blsp_spi_miso[6]</string>
  <string name="gpio_spi7_clk_str" type=0x00000001>blsp_spi_clk[7]</string>
  <string name="gpio_spi7_cs_str" type=0x00000001>blsp_spi_cs_n[7]</string>
  <string name="gpio_spi7_mosi_str" type=0x00000001>blsp_spi_mosi[7]</string>
  <string name="gpio_spi7_miso_str" type=0x00000001>blsp_spi_miso[7]</string>
  <string name="gpio_spi8_clk_str" type=0x00000001>blsp_spi_clk8_mira</string>
  <string name="gpio_spi8_cs_str" type=0x00000001>blsp_spi_cs_n8_mira</string>
  <string name="gpio_spi8_cs1_str" type=0x00000001>blsp_spi_cs1_n[8]</string>
  <string name="gpio_spi8_cs2_str" type=0x00000001>blsp_spi_cs2_n[8]</string>
  <string name="gpio_spi8_mosi_str" type=0x00000001>blsp_spi_mosi8_mira</string>
  <string name="gpio_spi8_miso_str" type=0x00000001>blsp_spi_miso8_mira</string>
     <var_seq name="spiqup1_appclk_name" type=0x00000001> gcc_blsp1_qup1_spi_apps_clk </var_seq>
  <var_seq name="spiqup2_appclk_name" type=0x00000001> gcc_blsp1_qup2_spi_apps_clk </var_seq>
  <var_seq name="spiqup3_appclk_name" type=0x00000001> gcc_blsp1_qup3_spi_apps_clk </var_seq>
  <var_seq name="spiqup4_appclk_name" type=0x00000001> gcc_blsp1_qup4_spi_apps_clk </var_seq>
  <var_seq name="spiqup5_appclk_name" type=0x00000001> gcc_blsp2_qup1_spi_apps_clk </var_seq>
  <var_seq name="spiqup6_appclk_name" type=0x00000001> gcc_blsp2_qup2_spi_apps_clk </var_seq>
     <var_seq name="spiqup7_appclk_name" type=0x00000001> gcc_blsp2_qup3_spi_apps_clk </var_seq>
  <var_seq name="spiqup8_appclk_name" type=0x00000001> gcc_blsp2_qup4_spi_apps_clk </var_seq>
  <var_seq name="spi_blsp1_hclk_name" type=0x00000001> gcc_blsp1_ahb_clk </var_seq>
     <var_seq name="spi_blsp2_hclk_name" type=0x00000001> gcc_blsp2_ahb_clk </var_seq>
    </global_def>
    <device id="/dev/buses/spi_1">
        <props name="QUP_CORE_NUM" type=0x00000002> 1 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC175000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 1 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC144000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 270 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 4 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 5 </props>
        <props name="is_multi_cs" type=0x00000002> 0 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi1_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi1_cs_str</props>
        <props name="gpio_spi_cs1_str" type=0x00000011>gpio_spi1_cs1_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi1_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi1_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCs1Config" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup1_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp1_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_2">
        <props name="QUP_CORE_NUM" type=0x00000002> 2 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC176000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 1 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC144000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 270 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 6 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 7 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi2_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi2_cs_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi2_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi2_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup2_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp1_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_3">
        <props name="QUP_CORE_NUM" type=0x00000002> 3 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC177000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 1 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC144000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 270 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 8 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 9 </props>
        <props name="is_multi_cs" type=0x00000002> 0 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi3_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi3_cs_str</props>
        <props name="gpio_spi_cs1_str" type=0x00000011>gpio_spi3_cs1_str</props>
        <props name="gpio_spi_cs2_str" type=0x00000011>gpio_spi3_cs2_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi3_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi3_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCs1Config" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCs2Config" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup3_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp1_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_4">
        <props name="QUP_CORE_NUM" type=0x00000002> 4 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC178000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 1 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC144000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 270 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 10 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 11 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi4_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi4_cs_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi4_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi4_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup4_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp1_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_5">
        <props name="QUP_CORE_NUM" type=0x00000002> 5 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC1B5000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 2 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC184000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 271 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 4 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 5 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi5_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi5_cs_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi5_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi5_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup5_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp2_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_6">
        <props name="QUP_CORE_NUM" type=0x00000002> 6 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC1B6000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 2 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC184000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 271 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 6 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 7 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi6_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi6_cs_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi6_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi6_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup6_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp2_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_7">
        <props name="QUP_CORE_NUM" type=0x00000002> 7 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC1B7000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 2 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC184000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 271 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 8 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 9 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi7_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi7_cs_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi7_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi7_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup7_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp2_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_8">
        <props name="QUP_CORE_NUM" type=0x00000002> 8 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0xC1B8000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 2 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0xC184000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 271 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 10 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 11 </props>
        <props name="is_multi_cs" type=0x00000002> 0 </props>
        <props name="gpio_spi_clk_str" type=0x00000011>gpio_spi8_clk_str</props>
        <props name="gpio_spi_cs_str" type=0x00000011>gpio_spi8_cs_str</props>
        <props name="gpio_spi_cs1_str" type=0x00000011>gpio_spi8_cs1_str</props>
        <props name="gpio_spi_cs2_str" type=0x00000011>gpio_spi8_cs2_str</props>
        <props name="gpio_spi_mosi_str" type=0x00000011>gpio_spi8_mosi_str</props>
        <props name="gpio_spi_miso_str" type=0x00000011>gpio_spi8_miso_str</props>
        <props name="GpioClkConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCsConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCs1Config" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioCs2Config" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMosiConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="GpioMisoConfig" type="TLMMGpioConfigIdType"> {TLMM_GPIO_INPUT, TLMM_GPIO_PULL_DOWN, TLMM_GPIO_8MA} </props>
        <props name="CHIP_APP_CLK_NAME" type=0x00000011> spiqup8_appclk_name </props>
        <props name="CHIP_HCLK_NAME" type=0x00000011> spi_blsp2_hclk_name </props>
    </device>
    <device id="/dev/buses/spi_sensor_1">
        <props name="QUP_CORE_NUM" type=0x00000002> 1 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0x15435000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 1 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0x15404000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 182 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 8 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 9 </props>
    </device>
    <device id="/dev/buses/spi_sensor_2">
        <props name="QUP_CORE_NUM" type=0x00000002> 2 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0x15436000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 1 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0x15404000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 182 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 10 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 11 </props>
    </device>
    <device id="/dev/buses/spi_sensor_3">
        <props name="QUP_CORE_NUM" type=0x00000002> 3 </props>
        <props name="QUP_BASE_ADDR" type=0x00000002> 0x15437000 </props>
        <props name="SW_ENABLE_BAM" type=0x00000002> 1 </props>
        <props name="BAM_BLSP_ID" type=0x00000002> 1 </props>
        <props name="BAM_BASE_ADDR" type=0x00000002> 0x15404000 </props>
        <props name="BAM_INTERRUPT_ID" type=0x00000002> 182 </props>
        <props name="BAM_TX_PIPE_NUM" type=0x00000002> 12 </props>
        <props name="BAM_RX_PIPE_NUM" type=0x00000002> 13 </props>
    </device>
</driver>

<driver name="NULL">
 <global_def>
 </global_def>
 <device id="/ac/xpu">
  <props name="disable_xpu_ac" type=0x00000002>
   0
  </props>
 </device>
</driver>

enum_header_path "secboot_oem.h"
enum_header_path "CeML.h"
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef signed int int32;
typedef signed short int16;
typedef signed char int8;
typedef unsigned long long uint64;
typedef long long int64;
typedef unsigned char byte;
typedef unsigned long UINTN;
typedef uint32 DALBOOL;
typedef uint32 DALDEVICEID;
typedef uint32 DalPowerCmd;
typedef uint32 DalPowerDomain;
typedef uint32 DalSysReq;
typedef UINTN DALHandle;
typedef int DALResult;
typedef void * DALEnvHandle;
typedef void * DALSYSEventHandle;
typedef uint32 DALMemAddr;
typedef UINTN DALSYSMemAddr;
typedef uint32 DALInterfaceVersion;
typedef unsigned char * DALDDIParamPtr;
typedef struct DALEventObject DALEventObject;
struct DALEventObject
{
    uint32 obj[8];
};
typedef DALEventObject * DALEventHandle;
typedef struct _DALMemObject
{
   uint32 memAttributes;
   uint32 sysObjInfo[2];
   uint32 dwLen;
   uint32 ownerVirtAddr;
   uint32 virtAddr;
   uint32 physAddr;
}
DALMemObject;
typedef struct _DALDDIMemBufDesc
{
   uint32 dwOffset;
   uint32 dwLen;
   uint32 dwUser;
}
DALDDIMemBufDesc;
typedef struct _DALDDIMemDescList
{
   uint32 dwFlags;
   uint32 dwNumBufs;
   DALDDIMemBufDesc bufList[1];
}
DALDDIMemDescList;
typedef struct DALSysMemDescBuf DALSysMemDescBuf;
struct DALSysMemDescBuf
{
   DALSYSMemAddr VirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   uint32 size;
   uint32 user;
};
typedef struct DALSysMemDescList DALSysMemDescList;
struct DALSysMemDescList
{
   uint32 dwObjInfo; uint32 hOwnerProc; DALSYSMemAddr thisVirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   DALSYSMemAddr VirtualAddr;
   uint32 dwCurBufIdx;
   uint32 dwNumDescBufs;
   DALSysMemDescBuf BufInfo[1];
};
typedef __builtin_va_list va_list;
typedef __builtin_va_list __isoc_va_list;
typedef unsigned long size_t;
typedef long ssize_t;
typedef long off_t;
typedef struct _IO_FILE FILE;
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;
extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;
FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);
int remove(const char *);
int rename(const char *, const char *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);
int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);
int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);
size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);
int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);
int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);
char *fgets(char *restrict, int, FILE *restrict);
int fputs(const char *restrict, FILE *restrict);
int puts(const char *);
int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);
int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);
int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);
void perror(const char *);
int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);
char *tmpnam(char *);
FILE *tmpfile(void);
FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);
char *tempnam(const char *, const char *);
char *cuserid(char *);
void setlinebuf(FILE *);
void setbuffer(FILE *, char *, size_t);
int fgetc_unlocked(FILE *);
int fputc_unlocked(int, FILE *);
int fflush_unlocked(FILE *);
size_t fread_unlocked(void *, size_t, size_t, FILE *);
size_t fwrite_unlocked(const void *, size_t, size_t, FILE *);
void clearerr_unlocked(FILE *);
int feof_unlocked(FILE *);
int ferror_unlocked(FILE *);
int fileno_unlocked(FILE *);
int getw(FILE *);
int putw(int, FILE *);
char *fgetln(FILE *, size_t *);
int asprintf(char **, const char *, ...);
int vasprintf(char **, const char *, __isoc_va_list);
typedef struct __locale_struct * locale_t;
void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);
char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);
char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);
int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);
int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);
char *strchr (const char *, int);
char *strrchr (const char *, int);
size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);
size_t strlen (const char *);
char *strerror (int);
int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
char *index (const char *, int);
char *rindex (const char *, int);
int ffs (int);
int ffsl (long);
int ffsll (long long);
int strcasecmp (const char *, const char *);
int strncasecmp (const char *, const char *, size_t);
int strcasecmp_l (const char *, const char *, locale_t);
int strncasecmp_l (const char *, const char *, size_t, locale_t);
char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);
void *memccpy (void *restrict, const void *restrict, int, size_t);
char *strsep(char **, const char *);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
typedef enum
{
    CEML_ERROR_SUCCESS = 0x0,
    CEML_ERROR_FAILURE = 0x1,
    CEML_ERROR_INVALID_PARAM = 0x2,
    CEML_ERROR_NOT_SUPPORTED = 0x3,
    CEML_ERROR_SHK_NOT_BLOWN = 0x4
} CeMLErrorType;
typedef struct CeMLHashAlgoCntxType CeMLHashAlgoCntxType;
typedef struct CeMLCipherAlgoCntxType CeMLCipherAlgoCntxType;
typedef struct
{
  void *pvBase;
  uint32 dwLen;
}CEMLIovecType;
typedef struct
{
  CEMLIovecType *iov;
  uint32 size;
}CEMLIovecListType;
typedef enum
{
   CEML_HASH_ALGO = 0x1,
   CEML_CIPHER_ALGO = 0x2
} CeMLAlgoType;
typedef enum
{
    CEML_HASH_ALGO_SHA1 = 0x1,
    CEML_HASH_ALGO_SHA256 = 0x2,
    CEML_HASH_ALGO_INVALID = 0x7FFFFFFF
  } CeMLHashAlgoType;
typedef enum
  {
    CEML_HASH_MODE_HASH = 0x0,
    CEML_HASH_MODE_HMAC = 0x1,
    CEML_HASH_MODE_INVALID = 0x7FFFFFFF
  } CeMLHashModeType;
typedef enum
  {
    CEML_HASH_FIRST = 0,
    CEML_HASH_LAST = 1,
    CEML_HASH_SEQ_INVALID = 0x7FFFFFFF
  } CeMLHashSeqType;
typedef enum
  {
    CEML_HASH_PARAM_MODE = 0x01,
    CEML_HASH_PARAM_HMAC_KEY = 0x02,
    CEML_HASH_PARAM_AUTH_KEY = 0x03,
    CEML_HASH_PARAM_SEQ = 0x04,
    CEML_HASH_PARAM_INVALID = 0x7FFFFFFF
  } CeMLHashParamType;
typedef enum
{
    CEML_CIPHER_MODE_ECB = 0x0,
    CEML_CIPHER_MODE_CBC = 0x1,
    CEML_CIPHER_MODE_CTR = 0x2,
    CEML_CIPHER_MODE_XTS = 0x3,
    CEML_CIPHER_MODE_CCM = 0x4,
    CEML_CIPHER_MODE_CTS = 0x5,
    CEML_CIPHER_MODE_INVALID = 0x6,
  } CeMLCipherModeType;
typedef enum
  {
    CEML_CIPHER_ENCRYPT = 0x00,
  CEML_CIPHER_DECRYPT = 0x01
  } CeMLCipherDir;
typedef enum
  {
    CEML_CIPHER_PARAM_DIRECTION = 0x01,
    CEML_CIPHER_PARAM_KEY = 0x02,
    CEML_CIPHER_PARAM_IV = 0x03,
    CEML_CIPHER_PARAM_MODE = 0x04,
    CEML_CIPHER_PARAM_NONCE = 0x05,
    CEML_CIPHER_PARAM_XTS_KEY = 0x06,
    CEML_CIPHER_PARAM_XTS_DU_SIZE = 0x07,
    CEML_CIPHER_PARAM_CCM_PAYLOAD_LEN = 0x08,
    CEML_CIPHER_PARAM_CCM_MAC_LEN = 0x09,
    CEML_CIPHER_PARAM_HW_KEY_TYPE = 0x0A,
    CEML_CIPHER_PARAM_CCM_HDR_LEN = 0x10,
    CEML_CIPHER_PARAM_INVALID = 0x11
  } CeMLCipherParamType;
typedef enum
  {
    CEML_CIPHER_ALG_AES128 = 0x0,
    CEML_CIPHER_ALG_AES256 = 0x1,
    CEML_CIPHER_ALG_TRIPLE_DES = 0x2,
    CEML_CIPHER_ALG_INVALID = 0xFF,
  } CeMLCipherAlgType;
typedef enum
  {
    CEML_CIPHER_HW_KEY_OEM = 0,
  CEML_CIPHER_HW_KEY_QC = 1
  } CeMLCipherHWKeyType;
typedef struct
{
  void * pClientCtxt;
} CeMLCntxHandle;
CeMLErrorType
CeMLInit (void);
CeMLErrorType
CeMLDeInit (void);
CeMLErrorType CeMLCipherReset(CeMLCntxHandle *ceMlHandle);
CeMLErrorType CeMLHashReset(CeMLCntxHandle *ceMlHandle);
CeMLErrorType
CeMLHashInit (CeMLCntxHandle ** _h,
                     CeMLHashAlgoType pAlgo);
CeMLErrorType
CeMLHashDeInit (CeMLCntxHandle ** _h);
CeMLErrorType
CeMLHashUpdate (CeMLCntxHandle * _h,
                     CEMLIovecListType ioVecIn);
CeMLErrorType
CeMLHashFinal (CeMLCntxHandle * _h,
                     CEMLIovecListType * ioVecOut);
CeMLErrorType
CeMLHashAtomic (CeMLCntxHandle * _h,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType * ioVecOut);
CeMLErrorType
CeMLHmac (uint8 * key_ptr,
                     uint32 keylen,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType * ioVecOut,
                     CeMLHashAlgoType pAlgo);
CeMLErrorType
CeMLCmac (uint8 *key_ptr,
                     uint32 keylen,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType *ioVecOut,
                     CeMLCipherAlgType pAlgo);
CeMLErrorType
CeMLHashSetParam (CeMLCntxHandle * _h,
                     CeMLHashParamType nParamID,
                     const void *pParam,
                     uint32 cParam,
                     CeMLHashAlgoType pAlgo );
CeMLErrorType CeMLHashSetParamAsU32(CeMLCntxHandle *_h,
                                    CeMLHashParamType nParamID,
                                    const void *pParam);
CeMLErrorType CeMLHashSetParamAsData(CeMLCntxHandle *_h,
                                       CeMLHashParamType nParamID,
                                       const void *pParam,
                                       size_t cParam,
                                       CeMLHashAlgoType pAlgo);
CeMLErrorType
CeMLCipherInit (CeMLCntxHandle ** _h,
                     CeMLCipherAlgType pAlgo);
CeMLErrorType
CeMLCipherDeInit (CeMLCntxHandle ** _h);
CeMLErrorType CeMLCipherSetParamAsU32(CeMLCntxHandle *_h,
                                                                         CeMLCipherParamType nParamID,
                                                                         void *pParam);
CeMLErrorType CeMLCipherSetParamAsData(CeMLCntxHandle *_h,
                                                                          CeMLCipherParamType nParamID,
                                                                          const void *pParam,
                                                                          size_t cParam);
CeMLErrorType CeMLCipherGetParamAsU32(CeMLCntxHandle *_h,
                                                                         CeMLCipherParamType nParamID,
                                                                         uint32 *pnOut);
CeMLErrorType CeMLCipherGetParamAsData(CeMLCntxHandle *_h,
                                                                           CeMLCipherParamType nParamID,
                                                                           void *pParam,
                                                                           size_t *cParam);
CeMLErrorType CeMLCipherSetParam (CeMLCntxHandle * ceMlHandle,
                                  CeMLCipherParamType nParamID,
                                  void *pParam,
                                  size_t cParam);
CeMLErrorType CeMLCipherGetParam (CeMLCntxHandle * _h,
                       CeMLCipherParamType nParamID,
                       void *pParam,
                       size_t *cParam );
CeMLErrorType
CeMLCipherData (CeMLCntxHandle * _h,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType * ioVecOut);
CeMLErrorType CeMLHmacInit(CeMLCntxHandle** cntx,
                           CeMLHashAlgoType pAlgo);
CeMLErrorType CeMLHmacUpdate(CeMLCntxHandle* cntx,
                             CEMLIovecListType ioVecIn);
CeMLErrorType CeMLHmacFinal(CeMLCntxHandle* cntx,
                            CEMLIovecListType *ioVecOut);
CeMLErrorType
CeMLHashCipherData(CeMLCntxHandle *_h1,
                   CeMLCntxHandle *_h2,
                   CEMLIovecListType ioVecIn,
                   CEMLIovecListType * ioVecOut,
                   uint8 * hash_out,
                   uint32 hash_out_len);
typedef struct {
  uint8 root_of_trust[32];
} SecbootRootOfTrustType;
<driver name="NULL">
  <!--
 <device id="/secboot/oem_secapp">
    <props name="sec_app_roots_of_trust" type="SecbootRootOfTrustType" array="True">
    {
      {
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
        0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10,
        0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
        0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
      },
      {
        0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A,
        0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32,
        0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A,
        0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42,
      },
    }
    </props>
  <props name="use_root_of_trust_only" type=0x00000002>
   0
  </props>
  <props name="msm_hw_id_upper" type=0x00000002>
   0x9ABCDEF0
  </props>
  <props name="msm_hw_id_lower" type=0x00000002>
   0xDEADBEEF
  </props>
  <props name="auth_use_serial_num" type=0x00000002>
   1
  </props>
  <props name="serial_num" type=0x00000002>
   0x12345678
  </props>
 </device>
  -->
</driver>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef signed int int32;
typedef signed short int16;
typedef signed char int8;
typedef unsigned long long uint64;
typedef long long int64;
typedef unsigned char byte;
typedef unsigned long UINTN;
typedef uint32 DALBOOL;
typedef uint32 DALDEVICEID;
typedef uint32 DalPowerCmd;
typedef uint32 DalPowerDomain;
typedef uint32 DalSysReq;
typedef UINTN DALHandle;
typedef int DALResult;
typedef void * DALEnvHandle;
typedef void * DALSYSEventHandle;
typedef uint32 DALMemAddr;
typedef UINTN DALSYSMemAddr;
typedef uint32 DALInterfaceVersion;
typedef unsigned char * DALDDIParamPtr;
typedef struct DALEventObject DALEventObject;
struct DALEventObject
{
    uint32 obj[8];
};
typedef DALEventObject * DALEventHandle;
typedef struct _DALMemObject
{
   uint32 memAttributes;
   uint32 sysObjInfo[2];
   uint32 dwLen;
   uint32 ownerVirtAddr;
   uint32 virtAddr;
   uint32 physAddr;
}
DALMemObject;
typedef struct _DALDDIMemBufDesc
{
   uint32 dwOffset;
   uint32 dwLen;
   uint32 dwUser;
}
DALDDIMemBufDesc;
typedef struct _DALDDIMemDescList
{
   uint32 dwFlags;
   uint32 dwNumBufs;
   DALDDIMemBufDesc bufList[1];
}
DALDDIMemDescList;
typedef struct DALSysMemDescBuf DALSysMemDescBuf;
struct DALSysMemDescBuf
{
   DALSYSMemAddr VirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   uint32 size;
   uint32 user;
};
typedef struct DALSysMemDescList DALSysMemDescList;
struct DALSysMemDescList
{
   uint32 dwObjInfo; uint32 hOwnerProc; DALSYSMemAddr thisVirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   DALSYSMemAddr VirtualAddr;
   uint32 dwCurBufIdx;
   uint32 dwNumDescBufs;
   DALSysMemDescBuf BufInfo[1];
};
typedef __builtin_va_list va_list;
typedef __builtin_va_list __isoc_va_list;
typedef unsigned long size_t;
typedef long ssize_t;
typedef long off_t;
typedef struct _IO_FILE FILE;
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;
extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;
FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);
int remove(const char *);
int rename(const char *, const char *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);
int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);
int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);
size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);
int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);
int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);
char *fgets(char *restrict, int, FILE *restrict);
int fputs(const char *restrict, FILE *restrict);
int puts(const char *);
int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);
int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);
int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);
void perror(const char *);
int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);
char *tmpnam(char *);
FILE *tmpfile(void);
FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);
char *tempnam(const char *, const char *);
char *cuserid(char *);
void setlinebuf(FILE *);
void setbuffer(FILE *, char *, size_t);
int fgetc_unlocked(FILE *);
int fputc_unlocked(int, FILE *);
int fflush_unlocked(FILE *);
size_t fread_unlocked(void *, size_t, size_t, FILE *);
size_t fwrite_unlocked(const void *, size_t, size_t, FILE *);
void clearerr_unlocked(FILE *);
int feof_unlocked(FILE *);
int ferror_unlocked(FILE *);
int fileno_unlocked(FILE *);
int getw(FILE *);
int putw(int, FILE *);
char *fgetln(FILE *, size_t *);
int asprintf(char **, const char *, ...);
int vasprintf(char **, const char *, __isoc_va_list);
typedef struct __locale_struct * locale_t;
void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);
char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);
char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);
int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);
int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);
char *strchr (const char *, int);
char *strrchr (const char *, int);
size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);
size_t strlen (const char *);
char *strerror (int);
int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
char *index (const char *, int);
char *rindex (const char *, int);
int ffs (int);
int ffsl (long);
int ffsll (long long);
int strcasecmp (const char *, const char *);
int strncasecmp (const char *, const char *, size_t);
int strcasecmp_l (const char *, const char *, locale_t);
int strncasecmp_l (const char *, const char *, size_t, locale_t);
char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);
void *memccpy (void *restrict, const void *restrict, int, size_t);
char *strsep(char **, const char *);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
typedef enum
{
    CEML_ERROR_SUCCESS = 0x0,
    CEML_ERROR_FAILURE = 0x1,
    CEML_ERROR_INVALID_PARAM = 0x2,
    CEML_ERROR_NOT_SUPPORTED = 0x3,
    CEML_ERROR_SHK_NOT_BLOWN = 0x4
} CeMLErrorType;
typedef struct CeMLHashAlgoCntxType CeMLHashAlgoCntxType;
typedef struct CeMLCipherAlgoCntxType CeMLCipherAlgoCntxType;
typedef struct
{
  void *pvBase;
  uint32 dwLen;
}CEMLIovecType;
typedef struct
{
  CEMLIovecType *iov;
  uint32 size;
}CEMLIovecListType;
typedef enum
{
   CEML_HASH_ALGO = 0x1,
   CEML_CIPHER_ALGO = 0x2
} CeMLAlgoType;
typedef enum
{
    CEML_HASH_ALGO_SHA1 = 0x1,
    CEML_HASH_ALGO_SHA256 = 0x2,
    CEML_HASH_ALGO_INVALID = 0x7FFFFFFF
  } CeMLHashAlgoType;
typedef enum
  {
    CEML_HASH_MODE_HASH = 0x0,
    CEML_HASH_MODE_HMAC = 0x1,
    CEML_HASH_MODE_INVALID = 0x7FFFFFFF
  } CeMLHashModeType;
typedef enum
  {
    CEML_HASH_FIRST = 0,
    CEML_HASH_LAST = 1,
    CEML_HASH_SEQ_INVALID = 0x7FFFFFFF
  } CeMLHashSeqType;
typedef enum
  {
    CEML_HASH_PARAM_MODE = 0x01,
    CEML_HASH_PARAM_HMAC_KEY = 0x02,
    CEML_HASH_PARAM_AUTH_KEY = 0x03,
    CEML_HASH_PARAM_SEQ = 0x04,
    CEML_HASH_PARAM_INVALID = 0x7FFFFFFF
  } CeMLHashParamType;
typedef enum
{
    CEML_CIPHER_MODE_ECB = 0x0,
    CEML_CIPHER_MODE_CBC = 0x1,
    CEML_CIPHER_MODE_CTR = 0x2,
    CEML_CIPHER_MODE_XTS = 0x3,
    CEML_CIPHER_MODE_CCM = 0x4,
    CEML_CIPHER_MODE_CTS = 0x5,
    CEML_CIPHER_MODE_INVALID = 0x6,
  } CeMLCipherModeType;
typedef enum
  {
    CEML_CIPHER_ENCRYPT = 0x00,
  CEML_CIPHER_DECRYPT = 0x01
  } CeMLCipherDir;
typedef enum
  {
    CEML_CIPHER_PARAM_DIRECTION = 0x01,
    CEML_CIPHER_PARAM_KEY = 0x02,
    CEML_CIPHER_PARAM_IV = 0x03,
    CEML_CIPHER_PARAM_MODE = 0x04,
    CEML_CIPHER_PARAM_NONCE = 0x05,
    CEML_CIPHER_PARAM_XTS_KEY = 0x06,
    CEML_CIPHER_PARAM_XTS_DU_SIZE = 0x07,
    CEML_CIPHER_PARAM_CCM_PAYLOAD_LEN = 0x08,
    CEML_CIPHER_PARAM_CCM_MAC_LEN = 0x09,
    CEML_CIPHER_PARAM_HW_KEY_TYPE = 0x0A,
    CEML_CIPHER_PARAM_CCM_HDR_LEN = 0x10,
    CEML_CIPHER_PARAM_INVALID = 0x11
  } CeMLCipherParamType;
typedef enum
  {
    CEML_CIPHER_ALG_AES128 = 0x0,
    CEML_CIPHER_ALG_AES256 = 0x1,
    CEML_CIPHER_ALG_TRIPLE_DES = 0x2,
    CEML_CIPHER_ALG_INVALID = 0xFF,
  } CeMLCipherAlgType;
typedef enum
  {
    CEML_CIPHER_HW_KEY_OEM = 0,
  CEML_CIPHER_HW_KEY_QC = 1
  } CeMLCipherHWKeyType;
typedef struct
{
  void * pClientCtxt;
} CeMLCntxHandle;
CeMLErrorType
CeMLInit (void);
CeMLErrorType
CeMLDeInit (void);
CeMLErrorType CeMLCipherReset(CeMLCntxHandle *ceMlHandle);
CeMLErrorType CeMLHashReset(CeMLCntxHandle *ceMlHandle);
CeMLErrorType
CeMLHashInit (CeMLCntxHandle ** _h,
                     CeMLHashAlgoType pAlgo);
CeMLErrorType
CeMLHashDeInit (CeMLCntxHandle ** _h);
CeMLErrorType
CeMLHashUpdate (CeMLCntxHandle * _h,
                     CEMLIovecListType ioVecIn);
CeMLErrorType
CeMLHashFinal (CeMLCntxHandle * _h,
                     CEMLIovecListType * ioVecOut);
CeMLErrorType
CeMLHashAtomic (CeMLCntxHandle * _h,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType * ioVecOut);
CeMLErrorType
CeMLHmac (uint8 * key_ptr,
                     uint32 keylen,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType * ioVecOut,
                     CeMLHashAlgoType pAlgo);
CeMLErrorType
CeMLCmac (uint8 *key_ptr,
                     uint32 keylen,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType *ioVecOut,
                     CeMLCipherAlgType pAlgo);
CeMLErrorType
CeMLHashSetParam (CeMLCntxHandle * _h,
                     CeMLHashParamType nParamID,
                     const void *pParam,
                     uint32 cParam,
                     CeMLHashAlgoType pAlgo );
CeMLErrorType CeMLHashSetParamAsU32(CeMLCntxHandle *_h,
                                    CeMLHashParamType nParamID,
                                    const void *pParam);
CeMLErrorType CeMLHashSetParamAsData(CeMLCntxHandle *_h,
                                       CeMLHashParamType nParamID,
                                       const void *pParam,
                                       size_t cParam,
                                       CeMLHashAlgoType pAlgo);
CeMLErrorType
CeMLCipherInit (CeMLCntxHandle ** _h,
                     CeMLCipherAlgType pAlgo);
CeMLErrorType
CeMLCipherDeInit (CeMLCntxHandle ** _h);
CeMLErrorType CeMLCipherSetParamAsU32(CeMLCntxHandle *_h,
                                                                         CeMLCipherParamType nParamID,
                                                                         void *pParam);
CeMLErrorType CeMLCipherSetParamAsData(CeMLCntxHandle *_h,
                                                                          CeMLCipherParamType nParamID,
                                                                          const void *pParam,
                                                                          size_t cParam);
CeMLErrorType CeMLCipherGetParamAsU32(CeMLCntxHandle *_h,
                                                                         CeMLCipherParamType nParamID,
                                                                         uint32 *pnOut);
CeMLErrorType CeMLCipherGetParamAsData(CeMLCntxHandle *_h,
                                                                           CeMLCipherParamType nParamID,
                                                                           void *pParam,
                                                                           size_t *cParam);
CeMLErrorType CeMLCipherSetParam (CeMLCntxHandle * ceMlHandle,
                                  CeMLCipherParamType nParamID,
                                  void *pParam,
                                  size_t cParam);
CeMLErrorType CeMLCipherGetParam (CeMLCntxHandle * _h,
                       CeMLCipherParamType nParamID,
                       void *pParam,
                       size_t *cParam );
CeMLErrorType
CeMLCipherData (CeMLCntxHandle * _h,
                     CEMLIovecListType ioVecIn,
                     CEMLIovecListType * ioVecOut);
CeMLErrorType CeMLHmacInit(CeMLCntxHandle** cntx,
                           CeMLHashAlgoType pAlgo);
CeMLErrorType CeMLHmacUpdate(CeMLCntxHandle* cntx,
                             CEMLIovecListType ioVecIn);
CeMLErrorType CeMLHmacFinal(CeMLCntxHandle* cntx,
                            CEMLIovecListType *ioVecOut);
CeMLErrorType
CeMLHashCipherData(CeMLCntxHandle *_h1,
                   CeMLCntxHandle *_h2,
                   CEMLIovecListType ioVecIn,
                   CEMLIovecListType * ioVecOut,
                   uint8 * hash_out,
                   uint32 hash_out_len);
typedef struct {
  uint8 root_of_trust[32];
} SecbootRootOfTrustType;
<driver name="NULL">
  <!--
 <device id="/secboot/oem_general">
    <props name="root_of_trust" type="uint8" array="True">
    {
      0xDE, 0x01, 0xAD, 0x02, 0xBE, 0x03, 0xEF, 0x04,
      0xDE, 0x05, 0xAD, 0x06, 0xDE, 0x07, 0xAD, 0x08,
      0xDE, 0x09, 0xAD, 0x0A, 0xBE, 0x0B, 0xEF, 0x0C,
      0xDE, 0x0D, 0xAD, 0x0E, 0xDE, 0x0F, 0xAD, 0x10,
    }
    </props>
  <props name="use_root_of_trust_only" type=0x00000002>
   0
  </props>
  <props name="msm_hw_id_upper" type=0x00000002>
   0x9ABCDEF0
  </props>
  <props name="msm_hw_id_lower" type=0x00000002>
   0xDEADBEEF
  </props>
  <props name="auth_use_serial_num" type=0x00000002>
   1
  </props>
  <props name="serial_num" type=0x00000002>
   0x12345678
  </props>
 </device>
  -->
</driver>

<driver name="NULL">
  <device id="qcom.tz.hdcp2p2">
    <!--
    hdcp2 storage_type defines where to store the key: it is defined
    as:
        SFS 1
        RPMB 2
    -->
    <props name="hdcp2p2_storage_type" type=0x00000002>
     2
    </props>
    <props name="chamomile_ips_hdcp2p2" type="byte" array="true">
    {
 0xAE, 0x11, 0x53, 0xAE, 0x51, 0xEF, 0x4A, 0x72, 0x7A, 0xE1,
 0x8D, 0x2A, 0xE2, 0x04, 0xE6, 0x61, 0xAC, 0xE5, 0xD4, 0x0A,
 0x8E, 0xC3, 0xCC, 0x85, 0x2B, 0xDF, 0x01, 0xBA, 0xB8, 0xFE,
 0x5B, 0x1B, 0x2E, 0xE6, 0xF2, 0x42, 0x48, 0x07, 0xB5, 0x21,
 0x56, 0xF8, 0x5A, 0xE9, 0xDA, 0xE6, 0x56, 0xEC, 0xAB, 0x76,
 0xA7, 0x1A, 0xD8, 0xD7, 0x22, 0x18, 0xC9, 0x67, 0x0E, 0x75,
 0xB6, 0xE8, 0x75, 0x3B, 0xD0, 0x94, 0x35, 0x85, 0x19, 0x4F,
 0xA1, 0xFE, 0xD7, 0xCF, 0xEE, 0x5F, 0xA2, 0x8D, 0xD0, 0xD3,
 0x86, 0x0B, 0x65, 0x95, 0xB3, 0x91, 0xF9, 0x08, 0x90, 0xD5,
 0x91, 0x49, 0x76, 0xDD, 0x6F, 0xC9, 0x75, 0x0C, 0x45, 0x13,
 0xFB, 0x6D, 0x68, 0x9A, 0xB1, 0xF1, 0x1B, 0x94, 0xE3, 0xFE,
 0x38, 0xCE, 0x74, 0x42, 0x7E, 0x77, 0x49, 0xF2, 0x3C, 0x38,
 0x33, 0x96, 0xA9, 0x8D, 0x36, 0x5E, 0x03, 0x2B, 0x70, 0x0F,
 0x23, 0x93, 0x85, 0xB9, 0x74, 0xC8, 0xC1, 0x78, 0xE2, 0xA7,
 0x50, 0xA5, 0x17, 0x48, 0x5A, 0x54, 0xDF, 0x4A, 0xB9, 0x2A,
 0x3C, 0x18, 0xDC, 0xD7, 0x72, 0xA3, 0x98, 0x2B, 0xF7, 0x87,
 0x0B, 0x2D, 0xA0, 0x50, 0x72, 0x71, 0x65, 0xA4, 0x6D, 0x71,
 0x23, 0x98, 0x2C, 0x64, 0xB6, 0x0B, 0xF8, 0x39, 0x80, 0x76,
 0xC1, 0xD6, 0xD2, 0x4A, 0x9B, 0x24, 0x24, 0xD2, 0x43, 0x68,
 0x66, 0xDB, 0xB0, 0x93, 0x45, 0x07, 0xA6, 0x4F, 0x52, 0x2C,
 0x53, 0xD3, 0xDB, 0xE8, 0xA1, 0x95, 0x05, 0x13, 0x34, 0xC8,
 0x37, 0xEA, 0xF4, 0x06, 0x8D, 0x2F, 0xD8, 0x94, 0x71, 0xCA,
 0x27, 0xC7, 0xA1, 0xB5, 0x28, 0xD2, 0x13, 0xE6, 0x06, 0xFE,
 0xD9, 0x32, 0x99, 0x27, 0x22, 0xE0, 0x65, 0xC8, 0x4A, 0x35,
 0x8C, 0xBA, 0x70, 0xD4, 0xAE, 0x62, 0xFE, 0x48, 0xC2, 0x59,
 0x4D, 0xFC, 0x5D, 0x93, 0x3C, 0xA3, 0x4B, 0x1C, 0x33, 0xE3,
 0xCA, 0xCD, 0xA9, 0x8C, 0xE5, 0x56, 0x66, 0xDA, 0x03, 0x23,
 0xD4, 0x2F, 0xBF, 0xCA, 0x71, 0x44, 0x5E, 0x5A, 0xEA, 0x06,
 0xF0, 0x86, 0x77, 0xAD, 0x1A, 0x96, 0xCF, 0xE7, 0x3D, 0xD8,
 0xB5, 0x6B, 0xDC, 0x3C, 0xFC, 0x5C, 0x65, 0x50, 0xE2, 0x15,
 0xDA, 0x83, 0xF7, 0xDE, 0xDC, 0x0F, 0x91, 0x55, 0xEA, 0x5A,
 0x26, 0x03, 0x65, 0xCC, 0x46, 0xE5, 0x63, 0x73, 0x7F, 0xA9,
 0x8D, 0x1B, 0xD8, 0x91, 0x9A, 0x9F, 0x94, 0x1B, 0xA7, 0x14,
 0x44, 0xBB, 0x2B, 0x75, 0xA2, 0xAC, 0xC7, 0xD7, 0x42, 0x9F,
 0x1D, 0x4B, 0x89, 0x90, 0x27, 0x12, 0x1A, 0xB3, 0xD4, 0x34,
 0xDB, 0x69, 0x4C, 0x87, 0xE1, 0xBB, 0xED, 0x90, 0xD7, 0x33,
 0x99, 0xB0, 0x07, 0xC2, 0xB3, 0xF9, 0x43, 0xCD, 0x3D, 0x78,
 0x1D, 0x8B, 0xC4, 0x9A, 0x8B, 0x74, 0xAD, 0x73, 0xC6, 0x74,
 0xA0, 0xF7, 0x67, 0x99, 0x58, 0x14, 0xDF, 0x06, 0x57, 0xF2,
 0x3C, 0x8F, 0x33, 0x9D, 0xA3, 0xF0, 0x51, 0x66, 0xC5, 0xD7,
 0x16, 0x95, 0x0A, 0xE7, 0x0F, 0x1E, 0xDD, 0x41, 0x88, 0xC3,
 0x91, 0x73, 0x6C, 0x87, 0xF3, 0x2F, 0xAF, 0x08, 0x2E, 0x8F,
 0x06, 0x05, 0x78, 0xA6, 0x77, 0xE9, 0x29, 0x1F, 0x13, 0x08,
 0x4A, 0xB2, 0xD3, 0x9D, 0xCB, 0x25, 0x7A, 0xDD, 0x1E, 0x1B,
 0x99, 0xDE, 0x8A, 0x95, 0x13, 0x88, 0xDD, 0x18, 0x35, 0x08,
 0x69, 0x13, 0xF8, 0x7F, 0xBA, 0x80, 0xE2, 0xEA, 0x81, 0x3E,
 0x8F, 0x9E, 0xAA, 0x0E, 0x21, 0x3A, 0x57, 0x02, 0x09, 0x3E,
 0x12, 0x50, 0x8D, 0xF8, 0x8A, 0xB9, 0x4B, 0x12, 0xE5, 0xA0,
 0x85, 0xDB, 0xAD, 0xAF, 0x63, 0xCF, 0x7B, 0x80, 0x51, 0x5D,
 0x87, 0x93, 0x47, 0xA4, 0x7F, 0xD2, 0x70, 0xA7, 0x15, 0xAD,
 0xDA, 0x90, 0x6A, 0x25, 0xDA, 0x8F, 0x80, 0x18, 0xC4, 0x51,
 0x85, 0xF3, 0xA7, 0x5F, 0xE6, 0x49, 0xF9, 0x02, 0xAC, 0x7E,
 0xDA, 0xBB, 0x84, 0x10, 0x89, 0x6F, 0xB3, 0xF5, 0xF3, 0x85,
 0x60, 0xC9, 0x43, 0xE7, 0x58, 0x66, 0x1E, 0x92, 0x60, 0xCE,
 0x77, 0xC2, 0xA9, 0xC3, 0x28, 0xE1, 0xDE, 0x93, 0x4A, 0x3C,
 0x79, 0xA9, 0x4E, 0xD5, 0x19, 0x41, 0xDC, 0x8E, 0x80, 0xC3,
 0x5F, 0xFF, 0x84, 0x75, 0xF9, 0xEB, 0x71, 0x36, 0xBB, 0x26,
 0xF2, 0x51, 0x1C, 0x2B, 0x43, 0x7B, 0xFB, 0x55, 0x53, 0x12,
 0x20, 0xD9, 0x7B, 0xA0, 0xB6, 0x77, 0x1F, 0xD3, 0x76, 0x7A,
 0x0F, 0x58, 0x88, 0xE6, 0xF4, 0x46, 0x70, 0x97, 0x93, 0x61,
 0x0A, 0x22, 0xB6, 0xDC, 0x3E, 0x18, 0x83, 0x84, 0x62, 0x2A,
 0xDD, 0xAE, 0xB2, 0x31, 0x5D, 0x0D, 0x86, 0xAB, 0xCA, 0x59,
 0x9F, 0x63, 0xF0, 0xEF, 0x0C, 0x7B, 0x95, 0x69, 0xF2, 0x45,
 0xA0, 0x7E, 0xE7, 0x23, 0x44, 0xA1, 0xEF, 0x24, 0xD5, 0x5A,
 0x1E, 0xE4, 0xC6, 0xCE, 0x27, 0xC7, 0x35, 0xF2, 0xF8, 0x75,
 0xF6, 0xDC, 0x42, 0x13, 0x95, 0x65, 0x96, 0x4F, 0xAB, 0xBB,
 0xD6, 0x59, 0xA8, 0x51, 0xCC, 0xCA, 0x54, 0xFF, 0x60, 0x02,
 0xAA, 0x61, 0xBB, 0x04, 0x9B, 0x84, 0x37, 0xD7, 0xD8, 0xFC,
 0xD9, 0xBE, 0x0F, 0x6E, 0x4E, 0xB9, 0x69, 0x07, 0x61, 0xD3,
 0xD0, 0xD3, 0xA5, 0x9B, 0x3E, 0xFD, 0x54, 0x9F, 0xA4, 0x43,
 0xFC, 0xD4, 0x72, 0x02, 0xE1, 0xEA, 0x9F, 0x6C, 0x36, 0x72,
 0x18, 0x8F, 0xE1, 0xE6, 0x45, 0x06, 0x10, 0x9A, 0x8B, 0x65,
 0xC4, 0x9C, 0x81, 0xB7, 0x67, 0x0A, 0xC2, 0xB0, 0x7F, 0xF8,
 0xFB, 0xBE, 0x79, 0x7F, 0x1D, 0xCB, 0x6B, 0x3E, 0xA3, 0x56,
 0x3B, 0xCE, 0xDA, 0x83, 0xF2, 0xDF, 0xBE, 0x33, 0x0C, 0x1C,
 0x8D, 0x4E, 0xFA, 0xA6, 0x83, 0x9C, 0xEC, 0x11, 0xF6, 0x6D,
 0x88, 0xD9, 0x70, 0x22, 0x39, 0xA2, 0xBE, 0x62, 0x7A, 0xFC,
 0x2C, 0x76, 0x1B, 0xFD, 0x74, 0xE3, 0x4C, 0x0A, 0x07, 0x8A,
 0x9E, 0x1C, 0x81, 0x13, 0x2E, 0x5B, 0xD3, 0xB4, 0x91, 0x8B,
 0xB5, 0x9F, 0x28, 0x09, 0x1C, 0x8A, 0x7A, 0x83, 0xAD, 0xE3,
 0x2A, 0x46, 0x07, 0x1E, 0x78, 0xA6, 0x1E, 0xEF, 0xA6, 0x24,
 0x43, 0xD3, 0xF9, 0x81, 0xF1, 0x4F, 0xCB, 0x9B, 0xA2, 0x43,
 0xA2, 0x2B, 0xF9, 0xA0, 0x5B, 0x37, 0xE8, 0xF7, 0x37, 0x39,
 0x69, 0xB4, 0xF3, 0x41, 0x99, 0x1A, 0xED, 0xDA, 0xFB, 0x5F,
 0xF2, 0x3D, 0xBC, 0xCD, 0x66, 0xFE, 0xB3, 0x30, 0x29, 0xE0,
 0x51, 0xF3, 0xE3, 0xA0, 0x30, 0x7F, 0xC7, 0x23, 0x13, 0xBA,
 0xA5, 0x9E, 0xA5, 0xE3, 0x47, 0x75, 0x22, 0xF2, 0xF5, 0x94,
 0xCF, 0xC3, 0x37, 0x1C, 0x1F, 0xB2, 0x9E, 0xA8, 0xED, 0x8D,
 0xFE, 0xC8, 0xDE, 0xCA, 0x1B, 0x15, 0xB7, 0x1A, 0x24, 0x30,
 0x46, 0x69, 0x9A, 0x5A, 0xDF, 0xE2, 0x66, 0x37, 0xA4, 0xBF,
 0x0A, 0x43, 0x49, 0xA9, 0x6F, 0x12, 0x9B, 0x6C, 0xEE, 0x43,
 0xD7, 0xE5, 0xC3, 0x5B, 0x64, 0xA0, 0x81, 0x6C, 0xE6, 0x96,
 0x9E, 0x3E, 0x89, 0x6B, 0x3B, 0xFD, 0x34, 0xA5, 0xF2, 0xD2,
 0x2F, 0x50, 0xB3, 0xF0, 0x47, 0x6C, 0x9E, 0x29, 0x49, 0xD0,
 0xA0, 0x45, 0x4C, 0xE1, 0x2B, 0xF4, 0x89, 0x51, 0x99, 0x12,
 0x61, 0x93, 0xE0, 0xEE, 0xCD, 0xC3, 0xE4, 0x9B, 0xAF, 0x87,
 0x9A, 0x38, 0xCF, 0x2B, 0xB8, 0x46, 0xCD, 0xC3, 0x06, 0xC1,
 0xDC, 0x67, 0x8D, 0x36, 0x3C, 0x49, 0x64, 0xC5, 0xBA, 0xF9,
 0x1B, 0xDE, 0x70, 0x3D, 0xE5, 0x02, 0xE3, 0x33, 0x68, 0x93,
 0x54, 0xE2, 0x6F, 0x15, 0x1B, 0x5C, 0x25, 0xF3, 0x8D, 0x0B,
 0x6A, 0x6E, 0x3C, 0xBC, 0x59, 0x07, 0x97, 0xFE, 0x2A, 0x68,
 0x00, 0x51, 0x2D, 0x0F, 0x7E, 0xE3, 0xFA, 0xAC, 0xC3, 0x7D,
 0x88, 0x0F, 0xBA, 0xE4, 0x23, 0xB2, 0x63, 0xB0, 0x0F, 0xD7,
 0x84, 0x09, 0x4A, 0xB1, 0x7B, 0x80, 0xF2, 0x8C, 0x03, 0x2F,
 0x79, 0x9D, 0x26, 0x22, 0x67, 0xFA, 0x11, 0x39, 0xD2, 0x11,
 0x8B, 0xA9, 0x01, 0x37, 0x93, 0xCF, 0x93, 0x62, 0xD6, 0x8B,
 0x40, 0x05, 0xB3, 0x9F, 0x87, 0xEE, 0x35, 0x21, 0x8D, 0x58,
 0x4D, 0x5A, 0xEF, 0x2B, 0x46, 0xA0, 0xB8, 0xB1, 0xF0, 0xD8,
 0x53, 0xD6, 0x93, 0x44, 0x28, 0xE4, 0xC2, 0x53, 0x9F, 0xC1,
 0x49, 0xD5, 0x3B, 0x37, 0xE5, 0x09, 0x22, 0x51, 0x6C, 0x18,
 0x59, 0xA9, 0x0D, 0xDF, 0xEF, 0x45, 0xBE, 0xEC, 0x4F, 0xA7,
 0x60, 0x98, 0xBD, 0x29, 0x4B, 0x0D, 0xDD, 0xAE, 0x2A, 0x94,
 0xCF, 0xF6, 0x14, 0x60, 0xF2, 0x08, 0x76, 0x9B, 0x6A, 0x3D,
 0xD1, 0x99, 0x89, 0xE0, 0x50, 0xE3, 0xC1, 0x2F, 0x5B, 0x50,
 0x39, 0x2D, 0xD4, 0xA9, 0xF2, 0xF8, 0x38, 0x5D, 0x66, 0x25,
 0x57, 0xF9, 0xC9, 0x73, 0x13, 0x10, 0x2D, 0x85, 0x08, 0x20,
 0xAB, 0x8E, 0x29, 0xE2, 0xF1, 0x6A, 0x28, 0xED, 0xF4, 0xE2,
 0x19, 0x99, 0xB2, 0x47, 0x9F, 0x30, 0x7D, 0xAD, 0xEF, 0xCE,
 0x6A, 0x61, 0x0A, 0xDE, 0x77, 0x52, 0x8E, 0xEA, 0xC1, 0xC4,
 0x08, 0xDA, 0x4B, 0xFA, 0xC7, 0x1E, 0xAC, 0x53, 0xA7, 0x06,
 0x84, 0xCC, 0x09, 0xFF, 0xF0, 0x81, 0xAA, 0x5C, 0xD6, 0xD8,
 0xC6, 0x0F, 0xDD, 0x1A, 0xA1, 0x02, 0xCB, 0x8D, 0xA4, 0x27,
 0x53, 0x48, 0x15, 0x27, 0x92, 0x19, 0xD8, 0xC2, 0x34, 0x40,
 0xAE, 0x3F, 0x61, 0xE5, 0x62, 0x97, 0xC1, 0x61, 0x3A, 0xB7,
 0xCA, 0xEE, 0x2A, 0xA6, 0xAA, 0xFC, 0x46, 0x82, 0x02, 0x8D,
 0x91, 0x3A, 0x4D, 0xE2, 0x04, 0x7B, 0xFC, 0xB9, 0x72, 0xD1,
 0x3B, 0xF1, 0x6F, 0x9D, 0x3E, 0x9B, 0xE7, 0x74, 0x70, 0x7E,
 0xFB, 0xD7, 0xDB, 0xC0, 0x69, 0xDE, 0x70, 0xE8, 0x7E, 0x98,
 0x3B, 0xE2, 0x42, 0xA6, 0xE8, 0xD4, 0xFE, 0x4D, 0x88, 0xC8,
 0x04, 0x0D, 0x0F, 0xEE, 0xA8, 0x25, 0xD7, 0x55, 0xD8, 0x43,
 0x59, 0x88, 0x93, 0x0C, 0x1C, 0x38, 0x9C, 0x26, 0x44, 0x79,
 0x79, 0x66, 0x1A, 0xE5, 0x9A, 0xC0, 0x94, 0xA3, 0xE5, 0x2D,
 0xB3, 0xD1, 0x28, 0x0B, 0xDD, 0x48, 0xCE, 0xDE, 0x45, 0x38,
 0xAE, 0xB2, 0xEA, 0x5B, 0x3A, 0x9A, 0x80, 0xC0, 0xCB, 0xC2,
 0xEC, 0x4E, 0xB2, 0xE1, 0x51, 0x8D, 0x9E, 0x60, 0x0F, 0x07,
 0x30, 0x5D, 0x8E, 0x11, 0xB8, 0x99, 0x23, 0xA6, 0x74, 0x37,
 0x9F, 0xA8, 0x4E, 0x6E, 0x3F, 0x35, 0xD5, 0x7E, 0x00, 0x66,
 0x75, 0xBC, 0xAC, 0xB9, 0x88, 0x11, 0xBC, 0xB8, 0xF0, 0xE3,
 0x9E, 0x85, 0x97, 0x2B, 0xB0, 0xF1, 0xB2, 0x06, 0xD9, 0x89,
 0xE4, 0x25, 0x21, 0x1D, 0xD1, 0x9B, 0xB3, 0xE7, 0xEC, 0x4F,
 0x5B, 0x6A, 0x65, 0x51, 0x17, 0xE6, 0x59, 0xB2, 0x23, 0xDC,
 0x51, 0x4E, 0xBC, 0x08, 0x63, 0x3C, 0x4A, 0xD7, 0xE9, 0x4D,
 0x79, 0x8C, 0x7C, 0x15, 0xA3, 0x4E, 0x32, 0x10, 0x18, 0x87,
 0x85, 0x2D, 0xBE, 0x13, 0x8F, 0xD1, 0x4D, 0x13, 0x8B, 0x7F,
 0xA3, 0x95, 0x9E, 0x0F, 0x1D, 0x7A, 0x1E, 0x9B, 0xEA, 0xEA,
 0x55, 0x68, 0x0C, 0xEB, 0x31, 0x27, 0x3D, 0xCC, 0x15, 0x85,
 0xA9, 0xF4, 0x03, 0xBE, 0x7A, 0x41, 0x01, 0xE2, 0xF4, 0x8E,
 0x88, 0xF3, 0x58, 0x24, 0x3D, 0x3F, 0xF0, 0x55, 0x69, 0x65,
 0xBA, 0xE0, 0x18, 0x95, 0x24, 0xB3, 0xA7, 0xB7, 0x0E, 0x3E,
 0x8B, 0xCC, 0x19, 0x2A, 0x74, 0x38, 0xA3, 0x7E, 0x57, 0x73,
 0x09, 0x35, 0xFB, 0xD5, 0x46, 0x42, 0x86, 0xB9, 0x31, 0x98,
 0xED, 0x73, 0xBA, 0xAB, 0x69, 0x28, 0x3B, 0xF1, 0x05, 0x40,
 0x9C, 0x3C, 0xE9, 0x0E, 0xFB, 0xDA, 0x7A, 0x45, 0xF0, 0x7E,
 0x40, 0x8B, 0x5F, 0x59, 0x29, 0x6F, 0xE1, 0x27, 0x00, 0x86,
 0x17, 0xBC, 0x1C, 0xFB, 0x7F, 0xBF, 0x83, 0x5C, 0x75, 0x69,
 0xED, 0xEC, 0x6C, 0x63, 0x5E, 0x84, 0x0A, 0x9A, 0xC7, 0x30,
 0x9A, 0x6B, 0xFE, 0x99, 0x4A, 0xDA, 0x0D, 0x28, 0x85, 0x4C,
 0x26, 0xC4, 0xD6, 0x23, 0x73, 0xE2, 0xCF, 0x2D, 0xDE, 0x14,
 0x9C, 0xCE, 0x2E, 0xF2, 0x39, 0x4E, 0xB3, 0x2A, 0x37, 0x78,
 0xF5, 0x50, 0x85, 0xBE, 0xD5, 0x13, 0xC8, 0x06, 0x52, 0x3B,
 0xAA, 0x5F, 0x33, 0xAD, 0x83, 0x8A, 0xBA, 0x34, 0x35, 0x42,
 0x82, 0x79, 0x63, 0x90, 0x45, 0xD3, 0xDA, 0x6E, 0x55, 0xE8,
 0xAD, 0x37, 0xB5, 0x7C, 0x45, 0xC9, 0x57, 0x86, 0x1E, 0x05,
 0xE1, 0xD8, 0xB2, 0x4C, 0xAA, 0x42, 0x96, 0x79, 0x70, 0xCD,
 0x70, 0x01, 0x8D, 0xA7, 0x13, 0x9D, 0xE0, 0x2F, 0xE8, 0xA7,
 0xFC, 0x69, 0xA3, 0x7E, 0x30, 0x5A, 0x75, 0x27, 0x3C, 0xB3,
 0x60, 0x1A, 0xEC, 0x91, 0x52, 0x1C, 0xF6, 0x86, 0xC4, 0x3C,
 0x75, 0x1D, 0xE0, 0x6D, 0x05, 0xD9, 0xDE, 0x31, 0x35, 0x8A,
 0xB6, 0xAD, 0xF5, 0x39, 0x00, 0xD1, 0xD8, 0x31, 0x60, 0x08,
 0x82, 0x8A, 0xC5, 0x13, 0xEE, 0x82, 0xF4, 0x4E, 0xF1, 0xFF,
 0x2A, 0xF6, 0x94, 0x37, 0x1F, 0x97, 0x1E, 0xD7, 0x68, 0x8A,
 0x78, 0xDB, 0xE4, 0x20, 0x49, 0xAB, 0x6F, 0xDC, 0xA5, 0x70,
 0x90, 0x93, 0x48, 0x5D, 0x9F, 0x03, 0x7D, 0x63, 0xE4, 0x19,
 0xFF, 0xB3, 0x76, 0x60, 0x89, 0xBF, 0xBE, 0xDC, 0x4B, 0x35,
 0xEB, 0xCE, 0xAC, 0x5A, 0x3D, 0x84, 0xDA, 0x54, 0xE5, 0xB2,
 0x38, 0x11, 0xC3, 0xB3, 0x29, 0x6B, 0x96, 0x92, 0x9A, 0x14,
 0x84, 0x89, 0x11, 0x43, 0x71, 0x97, 0x28, 0x56, 0xF6, 0x4A,
 0x83, 0x96, 0xFC, 0x9E, 0x01, 0xC5, 0x52, 0x78, 0x3F, 0x0D,
 0xC9, 0x2B, 0xDF, 0xA2, 0xCF, 0xCB, 0x93, 0x6C, 0xFE, 0x5B,
 0x1C, 0x99, 0x0E, 0x84, 0x9D, 0x1A, 0x1C, 0x27, 0x4A, 0x8D,
 0x5E, 0x42, 0xD2, 0x2B, 0xFA, 0x90, 0xAA, 0x58, 0x03, 0xD5,
 0x3B, 0x93, 0x3F, 0xF6, 0x8A, 0xDD, 0x15, 0x17, 0x82, 0xEB,
 0x36, 0x2D, 0x96, 0xA9, 0xFD, 0x51, 0xBE, 0x37, 0xD9, 0x67,
 0x28, 0xD6, 0x9F, 0xBF, 0x43, 0x4E, 0x7C, 0x35, 0xAF, 0x95,
 0x6B, 0xD5, 0xCE, 0x0B, 0x38, 0x9D, 0x8F, 0x84, 0x2C, 0x64,
 0x9F, 0x79, 0x11, 0x7D, 0x47, 0xDD, 0x3B, 0x42, 0x16, 0xEB,
 0xBF, 0xFB, 0x4A, 0xAF, 0xE0, 0x06, 0x96, 0x99, 0x4D, 0x3A,
 0x26, 0x31, 0xE4, 0xA6, 0x88, 0x4F, 0xA2, 0x00, 0x51, 0x2E,
 0xC0, 0x67, 0xC3, 0xB8, 0xF3, 0x00, 0xA3, 0x1C, 0xAE, 0x65,
 0xA0, 0xB5, 0x32, 0x96, 0x31, 0x4E, 0xFD, 0xC7, 0x17, 0x68,
 0xFF, 0xB8, 0x27, 0x2C, 0x95, 0x03, 0x70, 0xEF, 0x9C, 0x84,
 0x8E, 0x78, 0xA7, 0xF2, 0xD1, 0x34, 0x8E, 0xC2, 0x7A, 0xB8,
 0x09, 0x06, 0x78, 0x4B, 0x30, 0xCF, 0x70, 0x4A, 0xC0, 0xA4,
 0x44, 0xA8, 0xA1, 0x39, 0x52, 0x3A, 0x72, 0x1D, 0x8F, 0xA3,
 0x9D, 0xBF, 0xD0, 0x7D, 0x9D, 0xFF, 0xD9, 0x28, 0x3A, 0x38,
 0xB7, 0xF9, 0xA6, 0x49, 0x06, 0xCB, 0x65, 0xB7, 0x2E, 0x01,
 0x0F, 0x61, 0x65, 0x8C, 0x10, 0xAA, 0xE1, 0x5A, 0x1C, 0x5B,
 0xB9, 0x28, 0x6A, 0xD1, 0x90, 0x2D, 0xC4, 0x69, 0x43, 0xF4,
 0x4D, 0x51, 0x3A, 0xDB, 0x05, 0x84, 0x52, 0x5D, 0x04, 0x19,
 0xB1, 0x54, 0x27, 0x64, 0x2A, 0xCE, 0x44, 0x33, 0xD9, 0x9D,
 0xC4, 0x41, 0x75, 0x28, 0x28, 0xB2, 0x97, 0xC0, 0x68, 0x7D,
 0x3E, 0x67, 0xB5, 0xB8, 0x00, 0x9B, 0xB0, 0x2C, 0x94, 0x11,
 0xEE, 0x7C, 0xED, 0x2E, 0x22, 0x39, 0xA9, 0xD5, 0xC9, 0x1A,
 0xF0, 0xAC, 0x4D, 0x5E, 0x72, 0xCB, 0x8A, 0x7E, 0xAE, 0x00,
 0xC5, 0xBC, 0x29, 0x27, 0x16, 0x1C, 0x85, 0x1B, 0xFA, 0x45,
 0x3A, 0xAB, 0x94, 0xB5, 0x64, 0xA1, 0x68, 0x04, 0x6A, 0x4E,
 0xEB, 0x28, 0x3D, 0x33, 0xF9, 0x4E, 0x59, 0xFE, 0xB7, 0x6B,
 0x25, 0x6A, 0xC1, 0xE3, 0x35, 0xD2, 0xAC, 0x2C, 0xF0, 0x6F,
 0x60, 0x3F, 0x21, 0x4E, 0x98, 0xA7, 0x47, 0x36, 0x4A, 0xD3,
 0x6F, 0xBD, 0x51, 0xA9, 0xA7, 0x31, 0x9D, 0x88, 0x63, 0xD0,
 0xEB, 0x14, 0x25, 0x71, 0x33, 0x82, 0xA7, 0x6A, 0x82, 0x6C,
 0xA3, 0x81, 0x91, 0x0B, 0x85, 0x57, 0xAE, 0x9A, 0x62, 0x4D,
 0x10, 0x45, 0x41, 0xF3, 0xC5, 0x9F, 0x8B, 0x2E, 0xC2, 0x7F,
 0xA7, 0x6A, 0x4D, 0x7D, 0xF3, 0x36, 0x42, 0x97, 0x56, 0xD3,
 0xE3, 0xFC, 0xE6, 0x15, 0x57, 0xCA, 0x97, 0xC8, 0x86, 0x9A,
 0x30, 0x6E, 0x3C, 0x59, 0x9E, 0x7F, 0xA0, 0x26, 0x33, 0x6F,
 0x0A, 0x46, 0x97, 0xD0, 0x5F, 0xCC, 0x37, 0x3A, 0x5B, 0xE1,
 0x51, 0x1E, 0xD4, 0x07, 0xD9, 0x5F, 0x4F, 0xC5, 0x6D, 0x5C,
 0x00, 0x4E, 0xBB, 0xC2, 0x39, 0xCC, 0x0A, 0x86, 0x1E, 0xDB,
 0x70, 0x10, 0xB3, 0x2F, 0xE6, 0x29, 0x50, 0x03, 0x44, 0xA2,
 0xB8, 0xCF, 0x4D, 0xA7, 0x4A, 0x1A, 0xFD, 0x42, 0x90, 0x21,
 0x9B, 0xE7, 0x32, 0xE1, 0xE7, 0xDA, 0x45, 0x48, 0xC4, 0x9E,
 0x4B, 0x77, 0xA1, 0xF1, 0x1E, 0xFB, 0x5B, 0xE8, 0xE7, 0xB1,
 0x1E, 0xF6, 0x8A, 0xC4, 0x6E, 0x29, 0x40, 0xF4, 0x89, 0x1E,
 0xA7, 0x84, 0x0B, 0x6F, 0xA8, 0xD3, 0x8B, 0x7D, 0x42, 0x60,
 0xCE, 0x0C, 0x36, 0x1E, 0x45, 0xFC, 0xAF, 0x83, 0x9A, 0x18,
 0x21, 0xBA, 0x55, 0x03, 0x18, 0x68, 0x51, 0x95, 0xC0, 0x93,
 0xDF, 0x29, 0x93, 0x03, 0x31, 0xF4, 0xD8, 0x9C, 0xF9, 0xB4,
 0xCB, 0x3B, 0x8D, 0x94, 0x18, 0x37, 0x61, 0x18, 0x48, 0x49,
 0x56, 0xF3, 0x16, 0x3E, 0x6D, 0xB8, 0x7C, 0x29, 0xB1, 0x82,
 0x55, 0x7D, 0xD1, 0xEA, 0xAD, 0xE6, 0x64, 0xF3, 0x18, 0x49,
 0x5A, 0x0F, 0xF5, 0xB6, 0x5A, 0x1A, 0x51, 0x70, 0x1F, 0x31,
 0xFD, 0x60, 0x71, 0x4E, 0x41, 0x2C, 0xD5, 0xFA, 0x47, 0x05,
 0x88, 0x59, 0xF0, 0x23, 0xD0, 0xEF, 0xCB, 0x39, 0x74, 0x9F,
 0xC8, 0x61, 0xAA, 0x62, 0xB5, 0x2A, 0xCE, 0x8E, 0x74, 0x76,
 0xA2, 0x73, 0x53, 0x3A, 0xFC, 0x17, 0x36, 0x64, 0xFF, 0x89,
 0x78, 0x92, 0xE3, 0x35, 0xDE, 0xC4, 0x35, 0x7B, 0x4A, 0x29,
 0xFE, 0x6F, 0x13, 0xC8, 0xD1, 0x45, 0xB3, 0x8C, 0xC9, 0xFB,
 0x5F, 0x9C, 0xF9, 0x9D, 0xA8, 0x3D, 0xC6, 0xCB, 0x43, 0x7A,
 0x29, 0xDE, 0x4D, 0x31, 0x56, 0x04, 0x86, 0xAD, 0xE5, 0x64,
 0xA6, 0xAE, 0x4A, 0x73, 0x3B, 0x2A, 0xB1, 0x0E, 0x49, 0xD2,
 0x34, 0x79, 0xD9, 0xE4, 0x11, 0xF3, 0xB4, 0x5D, 0x37, 0x12,
 0x76, 0xB0, 0x59, 0x85, 0xEA, 0xD0, 0x3D, 0xEA, 0x89, 0x7E,
 0x72, 0xC0, 0x2C, 0x12, 0x3F, 0x71, 0x0D, 0x72, 0xCD, 0x3A,
 0x1D, 0x93, 0x02, 0xD9, 0x70, 0x2D, 0xBF, 0xFE, 0xE3, 0x65,
 0xB4, 0x97, 0xAC, 0x9F, 0x72, 0x20, 0xB0, 0xDA, 0xC0, 0x3A,
 0x70, 0xAB, 0x8E, 0xAE, 0x39, 0xF6, 0xE9, 0x1C, 0x4F, 0x9F,
 0xD1, 0x0E, 0xEB, 0x40, 0x8A, 0x36, 0x76, 0x34, 0xA8, 0x41,
 0x92, 0x2E, 0x22, 0xDE, 0x98, 0x06, 0xB0, 0x93, 0x8F, 0xBA,
 0x4A, 0x2E, 0x8F, 0xCD, 0xEA, 0xA0, 0x27, 0x8B, 0xF4, 0x2E,
 0x6B, 0xEB, 0x68, 0xD1, 0x66, 0xE0, 0x92, 0x60, 0x89, 0x40,
 0xA9, 0x94, 0xE7, 0x6B, 0x22, 0xDD, 0xC7, 0x3D, 0x1A, 0x76,
 0x39, 0xF3, 0x51, 0x97, 0x55, 0x2A, 0x61, 0xE9, 0xED, 0x73,
 0x29, 0x83, 0xFA, 0x7A, 0xE4, 0x9C, 0xC6, 0x16, 0xCC, 0x79,
 0xA4, 0x0A, 0xA7, 0x64, 0xAE, 0x1F, 0xBA, 0x31, 0x14, 0xD1,
 0xFB, 0xDB, 0xC7, 0xD3, 0x78, 0xAA, 0x63, 0xBC, 0xB4, 0xB9,
 0x10, 0xC7, 0x20, 0x8D, 0x34, 0x13, 0xE1, 0x66, 0xBE, 0x23,
 0xFC, 0x43, 0xD0, 0xDC, 0x16, 0xB4, 0xD4, 0xD2, 0xCC, 0x0E,
 0x2C, 0xC7, 0x9F, 0xA2, 0x28, 0x67, 0xA2, 0xCF, 0x51, 0x2E,
 0x87, 0x9F, 0x39, 0x29, 0x7D, 0xDE, 0x41, 0x60, 0xCE, 0x60,
 0x89, 0x5B, 0x5A, 0x57, 0x2D, 0xE3, 0xE3, 0xD0, 0x69, 0x4F,
 0x3B, 0xA3, 0x09, 0xC9, 0x32, 0x04, 0xCA, 0x28, 0xB8, 0x1D,
 0x10, 0x7B, 0x5D, 0x53, 0xCA, 0x72, 0x85, 0xE2, 0x13, 0xC8,
 0x19, 0x40, 0x28, 0x27, 0x09, 0xC0, 0x7A, 0x0A, 0x69, 0xCE,
 0xAA, 0xA0, 0xEB, 0x15, 0xC2, 0x5D, 0x72, 0xCD, 0x1B, 0xC0,
 0xF8, 0xCA, 0x36, 0x34, 0x56, 0x5F, 0x79, 0xCA, 0xA2, 0x8F,
 0xBC, 0xB0, 0xB8, 0xCB, 0xDF, 0xEC, 0xD4, 0xDA, 0x54, 0x76,
 0xC4, 0x1A, 0x55, 0xE5, 0xCE, 0x0A, 0x6D, 0xCB, 0x69, 0x35,
 0x9B, 0xE5, 0x0B, 0xBB, 0x8D, 0xDA, 0xCA, 0xA9, 0xC3, 0xB9,
 0x59, 0xA2, 0x14, 0x64, 0x03, 0xD9, 0x54, 0x8D, 0x46, 0x24,
 0xB5, 0x3D, 0xA2, 0xA5, 0xAB, 0x4F, 0x1B, 0xBD, 0xF1, 0xFC,
 0x9D, 0x70, 0x77, 0x79, 0x0C, 0x3A, 0x54, 0x8B, 0x86, 0x91,
 0x06, 0x6B, 0xDF, 0x9E, 0xEF, 0xC1, 0x76, 0x9B, 0x5B, 0x98,
 0x14, 0x99, 0x32, 0x31, 0x37, 0xC9, 0x88, 0x1B, 0x87, 0xE1,
 0x67, 0x61, 0x13, 0xFB, 0x9D, 0x41, 0x68, 0x24, 0x8B, 0xDA,
 0xD6, 0xB9, 0x5D, 0x29, 0x78, 0x5D, 0x48, 0x13, 0xB6, 0x81,
 0x85, 0xA3, 0x84, 0xB3, 0x6B, 0x15, 0x60, 0x95, 0x90, 0x05,
 0x2E, 0x65, 0x1B, 0x50, 0x43, 0x81, 0xCD, 0x26, 0x8D, 0x28,
 0xF1, 0x42, 0x46, 0xAE, 0xEB, 0x7B, 0xE2, 0xBB, 0xF1, 0x61,
 0x12, 0xC8, 0x27, 0xFB, 0x13, 0x06, 0x69, 0xE5, 0x6F, 0x46,
 0xD8, 0x2C, 0x63, 0x78, 0xC0, 0x62, 0xA0, 0xD3, 0x35, 0xE5,
 0x48, 0x3A, 0x26, 0xBD, 0xE0, 0x63, 0xC1, 0x7C, 0xEA, 0x46,
 0xBC, 0x81, 0x5B, 0xA3, 0x07, 0x40, 0x37, 0x80, 0x6E, 0x9C,
 0x33, 0x29, 0xDE, 0xBF, 0x34, 0xDF, 0x35, 0x30, 0x75, 0x3C,
 0x58, 0x2F, 0x05, 0xE6, 0x93, 0x52, 0xA4, 0x55, 0x10, 0x9C,
 0x61, 0xBF, 0xD0, 0x01, 0x9B, 0xE6, 0xE6, 0x53, 0x5F, 0x31,
 0x8D, 0x81, 0x1C, 0xF9, 0x1A, 0xC5, 0xCD, 0x97, 0xEB, 0xC1,
 0x29, 0xE7, 0xBD, 0x3A, 0xBD, 0xF8, 0x1B, 0x01, 0x94, 0x88,
 0xBA, 0x03, 0x2B, 0xD5, 0x79, 0x29, 0x60, 0x18, 0x7F, 0x3F,
 0xA0, 0xAE, 0xD2, 0x40, 0x74, 0x65, 0x1C, 0x64, 0xA3, 0x6E,
 0x94, 0x8B, 0x91, 0xCB, 0x11, 0xDE, 0x46, 0x80, 0xF1, 0x88,
 0xAE, 0x59, 0xA6, 0x2F, 0x26, 0xE4, 0x88, 0x6B, 0xC8, 0x71,
 0xA0, 0x09, 0x8E, 0x6B, 0x90, 0xE1, 0xEE, 0xB7, 0xF7, 0xBC,
 0x3C, 0xF5, 0xAE, 0x36, 0xE2, 0xAF, 0xDC, 0xE5, 0xFD, 0x96,
 0xFB, 0xC1, 0x81, 0x18, 0x94, 0xCF, 0x8E, 0x6A, 0x7A, 0x64,
 0x5F, 0x25, 0x07, 0x20, 0x08, 0x62, 0x58, 0x1D, 0xD0, 0xCD,
 0x5D, 0x77, 0x3D, 0x47, 0x40, 0x53, 0x8B, 0xDF, 0x7C, 0x6C,
 0xDF, 0x76, 0x80, 0x86, 0x9C, 0x60, 0x96, 0x5C, 0x69, 0x9E,
 0xA0, 0x50, 0x30, 0x9F, 0x7F, 0x36, 0x6E, 0xE1, 0x25, 0x0D,
 0x63, 0xB3, 0xA2, 0xF7, 0xA3, 0x56, 0x0C, 0xBE, 0xEF, 0x98,
 0xC5, 0x92, 0x8D, 0xEF, 0x67, 0x66, 0xFE, 0x85, 0x8B, 0x31,
 0x2B, 0xCE, 0x51, 0x79, 0x60, 0x3C, 0xC0, 0x2E, 0x6C, 0x92,
 0x8D, 0x74, 0xCA, 0x00, 0x0D, 0xB5, 0x4D, 0xA9, 0x06, 0x37,
 0xA2, 0x37, 0xAF, 0x5E, 0x5D, 0x7B, 0x46, 0xC5, 0x70, 0xDE,
 0xCF, 0xEA, 0x0F, 0x3D, 0x51, 0x22, 0x15, 0xF0, 0x82, 0x2E,
 0xD1, 0x13, 0xB8, 0x1A, 0x3E, 0x98, 0xCD, 0x95, 0xE4, 0xB3,
 0xC9, 0x0E, 0x57, 0x96, 0x9D, 0xCD, 0x45, 0x8D, 0x5A, 0x62,
 0x73, 0x70, 0xB6, 0x97, 0xD2, 0xAB, 0xE7, 0xB2, 0xFB, 0x9D,
 0x18, 0x4B, 0x45, 0xEA, 0x3F, 0x00, 0x81, 0x60, 0x80, 0x40,
 0xBB, 0x5F, 0x0D, 0x3A, 0x88, 0x9D, 0x6C, 0xAE, 0x3E, 0x7A,
 0x19, 0x7A, 0xCB, 0x85, 0xD5, 0x13, 0x8A, 0x42, 0x2B, 0x27,
 0xB2, 0x8F, 0x3C, 0xE3, 0x6F, 0x7F, 0xE7, 0x30, 0x72, 0x79,
 0xA1, 0x09, 0x54, 0xC1, 0x06, 0x86, 0x8C, 0x70, 0xDE, 0xC1,
 0x37, 0x3A, 0xBB, 0xE8, 0xDF, 0xF8, 0xAC, 0x40, 0x82, 0x03,
 0xE2, 0x10, 0x5C, 0x20, 0x28, 0xFF, 0x48, 0xCE, 0xD2, 0x3C,
 0x27, 0x55, 0x12, 0xD8, 0x49, 0x77, 0x22, 0xD7, 0xB1, 0x87,
 0x09, 0x8F, 0xB1, 0x8D, 0x6C, 0x0D, 0xEA, 0x0F, 0x95, 0xF3,
 0x2B, 0xF2, 0x79, 0xEE, 0x55, 0x1E, 0x28, 0x1F, 0x60, 0x25,
 0x86, 0x70, 0x4B, 0x37, 0x86, 0x03, 0x66, 0x5E, 0x4A, 0xC8,
 0xD9, 0x61, 0xA5, 0x93, 0x53, 0x54, 0xBA, 0xF1, 0x05, 0x0D,
 0x9A, 0x2D, 0xCB, 0x58, 0xEF, 0x60, 0xD7, 0xEB, 0x65, 0x27,
 0xFE, 0x5F, 0xBF, 0xBC, 0x17, 0x67, 0x1A, 0x38, 0xE5, 0x6F,
 0x53, 0x0D, 0xA4, 0xED, 0x75, 0xE5, 0xE5, 0xF5, 0xC1, 0x8C,
 0x36, 0xBE, 0xB4, 0x34, 0xB7, 0xFD, 0xF5, 0x03, 0x29, 0xB4,
 0x9A, 0x72, 0x26, 0x10, 0xCB, 0x9E, 0x69, 0x8D, 0x86, 0x38,
 0x09, 0x74, 0x75, 0x30, 0x23, 0xB6, 0xF4, 0x23, 0x3D, 0xEB,
 0xAB, 0xA7, 0x59, 0x3C, 0x1F, 0x84, 0xFF, 0x21, 0xEE, 0x50,
 0xBD, 0x4D, 0xA6, 0x3A, 0x22, 0x2F, 0xCF, 0x34, 0x1D, 0x42,
 0xD6, 0xE0, 0xF9, 0x3B, 0x19, 0x4C, 0x01, 0xB7, 0xA0, 0xA1,
 0x96, 0x53, 0x15, 0x24, 0x8C, 0x5B, 0xF6, 0x4D, 0x7A, 0xA9,
 0xD0, 0x94, 0xB0, 0xF4, 0x69, 0x57, 0x97, 0xAA, 0x82, 0x21,
 0x1E, 0x04, 0x6B, 0x29, 0xCD, 0x1F, 0x94, 0xB7, 0xFA, 0x15,
 0x8F, 0x43, 0xB9, 0xDA, 0x3F, 0xA2, 0xF9, 0x06, 0xD9, 0xBC,
 0x42, 0x89, 0xE7, 0xF4, 0x87, 0x48, 0x72, 0x16, 0xD9, 0x8C,
 0xED, 0x3D, 0xDE, 0x34, 0xB6, 0x46, 0xE0, 0x4B, 0x8D, 0x3F,
 0x5B, 0xA0, 0x15, 0x45, 0x29, 0x2F, 0x3B, 0xFB, 0xB6, 0xFA,
 0x2A, 0x88, 0xFD, 0xDB, 0xBE, 0xE4, 0xAF, 0x67, 0x5D, 0x88,
 0x9D, 0x86, 0x29, 0x54, 0xD7, 0x0C, 0xAC, 0x0F, 0x24, 0xD9,
 0xFE, 0x03, 0x02, 0x46, 0xFB, 0xBF, 0x2B, 0x88, 0x12, 0x22,
 0xA4, 0xC2, 0x8D, 0x6C, 0x6F, 0x51, 0xD1, 0x32, 0x5C, 0x05,
 0xEF, 0x98, 0xC8, 0xF2, 0x41, 0xD7, 0x64, 0x44, 0x50, 0xF7,
 0x71, 0x05, 0x5A, 0x10, 0x63, 0x5C, 0x36, 0xED, 0xCA, 0xFA,
 0xA9, 0xC3, 0xEA, 0x9C, 0xA8, 0x6E, 0x1E, 0x33, 0x43, 0xD4,
 0x48, 0x81, 0xF8, 0xC3, 0xB6, 0xD8, 0x34, 0x33, 0xEB, 0xAA,
 0x93, 0x71, 0x83, 0x0F, 0xDC, 0x7A, 0x42, 0x16, 0x45, 0x8C,
 0x4D, 0xEB, 0x44, 0x1C, 0x30, 0x92, 0xF8, 0x40, 0x5E, 0xD0,
 0xB8, 0xD9, 0xFD, 0x85, 0xD1, 0x2C, 0x40, 0x43, 0xBC, 0x49,
 0x40, 0xB4, 0x5F, 0xAA, 0x90, 0xE6, 0x08, 0x98, 0xC0, 0xA4,
 0x0F, 0x7F, 0x70, 0x6A, 0x12, 0x4F, 0xF6, 0x2C, 0x6C, 0xAF,
 0x36, 0xF9, 0x31, 0xCF, 0x96, 0xF2, 0x83, 0xAA, 0x16, 0xD7,
 0x69, 0xF8, 0x1E, 0x8A, 0x9F, 0x24, 0x82, 0x28, 0xBB, 0xD2,
 0x50, 0xF1, 0x9B, 0x4B, 0x12, 0x2B, 0xF1, 0x0E, 0x78, 0x56,
 0x04, 0x1F, 0x2C, 0x34, 0xFB, 0x9F, 0x1A, 0x1A, 0xED, 0x9D,
 0x39, 0xCB, 0xF5, 0x7C, 0x60, 0x12, 0x7C, 0x36, 0xE6, 0x8D,
 0xC6, 0x14, 0x77, 0xEF, 0x50, 0x69, 0xE5, 0x1A, 0xCA, 0x78,
 0xA1, 0x68, 0x7E, 0x4D, 0x3E, 0x67, 0xD2, 0x2F, 0x05, 0x04,
 0x22, 0xD5, 0x44, 0x6E, 0x02, 0x0C, 0x5C, 0xB8, 0xEF, 0xF0,
 0x1E, 0x8F, 0xF9, 0x6F, 0x0A, 0x8E, 0xFA, 0x14, 0xCF, 0x71,
 0x26, 0x81, 0x78, 0xDC, 0xFC, 0xF6, 0xEF, 0x1B, 0x31, 0x0E,
 0x09, 0x87, 0x34, 0x6D, 0xD6, 0xCA, 0x49, 0x01, 0xC4, 0x2E,
 0x9F, 0xAB, 0xB6, 0xA2, 0x10, 0x3D, 0x8A, 0x89, 0x2B, 0xBE,
 0x27, 0xD7, 0xF1, 0xA0, 0x64, 0x4D, 0x98, 0x62, 0x85, 0x03,
 0xA9, 0xC6, 0xA2, 0x3E, 0xCD, 0x6D, 0x14, 0x5C, 0x2A, 0x77,
 0x2A, 0x8E, 0x7A, 0xDB, 0x77, 0x52, 0xDF, 0x0E, 0xDF, 0x8A,
 0x00, 0x30, 0x60, 0xB7, 0xA1, 0xD5, 0x63, 0x0F, 0xBD, 0x36,
 0x85, 0xC4, 0x53, 0x39, 0x59, 0x8A, 0x09, 0xF5, 0xFA, 0xB4,
 0xA2, 0x10, 0x32, 0x52, 0x57, 0x0C, 0x2C, 0x0C, 0xA0, 0x13,
 0x60, 0xB2, 0x0D, 0x4F, 0xED, 0xF7, 0x97, 0x16, 0x15, 0x06,
 0xAB, 0x2D, 0x30, 0x9E, 0x5E, 0xBF, 0x03, 0x16, 0xC2, 0xEF,
 0x7D, 0xB2, 0xD1, 0x8E, 0x30, 0x56, 0x65, 0x86, 0xFB, 0xF3,
 0x4E, 0x57, 0xF7, 0x99, 0x5A, 0x7A, 0xFB, 0xB3, 0x67, 0x45,
 0x77, 0x38, 0x65, 0xEB, 0x16, 0x81, 0x14, 0x06, 0x61, 0x32,
 0x95, 0xE0, 0xA6, 0x2A, 0x26, 0xE0, 0xAD, 0xC2, 0x54, 0xED,
 0xBF, 0x3A, 0x02, 0x77, 0xF0, 0x70, 0x65, 0x64, 0x3E, 0x7D,
 0xE2, 0x4D, 0xC9, 0x1D, 0x56, 0x50, 0x4F, 0xFA, 0x8B, 0x43,
 0xB6, 0xAF, 0x1D, 0x2C, 0x18, 0x11, 0x8D, 0x18, 0xA4, 0x37,
 0xD8, 0x6F, 0xA9, 0x5C, 0x34, 0xDE, 0x2B, 0x6F, 0xBA, 0xD9,
 0xE0, 0x86, 0x72, 0xE8, 0x06, 0x61, 0x30, 0x15, 0x58, 0x17,
 0x70, 0x7C, 0x31, 0xE7, 0x27, 0x23, 0xC7, 0x8A, 0xDD, 0xD5,
 0xE5, 0x3D, 0xA8, 0x33, 0xCE, 0x31, 0xA0, 0xB7, 0x04, 0xEC,
 0x20, 0x45, 0x90, 0x0A, 0x16, 0xCD, 0x33, 0xF3, 0x3E, 0xDD,
 0x36, 0x0C, 0x2B, 0xB5, 0xD2, 0xD5, 0x6B, 0x00, 0xB7, 0xC2,
 0x9C, 0xEF, 0x60, 0x3C, 0xF7, 0x5D, 0x73, 0xB6, 0xD9, 0xF3,
 0xE0, 0xCB, 0xDA, 0x10, 0xA8, 0xEB, 0xB2, 0x33, 0x5E, 0xAB,
 0x07, 0x2F, 0x23, 0x68, 0xC3, 0xDF, 0xF3, 0xE1, 0xBB, 0xFE,
 0xAD, 0x27, 0xAA, 0xCE, 0x02, 0xFD, 0x79, 0xB5, 0x13, 0x81,
 0x33, 0xC6, 0x32, 0xA7, 0xC0, 0x06, 0x76, 0xF7, 0x5D, 0xAA,
 0x49, 0x82, 0x55, 0xA2, 0xC1, 0x3B, 0x22, 0x41, 0xAE, 0xFA,
 0x76, 0x66, 0x3F, 0x88, 0xEA, 0x8B, 0x34, 0x75, 0x48, 0x6E,
 0xF1, 0x0D, 0x68, 0xB8, 0xB8, 0x3F, 0x1C, 0x62, 0xAE, 0x78,
 0x03, 0x0E, 0xC9, 0x88, 0xEE, 0x6B, 0x76, 0x90, 0xF9, 0xDD,
 0x8D, 0x75, 0xEF, 0x6A, 0xB1, 0xA8, 0x56, 0xD0, 0xA6, 0xEE,
 0x9B, 0x17, 0x0A, 0x05, 0xAE, 0xD7, 0xFD, 0x5B, 0x4A, 0xDA,
 0x4E, 0xEF, 0xFD, 0x2C, 0xF8, 0x64, 0xFE, 0x96, 0x5F, 0x02,
 0x70, 0x01, 0x60, 0x3A, 0xE1, 0xD5, 0xB5, 0xA5, 0xC5, 0xB2,
 0x34, 0xD5, 0x81, 0xBA, 0x4B, 0x76, 0x8A, 0x30, 0x93, 0x2D,
 0xB1, 0x64, 0x3A, 0x04, 0x86, 0x58, 0x89, 0x8E, 0x06, 0x7A,
 0x40, 0xAD, 0x30, 0xD2, 0xAE, 0xF5, 0x6E, 0x04, 0x54, 0x0B,
 0x2E, 0xA8, 0x50, 0xD9, 0xF2, 0xD9, 0x5C, 0x89, 0x59, 0xC1,
 0xF3, 0xAD, 0xC2, 0x87, 0x57, 0xE4, 0xBB, 0xD3, 0x00, 0x83,
 0x8B, 0x58, 0xDE, 0xA7, 0xBB, 0x34, 0xBA, 0xF4, 0x3E, 0x5F,
 0x6A, 0x4A, 0x2E, 0x21, 0x53, 0x0E, 0x93, 0x45, 0xC4, 0x49,
 0x27, 0x0F, 0x64, 0xC7, 0x8E, 0x91, 0x0D, 0x55, 0x8F, 0x0C,
 0xF0, 0x84, 0x65, 0x86, 0xAA, 0x95, 0x16, 0x80, 0xA6, 0x85,
 0xFE, 0x72, 0xF7, 0xD6, 0xC4, 0xD9, 0x4B, 0xD6, 0x71, 0xE8,
 0x31, 0xCE, 0xF2, 0x77, 0xD1, 0xB8, 0x6B, 0x59, 0x71, 0xA0,
 0xC8, 0x84, 0x9D, 0x3D, 0xBD, 0xC7, 0xAD, 0xAD, 0x9E, 0xDB,
 0x58, 0x26, 0x71, 0x8E, 0xA2, 0xD0, 0x9E, 0xC8, 0x6A, 0x48,
 0x41, 0xED, 0x1B, 0x0B, 0xF0, 0x9F, 0x1B, 0x7C, 0xEF, 0xE8,
 0xDA, 0xF0, 0x78, 0xB9, 0xDC, 0xBA
 }
    </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
    <var_seq name="gppo_root_path" type=0x00000001>
      "/persist/data/"
    </var_seq>
  </global_def>
  <device id="commonlib">
    <props name="cmnlib_gppo_rpmb_enablement" type=0x00000002>
      1
    </props>
    <props name="cmnlib_gppo_root_path" type=0x00000011>
      gppo_root_path
    </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
    <var_seq name="fpta_name_str" type=0x00000001>
      fingerprint
    </var_seq>
    <var_seq name="fp_sensor_name_str" type=0x00000001>
      Stargate
    </var_seq>
    <var_seq name="irista_name_str" type=0x00000001>
      iris
    </var_seq>
  </global_def>
  <device id="keymaster">
    <props name="fpta_name" type=0x00000011>
      fpta_name_str
    </props>
<!--
    OEM specific requirement for GK Retry Timeout, default is 0.
-->
    <props name="gk_timeout_config" type=0x00000002>
      0
    </props>
    <props name="fp_sensor_name" type=0x00000011>
      fp_sensor_name_str
    </props>
    <props name="fp_sensor_version" type=0x00000002>
      1
    </props>
    <props name="enable_finger_id" type=0x00000002>
      0
    </props>
    <props name="enable_soter" type=0x00000002>
      0
    </props>
    <props name="irista_name" type=0x00000011>
      irista_name_str
    </props>
  </device>
    <device id="keymaster64">
    <props name="fpta_name" type=0x00000011>
      fpta_name_str
    </props>
<!--
    OEM specific requirement for GK Retry Timeout, default is 0.
-->
    <props name="gk_timeout_config" type=0x00000002>
      0
    </props>
    <props name="gk_enable_soter_test" type=0x00000002>
     0
    </props>
    <props name="fp_sensor_name" type=0x00000011>
      fp_sensor_name_str
    </props>
    <props name="fp_sensor_version" type=0x00000002>
      1
    </props>
    <props name="enable_finger_id" type=0x00000002>
      0
    </props>
    <props name="enable_soter" type=0x00000002>
      0
    </props>
    <props name="irista_name" type=0x00000011>
      irista_name_str
    </props>
    <props name="allow_reprovision" type=0x00000002>
      0
    </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
    <var_seq name="kernel_version_str" type=0x00000001>
        "Linux version 3.14.26-g43b1178-00038-g96ef344 (lnxbuild@abait242-sd-lnx) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Jun 5 15:15:57 PDT 2015"
    </var_seq>
  </global_def>
  <device id="dhsecapp">
    <props name="kernel_version" type=0x00000011>
        kernel_version_str
    </props>
    <props name="kernel_version_str_length" type=0x00000002>
        171
    </props>
    <props name="challenges" type="byte" array="true">
 {
  0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,
  0x00,0x54,0x08,0x00,0xC0,0xFF,0xFF,0xFF,
  0xF0,0xDE,0xBC,0x9A,0x78,0x56,0x34,0x12,
  0x5F,0xCF,0x13,0x25,0x41,0x64,0x6B,0xB8,
  0x1B,0xAA,0x16,0x58,0x0A,0xA0,0x30,0xC6,
  0xFD,0xC4,0x27,0xC4,0xA6,0x7C,0x14,0x63,
  0xA5,0x8E,0x51,0xCB,0x60,0xD2,0x0F,0x87,
  0xB2,0xD5,0x1A,0x6D,0x53,0xFA,0x37,0x26,0x80,0xDE,
  0x7C,0xE0,0x74,0xA0,0x0C,0x6E,0xD7,0xA2,0xE1,0x49
 }
    </props>
    <props name="challenges_array_length" type=0x00000002>
        76
    </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
    <var_seq name="fido_app_name" type=0x00000001>
      "fidocrypto"
    </var_seq>
    <var_seq name="client_empty_name" type=0x00000001>
      ""
    </var_seq>
  </global_def>
  <device id="chamomile">
    <props name="client_00" type=0x00000011>
      fido_app_name
    </props>
    <props name="client_01" type=0x00000011>
      client_empty_name
    </props>
    <props name="client_02" type=0x00000011>
      client_empty_name
    </props>
    <props name="client_03" type=0x00000011>
      client_empty_name
    </props>
    <props name="client_04" type=0x00000011>
      client_empty_name
    </props>
    <props name="client_05" type=0x00000011>
      client_empty_name
    </props>
    <props name="client_06" type=0x00000011>
      client_empty_name
    </props>
    <props name="client_07" type=0x00000011>
      client_empty_name
    </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
    <var_seq name="fpta_name_str" type=0x00000001>
      fingerprint
    </var_seq>
    <var_seq name="fp_sensor_name_str" type=0x00000001>
      Stargate
    </var_seq>
  </global_def>
  <device id="soter64">
    <props name="fpta_name" type=0x00000011>
      fpta_name_str
    </props>
    <props name="fp_sensor_name" type=0x00000011>
      fp_sensor_name_str
    </props>
    <props name="fp_sensor_version" type=0x00000002>
      1
    </props>
    <props name="enable_finger_id" type=0x00000002>
      0
    </props>
    <props name="enable_soter" type=0x00000002>
      0
    </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
  </global_def>
  <device id="/tz/oem">
    <props name="OEM_keystore_enable_rpmb" type=0x00000002>
      1
    </props>
    <props name="OEM_keystore_wrong_passwd_penalty" type=0x00000002>
      2000
    </props>
    <props name="OEM_keystore_retain_wrong_passwd_attempt" type=0x00000002>
      1
    </props>
    <props name="OEM_counter_enable_rpmb" type=0x00000002>
      1
    </props>
    <!-- Note !!! The OEM_allow_rpmb_key_provision property is used for the below condition only: !!!
      A customer wants to replace the storage part (eMMC/UFS), but since RPMB key provision fuse is blown,
      RPMB auto production key provision wont happen for the new part.
      The return TRUE value can override RPMB key provision fuse and let RPMB be provsioned with
      the new storage part.
      This functions MUST always return FALSE for production devices.
      Otherwise the security of the RPMB will be compromised -->
    <props name="OEM_allow_rpmb_key_provision" type=0x00000002>
      0
    </props>
    <props name="OEM_disable_rpmb_autoprovisioning" type=0x00000002>
      0
    </props>
    <props name="OEM_sec_wdog_bark_time" type="0x00000002">
      6000
    </props>
    <props name="OEM_sec_wdog_bite_time" type=0x00000002>
      22000
    </props>
    <props name="OEM_reset_reason_list" type=0x00000012>
      oem_rst_reason_list
    </props>
    <props name="OEM_l2_wa_enable" type="0x00000002">
    1
    </props>
    <!-- PIL load region information -->
    <props name="OEM_pil_secure_app_load_region_size" type=0x00000002>
      0x02200000
    </props>
    <props name="OEM_pil_subsys_load_region_start" type=0x00000002>
      0x8AC00000
    </props>
    <props name="OEM_pil_subsys_load_region_size" type=0x00000002>
      0xA400000
    </props>
    <props name="OEM_pil_enable_clear_pil_region" type=0x00000002>
      0
    </props>
    <!--
 <props name="oem_spare_region26_read_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region26_write_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region27_read_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region27_write_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region28_read_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region28_write_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region29_read_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region29_write_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region30_read_vmid" type=0x00000002>
      0x10000000
    </props>
 <props name="oem_spare_region30_write_vmid" type=0x00000002>
      0x10000000
    </props>
  -->
    <!-- Mark 3rd party signed secure applications sandboxed by default -->
    <props name="OEM_app_sandbox_default" type=0x00000002>
      1
    </props>
        <!-- Mark 3rd party signed secure applications sandboxed by default -->
    <props name="OEM_enablecrashdumps_before_arb" type=0x00000002>
      0
    </props>
    <!-- Enable TZ counter measure for hlos boot tampering -->
    <props name="OEM_counter_measure_enable" type=0x00000002>
      1
   </props>
  </device>
  <device id="eseservice">
    <!-- Embedded Secure Element information information -->
    <props name="OEM_ese_spi_device_id" type=0x00000002>
      0x00 <!--The SPI device ID which maps on to the BLSP QUP core use -->
    </props>
    <props name="OEM_ese_spi_chip_select_id" type=0x00000002>
      0x00 <!--The Chip Select index (0 to 3) on with Secure Element is connected -->
    </props>
    <props name="OEM_ese_spi_max_frequency" type=0x00000002>
      9600000 <!-- SPI clock frequency as detailed in the Secure Element T=1 specification -->
    </props>
    <props name="OEM_ese_spi_bits_per_word" type=0x00000002>
      8 <!--The bits per word transmitted from/to the Interface device over SPI -->
    </props>
    <props name="OEM_ese_spi_nad_command" type=0x00000002>
      0x5A <!-- NAD for commands to Secure Element. Should be changed to 0x00 for NQ220 -->
    </props>
    <props name="OEM_ese_spi_nad_response" type=0x00000002>
      0xA5 <!-- NAD for responses from the secure element -->
    </props>
    <props name="OEM_ese_feature_mask" type=0x00000002>
      <!-- 0x00000001 - Enable QSEE Secure Element Access Control -->
      <!-- 0x00000002 - Enable QSEE Secure Element Access Control APDU Filtering -->
      <!-- 0x00000004 - Allow SELECT Command for GP TEE SE API TEE_SEChannelTransmit -->
      <!-- 0x00000008 - Support for SPI Soft Reset of ESE -->
      <!-- 0x00000010 - Support sending SPI end of APDU session command -->
      <!-- 0x00000020 - Block access to Secure Element basic channel -->
      <!-- 0x00000040 - Block access to Secure Element default applet -->
      <!-- 0x00000080 - Use multi-byte NAD when polling for response -->
      <!-- 0xFFFFFFFF - All features mask -->
      0x00000000
    </props>
    <props name="OEM_ese_timers" type=0x00000002>
      <!-- 0x000007FF - Mask for Secure Element BWT - 1624ms maximum -->
      <!-- 0x003FF000 - Mask for Secure Element Response polling time - default 50ms -->
      0x00032658
    </props>
 <props name="OEM_kdf_app_key_workaround" type=0x00000002>
 <!-- 0 - suppport for lowercase letters for app id -->
 <!-- 1 - suppport app id backward compatability -->
      0
     </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
    <var_seq name="drm_data_store_path" type=0x00000001>
      "/data/misc/qsee/"
    </var_seq>
  </global_def>
  <device id="widevine">
<!--
    Not applicable to Widevine
-->
    <props name="license_data_store_path" type=0x00000011>
      drm_data_store_path
    </props>
<!--
    Not applicable to Widevine
-->
    <props name="disable_security_stream_check" type=0x00000002>
      0
    </props>
<!--
    Not applicable to Widevine
-->
    <props name="get_IV_constraint" type=0x00000002>
      0
    </props>
<!--
    Not applicable to Widevine
-->
    <props name="use_legacy_hdmi_hdcp_check" type=0x00000002>
      1
    </props>
<!--
    HDCP1.4 OEM config
    Warning!
    To OEM, please do NOT change this value. if you change, premium DRM content can be exposed.
-->
    <props name="use_oem_external_hdcp" type=0x00000002>
      0
    </props>
<!--
    customers need to config "provision_constraint_flag" to have single time provisioning
    feature with drm_prov_finalize().
    if "provision_constraint_flag" = 1, key provisioning can be done only once after calling drm_prov_finalize().
    if "provision_constraint_flag" = 0, there is no such constraint
-->
    <props name="provision_constraint_flag" type=0x00000002>
      0
    </props>
<!--
   The maximum HDCP 2.x version that OEM can support
   we define
   1 is NOT supported.
   2 is HDCP2.0;
   3 is HDCP2.1;
   4 is HDCP2.2;
-->
    <props name="maximum_hdcp_2x_capability" type=0x00000002>
      4
    </props>
<!--
   This feature for Widevine debug only
   if g_widevine_kcb_logging_flag is set (=1), every OEMCrypto_SelectKey will log
   key control block info: including magic, duration, nonce, control bits (4 bytes).
   Note, this feature should be only turned on for a debugging purpose. Turning on
   this feature adds more loggings and downgrades performance.
   0: Disable
   1: Enable
-->
    <props name="enable_kcb_logging_flag" type=0x00000002>
      0
    </props>
<!--
   0: DSI-0 is being used for External display
   1: DSI-1 is being used for External display
   NOTE: This will not configure DSI-0/DSI-1 for external display but it is only for informing widevine
   about which DSI interface is configured for external display.
-->
    <props name="external_display_dsi_intf_num" type=0x00000002>
      1
    </props>
<!--
  0: Allow secure content through DSI-0 and DSI-1
  1: Block secure content on DSI interface configured for external display but allow through local display
  2: Block both DSI-0 and DSI-1
  The table below shows the behavior for various combinations of external_display_dsi_intf_num and block_content_thru_dsi:
  +-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-++
  | Constant values | | Secure content |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-++
  | block_content_thru_dsi | external_display_dsi_intf_num | DSI0 | DSI1 |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-++
  | 0 | * | Allowed | Allowed |
  | 1 | 0 | Blocked | Allowed |
  | 1 | 1 | Allowed | Blocked |
  | 2 | * | Blocked | Blocked |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-+-++
-->
    <props name="block_content_thru_dsi" type=0x00000002>
      0
    </props>
  </device>
</driver>

<driver name="NULL">
    <!--
 "global_def" section contains strings used by the "device" section below.
 Each string should be referenced using the unique "name" property from the "device" section.
  -->
  <global_def>
    <var_seq name="system_path_00" type=0x00000001>
      "/system/build.prop"
    </var_seq>
    <var_seq name="system_path_01" type=0x00000001>
      "/system/default.prop"
    </var_seq>
    <var_seq name="system_path_02" type=0x00000001>
      "/system/app"
    </var_seq>
    <var_seq name="system_path_03" type=0x00000001>
      "/system/bin"
    </var_seq>
    <var_seq name="system_path_04" type=0x00000001>
      "/system/etc"
    </var_seq>
    <var_seq name="system_path_05" type=0x00000001>
      "/system/framework"
    </var_seq>
    <var_seq name="system_path_06" type=0x00000001>
      "/system/lib"
    </var_seq>
    <var_seq name="system_path_07" type=0x00000001>
      "/system/priv-app"
    </var_seq>
    <var_seq name="system_path_08" type=0x00000001>
      "/system/vendor"
    </var_seq>
    <var_seq name="system_path_09" type=0x00000001>
      "/system/xbin"
    </var_seq>
  </global_def>
  <!-- "device" section contains configuration properties read by MDTP -->
  <device id="mdtp">
    <!-- "mdtp_system_min_verify_ratio" property specifies minimal verify ratio for the system partition.
    The property value unit are percent and the valid numeric range is 1 to 100.
    For example: value of 10 will result in 10% minimal verification ratio.
    -->
    <props name="mdtp_system_min_verify_ratio" type=0x00000002>
      10
    </props>
    <!-- "mdtp_system_path_##" properties specifies file/directory path to protect by MDTP
    - Each property "name" attribute should end with two decimal digits.
      Allowed range is 00-99 (mdtp_system_path_00 ... mdtp_system_path_99)
    - The properties definition should come in a strict incremental order
      E.g: mdtp_system_path_00, mdtp_system_path_01, mdtp_system_path_02 ,...
    - The property value is a name reference to a string defined in a "global_def" section above
    - At least one system path property should be present in this concfiguration file. Otherwise the
      whole configuraiton will be discarded.
    - Properties are processed in order. If an invalid property is encounterd or property
      is missing the rest of configration will discarded.
    -->
    <props name="mdtp_system_path_00" type=0x00000011>
      system_path_00
    </props>
    <props name="mdtp_system_path_01" type=0x00000011>
      system_path_01
    </props>
    <props name="mdtp_system_path_02" type=0x00000011>
      system_path_02
    </props>
    <props name="mdtp_system_path_03" type=0x00000011>
      system_path_03
    </props>
    <props name="mdtp_system_path_04" type=0x00000011>
      system_path_04
    </props>
    <props name="mdtp_system_path_05" type=0x00000011>
      system_path_05
    </props>
    <props name="mdtp_system_path_06" type=0x00000011>
      system_path_06
    </props>
    <props name="mdtp_system_path_07" type=0x00000011>
      system_path_07
    </props>
    <props name="mdtp_system_path_08" type=0x00000011>
      system_path_08
    </props>
    <props name="mdtp_system_path_09" type=0x00000011>
      system_path_09
    </props>
  </device>
</driver>

<driver name="NULL">
  <global_def>
    <var_seq name="drm_data_store_path" type=0x00000001>
      "/data/misc/qsee/"
    </var_seq>
  </global_def>
  <device id="playread">
    <props name="license_data_store_path" type=0x00000011>
      drm_data_store_path
    </props>
<!--
    customers need to config "proprietary_play_enabler_video_protect"
    if "proprietary_play_enabler_video_protect" = 1, g_bUse_proprietary_play_enabler_default_subsample = 1
                audio stream must match customer specific requirements and default behaviour is "CHECK_SUBSAMPLE"
                This is the case where server side development is completely up and running.
    if "proprietary_play_enabler_video_protect" = 1, g_bUse_proprietary_play_enabler_default_subsample = 0
                audio stream must match customer specific requirements and default behaviour "CHECK_NONE"
                This is the case where server side development is in intermediate stage where there can be a GUID in license
    if "proprietary_play_enabler_video_protect" = 0, g_bUse_proprietary_play_enabler_default_subsample = 1
                server side development is not ready (no GUIDs in license) and default behaviour "CHECK_SUBSAMPLE"
    if "proprietary_play_enabler_video_protect" = 0, g_bUse_proprietary_play_enabler_default_subsample = 0
                server side development is not ready (no GUIDs in license) and default behaviour "CHECK_NONE"
   NOTE: "IV_constraint" and below flags SHOULD NOT be used together.
-->
    <props name="proprietary_play_enabler_video_protect" type=0x00000002>
      0
    </props>
    <props name="proprietary_play_enabler_default_behaviour" type=0x00000002>
      0
    </props>
<!--
    customers need to configure "get_IV_constraint"
    if "IV_constraint" = 1, audio IV must begin with 0b01
                                 video IV must begin with 0b00
    if "IV_constraint" = 0, there is no such a constraint
-->
    <props name="IV_constraint" type=0x00000002>
      0
    </props>
<!--
    This is the robustness version value used by porting kit while generating
    device certificates. This value should be incremented by OEMs as part of
    reprovisioning the device whenever there is a revocation. If there is a
    mismatch between this value and the robustness version used in model
    certificates, then initialize will fail. Hence, this value should always be
    same as that of the value used in model certificates.
-->
    <props name="robustness_version" type=0x00000002>
      0
    </props>
<!--
   OEMs need to set this flag to zero to avoid check for existence of
   play enabler object in license.
   set "proprietary_play_enabler_profile" = 1, to check for existence of
   play enabler object in license.
   Note: Blocking or unblocking HDCP display is based on how this flag is
         used with "proprietary_opl_profile_0". Valid combinations
         are explained in the comment section for "proprietary_opl_profile_0".
   set "proprietary_play_enabler_profile" = 0, to ignore check for
   existence of play enabler object in license.
-->
    <props name="proprietary_play_enabler_profile" type=0x00000002>
      0
    </props>
<!--
   OEMs need to define this flag to enable check for OPL >= 270.
   Please note that if this flag has to be enabled then "proprietary_play_enabler_profile"
   should also be enabled. Below are the valid/invalid combinations.
   (1) "proprietary_play_enabler_profile" = 0, "proprietary_opl_profile_0" = 0 (valid)
       HDCP display is controlled with regular OPL>=301 check
   (2) "proprietary_play_enabler_profile" = 1, "proprietary_opl_profile_0" = 0 (valid)
       HDCP display is blocked if play enabler object is not found in license.
   (3) "proprietary_play_enabler_profile" = 0, "proprietary_opl_profile_0" = 1 (Invalid)
       Invalid combination. Result is same as case (1)
   (4) "proprietary_play_enabler_profile" = 1, "proprietary_opl_profile_0" = 1 (valid)
       HDCP display is blocked if OPL>=270.
   set "proprietary_opl_profile_0" = 1, to check for OPL >= 270 in license.
   Note: If this flag is enabled (set to one) then OPL >=270 check will act as fallback
         check in case play enabler object for HDCP display is not found in license.
         i.e., HDCP WFD gets blocked if play enabler object is not found and OPL >= 270.
   set "proprietary_opl_profile_0" = 0, to ignore OPL 270 check
   Note: If this flag is disabled (set to zero) then HDCP display gets blocked if play
         enabler object for HDCP display is not found in license.
-->
    <props name="proprietary_opl_profile_0" type=0x00000002>
      0
    </props>
    <props name="disable_security_stream_check" type=0x00000002>
      0
    </props>
<!--
    customers need to config "provision_constraint_flag" to have single time provisioning
    feature with drm_prov_finalize().
    if "provision_constraint_flag" = 1, key provisioning can be done only once after calling drm_prov_finalize().
    if "provision_constraint_flag" = 0, there is no such constraint
-->
    <props name="provision_constraint_flag" type=0x00000002>
      0
    </props>
    <props name="use_legacy_hdmi_hdcp_check" type=0x00000002>
      1
    </props>
  </device>
</driver>

<driver name="NULL">
  <device id="hdcp1">
    <!--
    hdcp1 storage_type defines where to store the key: it is defined
    as:
        SFS 1
        RPMB 2
    -->
    <props name="hdcp1_storage_type" type=0x00000002>
     2
    </props>
    <props name="chamomile_ips" type="byte" array="true">
    {
 0xAE, 0x11, 0x53, 0xAE, 0x51, 0xEF, 0x4A, 0x72, 0x7A, 0xE1,
 0x8D, 0x2A, 0xE2, 0x04, 0xE6, 0x61, 0xAC, 0xE5, 0xD4, 0x0A,
 0x8E, 0xC3, 0xCC, 0x85, 0x2B, 0xDF, 0x01, 0xBA, 0xB8, 0xFE,
 0x5B, 0x1B, 0x2E, 0xE6, 0xF2, 0x42, 0x48, 0x07, 0xB5, 0x21,
 0x56, 0xF8, 0x5A, 0xE9, 0xDA, 0xE6, 0x56, 0xEC, 0xAB, 0x76,
 0xA7, 0x1A, 0xD8, 0xD7, 0x22, 0x18, 0xC9, 0x67, 0x0E, 0x75,
 0xB6, 0xE8, 0x75, 0x3B, 0xD0, 0x94, 0x35, 0x85, 0x19, 0x4F,
 0xA1, 0xFE, 0xD7, 0xCF, 0xEE, 0x5F, 0xA2, 0x8D, 0xD0, 0xD3,
 0x86, 0x0B, 0x65, 0x95, 0xB3, 0x91, 0xF9, 0x08, 0x90, 0xD5,
 0x91, 0x49, 0x76, 0xDD, 0x6F, 0xC9, 0x75, 0x0C, 0x45, 0x13,
 0xFB, 0x6D, 0x68, 0x9A, 0xB1, 0xF1, 0x1B, 0x94, 0xE3, 0xFE,
 0x38, 0xCE, 0x74, 0x42, 0x7E, 0x77, 0x49, 0xF2, 0x3C, 0x38,
 0x33, 0x96, 0xA9, 0x8D, 0x36, 0x5E, 0x03, 0x2B, 0x70, 0x0F,
 0x23, 0x93, 0x85, 0xB9, 0x74, 0xC8, 0xC1, 0x78, 0xE2, 0xA7,
 0x50, 0xA5, 0x17, 0x48, 0x5A, 0x54, 0xDF, 0x4A, 0xB9, 0x2A,
 0x3C, 0x18, 0xDC, 0xD7, 0x72, 0xA3, 0x98, 0x2B, 0xF7, 0x87,
 0x0B, 0x2D, 0xA0, 0x50, 0x72, 0x71, 0x65, 0xA4, 0x6D, 0x71,
 0x23, 0x98, 0x2C, 0x64, 0xB6, 0x0B, 0xF8, 0x39, 0x80, 0x76,
 0xC1, 0xD6, 0xD2, 0x4A, 0x9B, 0x24, 0x24, 0xD2, 0x43, 0x68,
 0x66, 0xDB, 0xB0, 0x93, 0x45, 0x07, 0xA6, 0x4F, 0x52, 0x2C,
 0x53, 0xD3, 0xDB, 0xE8, 0xA1, 0x95, 0x05, 0x13, 0x34, 0xC8,
 0x37, 0xEA, 0xF4, 0x06, 0x8D, 0x2F, 0xD8, 0x94, 0x71, 0xCA,
 0x27, 0xC7, 0xA1, 0xB5, 0x28, 0xD2, 0x13, 0xE6, 0x06, 0xFE,
 0xD9, 0x32, 0x99, 0x27, 0x22, 0xE0, 0x65, 0xC8, 0x4A, 0x35,
 0x8C, 0xBA, 0x70, 0xD4, 0xAE, 0x62, 0xFE, 0x48, 0xC2, 0x59,
 0x4D, 0xFC, 0x5D, 0x93, 0x3C, 0xA3, 0x4B, 0x1C, 0x33, 0xE3,
 0xCA, 0xCD, 0xA9, 0x8C, 0xE5, 0x56, 0x66, 0xDA, 0x03, 0x23,
 0xD4, 0x2F, 0xBF, 0xCA, 0x71, 0x44, 0x5E, 0x5A, 0xEA, 0x06,
 0xF0, 0x86, 0x77, 0xAD, 0x1A, 0x96, 0xCF, 0xE7, 0x3D, 0xD8,
 0xB5, 0x6B, 0xDC, 0x3C, 0xFC, 0x5C, 0x65, 0x50, 0xE2, 0x15,
 0xDA, 0x83, 0xF7, 0xDE, 0xDC, 0x0F, 0x91, 0x55, 0xEA, 0x5A,
 0x26, 0x03, 0x65, 0xCC, 0x46, 0xE5, 0x63, 0x73, 0x7F, 0xA9,
 0x8D, 0x1B, 0xD8, 0x91, 0x9A, 0x9F, 0x94, 0x1B, 0xA7, 0x14,
 0x44, 0xBB, 0x2B, 0x75, 0xA2, 0xAC, 0xC7, 0xD7, 0x42, 0x9F,
 0x1D, 0x4B, 0x89, 0x90, 0x27, 0x12, 0x1A, 0xB3, 0xD4, 0x34,
 0xDB, 0x69, 0x4C, 0x87, 0xE1, 0xBB, 0xED, 0x90, 0xD7, 0x33,
 0x99, 0xB0, 0x07, 0xC2, 0xB3, 0xF9, 0x43, 0xCD, 0x3D, 0x78,
 0x1D, 0x8B, 0xC4, 0x9A, 0x8B, 0x74, 0xAD, 0x73, 0xC6, 0x74,
 0xA0, 0xF7, 0x67, 0x99, 0x58, 0x14, 0xDF, 0x06, 0x57, 0xF2,
 0x3C, 0x8F, 0x33, 0x9D, 0xA3, 0xF0, 0x51, 0x66, 0xC5, 0xD7,
 0x16, 0x95, 0x0A, 0xE7, 0x0F, 0x1E, 0xDD, 0x41, 0x88, 0xC3,
 0x91, 0x73, 0x6C, 0x87, 0xF3, 0x2F, 0xAF, 0x08, 0x2E, 0x8F,
 0x06, 0x05, 0x78, 0xA6, 0x77, 0xE9, 0x29, 0x1F, 0x13, 0x08,
 0x4A, 0xB2, 0xD3, 0x9D, 0xCB, 0x25, 0x7A, 0xDD, 0x1E, 0x1B,
 0x99, 0xDE, 0x8A, 0x95, 0x13, 0x88, 0xDD, 0x18, 0x35, 0x08,
 0x69, 0x13, 0xF8, 0x7F, 0xBA, 0x80, 0xE2, 0xEA, 0x81, 0x3E,
 0x8F, 0x9E, 0xAA, 0x0E, 0x21, 0x3A, 0x57, 0x02, 0x09, 0x3E,
 0x12, 0x50, 0x8D, 0xF8, 0x8A, 0xB9, 0x4B, 0x12, 0xE5, 0xA0,
 0x85, 0xDB, 0xAD, 0xAF, 0x63, 0xCF, 0x7B, 0x80, 0x51, 0x5D,
 0x87, 0x93, 0x47, 0xA4, 0x7F, 0xD2, 0x70, 0xA7, 0x15, 0xAD,
 0xDA, 0x90, 0x6A, 0x25, 0xDA, 0x8F, 0x80, 0x18, 0xC4, 0x51,
 0x85, 0xF3, 0xA7, 0x5F, 0xE6, 0x49, 0xF9, 0x02, 0xAC, 0x7E,
 0xDA, 0xBB, 0x84, 0x10, 0x89, 0x6F, 0xB3, 0xF5, 0xF3, 0x85,
 0x60, 0xC9, 0x43, 0xE7, 0x58, 0x66, 0x1E, 0x92, 0x60, 0xCE,
 0x77, 0xC2, 0xA9, 0xC3, 0x28, 0xE1, 0xDE, 0x93, 0x4A, 0x3C,
 0x79, 0xA9, 0x4E, 0xD5, 0x19, 0x41, 0xDC, 0x8E, 0x80, 0xC3,
 0x5F, 0xFF, 0x84, 0x75, 0xF9, 0xEB, 0x71, 0x36, 0xBB, 0x26,
 0xF2, 0x51, 0x1C, 0x2B, 0x43, 0x7B, 0xFB, 0x55, 0x53, 0x12,
 0x20, 0xD9, 0x7B, 0xA0, 0xB6, 0x77, 0x1F, 0xD3, 0x76, 0x7A,
 0x0F, 0x58, 0x88, 0xE6, 0xF4, 0x46, 0x70, 0x97, 0x93, 0x61,
 0x0A, 0x22, 0xB6, 0xDC, 0x3E, 0x18, 0x83, 0x84, 0x62, 0x2A,
 0xDD, 0xAE, 0xB2, 0x31, 0x5D, 0x0D, 0x86, 0xAB, 0xCA, 0x59,
 0x9F, 0x63, 0xF0, 0xEF, 0x0C, 0x7B, 0x95, 0x69, 0xF2, 0x45,
 0xA0, 0x7E, 0xE7, 0x23, 0x44, 0xA1, 0xEF, 0x24, 0xD5, 0x5A,
 0x1E, 0xE4, 0xC6, 0xCE, 0x27, 0xC7, 0x35, 0xF2, 0xF8, 0x75,
 0xF6, 0xDC, 0x42, 0x13, 0x95, 0x65, 0x96, 0x4F, 0xAB, 0xBB,
 0xD6, 0x59, 0xA8, 0x51, 0xCC, 0xCA, 0x54, 0xFF, 0x60, 0x02,
 0xAA, 0x61, 0xBB, 0x04, 0x9B, 0x84, 0x37, 0xD7, 0xD8, 0xFC,
 0xD9, 0xBE, 0x0F, 0x6E, 0x4E, 0xB9, 0x69, 0x07, 0x61, 0xD3,
 0xD0, 0xD3, 0xA5, 0x9B, 0x3E, 0xFD, 0x54, 0x9F, 0xA4, 0x43,
 0xFC, 0xD4, 0x72, 0x02, 0xE1, 0xEA, 0x9F, 0x6C, 0x36, 0x72,
 0x18, 0x8F, 0xE1, 0xE6, 0x45, 0x06, 0x10, 0x9A, 0x8B, 0x65,
 0xC4, 0x9C, 0x81, 0xB7, 0x67, 0x0A, 0xC2, 0xB0, 0x7F, 0xF8,
 0xFB, 0xBE, 0x79, 0x7F, 0x1D, 0xCB, 0x6B, 0x3E, 0xA3, 0x56,
 0x3B, 0xCE, 0xDA, 0x83, 0xF2, 0xDF, 0xBE, 0x33, 0x0C, 0x1C,
 0x8D, 0x4E, 0xFA, 0xA6, 0x83, 0x9C, 0xEC, 0x11, 0xF6, 0x6D,
 0x88, 0xD9, 0x70, 0x22, 0x39, 0xA2, 0xBE, 0x62, 0x7A, 0xFC,
 0x2C, 0x76, 0x1B, 0xFD, 0x74, 0xE3, 0x4C, 0x0A, 0x07, 0x8A,
 0x9E, 0x1C, 0x81, 0x13, 0x2E, 0x5B, 0xD3, 0xB4, 0x91, 0x8B,
 0xB5, 0x9F, 0x28, 0x09, 0x1C, 0x8A, 0x7A, 0x83, 0xAD, 0xE3,
 0x2A, 0x46, 0x07, 0x1E, 0x78, 0xA6, 0x1E, 0xEF, 0xA6, 0x24,
 0x43, 0xD3, 0xF9, 0x81, 0xF1, 0x4F, 0xCB, 0x9B, 0xA2, 0x43,
 0xA2, 0x2B, 0xF9, 0xA0, 0x5B, 0x37, 0xE8, 0xF7, 0x37, 0x39,
 0x69, 0xB4, 0xF3, 0x41, 0x99, 0x1A, 0xED, 0xDA, 0xFB, 0x5F,
 0xF2, 0x3D, 0xBC, 0xCD, 0x66, 0xFE, 0xB3, 0x30, 0x29, 0xE0,
 0x51, 0xF3, 0xE3, 0xA0, 0x30, 0x7F, 0xC7, 0x23, 0x13, 0xBA,
 0xA5, 0x9E, 0xA5, 0xE3, 0x47, 0x75, 0x22, 0xF2, 0xF5, 0x94,
 0xCF, 0xC3, 0x37, 0x1C, 0x1F, 0xB2, 0x9E, 0xA8, 0xED, 0x8D,
 0xFE, 0xC8, 0xDE, 0xCA, 0x1B, 0x15, 0xB7, 0x1A, 0x24, 0x30,
 0x46, 0x69, 0x9A, 0x5A, 0xDF, 0xE2, 0x66, 0x37, 0xA4, 0xBF,
 0x0A, 0x43, 0x49, 0xA9, 0x6F, 0x12, 0x9B, 0x6C, 0xEE, 0x43,
 0xD7, 0xE5, 0xC3, 0x5B, 0x64, 0xA0, 0x81, 0x6C, 0xE6, 0x96,
 0x9E, 0x3E, 0x89, 0x6B, 0x3B, 0xFD, 0x34, 0xA5, 0xF2, 0xD2,
 0x2F, 0x50, 0xB3, 0xF0, 0x47, 0x6C, 0x9E, 0x29, 0x49, 0xD0,
 0xA0, 0x45, 0x4C, 0xE1, 0x2B, 0xF4, 0x89, 0x51, 0x99, 0x12,
 0x61, 0x93, 0xE0, 0xEE, 0xCD, 0xC3, 0xE4, 0x9B, 0xAF, 0x87,
 0x9A, 0x38, 0xCF, 0x2B, 0xB8, 0x46, 0xCD, 0xC3, 0x06, 0xC1,
 0xDC, 0x67, 0x8D, 0x36, 0x3C, 0x49, 0x64, 0xC5, 0xBA, 0xF9,
 0x1B, 0xDE, 0x70, 0x3D, 0xE5, 0x02, 0xE3, 0x33, 0x68, 0x93,
 0x54, 0xE2, 0x6F, 0x15, 0x1B, 0x5C, 0x25, 0xF3, 0x8D, 0x0B,
 0x6A, 0x6E, 0x3C, 0xBC, 0x59, 0x07, 0x97, 0xFE, 0x2A, 0x68,
 0x00, 0x51, 0x2D, 0x0F, 0x7E, 0xE3, 0xFA, 0xAC, 0xC3, 0x7D,
 0x88, 0x0F, 0xBA, 0xE4, 0x23, 0xB2, 0x63, 0xB0, 0x0F, 0xD7,
 0x84, 0x09, 0x4A, 0xB1, 0x7B, 0x80, 0xF2, 0x8C, 0x03, 0x2F,
 0x79, 0x9D, 0x26, 0x22, 0x67, 0xFA, 0x11, 0x39, 0xD2, 0x11,
 0x8B, 0xA9, 0x01, 0x37, 0x93, 0xCF, 0x93, 0x62, 0xD6, 0x8B,
 0x40, 0x05, 0xB3, 0x9F, 0x87, 0xEE, 0x35, 0x21, 0x8D, 0x58,
 0x4D, 0x5A, 0xEF, 0x2B, 0x46, 0xA0, 0xB8, 0xB1, 0xF0, 0xD8,
 0x53, 0xD6, 0x93, 0x44, 0x28, 0xE4, 0xC2, 0x53, 0x9F, 0xC1,
 0x49, 0xD5, 0x3B, 0x37, 0xE5, 0x09, 0x22, 0x51, 0x6C, 0x18,
 0x59, 0xA9, 0x0D, 0xDF, 0xEF, 0x45, 0xBE, 0xEC, 0x4F, 0xA7,
 0x60, 0x98, 0xBD, 0x29, 0x4B, 0x0D, 0xDD, 0xAE, 0x2A, 0x94,
 0xCF, 0xF6, 0x14, 0x60, 0xF2, 0x08, 0x76, 0x9B, 0x6A, 0x3D,
 0xD1, 0x99, 0x89, 0xE0, 0x50, 0xE3, 0xC1, 0x2F, 0x5B, 0x50,
 0x39, 0x2D, 0xD4, 0xA9, 0xF2, 0xF8, 0x38, 0x5D, 0x66, 0x25,
 0x57, 0xF9, 0xC9, 0x73, 0x13, 0x10, 0x2D, 0x85, 0x08, 0x20,
 0xAB, 0x8E, 0x29, 0xE2, 0xF1, 0x6A, 0x28, 0xED, 0xF4, 0xE2,
 0x19, 0x99, 0xB2, 0x47, 0x9F, 0x30, 0x7D, 0xAD, 0xEF, 0xCE,
 0x6A, 0x61, 0x0A, 0xDE, 0x77, 0x52, 0x8E, 0xEA, 0xC1, 0xC4,
 0x08, 0xDA, 0x4B, 0xFA, 0xC7, 0x1E, 0xAC, 0x53, 0xA7, 0x06,
 0x84, 0xCC, 0x09, 0xFF, 0xF0, 0x81, 0xAA, 0x5C, 0xD6, 0xD8,
 0xC6, 0x0F, 0xDD, 0x1A, 0xA1, 0x02, 0xCB, 0x8D, 0xA4, 0x27,
 0x53, 0x48, 0x15, 0x27, 0x92, 0x19, 0xD8, 0xC2, 0x34, 0x40,
 0xAE, 0x3F, 0x61, 0xE5, 0x62, 0x97, 0xC1, 0x61, 0x3A, 0xB7,
 0xCA, 0xEE, 0x2A, 0xA6, 0xAA, 0xFC, 0x46, 0x82, 0x02, 0x8D,
 0x91, 0x3A, 0x4D, 0xE2, 0x04, 0x7B, 0xFC, 0xB9, 0x72, 0xD1,
 0x3B, 0xF1, 0x6F, 0x9D, 0x3E, 0x9B, 0xE7, 0x74, 0x70, 0x7E,
 0xFB, 0xD7, 0xDB, 0xC0, 0x69, 0xDE, 0x70, 0xE8, 0x7E, 0x98,
 0x3B, 0xE2, 0x42, 0xA6, 0xE8, 0xD4, 0xFE, 0x4D, 0x88, 0xC8,
 0x04, 0x0D, 0x0F, 0xEE, 0xA8, 0x25, 0xD7, 0x55, 0xD8, 0x43,
 0x59, 0x88, 0x93, 0x0C, 0x1C, 0x38, 0x9C, 0x26, 0x44, 0x79,
 0x79, 0x66, 0x1A, 0xE5, 0x9A, 0xC0, 0x94, 0xA3, 0xE5, 0x2D,
 0xB3, 0xD1, 0x28, 0x0B, 0xDD, 0x48, 0xCE, 0xDE, 0x45, 0x38,
 0xAE, 0xB2, 0xEA, 0x5B, 0x3A, 0x9A, 0x80, 0xC0, 0xCB, 0xC2,
 0xEC, 0x4E, 0xB2, 0xE1, 0x51, 0x8D, 0x9E, 0x60, 0x0F, 0x07,
 0x30, 0x5D, 0x8E, 0x11, 0xB8, 0x99, 0x23, 0xA6, 0x74, 0x37,
 0x9F, 0xA8, 0x4E, 0x6E, 0x3F, 0x35, 0xD5, 0x7E, 0x00, 0x66,
 0x75, 0xBC, 0xAC, 0xB9, 0x88, 0x11, 0xBC, 0xB8, 0xF0, 0xE3,
 0x9E, 0x85, 0x97, 0x2B, 0xB0, 0xF1, 0xB2, 0x06, 0xD9, 0x89,
 0xE4, 0x25, 0x21, 0x1D, 0xD1, 0x9B, 0xB3, 0xE7, 0xEC, 0x4F,
 0x5B, 0x6A, 0x65, 0x51, 0x17, 0xE6, 0x59, 0xB2, 0x23, 0xDC,
 0x51, 0x4E, 0xBC, 0x08, 0x63, 0x3C, 0x4A, 0xD7, 0xE9, 0x4D,
 0x79, 0x8C, 0x7C, 0x15, 0xA3, 0x4E, 0x32, 0x10, 0x18, 0x87,
 0x85, 0x2D, 0xBE, 0x13, 0x8F, 0xD1, 0x4D, 0x13, 0x8B, 0x7F,
 0xA3, 0x95, 0x9E, 0x0F, 0x1D, 0x7A, 0x1E, 0x9B, 0xEA, 0xEA,
 0x55, 0x68, 0x0C, 0xEB, 0x31, 0x27, 0x3D, 0xCC, 0x15, 0x85,
 0xA9, 0xF4, 0x03, 0xBE, 0x7A, 0x41, 0x01, 0xE2, 0xF4, 0x8E,
 0x88, 0xF3, 0x58, 0x24, 0x3D, 0x3F, 0xF0, 0x55, 0x69, 0x65,
 0xBA, 0xE0, 0x18, 0x95, 0x24, 0xB3, 0xA7, 0xB7, 0x0E, 0x3E,
 0x8B, 0xCC, 0x19, 0x2A, 0x74, 0x38, 0xA3, 0x7E, 0x57, 0x73,
 0x09, 0x35, 0xFB, 0xD5, 0x46, 0x42, 0x86, 0xB9, 0x31, 0x98,
 0xED, 0x73, 0xBA, 0xAB, 0x69, 0x28, 0x3B, 0xF1, 0x05, 0x40,
 0x9C, 0x3C, 0xE9, 0x0E, 0xFB, 0xDA, 0x7A, 0x45, 0xF0, 0x7E,
 0x40, 0x8B, 0x5F, 0x59, 0x29, 0x6F, 0xE1, 0x27, 0x00, 0x86,
 0x17, 0xBC, 0x1C, 0xFB, 0x7F, 0xBF, 0x83, 0x5C, 0x75, 0x69,
 0xED, 0xEC, 0x6C, 0x63, 0x5E, 0x84, 0x0A, 0x9A, 0xC7, 0x30,
 0x9A, 0x6B, 0xFE, 0x99, 0x4A, 0xDA, 0x0D, 0x28, 0x85, 0x4C,
 0x26, 0xC4, 0xD6, 0x23, 0x73, 0xE2, 0xCF, 0x2D, 0xDE, 0x14,
 0x9C, 0xCE, 0x2E, 0xF2, 0x39, 0x4E, 0xB3, 0x2A, 0x37, 0x78,
 0xF5, 0x50, 0x85, 0xBE, 0xD5, 0x13, 0xC8, 0x06, 0x52, 0x3B,
 0xAA, 0x5F, 0x33, 0xAD, 0x83, 0x8A, 0xBA, 0x34, 0x35, 0x42,
 0x82, 0x79, 0x63, 0x90, 0x45, 0xD3, 0xDA, 0x6E, 0x55, 0xE8,
 0xAD, 0x37, 0xB5, 0x7C, 0x45, 0xC9, 0x57, 0x86, 0x1E, 0x05,
 0xE1, 0xD8, 0xB2, 0x4C, 0xAA, 0x42, 0x96, 0x79, 0x70, 0xCD,
 0x70, 0x01, 0x8D, 0xA7, 0x13, 0x9D, 0xE0, 0x2F, 0xE8, 0xA7,
 0xFC, 0x69, 0xA3, 0x7E, 0x30, 0x5A, 0x75, 0x27, 0x3C, 0xB3,
 0x60, 0x1A, 0xEC, 0x91, 0x52, 0x1C, 0xF6, 0x86, 0xC4, 0x3C,
 0x75, 0x1D, 0xE0, 0x6D, 0x05, 0xD9, 0xDE, 0x31, 0x35, 0x8A,
 0xB6, 0xAD, 0xF5, 0x39, 0x00, 0xD1, 0xD8, 0x31, 0x60, 0x08,
 0x82, 0x8A, 0xC5, 0x13, 0xEE, 0x82, 0xF4, 0x4E, 0xF1, 0xFF,
 0x2A, 0xF6, 0x94, 0x37, 0x1F, 0x97, 0x1E, 0xD7, 0x68, 0x8A,
 0x78, 0xDB, 0xE4, 0x20, 0x49, 0xAB, 0x6F, 0xDC, 0xA5, 0x70,
 0x90, 0x93, 0x48, 0x5D, 0x9F, 0x03, 0x7D, 0x63, 0xE4, 0x19,
 0xFF, 0xB3, 0x76, 0x60, 0x89, 0xBF, 0xBE, 0xDC, 0x4B, 0x35,
 0xEB, 0xCE, 0xAC, 0x5A, 0x3D, 0x84, 0xDA, 0x54, 0xE5, 0xB2,
 0x38, 0x11, 0xC3, 0xB3, 0x29, 0x6B, 0x96, 0x92, 0x9A, 0x14,
 0x84, 0x89, 0x11, 0x43, 0x71, 0x97, 0x28, 0x56, 0xF6, 0x4A,
 0x83, 0x96, 0xFC, 0x9E, 0x01, 0xC5, 0x52, 0x78, 0x3F, 0x0D,
 0xC9, 0x2B, 0xDF, 0xA2, 0xCF, 0xCB, 0x93, 0x6C, 0xFE, 0x5B,
 0x1C, 0x99, 0x0E, 0x84, 0x9D, 0x1A, 0x1C, 0x27, 0x4A, 0x8D,
 0x5E, 0x42, 0xD2, 0x2B, 0xFA, 0x90, 0xAA, 0x58, 0x03, 0xD5,
 0x3B, 0x93, 0x3F, 0xF6, 0x8A, 0xDD, 0x15, 0x17, 0x82, 0xEB,
 0x36, 0x2D, 0x96, 0xA9, 0xFD, 0x51, 0xBE, 0x37, 0xD9, 0x67,
 0x28, 0xD6, 0x9F, 0xBF, 0x43, 0x4E, 0x7C, 0x35, 0xAF, 0x95,
 0x6B, 0xD5, 0xCE, 0x0B, 0x38, 0x9D, 0x8F, 0x84, 0x2C, 0x64,
 0x9F, 0x79, 0x11, 0x7D, 0x47, 0xDD, 0x3B, 0x42, 0x16, 0xEB,
 0xBF, 0xFB, 0x4A, 0xAF, 0xE0, 0x06, 0x96, 0x99, 0x4D, 0x3A,
 0x26, 0x31, 0xE4, 0xA6, 0x88, 0x4F, 0xA2, 0x00, 0x51, 0x2E,
 0xC0, 0x67, 0xC3, 0xB8, 0xF3, 0x00, 0xA3, 0x1C, 0xAE, 0x65,
 0xA0, 0xB5, 0x32, 0x96, 0x31, 0x4E, 0xFD, 0xC7, 0x17, 0x68,
 0xFF, 0xB8, 0x27, 0x2C, 0x95, 0x03, 0x70, 0xEF, 0x9C, 0x84,
 0x8E, 0x78, 0xA7, 0xF2, 0xD1, 0x34, 0x8E, 0xC2, 0x7A, 0xB8,
 0x09, 0x06, 0x78, 0x4B, 0x30, 0xCF, 0x70, 0x4A, 0xC0, 0xA4,
 0x44, 0xA8, 0xA1, 0x39, 0x52, 0x3A, 0x72, 0x1D, 0x8F, 0xA3,
 0x9D, 0xBF, 0xD0, 0x7D, 0x9D, 0xFF, 0xD9, 0x28, 0x3A, 0x38,
 0xB7, 0xF9, 0xA6, 0x49, 0x06, 0xCB, 0x65, 0xB7, 0x2E, 0x01,
 0x0F, 0x61, 0x65, 0x8C, 0x10, 0xAA, 0xE1, 0x5A, 0x1C, 0x5B,
 0xB9, 0x28, 0x6A, 0xD1, 0x90, 0x2D, 0xC4, 0x69, 0x43, 0xF4,
 0x4D, 0x51, 0x3A, 0xDB, 0x05, 0x84, 0x52, 0x5D, 0x04, 0x19,
 0xB1, 0x54, 0x27, 0x64, 0x2A, 0xCE, 0x44, 0x33, 0xD9, 0x9D,
 0xC4, 0x41, 0x75, 0x28, 0x28, 0xB2, 0x97, 0xC0, 0x68, 0x7D,
 0x3E, 0x67, 0xB5, 0xB8, 0x00, 0x9B, 0xB0, 0x2C, 0x94, 0x11,
 0xEE, 0x7C, 0xED, 0x2E, 0x22, 0x39, 0xA9, 0xD5, 0xC9, 0x1A,
 0xF0, 0xAC, 0x4D, 0x5E, 0x72, 0xCB, 0x8A, 0x7E, 0xAE, 0x00,
 0xC5, 0xBC, 0x29, 0x27, 0x16, 0x1C, 0x85, 0x1B, 0xFA, 0x45,
 0x3A, 0xAB, 0x94, 0xB5, 0x64, 0xA1, 0x68, 0x04, 0x6A, 0x4E,
 0xEB, 0x28, 0x3D, 0x33, 0xF9, 0x4E, 0x59, 0xFE, 0xB7, 0x6B,
 0x25, 0x6A, 0xC1, 0xE3, 0x35, 0xD2, 0xAC, 0x2C, 0xF0, 0x6F,
 0x60, 0x3F, 0x21, 0x4E, 0x98, 0xA7, 0x47, 0x36, 0x4A, 0xD3,
 0x6F, 0xBD, 0x51, 0xA9, 0xA7, 0x31, 0x9D, 0x88, 0x63, 0xD0,
 0xEB, 0x14, 0x25, 0x71, 0x33, 0x82, 0xA7, 0x6A, 0x82, 0x6C,
 0xA3, 0x81, 0x91, 0x0B, 0x85, 0x57, 0xAE, 0x9A, 0x62, 0x4D,
 0x10, 0x45, 0x41, 0xF3, 0xC5, 0x9F, 0x8B, 0x2E, 0xC2, 0x7F,
 0xA7, 0x6A, 0x4D, 0x7D, 0xF3, 0x36, 0x42, 0x97, 0x56, 0xD3,
 0xE3, 0xFC, 0xE6, 0x15, 0x57, 0xCA, 0x97, 0xC8, 0x86, 0x9A,
 0x30, 0x6E, 0x3C, 0x59, 0x9E, 0x7F, 0xA0, 0x26, 0x33, 0x6F,
 0x0A, 0x46, 0x97, 0xD0, 0x5F, 0xCC, 0x37, 0x3A, 0x5B, 0xE1,
 0x51, 0x1E, 0xD4, 0x07, 0xD9, 0x5F, 0x4F, 0xC5, 0x6D, 0x5C,
 0x00, 0x4E, 0xBB, 0xC2, 0x39, 0xCC, 0x0A, 0x86, 0x1E, 0xDB,
 0x70, 0x10, 0xB3, 0x2F, 0xE6, 0x29, 0x50, 0x03, 0x44, 0xA2,
 0xB8, 0xCF, 0x4D, 0xA7, 0x4A, 0x1A, 0xFD, 0x42, 0x90, 0x21,
 0x9B, 0xE7, 0x32, 0xE1, 0xE7, 0xDA, 0x45, 0x48, 0xC4, 0x9E,
 0x4B, 0x77, 0xA1, 0xF1, 0x1E, 0xFB, 0x5B, 0xE8, 0xE7, 0xB1,
 0x1E, 0xF6, 0x8A, 0xC4, 0x6E, 0x29, 0x40, 0xF4, 0x89, 0x1E,
 0xA7, 0x84, 0x0B, 0x6F, 0xA8, 0xD3, 0x8B, 0x7D, 0x42, 0x60,
 0xCE, 0x0C, 0x36, 0x1E, 0x45, 0xFC, 0xAF, 0x83, 0x9A, 0x18,
 0x21, 0xBA, 0x55, 0x03, 0x18, 0x68, 0x51, 0x95, 0xC0, 0x93,
 0xDF, 0x29, 0x93, 0x03, 0x31, 0xF4, 0xD8, 0x9C, 0xF9, 0xB4,
 0xCB, 0x3B, 0x8D, 0x94, 0x18, 0x37, 0x61, 0x18, 0x48, 0x49,
 0x56, 0xF3, 0x16, 0x3E, 0x6D, 0xB8, 0x7C, 0x29, 0xB1, 0x82,
 0x55, 0x7D, 0xD1, 0xEA, 0xAD, 0xE6, 0x64, 0xF3, 0x18, 0x49,
 0x5A, 0x0F, 0xF5, 0xB6, 0x5A, 0x1A, 0x51, 0x70, 0x1F, 0x31,
 0xFD, 0x60, 0x71, 0x4E, 0x41, 0x2C, 0xD5, 0xFA, 0x47, 0x05,
 0x88, 0x59, 0xF0, 0x23, 0xD0, 0xEF, 0xCB, 0x39, 0x74, 0x9F,
 0xC8, 0x61, 0xAA, 0x62, 0xB5, 0x2A, 0xCE, 0x8E, 0x74, 0x76,
 0xA2, 0x73, 0x53, 0x3A, 0xFC, 0x17, 0x36, 0x64, 0xFF, 0x89,
 0x78, 0x92, 0xE3, 0x35, 0xDE, 0xC4, 0x35, 0x7B, 0x4A, 0x29,
 0xFE, 0x6F, 0x13, 0xC8, 0xD1, 0x45, 0xB3, 0x8C, 0xC9, 0xFB,
 0x5F, 0x9C, 0xF9, 0x9D, 0xA8, 0x3D, 0xC6, 0xCB, 0x43, 0x7A,
 0x29, 0xDE, 0x4D, 0x31, 0x56, 0x04, 0x86, 0xAD, 0xE5, 0x64,
 0xA6, 0xAE, 0x4A, 0x73, 0x3B, 0x2A, 0xB1, 0x0E, 0x49, 0xD2,
 0x34, 0x79, 0xD9, 0xE4, 0x11, 0xF3, 0xB4, 0x5D, 0x37, 0x12,
 0x76, 0xB0, 0x59, 0x85, 0xEA, 0xD0, 0x3D, 0xEA, 0x89, 0x7E,
 0x72, 0xC0, 0x2C, 0x12, 0x3F, 0x71, 0x0D, 0x72, 0xCD, 0x3A,
 0x1D, 0x93, 0x02, 0xD9, 0x70, 0x2D, 0xBF, 0xFE, 0xE3, 0x65,
 0xB4, 0x97, 0xAC, 0x9F, 0x72, 0x20, 0xB0, 0xDA, 0xC0, 0x3A,
 0x70, 0xAB, 0x8E, 0xAE, 0x39, 0xF6, 0xE9, 0x1C, 0x4F, 0x9F,
 0xD1, 0x0E, 0xEB, 0x40, 0x8A, 0x36, 0x76, 0x34, 0xA8, 0x41,
 0x92, 0x2E, 0x22, 0xDE, 0x98, 0x06, 0xB0, 0x93, 0x8F, 0xBA,
 0x4A, 0x2E, 0x8F, 0xCD, 0xEA, 0xA0, 0x27, 0x8B, 0xF4, 0x2E,
 0x6B, 0xEB, 0x68, 0xD1, 0x66, 0xE0, 0x92, 0x60, 0x89, 0x40,
 0xA9, 0x94, 0xE7, 0x6B, 0x22, 0xDD, 0xC7, 0x3D, 0x1A, 0x76,
 0x39, 0xF3, 0x51, 0x97, 0x55, 0x2A, 0x61, 0xE9, 0xED, 0x73,
 0x29, 0x83, 0xFA, 0x7A, 0xE4, 0x9C, 0xC6, 0x16, 0xCC, 0x79,
 0xA4, 0x0A, 0xA7, 0x64, 0xAE, 0x1F, 0xBA, 0x31, 0x14, 0xD1,
 0xFB, 0xDB, 0xC7, 0xD3, 0x78, 0xAA, 0x63, 0xBC, 0xB4, 0xB9,
 0x10, 0xC7, 0x20, 0x8D, 0x34, 0x13, 0xE1, 0x66, 0xBE, 0x23,
 0xFC, 0x43, 0xD0, 0xDC, 0x16, 0xB4, 0xD4, 0xD2, 0xCC, 0x0E,
 0x2C, 0xC7, 0x9F, 0xA2, 0x28, 0x67, 0xA2, 0xCF, 0x51, 0x2E,
 0x87, 0x9F, 0x39, 0x29, 0x7D, 0xDE, 0x41, 0x60, 0xCE, 0x60,
 0x89, 0x5B, 0x5A, 0x57, 0x2D, 0xE3, 0xE3, 0xD0, 0x69, 0x4F,
 0x3B, 0xA3, 0x09, 0xC9, 0x32, 0x04, 0xCA, 0x28, 0xB8, 0x1D,
 0x10, 0x7B, 0x5D, 0x53, 0xCA, 0x72, 0x85, 0xE2, 0x13, 0xC8,
 0x19, 0x40, 0x28, 0x27, 0x09, 0xC0, 0x7A, 0x0A, 0x69, 0xCE,
 0xAA, 0xA0, 0xEB, 0x15, 0xC2, 0x5D, 0x72, 0xCD, 0x1B, 0xC0,
 0xF8, 0xCA, 0x36, 0x34, 0x56, 0x5F, 0x79, 0xCA, 0xA2, 0x8F,
 0xBC, 0xB0, 0xB8, 0xCB, 0xDF, 0xEC, 0xD4, 0xDA, 0x54, 0x76,
 0xC4, 0x1A, 0x55, 0xE5, 0xCE, 0x0A, 0x6D, 0xCB, 0x69, 0x35,
 0x9B, 0xE5, 0x0B, 0xBB, 0x8D, 0xDA, 0xCA, 0xA9, 0xC3, 0xB9,
 0x59, 0xA2, 0x14, 0x64, 0x03, 0xD9, 0x54, 0x8D, 0x46, 0x24,
 0xB5, 0x3D, 0xA2, 0xA5, 0xAB, 0x4F, 0x1B, 0xBD, 0xF1, 0xFC,
 0x9D, 0x70, 0x77, 0x79, 0x0C, 0x3A, 0x54, 0x8B, 0x86, 0x91,
 0x06, 0x6B, 0xDF, 0x9E, 0xEF, 0xC1, 0x76, 0x9B, 0x5B, 0x98,
 0x14, 0x99, 0x32, 0x31, 0x37, 0xC9, 0x88, 0x1B, 0x87, 0xE1,
 0x67, 0x61, 0x13, 0xFB, 0x9D, 0x41, 0x68, 0x24, 0x8B, 0xDA,
 0xD6, 0xB9, 0x5D, 0x29, 0x78, 0x5D, 0x48, 0x13, 0xB6, 0x81,
 0x85, 0xA3, 0x84, 0xB3, 0x6B, 0x15, 0x60, 0x95, 0x90, 0x05,
 0x2E, 0x65, 0x1B, 0x50, 0x43, 0x81, 0xCD, 0x26, 0x8D, 0x28,
 0xF1, 0x42, 0x46, 0xAE, 0xEB, 0x7B, 0xE2, 0xBB, 0xF1, 0x61,
 0x12, 0xC8, 0x27, 0xFB, 0x13, 0x06, 0x69, 0xE5, 0x6F, 0x46,
 0xD8, 0x2C, 0x63, 0x78, 0xC0, 0x62, 0xA0, 0xD3, 0x35, 0xE5,
 0x48, 0x3A, 0x26, 0xBD, 0xE0, 0x63, 0xC1, 0x7C, 0xEA, 0x46,
 0xBC, 0x81, 0x5B, 0xA3, 0x07, 0x40, 0x37, 0x80, 0x6E, 0x9C,
 0x33, 0x29, 0xDE, 0xBF, 0x34, 0xDF, 0x35, 0x30, 0x75, 0x3C,
 0x58, 0x2F, 0x05, 0xE6, 0x93, 0x52, 0xA4, 0x55, 0x10, 0x9C,
 0x61, 0xBF, 0xD0, 0x01, 0x9B, 0xE6, 0xE6, 0x53, 0x5F, 0x31,
 0x8D, 0x81, 0x1C, 0xF9, 0x1A, 0xC5, 0xCD, 0x97, 0xEB, 0xC1,
 0x29, 0xE7, 0xBD, 0x3A, 0xBD, 0xF8, 0x1B, 0x01, 0x94, 0x88,
 0xBA, 0x03, 0x2B, 0xD5, 0x79, 0x29, 0x60, 0x18, 0x7F, 0x3F,
 0xA0, 0xAE, 0xD2, 0x40, 0x74, 0x65, 0x1C, 0x64, 0xA3, 0x6E,
 0x94, 0x8B, 0x91, 0xCB, 0x11, 0xDE, 0x46, 0x80, 0xF1, 0x88,
 0xAE, 0x59, 0xA6, 0x2F, 0x26, 0xE4, 0x88, 0x6B, 0xC8, 0x71,
 0xA0, 0x09, 0x8E, 0x6B, 0x90, 0xE1, 0xEE, 0xB7, 0xF7, 0xBC,
 0x3C, 0xF5, 0xAE, 0x36, 0xE2, 0xAF, 0xDC, 0xE5, 0xFD, 0x96,
 0xFB, 0xC1, 0x81, 0x18, 0x94, 0xCF, 0x8E, 0x6A, 0x7A, 0x64,
 0x5F, 0x25, 0x07, 0x20, 0x08, 0x62, 0x58, 0x1D, 0xD0, 0xCD,
 0x5D, 0x77, 0x3D, 0x47, 0x40, 0x53, 0x8B, 0xDF, 0x7C, 0x6C,
 0xDF, 0x76, 0x80, 0x86, 0x9C, 0x60, 0x96, 0x5C, 0x69, 0x9E,
 0xA0, 0x50, 0x30, 0x9F, 0x7F, 0x36, 0x6E, 0xE1, 0x25, 0x0D,
 0x63, 0xB3, 0xA2, 0xF7, 0xA3, 0x56, 0x0C, 0xBE, 0xEF, 0x98,
 0xC5, 0x92, 0x8D, 0xEF, 0x67, 0x66, 0xFE, 0x85, 0x8B, 0x31,
 0x2B, 0xCE, 0x51, 0x79, 0x60, 0x3C, 0xC0, 0x2E, 0x6C, 0x92,
 0x8D, 0x74, 0xCA, 0x00, 0x0D, 0xB5, 0x4D, 0xA9, 0x06, 0x37,
 0xA2, 0x37, 0xAF, 0x5E, 0x5D, 0x7B, 0x46, 0xC5, 0x70, 0xDE,
 0xCF, 0xEA, 0x0F, 0x3D, 0x51, 0x22, 0x15, 0xF0, 0x82, 0x2E,
 0xD1, 0x13, 0xB8, 0x1A, 0x3E, 0x98, 0xCD, 0x95, 0xE4, 0xB3,
 0xC9, 0x0E, 0x57, 0x96, 0x9D, 0xCD, 0x45, 0x8D, 0x5A, 0x62,
 0x73, 0x70, 0xB6, 0x97, 0xD2, 0xAB, 0xE7, 0xB2, 0xFB, 0x9D,
 0x18, 0x4B, 0x45, 0xEA, 0x3F, 0x00, 0x81, 0x60, 0x80, 0x40,
 0xBB, 0x5F, 0x0D, 0x3A, 0x88, 0x9D, 0x6C, 0xAE, 0x3E, 0x7A,
 0x19, 0x7A, 0xCB, 0x85, 0xD5, 0x13, 0x8A, 0x42, 0x2B, 0x27,
 0xB2, 0x8F, 0x3C, 0xE3, 0x6F, 0x7F, 0xE7, 0x30, 0x72, 0x79,
 0xA1, 0x09, 0x54, 0xC1, 0x06, 0x86, 0x8C, 0x70, 0xDE, 0xC1,
 0x37, 0x3A, 0xBB, 0xE8, 0xDF, 0xF8, 0xAC, 0x40, 0x82, 0x03,
 0xE2, 0x10, 0x5C, 0x20, 0x28, 0xFF, 0x48, 0xCE, 0xD2, 0x3C,
 0x27, 0x55, 0x12, 0xD8, 0x49, 0x77, 0x22, 0xD7, 0xB1, 0x87,
 0x09, 0x8F, 0xB1, 0x8D, 0x6C, 0x0D, 0xEA, 0x0F, 0x95, 0xF3,
 0x2B, 0xF2, 0x79, 0xEE, 0x55, 0x1E, 0x28, 0x1F, 0x60, 0x25,
 0x86, 0x70, 0x4B, 0x37, 0x86, 0x03, 0x66, 0x5E, 0x4A, 0xC8,
 0xD9, 0x61, 0xA5, 0x93, 0x53, 0x54, 0xBA, 0xF1, 0x05, 0x0D,
 0x9A, 0x2D, 0xCB, 0x58, 0xEF, 0x60, 0xD7, 0xEB, 0x65, 0x27,
 0xFE, 0x5F, 0xBF, 0xBC, 0x17, 0x67, 0x1A, 0x38, 0xE5, 0x6F,
 0x53, 0x0D, 0xA4, 0xED, 0x75, 0xE5, 0xE5, 0xF5, 0xC1, 0x8C,
 0x36, 0xBE, 0xB4, 0x34, 0xB7, 0xFD, 0xF5, 0x03, 0x29, 0xB4,
 0x9A, 0x72, 0x26, 0x10, 0xCB, 0x9E, 0x69, 0x8D, 0x86, 0x38,
 0x09, 0x74, 0x75, 0x30, 0x23, 0xB6, 0xF4, 0x23, 0x3D, 0xEB,
 0xAB, 0xA7, 0x59, 0x3C, 0x1F, 0x84, 0xFF, 0x21, 0xEE, 0x50,
 0xBD, 0x4D, 0xA6, 0x3A, 0x22, 0x2F, 0xCF, 0x34, 0x1D, 0x42,
 0xD6, 0xE0, 0xF9, 0x3B, 0x19, 0x4C, 0x01, 0xB7, 0xA0, 0xA1,
 0x96, 0x53, 0x15, 0x24, 0x8C, 0x5B, 0xF6, 0x4D, 0x7A, 0xA9,
 0xD0, 0x94, 0xB0, 0xF4, 0x69, 0x57, 0x97, 0xAA, 0x82, 0x21,
 0x1E, 0x04, 0x6B, 0x29, 0xCD, 0x1F, 0x94, 0xB7, 0xFA, 0x15,
 0x8F, 0x43, 0xB9, 0xDA, 0x3F, 0xA2, 0xF9, 0x06, 0xD9, 0xBC,
 0x42, 0x89, 0xE7, 0xF4, 0x87, 0x48, 0x72, 0x16, 0xD9, 0x8C,
 0xED, 0x3D, 0xDE, 0x34, 0xB6, 0x46, 0xE0, 0x4B, 0x8D, 0x3F,
 0x5B, 0xA0, 0x15, 0x45, 0x29, 0x2F, 0x3B, 0xFB, 0xB6, 0xFA,
 0x2A, 0x88, 0xFD, 0xDB, 0xBE, 0xE4, 0xAF, 0x67, 0x5D, 0x88,
 0x9D, 0x86, 0x29, 0x54, 0xD7, 0x0C, 0xAC, 0x0F, 0x24, 0xD9,
 0xFE, 0x03, 0x02, 0x46, 0xFB, 0xBF, 0x2B, 0x88, 0x12, 0x22,
 0xA4, 0xC2, 0x8D, 0x6C, 0x6F, 0x51, 0xD1, 0x32, 0x5C, 0x05,
 0xEF, 0x98, 0xC8, 0xF2, 0x41, 0xD7, 0x64, 0x44, 0x50, 0xF7,
 0x71, 0x05, 0x5A, 0x10, 0x63, 0x5C, 0x36, 0xED, 0xCA, 0xFA,
 0xA9, 0xC3, 0xEA, 0x9C, 0xA8, 0x6E, 0x1E, 0x33, 0x43, 0xD4,
 0x48, 0x81, 0xF8, 0xC3, 0xB6, 0xD8, 0x34, 0x33, 0xEB, 0xAA,
 0x93, 0x71, 0x83, 0x0F, 0xDC, 0x7A, 0x42, 0x16, 0x45, 0x8C,
 0x4D, 0xEB, 0x44, 0x1C, 0x30, 0x92, 0xF8, 0x40, 0x5E, 0xD0,
 0xB8, 0xD9, 0xFD, 0x85, 0xD1, 0x2C, 0x40, 0x43, 0xBC, 0x49,
 0x40, 0xB4, 0x5F, 0xAA, 0x90, 0xE6, 0x08, 0x98, 0xC0, 0xA4,
 0x0F, 0x7F, 0x70, 0x6A, 0x12, 0x4F, 0xF6, 0x2C, 0x6C, 0xAF,
 0x36, 0xF9, 0x31, 0xCF, 0x96, 0xF2, 0x83, 0xAA, 0x16, 0xD7,
 0x69, 0xF8, 0x1E, 0x8A, 0x9F, 0x24, 0x82, 0x28, 0xBB, 0xD2,
 0x50, 0xF1, 0x9B, 0x4B, 0x12, 0x2B, 0xF1, 0x0E, 0x78, 0x56,
 0x04, 0x1F, 0x2C, 0x34, 0xFB, 0x9F, 0x1A, 0x1A, 0xED, 0x9D,
 0x39, 0xCB, 0xF5, 0x7C, 0x60, 0x12, 0x7C, 0x36, 0xE6, 0x8D,
 0xC6, 0x14, 0x77, 0xEF, 0x50, 0x69, 0xE5, 0x1A, 0xCA, 0x78,
 0xA1, 0x68, 0x7E, 0x4D, 0x3E, 0x67, 0xD2, 0x2F, 0x05, 0x04,
 0x22, 0xD5, 0x44, 0x6E, 0x02, 0x0C, 0x5C, 0xB8, 0xEF, 0xF0,
 0x1E, 0x8F, 0xF9, 0x6F, 0x0A, 0x8E, 0xFA, 0x14, 0xCF, 0x71,
 0x26, 0x81, 0x78, 0xDC, 0xFC, 0xF6, 0xEF, 0x1B, 0x31, 0x0E,
 0x09, 0x87, 0x34, 0x6D, 0xD6, 0xCA, 0x49, 0x01, 0xC4, 0x2E,
 0x9F, 0xAB, 0xB6, 0xA2, 0x10, 0x3D, 0x8A, 0x89, 0x2B, 0xBE,
 0x27, 0xD7, 0xF1, 0xA0, 0x64, 0x4D, 0x98, 0x62, 0x85, 0x03,
 0xA9, 0xC6, 0xA2, 0x3E, 0xCD, 0x6D, 0x14, 0x5C, 0x2A, 0x77,
 0x2A, 0x8E, 0x7A, 0xDB, 0x77, 0x52, 0xDF, 0x0E, 0xDF, 0x8A,
 0x00, 0x30, 0x60, 0xB7, 0xA1, 0xD5, 0x63, 0x0F, 0xBD, 0x36,
 0x85, 0xC4, 0x53, 0x39, 0x59, 0x8A, 0x09, 0xF5, 0xFA, 0xB4,
 0xA2, 0x10, 0x32, 0x52, 0x57, 0x0C, 0x2C, 0x0C, 0xA0, 0x13,
 0x60, 0xB2, 0x0D, 0x4F, 0xED, 0xF7, 0x97, 0x16, 0x15, 0x06,
 0xAB, 0x2D, 0x30, 0x9E, 0x5E, 0xBF, 0x03, 0x16, 0xC2, 0xEF,
 0x7D, 0xB2, 0xD1, 0x8E, 0x30, 0x56, 0x65, 0x86, 0xFB, 0xF3,
 0x4E, 0x57, 0xF7, 0x99, 0x5A, 0x7A, 0xFB, 0xB3, 0x67, 0x45,
 0x77, 0x38, 0x65, 0xEB, 0x16, 0x81, 0x14, 0x06, 0x61, 0x32,
 0x95, 0xE0, 0xA6, 0x2A, 0x26, 0xE0, 0xAD, 0xC2, 0x54, 0xED,
 0xBF, 0x3A, 0x02, 0x77, 0xF0, 0x70, 0x65, 0x64, 0x3E, 0x7D,
 0xE2, 0x4D, 0xC9, 0x1D, 0x56, 0x50, 0x4F, 0xFA, 0x8B, 0x43,
 0xB6, 0xAF, 0x1D, 0x2C, 0x18, 0x11, 0x8D, 0x18, 0xA4, 0x37,
 0xD8, 0x6F, 0xA9, 0x5C, 0x34, 0xDE, 0x2B, 0x6F, 0xBA, 0xD9,
 0xE0, 0x86, 0x72, 0xE8, 0x06, 0x61, 0x30, 0x15, 0x58, 0x17,
 0x70, 0x7C, 0x31, 0xE7, 0x27, 0x23, 0xC7, 0x8A, 0xDD, 0xD5,
 0xE5, 0x3D, 0xA8, 0x33, 0xCE, 0x31, 0xA0, 0xB7, 0x04, 0xEC,
 0x20, 0x45, 0x90, 0x0A, 0x16, 0xCD, 0x33, 0xF3, 0x3E, 0xDD,
 0x36, 0x0C, 0x2B, 0xB5, 0xD2, 0xD5, 0x6B, 0x00, 0xB7, 0xC2,
 0x9C, 0xEF, 0x60, 0x3C, 0xF7, 0x5D, 0x73, 0xB6, 0xD9, 0xF3,
 0xE0, 0xCB, 0xDA, 0x10, 0xA8, 0xEB, 0xB2, 0x33, 0x5E, 0xAB,
 0x07, 0x2F, 0x23, 0x68, 0xC3, 0xDF, 0xF3, 0xE1, 0xBB, 0xFE,
 0xAD, 0x27, 0xAA, 0xCE, 0x02, 0xFD, 0x79, 0xB5, 0x13, 0x81,
 0x33, 0xC6, 0x32, 0xA7, 0xC0, 0x06, 0x76, 0xF7, 0x5D, 0xAA,
 0x49, 0x82, 0x55, 0xA2, 0xC1, 0x3B, 0x22, 0x41, 0xAE, 0xFA,
 0x76, 0x66, 0x3F, 0x88, 0xEA, 0x8B, 0x34, 0x75, 0x48, 0x6E,
 0xF1, 0x0D, 0x68, 0xB8, 0xB8, 0x3F, 0x1C, 0x62, 0xAE, 0x78,
 0x03, 0x0E, 0xC9, 0x88, 0xEE, 0x6B, 0x76, 0x90, 0xF9, 0xDD,
 0x8D, 0x75, 0xEF, 0x6A, 0xB1, 0xA8, 0x56, 0xD0, 0xA6, 0xEE,
 0x9B, 0x17, 0x0A, 0x05, 0xAE, 0xD7, 0xFD, 0x5B, 0x4A, 0xDA,
 0x4E, 0xEF, 0xFD, 0x2C, 0xF8, 0x64, 0xFE, 0x96, 0x5F, 0x02,
 0x70, 0x01, 0x60, 0x3A, 0xE1, 0xD5, 0xB5, 0xA5, 0xC5, 0xB2,
 0x34, 0xD5, 0x81, 0xBA, 0x4B, 0x76, 0x8A, 0x30, 0x93, 0x2D,
 0xB1, 0x64, 0x3A, 0x04, 0x86, 0x58, 0x89, 0x8E, 0x06, 0x7A,
 0x40, 0xAD, 0x30, 0xD2, 0xAE, 0xF5, 0x6E, 0x04, 0x54, 0x0B,
 0x2E, 0xA8, 0x50, 0xD9, 0xF2, 0xD9, 0x5C, 0x89, 0x59, 0xC1,
 0xF3, 0xAD, 0xC2, 0x87, 0x57, 0xE4, 0xBB, 0xD3, 0x00, 0x83,
 0x8B, 0x58, 0xDE, 0xA7, 0xBB, 0x34, 0xBA, 0xF4, 0x3E, 0x5F,
 0x6A, 0x4A, 0x2E, 0x21, 0x53, 0x0E, 0x93, 0x45, 0xC4, 0x49,
 0x27, 0x0F, 0x64, 0xC7, 0x8E, 0x91, 0x0D, 0x55, 0x8F, 0x0C,
 0xF0, 0x84, 0x65, 0x86, 0xAA, 0x95, 0x16, 0x80, 0xA6, 0x85,
 0xFE, 0x72, 0xF7, 0xD6, 0xC4, 0xD9, 0x4B, 0xD6, 0x71, 0xE8,
 0x31, 0xCE, 0xF2, 0x77, 0xD1, 0xB8, 0x6B, 0x59, 0x71, 0xA0,
 0xC8, 0x84, 0x9D, 0x3D, 0xBD, 0xC7, 0xAD, 0xAD, 0x9E, 0xDB,
 0x58, 0x26, 0x71, 0x8E, 0xA2, 0xD0, 0x9E, 0xC8, 0x6A, 0x48,
 0x41, 0xED, 0x1B, 0x0B, 0xF0, 0x9F, 0x1B, 0x7C, 0xEF, 0xE8,
 0xDA, 0xF0, 0x78, 0xB9, 0xDC, 0xBA
 }
    </props>
  </device>
</driver>

<driver name="NULL">
  <device id="/tz/oem/kdf_fix">
<!--
  OEM configurable fix for KDF issue
  where in-place key derivation results in
  reducing key strength. Enabling the fix will break
  backward compatibility for the features which depend
  on KDF key derived from stored persistent key (e.g. OTA
  update when FDE is enable)
  0: Disables KDF fix
  1: Enables KDF fix
-->
    <props name="is_kdf_fix_enable" type=0x00000002>
      1
    </props>
  </device>
</driver>

<driver name="NULL">
    <!--
 "global_def" section contains strings used by the "device" section below.
 Each string should be referenced using the unique "name" property from the "device" section.
  -->
  <global_def>
    <var_seq name="qti_fp_app_name" type=0x00000001>
      fingerprint
    </var_seq>
    <var_seq name="qti_fp_oem_str" type=0x00000001>
      oem_str
    </var_seq>
  </global_def>
  <!-- "device" section contains configuration properties read by fingerprint -->
  <device id="fingerprint">
    <!-- "fingerprint_oem_config_enable" property specifies if OEM configs properties
    defined in this config files are enabled and to be used.
    0 = disabled and oem configs in this file will be ignored
    1 = enabled and oem configs in this file will be picked
    -->
    <props name="fingerprint_oem_config_enable" type=0x00000002>
      0
    </props>
    <!-- "fingerprint_qsee_spidev_id" property specifies qsee spi device id
    for the gpio pins to be used for spi communication from MSM to QBT ASIC.
    Note: spidev_id=4 corresponds to QSEE_SPI_DEVICE_5
    -->
    <props name="fingerprint_qsee_spidev_id" type=0x00000002>
      4
    </props>
    <!-- "fingerprint_qsee_spidev_speed" property specifies spi bus speed in HZ
    for spi communication from MSM to QBT ASIC
    -->
    <props name="fingerprint_qsee_spidev_speed" type=0x00000002>
      25*1000*1000
    </props>
    <!-- "fingerprint_oem_str" property specifies string to identify oem -->
    <props name="fingerprint_oem_str" type=0x00000011>
      qti_fp_oem_str
    </props>
  </device>
</driver>

<driver name="NULL">
   <global_def>
   </global_def>
   <device id="/dev/ABTimeoutOEM">
     <props name="ABT_Propdata_oem" type=0x00000012>
        ABT_propdata_oem
     </props>
   </device>
   <device id="/dev/NOCErrorOEM">
     <props name="NOCError_Propdata_oem" type=0x00000012>
        NOCERR_propdata_oem
     </props>
   </device>
   <device id="/dev/BIMCErrorOEM">
     <props name="BIMCError_Propdata_oem" type=0x00000012>
        BIMC_propdata_oem
     </props>
   </device>
</driver>

<driver name="NULL">
   <device id="/pmic/periph">
      <props name="arb_priority_cfg" type=0x00000012>
         pm_arb_priorities
      </props>
      <props name="number_priorities" type=0x00000012>
         pm_num_prio
      </props>
      <props name="number_pvc_port" type=0x00000012>
         pm_num_pvc_port
      </props>
      <props name="pvc_port_cfg" type=0x00000012>
         pm_arb_pvc_cfg
      </props>
      <props name="spmi_channel_cfg" type=0x00000012>
         pm_spmi_pheriph_cfg
      </props>
      <props name="spmi_channel_cfg_size" type=0x00000012>
         pm_spmi_pheriph_cfg_sz
      </props>
      <props name="tz_mpu_rg_cfg" type=0x00000012>
       pm_mpu_rg_cfg
      </props>
      <props name="rg_cfg_size" type=0x00000012>
        pm_spmi_rg_sz
      </props>
      <props name="pmic_arb_hal_id_xpu" type=0x00000012>
         pm_hal_id_xpu
      </props>
      <props name="spmi_rg_config" type=0x00000012>
       pm_spmi_rg_cfg
      </props>
   </device>
</driver>

<driver name="NULL">
<device id="/tz/pmic">
<props name="QFPROM_rail_id" type=0x00000002>
10
</props>
<props name="QFPROM_rail_type" type=0x00000002>
0x616F646C
</props>
<props name="pam_qfprom_rail" type=0x00000012>
pm_pam_qfprom_rail
</props>
<props name="reg_dump_list" type=0x00000012>
 pm_reg_dump_list
</props>
</device>
</driver>

enum_header_path "TlmmPropDef.h"
enum_header_path "HALxpu3.h"
enum_header_path "HALxpu3Target.h"
enum_header_path "HALcomdef.h"
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef signed int int32;
typedef signed short int16;
typedef signed char int8;
typedef unsigned long long uint64;
typedef long long int64;
typedef unsigned char byte;
typedef unsigned long UINTN;
typedef uint32 DALBOOL;
typedef uint32 DALDEVICEID;
typedef uint32 DalPowerCmd;
typedef uint32 DalPowerDomain;
typedef uint32 DalSysReq;
typedef UINTN DALHandle;
typedef int DALResult;
typedef void * DALEnvHandle;
typedef void * DALSYSEventHandle;
typedef uint32 DALMemAddr;
typedef UINTN DALSYSMemAddr;
typedef uint32 DALInterfaceVersion;
typedef unsigned char * DALDDIParamPtr;
typedef struct DALEventObject DALEventObject;
struct DALEventObject
{
    uint32 obj[8];
};
typedef DALEventObject * DALEventHandle;
typedef struct _DALMemObject
{
   uint32 memAttributes;
   uint32 sysObjInfo[2];
   uint32 dwLen;
   uint32 ownerVirtAddr;
   uint32 virtAddr;
   uint32 physAddr;
}
DALMemObject;
typedef struct _DALDDIMemBufDesc
{
   uint32 dwOffset;
   uint32 dwLen;
   uint32 dwUser;
}
DALDDIMemBufDesc;
typedef struct _DALDDIMemDescList
{
   uint32 dwFlags;
   uint32 dwNumBufs;
   DALDDIMemBufDesc bufList[1];
}
DALDDIMemDescList;
typedef struct DALSysMemDescBuf DALSysMemDescBuf;
struct DALSysMemDescBuf
{
   DALSYSMemAddr VirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   uint32 size;
   uint32 user;
};
typedef struct DALSysMemDescList DALSysMemDescList;
struct DALSysMemDescList
{
   uint32 dwObjInfo; uint32 hOwnerProc; DALSYSMemAddr thisVirtualAddr;
   DALSYSMemAddr PhysicalAddr;
   DALSYSMemAddr VirtualAddr;
   uint32 dwCurBufIdx;
   uint32 dwNumDescBufs;
   DALSysMemDescBuf BufInfo[1];
};
typedef struct {
   uint32 nGpioNumber;
   uint32 nFunctionSelect;
}TLMMGpioIdType;
typedef struct {
   uint32 nTileXPU;
   uint32 nTileBase;
}TLMMXPUTileType;
typedef unsigned long uintptr_t;
typedef long intptr_t;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef long intmax_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned long uintmax_t;
typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef unsigned char boolean;
typedef uint32_t bool32;
typedef uintptr_t uintnt;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned char uint1;
typedef unsigned short uint2;
typedef unsigned int uint4;
typedef signed char int1;
typedef signed short int2;
typedef long int int4;
typedef signed int sint31;
typedef signed short sint15;
typedef signed char sint7;
typedef uint16 UWord16 ;
typedef uint32 UWord32 ;
typedef int32 Word32 ;
typedef int16 Word16 ;
typedef uint8 UWord8 ;
typedef int8 Word8 ;
typedef int32 Vect32 ;
typedef enum
{
  HAL_XPU2_NO_ERROR = 0,
  HAL_XPU2_INVALID_INSTANCE,
  HAL_XPU2_UNSUPPORTED_INSTANCE_FOR_TARGET,
  HAL_XPU2_UNSUPPORTED_HANDLER,
  HAL_XPU2_INVALID_BASE_ADDR,
  HAL_XPU2_INVALID_PARAM,
  HAL_XPU2_READ_WRITE_MISMATCH,
  HAL_XPU2_UNSUPPORTED_CFG_FOR_XPU
} HAL_xpu3_Status;
typedef enum
{
  HAL_XPU2_APCS_MPU ,
  HAL_XPU2_CRYPTO0_BAM,
  HAL_XPU2_DCC,
  HAL_XPU2_IPA_0_GSI_TOP,
  HAL_XPU2_IPA,
  HAL_XPU2_MCCC_APU,
  HAL_XPU2_MMSS,
  HAL_XPU2_MMSS_CC,
  HAL_XPU2_BAM_BLSP1_DMA,
  HAL_XPU2_BAM_BLSP2_DMA,
  HAL_XPU2_SKL,
  HAL_XPU2_SP_SCSR,
  HAL_XPU2_SSC_BLSP_BAM,
  HAL_XPU2_TLMM_XPU_EAST,
  HAL_XPU2_TLMM_XPU_NORTH,
  HAL_XPU2_TLMM_XPU_WEST,
  HAL_XPU2_UFS_ICE,
  HAL_XPU2_MNOC,
  HAL_XPU2_GCC_RPU,
  HAL_XPU2_TCSR_MUTEX,
  HAL_XPU2_TCSR_REGS,
  HAL_XPU2_BIMC_APU,
  HAL_XPU2_MCCC_APU2,
  HAL_XPU2_MPM2,
  HAL_XPU2_IMEM_APU,
  HAL_XPU2_RAMBLUR_PIMEM_APU,
  HAL_XPU2_SEC_CTRL_APU,
  HAL_XPU2_SPDM_APU,
  HAL_XPU2_ANOC1_MPU,
  HAL_XPU2_ANOC2_MPU,
  HAL_XPU2_BOOT_ROM,
  HAL_XPU2_CNOC_A1NOC_MPU,
  HAL_XPU2_CNOC_A2NOC_MPU,
  HAL_XPU2_CNOC_QDSS_MPU,
  HAL_XPU2_CNOC_SNOC_MPU,
  HAL_XPU2_CNOC_SNOC_MS_MPU,
  HAL_XPU2_LPASS_Q6SS_MPU,
  HAL_XPU2_MSS_MPU,
  HAL_XPU2_MSS_Q6_MPU,
  HAL_XPU2_IMEM_MPU,
  HAL_XPU2_PMIC_ARB,
  HAL_XPU2_QM_MPU_CFG,
  HAL_XPU2_RAMBLUR_PIMEM_MPU,
  HAL_XPU2_RPM_MSTR_MPU,
  HAL_XPU2_CFG_SSC,
  HAL_XPU2_SSC_Q6_MPU,
  HAL_XPU2_BIMC_MPU0,
  HAL_XPU2_BIMC_MPU1,
  HAL_XPU2_TLMM,
  HAL_XPU2_MSS_NAV_MPU,
  HAL_XPU2_LPASS_CFG_MPU,
  HAL_XPU2_TURING_Q6_MPU,
  HAL_XPU2_LPASS_SENSOR_BLSP_BAM,
  HAL_XPU2_TLMM_XPU_CENTER,
  HAL_XPU2_TLMM_XPU_SOUTH,
  HAL_XPU2_SDC1_SDCC_ICE,
  HAL_XPU2_TITAN_SS_APU,
  HAL_XPU2_CNOC_AOSS_MPU,
  HAL_XPU2_LLCC_BROADCAST_MPU,
  HAL_XPU2_SSC_SDC_MPU,
  HAL_DC_NOC_BROADCAST_MPU,
  HAL_DC_NOC_NON_BROADCAST_MPU,
  HAL_AOSS_MPU,
  HAL_XPU2_BIMC_MPU2,
  HAL_XPU2_BIMC_MPU3,
  HAL_MEMNOC_MS_MPU,
  HAL_XPU2_COUNT,
  HAL_XPU2_SIZE = 0x7FFFFFFF
} HAL_xpu2_XPU2Type;
typedef uint32 HAL_xpu3_ResourceGroupIDType;
typedef struct
{
  uint32 uStartLower;
  uint32 uStartUpper;
  uint32 uEndLower;
  uint32 uEndUpper;
} HAL_xpu3_ResourceGroupAddrType;
typedef enum
{
  HAL_XPU2_CONFIG_SECURE = 0x0,
  HAL_XPU2_CONFIG_NON_SECURE = 0x1,
  HAL_XPU2_CONFIG_MODEM = 0x2,
  HAL_XPU2_CONFIG_SP = 0x3,
  HAL_XPU2_CONFIG_UNOWNED = 0x4,
  HAL_XPU2_CONFIG_COUNT,
  HAL_XPU2_CONFIG_SIZE = 0x7FFFFFFF,
} HAL_xpu3_ConfigType;
typedef struct
{
  bool32 bMultiVMID;
  union
  {
    struct
    {
      uint32 auVMID[((31/32) + 1)];
      uint32 auVMIDPerm[((31/16) + 1)];
    } multi;
  } Vmid_Type;
} HAL_xpu3_ResourceGroupPermissionType;
typedef struct
{
  boolean bSecureClientROEn : 0x2 +1;
  boolean bNonSecureClientROEn : 0x2 +1;
  boolean bNonSecureClientWOEn : 0x2 +1;
  boolean bSecureClientWOEn : 0x2 +1;
} HAL_xpu3_ResourceGroupClientPermType;
typedef struct
{
  HAL_xpu3_ResourceGroupAddrType resAddr;
  HAL_xpu3_ResourceGroupPermissionType resPerm;
  HAL_xpu3_ResourceGroupClientPermType clientPerm;
  HAL_xpu3_ConfigType eConfig;
} HAL_xpu3_ResourceGroupConfigType;
typedef struct
{
  HAL_xpu3_ResourceGroupPermissionType *pUnmapRGPerm;
  boolean bEnableVmidCheck : 1;
  boolean bEnablexPROTNSCheck : 1;
  boolean bSecureConfigWriteDisable : 1;
  boolean bMSAClientAccessControl : 1;
  boolean bSPClientAccessControl : 1;
  boolean bUnmapMemoryClientROEn : 0x2 +1;
  boolean bUnmapMemoryClientWOEn : 0x2 +1;
  boolean bUnmapMemoryOwnerAPPS :1;
  boolean bUnmapMemoryOwnerSP :1;
  boolean bUnmapMemoryOwnerMSA:1;
  boolean bUnmapMemoryOwnerSecure :1;
  boolean bUnmapMemorySecureROE :1;
  boolean bUnmapMemorySecureWOE :1;
} HAL_xpu3_DefaultxPU3ConfigType;
typedef enum
{
  HAL_XPU2_ERROR_O_CFG_RPT_EN = 0x1,
  HAL_XPU2_ERROR_O_CLIENT_RPT_EN = 0x2,
  HAL_XPU2_ERROR_O_CFG_INT_EN = 0x4,
  HAL_XPU2_ERROR_O_CLIENT_INT_EN = 0x8,
  HAL_XPU2_ERROR_O_SIZE = 0x7FFFFFFF
} HAL_xpu3_ErrorOptionsType;
typedef uint32 HAL_xpu3_ErrorOptionsConfigType;
typedef enum
{
  HAL_XPU2_DEVICE_RPU = 0,
  HAL_XPU2_DEVICE_APU = 1,
  HAL_XPU2_DEVICE_MPU = 2,
  HAL_XPU2_DEVICE_COUNT,
  HAL_XPU2_DEVICE_DNE = 0x7FFFFFFE,
  HAL_XPU2_DEVICE_SIZE = 0x7FFFFFFF,
} HAL_xpu3_XPUDeviceType;
typedef struct
{
  HAL_xpu3_XPUDeviceType eXpu2Type;
  uint32 uResourceGroupCount;
  uint32 uNumVMID;
  uint32 uResourceGroupRes;
  uint64 uResourceGroupResMax;
  boolean bMultiVMID : 1;
  boolean bFullPerm : 1;
  boolean bQADSupport : 0x2 +1;
  boolean bVMID_ACR : 1;
  const char *szXpu2Name;
} HAL_xpu3_XPUDeviceParamsType;
typedef enum
{
  HAL_XPU2_ERROR_F_CONFIG_PORT = 0x1,
  HAL_XPU2_ERROR_F_CLIENT_PORT = 0x2,
  HAL_XPU2_ERROR_F_MULTIPLE = 0x4,
  HAL_XPU2_ERROR_F_MULTI_CONFIG_PORT = 0x8,
  HAL_XPU2_ERROR_F_MULTI_CLIENT_PORT = 0x10,
  HAL_XPU2_ERROR_FLAGS_SIZE = 0x7FFFFFFF
} HAL_xpu3_ErrorFlagsType;
typedef uint32 HAL_xpu3_ErrorFlagsConfigType;
typedef enum
{
  HAL_XPU2_BUS_F_ERROR_AC = 0x1,
  HAL_XPU2_BUS_F_ERROR_DCD = 0x2,
  HAL_XPU2_BUS_F_ASHARED = 0x4,
  HAL_XPU2_BUS_F_AINNERSHARED = 0x8,
  HAL_XPU2_BUS_F_APRIV = 0x10,
  HAL_XPU2_BUS_F_APROTNS = 0x20,
  HAL_XPU2_BUS_F_AINST = 0x40,
  HAL_XPU2_BUS_F_AWRITE = 0x80,
  HAL_XPU2_BUS_F_AOOO = 0x100,
  HAL_XPU2_BUS_F_AFULL = 0x200,
  HAL_XPU2_BUS_F_ABURST = 0x400,
  HAL_XPU2_BUS_F_BURSTLEN = 0x800,
  HAL_XPU2_BUS_F_ARDALLOCATE = 0x1000,
  HAL_XPU2_BUS_F_AEXCLUSIVE = 0x2000,
  HAL_XPU2_BUS_F_ARDBEADNDXEN = 0x4000,
  HAL_XPU2_BUS_F_AMSSSELFAUTH = 0x8000,
  HAL_XPU2_BUS_F_SAVERESTORE_IN_PROG = 0x10000,
  HAL_XPU2_BUS_F_MSA_RG_MATCH = 0x20000,
  HAL_XPU2_BUS_F_SECURE_RG_MATCH = 0x40000,
  HAL_XPU2_BUS_F_NONSECURE_RG_MATCH = 0x80000,
  HAL_XPU2_BUS_F_SP_RG_MATCH = 0x100000,
  HAL_XPU2_BUS_F_SP = 0x200000,
  HAL_XPU2_BUS_FLAGS_SIZE = 0x7FFFFFFF
} HAL_xpu3_BusErrorFlagsType;
typedef uint32 HAL_xpu3_BusErrorFlagsMaskType;
typedef struct
{
  HAL_xpu3_ErrorFlagsConfigType uErrorFlags;
  HAL_xpu3_BusErrorFlagsMaskType uBusFlags;
  uint32 uPhysicalAddressLower32;
  uint32 uPhysicalAddressUpper32;
  uint32 uMasterId;
  uint32 uAVMID;
  uint32 uATID;
  uint32 uABID;
  uint32 uAPID;
  uint32 uALen;
  uint32 uASize;
  uint32 uAMemType;
  uint32 uAPReqPriority;
} HAL_xpu3_ErrorType;
HAL_xpu3_Status HAL_xpu3_Init
  ( HAL_xpu2_XPU2Type eXpu2,
    const HAL_xpu3_DefaultxPU3ConfigType *pDefaultConfig,
    char ** ppszVersion );
HAL_xpu3_Status HAL_xpu3_RestoreSecureConfig ( HAL_xpu2_XPU2Type eXpu2 );
HAL_xpu3_Status HAL_xpu3_Reset ( HAL_xpu2_XPU2Type eXpu2 ) ;
HAL_xpu3_Status HAL_xpu3_ConfigAccessPermissions
  ( HAL_xpu2_XPU2Type eXpu2,
    const HAL_xpu3_ResourceGroupPermissionType *pAccessConfig );
HAL_xpu3_Status HAL_xpu3_ConfigUnmappedPartitionPermissions
  ( HAL_xpu2_XPU2Type eXpu2,
    const HAL_xpu3_ResourceGroupPermissionType *pUnmapRGPerm );
void HAL_xpu3_EnableAPPSAuth( HAL_xpu2_XPU2Type eXpu2 );
void HAL_xpu3_EnableMSSSelfAuth( HAL_xpu2_XPU2Type eXpu2 );
void HAL_xpu3_EnableSPAuth( HAL_xpu2_XPU2Type eXpu2 );
HAL_xpu3_Status HAL_xpu3_EnableMPUPartition
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ResourceGroupIDType uResID );
HAL_xpu3_Status HAL_xpu3_DisableMPUPartition
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ResourceGroupIDType uResID );
HAL_xpu3_Status HAL_xpu3_ConfigResourceGroup
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ResourceGroupIDType uResID,
    const HAL_xpu3_ResourceGroupConfigType *pResConfig );
HAL_xpu3_Status HAL_xpu3_ConfigErrorReporting
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ConfigType eConfig,
    HAL_xpu3_ErrorOptionsConfigType errOpt );
void HAL_xpu3_GetDeviceParameters( HAL_xpu2_XPU2Type eXpu2,
                                   HAL_xpu3_XPUDeviceParamsType *pDevParams );
void HAL_xpu3_GetAccessPermissions
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ResourceGroupPermissionType *pAccessConfig );
void HAL_xpu3_GetUnmappedPartitionPermissions
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ResourceGroupPermissionType *pUnmapRGPerm );
void HAL_xpu3_GetResourceGroupConfig
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ResourceGroupIDType uResID,
    HAL_xpu3_ResourceGroupConfigType *pResConfig );
void HAL_xpu3_GetErrorReportingConfig
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ConfigType eConfig,
    HAL_xpu3_ErrorOptionsConfigType *pErrConfig );
bool32 HAL_xpu3_IsError ( HAL_xpu2_XPU2Type eXpu2,
                                   HAL_xpu3_ConfigType eConfig );
void HAL_xpu3_GetError( HAL_xpu2_XPU2Type eXpu2,
                        HAL_xpu3_ConfigType eConfig,
                        HAL_xpu3_ErrorType *pError );
HAL_xpu3_Status HAL_xpu3_ClearError( HAL_xpu2_XPU2Type eXpu2,
                                     HAL_xpu3_ConfigType eConfig );
HAL_xpu3_Status HAL_xpu3_ClearErrorExt( HAL_xpu2_XPU2Type eXpu2,
                                        HAL_xpu3_ConfigType eConfig,
                                        HAL_xpu3_ErrorFlagsConfigType uErrorFlags );
HAL_xpu3_Status HAL_xpu3_GetResourceGroupOwnerInfo
(
  HAL_xpu2_XPU2Type eXpu2,
  uint32 *puResIDMaskPtr,
  uint32 size,
  uint32 *pNumOwnership
);
bool32 HAL_xpu3_IsError_NoLock( HAL_xpu2_XPU2Type eXpu2,
                                HAL_xpu3_ConfigType eConfig );
HAL_xpu3_Status HAL_xpu3_ClearError_NoLock( HAL_xpu2_XPU2Type eXpu2,
                                            HAL_xpu3_ConfigType eConfig );
void HAL_xpu3_GetError_NoLock( HAL_xpu2_XPU2Type eXpu2,
                               HAL_xpu3_ConfigType eConfig,
                               HAL_xpu3_ErrorType *pError );
void HAL_xpu3_GetDeviceParameters_NoLock( HAL_xpu2_XPU2Type eXpu2,
                                          HAL_xpu3_XPUDeviceParamsType *pDevParams );
void HAL_xpu3_GetResourceGroupConfig_NoLock
  ( HAL_xpu2_XPU2Type eXpu2,
    HAL_xpu3_ResourceGroupIDType uResID,
    HAL_xpu3_ResourceGroupConfigType *pResConfig );
HAL_xpu3_Status HAL_xpu3_GetResourceGroupOwnerInfo_NoLock
(
  HAL_xpu2_XPU2Type eXpu2,
  uint32 *puResIDMaskPtr,
  uint32 size,
  uint32 *pNumOwnership
);
HAL_xpu3_Status HAL_xpu3_ClearRG_Owner(HAL_xpu2_XPU2Type eXpu2, uint32 resid);
HAL_xpu3_Status HAL_xpu3_ResetRG_addr(HAL_xpu2_XPU2Type eXpu2);
HAL_xpu3_Status HAL_xpu3_ConfigUnmapPartition
(
  HAL_xpu2_XPU2Type eXpu2,
  const HAL_xpu3_DefaultxPU3ConfigType *pDefaultConfig
);
<driver name="NULL">
  <global_def>
    <var_seq name="tlmm_xpu_pins" type=0x00000003>
      0xFFFFFFFF, end
    </var_seq>
    <var_seq name="tlmm_xpu_sections" type=0x00000003>
      HAL_XPU2_TLMM_XPU_SOUTH,
      HAL_XPU2_TLMM_XPU_CENTER,
      HAL_XPU2_TLMM_XPU_NORTH,
      end
    </var_seq>
    <var_seq name="tlmm_tile_bases" type=0x00000003>
      (0x03000000 + 0x00100000),
      (0x03000000 + 0x00500000),
      (0x03000000 + 0x00900000),
      end
    </var_seq>
  </global_def>
  <device id="/tlmm/configs">
    <props name="blsp_spi_mosi[1]" type="TLMMGpioIdType">{0, 1}</props>
    <props name="blsp_spi_miso[1]" type="TLMMGpioIdType">{1, 1}</props>
    <props name="blsp_spi_cs_n[1]" type="TLMMGpioIdType">{2, 1}</props>
    <props name="blsp_spi_clk[1]" type="TLMMGpioIdType">{3, 1}</props>
    <props name="blsp_spi_mosi[2]" type="TLMMGpioIdType">{4, 1}</props>
    <props name="blsp_spi_miso[2]" type="TLMMGpioIdType">{5, 1}</props>
    <props name="blsp_spi_cs_n[2]" type="TLMMGpioIdType">{6, 1}</props>
    <props name="blsp_spi_clk[2]" type="TLMMGpioIdType">{7, 1}</props>
    <props name="blsp_spi_mosi[3]" type="TLMMGpioIdType">{8, 1}</props>
    <props name="blsp_spi_miso[3]" type="TLMMGpioIdType">{9, 1}</props>
    <props name="blsp_spi_cs_n[3]" type="TLMMGpioIdType">{10, 1}</props>
    <props name="blsp_spi_clk[3]" type="TLMMGpioIdType">{11, 1}</props>
    <props name="blsp_spi_mosi[4]" type="TLMMGpioIdType">{12, 1}</props>
    <props name="blsp_spi_miso[4]" type="TLMMGpioIdType">{13, 1}</props>
    <props name="blsp_spi_cs_n[4]" type="TLMMGpioIdType">{14, 1}</props>
    <props name="blsp_spi_clk[4]" type="TLMMGpioIdType">{15, 1}</props>
    <props name="blsp_spi_mosi[5]" type="TLMMGpioIdType">{16, 2}</props>
    <props name="blsp_spi_miso[5]" type="TLMMGpioIdType">{17, 2}</props>
    <props name="blsp_spi_cs_n[5]" type="TLMMGpioIdType">{18, 2}</props>
    <props name="blsp_spi_clk[5]" type="TLMMGpioIdType">{19, 2}</props>
    <props name="blsp_spi_mosi[6]" type="TLMMGpioIdType">{20, 1}</props>
    <props name="blsp_spi_miso[6]" type="TLMMGpioIdType">{21, 1}</props>
    <props name="blsp_spi_cs_n[6]" type="TLMMGpioIdType">{22, 1}</props>
    <props name="blsp_spi_clk[6]" type="TLMMGpioIdType">{23, 1}</props>
    <props name="blsp_spi_mosi[7]" type="TLMMGpioIdType">{24, 1}</props>
    <props name="blsp_spi_miso[7]" type="TLMMGpioIdType">{25, 1}</props>
    <props name="blsp_spi_cs_n[7]" type="TLMMGpioIdType">{26, 1}</props>
    <props name="blsp_spi_clk[7]" type="TLMMGpioIdType">{27, 1}</props>
    <props name="blsp_spi_mosi8_mira" type="TLMMGpioIdType">{28, 1}</props>
    <props name="blsp_spi_miso8_mira" type="TLMMGpioIdType">{29, 1}</props>
    <props name="blsp_spi_cs_n8_mira" type="TLMMGpioIdType">{30, 1}</props>
    <props name="blsp_spi_cs1_n[3]" type="TLMMGpioIdType">{30, 4}</props>
    <props name="blsp_spi_clk8_mira" type="TLMMGpioIdType">{31, 1}</props>
    <props name="blsp_spi_mosi8_mirb" type="TLMMGpioIdType">{40, 3}</props>
    <props name="blsp_spi_miso8_mirb" type="TLMMGpioIdType">{41, 3}</props>
    <props name="blsp_spi_clk8_mirb" type="TLMMGpioIdType">{44, 3}</props>
    <props name="blsp_spi_cs1_n[1]" type="TLMMGpioIdType">{46, 1}</props>
    <props name="blsp_spi_cs_n8_mirb" type="TLMMGpioIdType">{52, 2}</props>
    <props name="blsp_spi_cs1_n[8]" type="TLMMGpioIdType">{64, 2}</props>
    <props name="blsp_spi_cs2_n[3]" type="TLMMGpioIdType">{65, 2}</props>
    <props name="blsp_spi_cs2_n[8]" type="TLMMGpioIdType">{76, 1}</props>
    <props name="blsp_i2c_sda[1]" type="TLMMGpioIdType">{2, 3}</props>
    <props name="blsp_i2c_scl[1]" type="TLMMGpioIdType">{3, 3}</props>
    <props name="blsp_i2c_sda[2]" type="TLMMGpioIdType">{6, 2}</props>
    <props name="blsp_i2c_scl[2]" type="TLMMGpioIdType">{7, 2}</props>
    <props name="blsp_i2c_sda[3]" type="TLMMGpioIdType">{10, 2}</props>
    <props name="blsp_i2c_scl[3]" type="TLMMGpioIdType">{11, 2}</props>
    <props name="blsp_i2c_sda[4]" type="TLMMGpioIdType">{14, 2}</props>
    <props name="blsp_i2c_scl[4]" type="TLMMGpioIdType">{15, 2}</props>
    <props name="blsp_i2c_sda[5]" type="TLMMGpioIdType">{18, 3}</props>
    <props name="blsp_i2c_scl[5]" type="TLMMGpioIdType">{19, 3}</props>
    <props name="blsp_i2c_sda[6]" type="TLMMGpioIdType">{22, 3}</props>
    <props name="blsp_i2c_scl[6]" type="TLMMGpioIdType">{23, 3}</props>
    <props name="blsp_i2c_sda[7]" type="TLMMGpioIdType">{26, 3}</props>
    <props name="blsp_i2c_scl[7]" type="TLMMGpioIdType">{27, 3}</props>
    <props name="BLSP_I2C_SDA8_MIRA" type="TLMMGpioIdType">{30, 3}</props>
    <props name="BLSP_I2C_SCL8_MIRA" type="TLMMGpioIdType">{31, 3}</props>
    <props name="BLSP_I2C_SCL8_MIRB" type="TLMMGpioIdType">{44, 4}</props>
    <props name="BLSP_I2C_SDA8_MIRB" type="TLMMGpioIdType">{52, 3}</props>
    <props name="tlmm_gpio_test_pin" type="TLMMGpioIdType">{8, 1}</props>
    <props name="blsp_uart_tx[1]" type="TLMMGpioIdType">{0, 2}</props>
    <props name="blsp_uart_rx[1]" type="TLMMGpioIdType">{1, 2}</props>
    <props name="blsp_uart_cts_n[1]" type="TLMMGpioIdType">{2, 2}</props>
    <props name="blsp_uart_rfr_n[1]" type="TLMMGpioIdType">{3, 2}</props>
    <props name="blsp_uart_tx[5]" type="TLMMGpioIdType">{16, 1}</props>
    <props name="blsp_uart_rx[5]" type="TLMMGpioIdType">{17, 1}</props>
    <props name="blsp_uart_cts_n[5]" type="TLMMGpioIdType">{18, 1}</props>
    <props name="blsp_uart_rfr_n[5]" type="TLMMGpioIdType">{19, 1}</props>
    <props name="blsp_uart_tx[2]" type="TLMMGpioIdType">{20, 2}</props>
    <props name="blsp_uart_rx[2]" type="TLMMGpioIdType">{21, 2}</props>
    <props name="blsp_uart_cts_n[2]" type="TLMMGpioIdType">{22, 2}</props>
    <props name="blsp_uart_rfr_n[2]" type="TLMMGpioIdType">{23, 2}</props>
    <props name="BLSP_UART_TX6_MIRA" type="TLMMGpioIdType">{24, 2}</props>
    <props name="BLSP_UART_RX6_MIRA" type="TLMMGpioIdType">{25, 2}</props>
    <props name="BLSP_UART_CTS_N6_MIRA" type="TLMMGpioIdType">{26, 2}</props>
    <props name="BLSP_UART_RFR_N6_MIRA" type="TLMMGpioIdType">{27, 2}</props>
    <props name="BLSP_UART_TX6_MIRB" type="TLMMGpioIdType">{28, 2}</props>
    <props name="BLSP_UART_RX6_MIRB" type="TLMMGpioIdType">{29, 2}</props>
    <props name="BLSP_UART_CTS_N6_MIRB" type="TLMMGpioIdType">{30, 2}</props>
    <props name="BLSP_UART_RFR_N6_MIRB" type="TLMMGpioIdType">{31, 2}</props>
    <props name="tlmm_xpu_protection" type=0x00000014>
      tlmm_xpu_pins
    </props>
    <props name="tlmm_xpu" type=0x00000014>
      tlmm_xpu_sections
    </props>
    <props name="tlmm_tiles" type=0x00000014>
      tlmm_tile_bases
    </props>
    <props name="tlmm_num_tiles" type=0x00000002>
      3
    </props>
    <props name="tlmm_base" type=0x00000002>
      0x01000000
    </props>
    <props name="tlmm_offset" type=0x00000002>
      0x00010000
    </props>
    <props name="tlmm_total_gpio" type=0x00000002>
      114
    </props>
  </device>
</driver>

</module>
</dal>
