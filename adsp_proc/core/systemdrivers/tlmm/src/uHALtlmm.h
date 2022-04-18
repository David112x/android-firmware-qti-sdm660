#ifndef UHALTLMM_H
#define UHALTLMM_H

/*===============================================================================

                    T O P  L E V E L  M O D E  M U X  (TLMM) 
              H A R D W A R E   A B S T R A C T I O N   L A Y E R

FILE:         HALtlmm.h

DESCRIPTION:  
              This contains externalized TLMM HAL code.  Functions that
              are prototyped here are available to the TLMM driver.

=================================================================================

                             Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/tlmm/src/uHALtlmm.h#1 $

when       who     what, where, why
--------   ---     --------------------------------------------------------------
03/27/15   dcf     Created 

=================================================================================
             Copyright � 2015 QUALCOMM Technologies, Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
=================================================================================
*/

#include "HALcomdef.h"

/*===============================================================================
  This enumeration is used by the driver to request a particular port to be
  configured.
  -----------------------------------------------------------------------------*/

typedef uint32 uHAL_tlmm_PortType;

typedef enum
{
  HAL_TLMM_NO_PULL   = 0,
  HAL_TLMM_PULL_DOWN = 1,
  HAL_TLMM_KEEPER    = 2,
  HAL_TLMM_PULL_UP   = 3
}uHAL_tlmm_PullType;

typedef enum
{
  HAL_TLMM_INPUT  = 0,
  HAL_TLMM_OUTPUT = 1,
}uHAL_tlmm_DirType;

typedef enum
{
  HAL_TLMM_DRIVE_2MA  = 0,
  HAL_TLMM_DRIVE_4MA  = 1,
  HAL_TLMM_DRIVE_6MA  = 2,
  HAL_TLMM_DRIVE_8MA  = 3,
  HAL_TLMM_DRIVE_10MA = 4,
  HAL_TLMM_DRIVE_12MA = 5,
  HAL_TLMM_DRIVE_14MA = 6,
  HAL_TLMM_DRIVE_16MA = 7
}uHAL_tlmm_DriveType;


/* The enumeration for GPIO value(high or low) type. */
typedef enum
{
    HAL_TLMM_LOW_VALUE  = 0,
    HAL_TLMM_HIGH_VALUE = 1
}uHAL_tlmm_ValueType;

#define HAL_TLMM_OUTPUT_LOW    (HAL_TLMM_LOW_VALUE | 0x2)
#define HAL_TLMM_OUTPUT_HIGH   (HAL_TLMM_HIGH_VALUE | 0x2)

/*
 * The uHAL_tlmm_GpioType is the basic GPIO configuration element.  It 
 * contains information about the configuration of a particular GPIO. 
 */
typedef struct
{
  uint8 nFunc;        /* Function select for a GPIO (0-15). */
  uint8 nDir;         /* Direction select for a GPIO (INPUT/OUTPUT). */
  uint8 nPull;        /* Pull Value (PULL-DOWN, PULL-UP, KEEPER, NO-PULL */
  uint8 nDrive;       /* Drive strength (2-16 mA in even increments). */
}uHAL_tlmm_GpioType;



typedef struct
{
  uint32                nNumGpio;
  uint32                nBaseAddress;

}uHAL_tlmm_InitType;


#define HAL_GPIO_NUMBER(config) (((config)&0x3FF0)>>4)
#define HAL_GPIO_OUTVAL(config) (((config)&0x1E00000)>>0x15)
#define HAL_DRVSTR_VAL(config) (((config)&0x1E0000)>>17)
#define HAL_PULL_VAL(config) (((config)&0x18000)>>15)
#define HAL_DIR_VAL(config) (((config)&0x4000)>>14)
#define HAL_FUNC_VAL(config)  ((config)&0xF)


/*===============================================================================
    Function prototypes that are available to the TLMM driver.
  =============================================================================*/
void uHAL_tlmm_Init            ( uHAL_tlmm_InitType* pHALTLMMInit );
void uHAL_tlmm_Reset           ( void );

boolean uHAL_tlmm_ReadGpio     ( uint32 nWhichConfig );

void uHAL_tlmm_WriteGpio       ( uint32 nWhichConfig, boolean bValue );

void uHAL_tlmm_WriteGpioGroup  ( uint32 *nWhichConfigSet, uint32 nWhatSize, boolean nValue );

void uHAL_tlmm_ConfigGpio      ( uint32 nWhichConfig );

void uHAL_tlmm_ConfigPin( uHAL_tlmm_GpioType* pGpio );

void uHAL_tlmm_ConfigGpioGroup ( uint32 *nWhichGpioSet, uint32 nWhatSize );

boolean uHAL_tlmm_GetOutput( uint32 nWhichGpio );

void uHAL_tlmm_GetNumberGpio( uint32* pnNumGpio );

void uHAL_tlmm_SetNumberGpio( uint32 nNumGpio );

void uHAL_tlmm_SetPull( uint32 nGpioNumber, uHAL_tlmm_PullType ePull );

void uHAL_tlmm_SetDirection( uint32 nGpioNumber, uHAL_tlmm_DirType eDirection );

void uHAL_tlmm_SetDirectionGroup( uint32* nWhichConfig, uHAL_tlmm_DirType eDirection );

void uHAL_tlmm_SetDriveStrength( uint32 nGpioNumber, uHAL_tlmm_DriveType eDrive );

void uHAL_tlmm_SetFunction( uint32 nGpioNumber, uint32 nFuncVal );

void uHAL_tlmm_GetConfig( uint32 nGpioNumber, uHAL_tlmm_GpioType* tGpio );

/*
=================================================================================
  INTERFACES DOCUMENTATION - See source files for parameter descriptions.
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_Init ( char ** ppszVersion )

DESCRIPTION
   Does the initializing of the hardware buffers and address structures.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_Reset( void )

DESCRIPTION
   Programs hardware to the reset state.

DEPENDENCIES
  Please describe what need to be done before call this function

RETURN VALUE
  If void is NOT used, please describe what is returned

SIDE EFFECTS
  If you need add this comment
 
=================================================================================  
 
FUNCTION  
  void uHAL_tlmm_ConfigGpio ( uint32 nWhichGpio, uint32 nCfgIdx )

DESCRIPTION
   Configures the specified GPIO to the requested configuration at the
   provided index.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_Save ( void )

DESCRIPTION
   Saves the contents of the GPIO registers.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_Restore( void )

DESCRIPTION
   Restores the state of the GPIO_OUT and GPIO_OE registers.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  uHAL_tlmm_ReadGpio( uint32 nWhichGroup, 
                     uint32 nGpioOffset, 
                     bool *pReturnValue )

DESCRIPTION
   Returns the boolean value read at the register location to the client 
   request.

DEPENDENCIES
    GPIO should be configured to be input before calling this function. 

RETURN VALUE
  Returns the value "HIGH" or "LOW" as a boolean pointer.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_WriteGpio( uint32 nWhichClient, 
                           uint32 nWhichSignal, 
                           bool bValue )

DESCRIPTION
   Writes a high (TRUE) or low (FALSE) value to the specified GPIO

DEPENDENCIES
     The GPIO should be configured to be output before calling this function;
    otherwise, the value written to the GPIO may not take effect.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_WriteGpioGroup( uint32 nWhichConfigSet[], uint16 nWhatSize )

DESCRIPTION
   Outputs the supplied value to a group of GPIOs.  Each GPIO is provided as a 
   combination of GPIO and configuration index pair as defined in the TLMM
   driver BSP.

DEPENDENCIES
     The GPIO should be configured to be output before calling this function;
    otherwise, the value written to the GPIO may not take effect.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
=================================================================================

uHAL_tlmm_ConfigGpio( uint32 nWhichConfig )

Description:
   Configures the selected GPIO to the configuration that specified in the 
   nWhichConfig entry in the TLMM BSP

See Also:

================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_EnableGpio ( uint32 nWhichConfig )

DESCRIPTION
   Enables the GPIO corresponding to the nWhichSignal index for the nWhichClient
   to value before disable was called.  If disable has not
   been called it enables the gpio to the default BSP value.

DEPENDENCIES
  Please describe what need to be done before call this function

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_EnableGpioGroup ( const uint32 nWhichConfigSet, 
                                  uint16 nWhatSize )

DESCRIPTION
   This function enables output operations on the corresponding group of 
   GPIOs.  Its purpose is to provide a mechanism to allow/deny GPIO configuration.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_DisableGpio ( uint32 nWhichGpio )

DESCRIPTION
   Disable operation of nWhichGpio. 

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_DisableGpioGroup ( const uint32 nWhichConfigSet, 
                                   uint16 nWhatSize )

DESCRIPTION
   This function disables output operations on the corresponding group of 
   GPIOs.  Its purpose is to provide a mechanism to allow/deny GPIO 
   configuration.

   DISABLE = 0x1
   ENABLE = 0x0

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_ConfigGpioGroup ( uint32 nWhichGpioSet[], 
                                  uint32 nWhichCfgSet[], 
                                  uint8 size )

DESCRIPTION
   Configures a group of GPIOs based on the supplied input parameters.  Each
   array contains a GPIO/Configuration set, but we extract only the GPIO from
   the first array and the configuration from the second.  This allows GPIO
   groups to be set to several different configurations, such as primary,
   sleep, or default group configuration.

DEPENDENCIES
  Any validity or boundary checking must be done by the calling function.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_ConfigForPowerCollapse

DESCRIPTION
   Configures any registers in preparation for power collapse.

   Note:  Anything settings changed in this function should be restored in 
          the function uHAL_tlmm_RestoreFromPowerCollapse().

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  Register will be set to their low-power settings.
 
================================================================================= 
 
FUNCTION  
  void uHAL_tlmm_RestoreFromPowerCollapse

DESCRIPTION
   Restores any register settings for from power collapse.

   Note:  uHAL_tlmm_ConfigForPowerCollapse() should have been called prior
          to calling this function in order to ensure the buffers are valid.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  Registers are returned to their previous settings.

=================================================================================

FUNCTION  
  void uHAL_tlmm_SelectPort(uHAL_tlmm_PortType ePort)

DESCRIPTION
   Selects the specified port if it is defined.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=================================================================================

FUNCTION  
  void uHAL_tlmm_ConfigKeysense(const uint32 nKeysenseArr[],
                               uint16 nNumKeysense);

DESCRIPTION
   Configures the Keysense register to the GPIOs specified in the driver
   BSP.

DEPENDENCIES
  At this time, assumes keysense GPIOs are contained in one register.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=================================================================================

FUNCTION
  void uHAL_tlmm_SetPort(uHAL_tlmm_PortType ePort, uint32 mask, uint32 value);

DESCRIPTION
   Configures the specified port to the specified value.

DEPENDENCIES
   None.

RETURN VALUE
   None.

SIDE EFFECTS
   None.
 
===============================================================================

FUNCTION  
  void uHAL_tlmm_TristateGpioGroup ( uint32 nWhichGpioSet[], 
                                  uint32 nWhichCfgSet[], 
                                  uint8 size )

DESCRIPTION
   Tristates a group of GPIOs to the given input set of gpio configurations.  

PARAMETERS
   nWhichGpioSet[]  - An array of GPIO configurations to extract the GPIO 
                      numbers to configure.
   nWhichCfgSet[]   - An array of GPIO configurations to extract the GPIO
                      configuration information to set the above GPIOs to.
   nWhatSize        - The size of the first array.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=============================================================================== 
 
FUNCTION  
  void uHAL_tlmm_TristateGpio ( uint32 nWhichConfig )

DESCRIPTION
   Tristate the specified GPIO to the requested configuration at the
   provided index.

PARAMETERS
   Packed configuration data containing GPIO number and configuration info.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=============================================================================== 
 
FUNCTION  
  boolean uHAL_tlmm_GetOutput ( uint32 nWhichGpio )

DESCRIPTION
   Reads the output of a particular GPIO which is configured as a bit-banged
   GPIO (output & function 0)

PARAMETERS
   GPIO number to read from.

DEPENDENCIES
  None.

RETURN VALUE
  TRUE  - Output is currently HIGH.
  FALSE - Output is currently LOW.

SIDE EFFECTS
  None.
 
=============================================================================== 
 
FUNCTION  
  void uHAL_tlmm_GetNumberGpio ( uint32 *nTotalGPIO )

DESCRIPTION
   Retrieves the total number of GPIO for a particular target.

PARAMETERS
   Pointer for the total number of GPIO on the target return value.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
 
===========================================================================

FUNCTION  
  void uHAL_tlmm_SetPull( uint32 nGpioNumber, uHAL_tlmm_PullType nPull )

DESCRIPTION
   Updates the PULL value of a GPIO.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   ePull       - The uHAL_tlmm_PullType value to set to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===========================================================================

FUNCTION  
  void uHAL_tlmm_SetDirection( uint32 nGpioNumber, uHAL_tlmm_DirType nPull )

DESCRIPTION
   Changes the direction of a GPIO.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   eDirection  - The uHAL_tlmm_DirType value to change to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===========================================================================

FUNCTION  
  void uHAL_tlmm_SetDriveStrength( uint32 nGpioNumber, uHAL_tlmm_DriveType nPull )

DESCRIPTION
   Changes the drive strength of a GPIO.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   eDrive      - The uHAL_tlmm_DriveType value to change to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===========================================================================

FUNCTION  
  void uHAL_tlmm_SetFunction( uint32 nGpioNumber, uHAL_tlmm_DriveType nPull )

DESCRIPTION
   Changes the function select of a GPIO.  Only use this API if you know
   what you're doing as HW may enter a bad state if not properly set.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   nFuncVal    - The Function select to set.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===============================================================================*/

#endif /* #ifndef UHALTLMM_H */

