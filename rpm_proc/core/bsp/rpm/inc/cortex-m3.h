#ifndef CORTEX_M3_H
#define CORTEX_M3_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#ifdef __clang__
#include "llvm_compat.h"
#endif
// This structure exposes the Cortex-M3's "System Control Space" registers.
typedef volatile struct
{
  int MasterCtrl;
  int IntCtrlType;
  int Reserved008_00c[2];
  struct
  {
    int Ctrl;
    int Reload;
    int Value;
    int Calibration;
  } SysTick;

  int Reserved020_0fc[(0x100-0x20)/4];

  struct
  {
    int Enable[32];
    int Disable[32];
    int Set[32];
    int Clear[32];
    int Active[64];
    int Priority[64];
  } NVIC;

  int zReserved0x500_0xcfc[(0xd00-0x500)/4];

  int CPUID;
  int IRQControlState;
  unsigned ExceptionTableOffset;
  int AIRC;
  int SysCtrl;
  int ConfigCtrl;
  int SystemPriority[3];
  int SystemHandlerCtrlAndState;
  int ConfigurableFaultStatus;
  int HardFaultStatus;
  int DebugFaultStatus;
  int MemManageAddress;
  int BusFaultAddress;
  int AuxFaultStatus;

  int zReserved0xd40_0xd90[(0xd90-0xd40)/4];        

  struct
  {
    int Type;
    int Ctrl;
    int RegionNumber;
    int RegionBaseAddr;
    int RegionAttrSize;
  } MPU;
} SCS_t;

typedef volatile struct
{
    int SoftwareTriggerInterrupt;
} STIR_t;

#define SCS (*((SCS_t*)(0xE000E000)))
#define STIR (*((STIR_t*)(0xE000EF00)))

#define TRIGGER_NMI() do { SCS.IRQControlState = 0x80000000; } while(0);

typedef enum
{
    RISING_EDGE,
    FALLING_EDGE,
    LEVEL_HIGH,
    LEVEL_LOW,
} interrupt_config;

typedef void (*isr_type)(void) __irq;

void interrupt_set_isr(unsigned num, isr_type isr);
void interrupt_configure(unsigned num, interrupt_config config);
void interrupt_set_priority(unsigned num, unsigned priority);
void interrupt_soft_trigger(unsigned num);

void interrupt_enable(unsigned num);
void interrupt_enable_no_clear(unsigned num);
void interrupt_disable(unsigned num); 
void interrupt_clear(unsigned num);      
bool interrupt_is_pending(unsigned num); 

#ifdef __clang__
#define __schedule_barrier() __asm__("": : :"memory");
#else 
	register unsigned _ipsr __asm("ipsr");
#endif

static __forceinline unsigned interrupt_current_isr()
{
#ifdef __clang__
  return __builtin_arm_rsr("IPSR") - 0x10;
#else
    return (_ipsr - 0x10);
#endif
}

bool is_any_interrupt_pending(void);
static void memory_barrier(void)
{
    //disable instruction re-ordering to ensure memory consistency.
    __schedule_barrier();
    // Some use cases might only require dmb, but until such a case is
    // identified, prefer the stronger dsb.
    __dsb(0xf);
}

#ifndef __clang__
register unsigned _basepri __asm("basepri");
#endif
static __forceinline void set_basepri(unsigned value)
{
#ifdef __clang__
  __builtin_arm_wsr("BASEPRI", value);
#else
  _basepri = value;
#endif
}

static __forceinline unsigned get_basepri(void)
{
#ifdef __clang__
  return __builtin_arm_rsr("BASEPRI");
#else
  return _basepri;
#endif
}

#ifdef __cplusplus
}
#endif

#endif // CORTEX_M3_H

