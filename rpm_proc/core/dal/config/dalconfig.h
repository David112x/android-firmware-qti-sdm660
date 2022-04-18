
#ifndef DAL_CONFIG_H
#define DAL_CONFIG_H

#if !defined (DAL_NATIVE_PLATFORM)
#define DAL_BUILD_MULTI_PROC_IMAGE
#endif

#if defined (FEATURE_WINCE) || defined (WINSIM)
   //dont include customer.h for WM
   //microsoft compiler directiver for align
   #define DAL_ALIGN(bits) __declspec(align(bits))
#elif defined (FEATURE_QDSP)
   //dont include customer.h for QDSP MM builds
   //GCC compiler directiver for align
   #define DAL_ALIGN(bits) __attribute__ ((aligned (bits)))
#elif defined (DAL_NATIVE_PLATFORM)
   //dont include customer.h for DAL Native build
   //rvct22 compiler directive for align
   #define DAL_ALIGN(bits) __align(bits)
#else
   //include for modem env
   #include "customer.h"
   //rvct22 compiler directiver for align
   #define DAL_ALIGN(bits) __align(bits)
#endif

#include "DALPropDef.h"

#ifdef ARCH_QDSP6 /* QDSP6 */
   #define DAL_CONFIG_ARCH       DAL_CONFIG_ARCH_QDSP6_V2
#else
   #ifdef __TARGET_CPU_ARM926EJ_S /* ARM9 */
      #define DAL_CONFIG_ARCH    DAL_CONFIG_ARCH_ARM_V5
   #elif defined (__TARGET_CPU_ARM7TDMI_S) /*ARM7*/
      #define DAL_CONFIG_ARCH DAL_CONFIG_ARCH_ARM_V4
   #else /* ARM11 */
      #define DAL_CONFIG_ARCH    DAL_CONFIG_ARCH_ARM_V7
   #endif
#endif

/* define the OS env for apps processor */
#if defined (FEATURE_APPS_IMAGE_WINMOB) || defined (FEATURE_WINCE)
   #define DAL_CONFIG_HLOS_ENV DALPROP_HLOS_ENV_WM
   #if defined (FEATURE_DAL_APPS_WM7)
   //WM-7
      #define DAL_CONFIG_HLOS_WM_VER DALPROP_HLOS_ENV_WM7
   #else
   //Assume WM-6
      #define DAL_CONFIG_HLOS_WM_VER DALPROP_HLOS_ENV_WM6
   #endif
#elif defined (FEATURE_NATIVELINUX)
   #define DAL_CONFIG_HLOS_ENV DALPROP_HLOS_ENV_LINUX
#elif defined (DAL_NATIVE_PLATFORM)
   #define DAL_CONFIG_HLOS_ENV DALPROP_MOD_ENV_QCOM
#elif !defined (FEATURE_QDSP) /* QDSP images must remain OS agnostic */
   #define DAL_CONFIG_HLOS_ENV DALPROP_HLOS_ENV_BREW
#endif

#endif /* DAL_CONFIG_H */

