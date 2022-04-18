/*===========================================================================
                          M M   W r a p p e r
                    f o r   M M   D e b u g   M s g

*//** @file MMDebugMsg.c
  This file defines a methods that can be used to output debug messages

Copyright (c) 2012,2017-2019 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
*//*========================================================================*/


/*===========================================================================
                             Edit History

$Header: //source/qcom/qct/multimedia2/platform/OSAbstraction/WM/rel/2.0/src/MMDebugMsg.c#1 $

when       who         what, where, why
--------   ---         -------------------------------------------------------
07/19/12   gkapalli    Created file.


============================================================================*/



/*===========================================================================
 Include Files
============================================================================*/
#include <MMDebugMsg.h>
#include "MMMalloc.h"
#include "MMThread.h"
#include <string.h>
#include <stdlib.h>
#include "MMCriticalSection.h"
#include "AEEstd.h"
#include "MMFile.h"
#include <fcntl.h>
#include <cutils/properties.h>
#include <pthread.h>

/* =======================================================================

                DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains definitions for constants, macros, types, variables
and other items needed by this module.

========================================================================== */


#define MAP_SIZE (MSG_SSID_APPS_LAST - MSG_SSID_APPS +1)
#define MMOSAL_CONFIG_BUFFER_SIZE  2048
#define MMOSAL_LOGMASK_CONFIG_FILE "/data/mmosal_logmask.cfg"
#define MMOSAL_LOGMASK_CONFIG_FILE_MEDIASERVER "/data/misc/media/mmosal_logmask.cfg"
#define MMOSAL_VENDOR_LOGMASK_CONFIG_FILE "/data/vendor/mmosal_logmask.cfg"

static int  nMMOSALDebugRefCnt = 0;
//! Use static recursive mutex to avoid race condition if multi cores are used
#ifdef PTHREAD_RECURSIVE_MUTEX_INITIALIZER
pthread_mutex_t mOSALMutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER;
#else
pthread_mutex_t mOSALMutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
#endif
static int ssidMaskMap[MAP_SIZE];

/* =======================================================================
**                        Class & Function Definations
** ======================================================================= */

/**
 * Resets the logmask map
 *
 * @return None
 */
static void resetMaskMap()
{
    /*  Default bit mask. Error and Fatal are enabled.
    0 0 1 1 1 1 1 1 <- bit mask
        D F E H M L (Debug, Fatal, Error, High, Medium, Low)
    0 0 0 1 1 1 0 0 default priority*/
    int index;
    for(index = 0;index < MAP_SIZE; ++index)
    {
        //Don't reset the mask if it's already been initialized
      if(!(ssidMaskMap[index] & MM_MSG_MASK_INIT))
         ssidMaskMap[index] = 24;
    }
}

/**
 * Initializes the Diag Interface
 *
 * @return 0 value on success else failure
 */
int MM_Debug_Initialize()
{
  int res=1;
  //! Lock the function using static Mutex
  res = pthread_mutex_lock(&mOSALMutex);
  if (0 != res)
  {
    LOGE("Mutex Lock failed in Init, %d", res);
  }

  /* Below counter will help to check whether mask is already updated or not.
     It is not required to execute same config file multiple times. */
  if (nMMOSALDebugRefCnt == 0)
  {
    char MMOSALDebugConfig[MMOSAL_CONFIG_BUFFER_SIZE+1];
    MM_HANDLE nMMOSALDebugConfigFile = NULL;
    size_t pnBytesRead = 0;

    resetMaskMap();
    MMOSALDebugConfig[0] = '\0';

    /*
     * To keep the config file path location backward compatible with other domains like
     * WFD, first attempt is to read from MMOSAL_LOGMASK_CONFIG_FILE (path loc is /data/)
     * If file open or read permission issues in above location then read from
     * MMOSAL_LOGMASK_CONFIG_FILE_MEDIASERVER (path loc is /data/misc/media) which is
     * the partition location that media server process should use.
     */

    if (GetContext() == OSAL_SYS_CTX)
      res = MM_File_Create(MMOSAL_LOGMASK_CONFIG_FILE, MM_FILE_CREATE_R, &nMMOSALDebugConfigFile);
    else
      res = MM_File_Create(MMOSAL_VENDOR_LOGMASK_CONFIG_FILE, MM_FILE_CREATE_R, &nMMOSALDebugConfigFile);

    if (res == 0)
    {
      res = MM_File_Read(nMMOSALDebugConfigFile, MMOSALDebugConfig, (size_t)MMOSAL_CONFIG_BUFFER_SIZE,(ssize_t *) &pnBytesRead);
      MM_File_Release(nMMOSALDebugConfigFile);
    }

    if(res != 0)
    {
      LOGE("Open or read fail on /data/mmosal_logmask.cfg. Possible permission denied issue. Looking for /data/misc/media/mmosal_logmask.cfg");
      if (GetContext() == OSAL_SYS_CTX)
        res = MM_File_Create(MMOSAL_LOGMASK_CONFIG_FILE_MEDIASERVER, MM_FILE_CREATE_R, &nMMOSALDebugConfigFile);
      if (res == 0)
      {
        res = MM_File_Read(nMMOSALDebugConfigFile, MMOSALDebugConfig, (size_t)MMOSAL_CONFIG_BUFFER_SIZE,(ssize_t *) &pnBytesRead);
        MM_File_Release(nMMOSALDebugConfigFile);
      }
    }

    if (res == 0 && pnBytesRead > 0)
    {
      MMOSALDebugConfig[pnBytesRead] = '\0';

      if (std_strlen(MMOSALDebugConfig) > 0)
      {
        char sPattern[32];
        int nLogMask = 0;
        char* pLogMask = NULL;

        (void)std_strlprintf(sPattern, sizeof(sPattern), "LOGMASK = %d", MSG_SSID_APPS_ALL);
        pLogMask = std_strstr(MMOSALDebugConfig, sPattern);
        if (pLogMask)
        {
          int index;
          nLogMask = atoi(pLogMask + std_strlen(sPattern)+1);
          for(index=0;index<MAP_SIZE;index++)
          {
            ssidMaskMap[index]=nLogMask;
            ssidMaskMap[index] |= MM_MSG_MASK_INIT;
          }
        }

        (void)std_strlprintf(sPattern, sizeof(sPattern), "LOGMASK = ");
        pLogMask = std_strstr(MMOSALDebugConfig, sPattern);

        if (pLogMask)
        {
          int nSysID=0;
          do
          {
            pLogMask = pLogMask + std_strlen(sPattern);
            nSysID=atoi(pLogMask)-MSG_SSID_APPS;
            nLogMask = atoi(pLogMask+5);
            if (nSysID >= 0 && nSysID < MAP_SIZE)
            {
             ssidMaskMap[nSysID]=nLogMask;
             ssidMaskMap[nSysID] |= MM_MSG_MASK_INIT;
             pLogMask = std_strstr(pLogMask, sPattern);
            }
          } while (pLogMask!='\0');
        }
      }
    }
  }
  nMMOSALDebugRefCnt++;

  res = pthread_mutex_unlock(&mOSALMutex);
  if (0 != res)
  {
    LOGE("Mutex UnLock failed in Init, %d", res);
  }
  return 0;
}

/**
 * Initializes the Diag Interface for logging based on property read
 *
 * @return 0 value on success else failure
 */
int MM_Debug_Initialize_Ex()
{
  int res=1;
  //! Lock the function using static Mutex
  res = pthread_mutex_lock(&mOSALMutex);
  if (0 != res)
  {
    LOGE("Mutex Lock failed in Init, %d", res);
  }

  resetMaskMap();

  char sValue[PROPERTY_VALUE_MAX] = { (char)0 };
  if (GetContext() == OSAL_SYS_CTX)
    property_get("vendor.debug.mmosal.config", sValue, "");
  int nPropLen = std_strlen(sValue);

  // Checking propertyLength >=6 to make sure that
  //it successfully parse property ex: property value 60xx:Y
  if (nPropLen >= 6)
  {
    int nLenVar = 0;
    int index = 0;
    for (nLenVar = 0; nLenVar < nPropLen; nLenVar++)
    {
      int nTempVar = nLenVar;
      while (sValue[nTempVar] >= '0' && sValue[nTempVar] <= '9')
        nTempVar++;
      if (sValue[nTempVar] != ':')
        break;
      int nSysID = atoi(sValue + nLenVar) - MSG_SSID_APPS;
      nLenVar = ++nTempVar;
      while (sValue[nTempVar] >= '0' && sValue[nTempVar] <= '9')
        nTempVar++;
      if (sValue[nTempVar] != ':' && sValue[nTempVar] != '\0')
        break;
      int nMask = atoi(sValue + nLenVar);
      if (nSysID >= 0 && nSysID < MAP_SIZE && !(nMask >> 6))
      {
        if (nSysID == (int)(MSG_SSID_APPS_ALL - MSG_SSID_APPS))
        {
          for(index = 0; index < MAP_SIZE; index++)
          {
            ssidMaskMap[index] = nMask;
            ssidMaskMap[index] |= MM_MSG_MASK_INIT;
          }
        }
        else
        {
          ssidMaskMap[nSysID] = nMask;
          ssidMaskMap[nSysID] |= MM_MSG_MASK_INIT;
          LOGE("%d %d", nSysID + MSG_SSID_APPS, nMask);
        }
      }
      nLenVar = nTempVar;
    }

    if (nLenVar < nPropLen)
    {
      LOGE("Error parsing mmosal.debug.config at %d", nLenVar);
    }
  }
  nMMOSALDebugRefCnt++;
  res = pthread_mutex_unlock(&mOSALMutex);
  if (0 != res)
  {
    LOGE("Mutex UnLock failed in Init, %d", res);
  }
  return 0;
}
/**
 * De-Initializes the Diag Interface
 *
 * @return 0 value on success else failure
 */
int MM_Debug_Deinitialize()
{
  int res = 1; //failure
  res = pthread_mutex_lock(&mOSALMutex);
  if (0 != res)
  {
    LOGE("Mutex Lock failed in Deinit, %d", res);
  }
  if (nMMOSALDebugRefCnt)
  {
    nMMOSALDebugRefCnt--;
  }
  res = pthread_mutex_unlock(&mOSALMutex);
  if (0 != res)
  {
    LOGE("Mutex UnLock failed in Deinit, %d", res);
  }
  return 0;
}

/**
 * Get the log mask for the specified system ID from the config file
 *
 * @return log mask
 */
int GetLogMask(const unsigned int nSysID)
{
  int nLogMask = 0;

  //MM_CriticalSection_Enter(hMMOSALDebugLock);
  nLogMask = (nMMOSALDebugRefCnt > 0) ? ssidMaskMap[nSysID-6000] : 28;
  //MM_CriticalSection_Leave(hMMOSALDebugLock);

  return nLogMask;
}

/**
 * Get the current context (system/vendor)
 *
 * @return OSAL_VND_CTX if vendor context, OSAL_SYS_CTX otherwise
 */
osal_ctx GetContext()
{
#ifndef _VENDOR_OSAL_
    return OSAL_SYS_CTX;
#else
    return OSAL_VND_CTX;
#endif
}
