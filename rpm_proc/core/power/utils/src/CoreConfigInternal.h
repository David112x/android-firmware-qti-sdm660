#ifndef CORECONFIGINTERNAL_H
#define CORECONFIGINTERNAL_H
/*=============================================================================
  FILE:         CoreConfigInternal.h
  
  OVERVIEW:     This file provides the internal implementation of the abstract
                configuration reader/writer.
 
                Copyright (c) 2010 Qualcomm Technologies Incorporated.
                All Rights Reserved.
                Qualcomm Confidential and Proprietary
  $Header: //components/rel/rpm.bf/1.8/core/power/utils/src/CoreConfigInternal.h#1 $
=============================================================================*/
#include "CoreConfig.h"
/* ==================================================================
                  GLOBAL TYPE DEFINITIONS
   ================================================================== */              
/**
 * CoreConfigVtable 
 *  
 * @brief Provides pointers to the functions to call to do the 
 *        various operations that are supported by the
 *        CoreConfig subsystem.
 */
typedef struct CoreConfigVtable
{
  unsigned int ( *ReadUint32 )( CoreConfigHandle config, 
                                char *section, char *key,
                                unsigned int *value );
  unsigned int ( *ReadString )( CoreConfigHandle config,
                                char *section, char *key,
                                char *string, unsigned int *size );
} CoreConfigVtable;
/**
 * CoreConfig 
 *  
 * @brief Provides the base class that should be used by other 
 *        subsystems that implement the functions in the vector
 *        table.
 */
typedef struct CoreConfig
{
  CoreConfigVtable vtable;
} CoreConfig;
#endif /* CORECONFIGINTERNAL_H */
