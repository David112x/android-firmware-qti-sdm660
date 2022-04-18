#ifndef LLVM_COMPAT_H
#define LLVM_COMPAT_H

#ifdef __clang__
#define __irq __attribute__((interrupt("IRQ")))
#define __weak __attribute__((weak))
#define __asm  __attribute__((naked))
#define __packed __attribute__((packed))
#define __forceinline __attribute__((always_inline))
#define __pure __attribute__((pure))
#define __dsb(x) __builtin_arm_dsb(x)
#define __isb(x) __builtin_arm_isb(x)
#define __clz(x) __builtin_clz(x)
#define __return_address() __builtin_return_address(0)
#define __value_in_regs
static inline unsigned int __rbit(unsigned int val) {
    int ret;
      __asm__("rbit %[Rd], %[Rs]" : [Rd] "=r"(ret) : [Rs] "r" (val));
        return ret;
}
#endif


#endif
