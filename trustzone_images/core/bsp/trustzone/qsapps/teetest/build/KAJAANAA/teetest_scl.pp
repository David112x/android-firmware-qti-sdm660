# 1 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/securemsm/trustzone/qsapps/teetest/teetest/build/teetest.ld"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 333 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/local/mnt/workspace/CRMBuilds/TZ.BF.4.0.7.1-00006-S660AAAAANAZT-2_20200329_233006/b/HK11/trustzone_images/core/securemsm/trustzone/qsapps/teetest/teetest/build/teetest.ld" 2
PHDRS {
  CODE_RO PT_LOAD;
  DATA PT_LOAD;
  GOT PT_LOAD;
  REL_H PT_LOAD;
  REL_H_DYN PT_DYNAMIC;
  REL_D PT_LOAD;
}

SECTIONS {
  .text : {
    KEEP(*\teetest_entry.o (TZTEETESTAPPENTRYCODE))
    KEEP(*\teetest_smc.o (TEE_SMC))
    * (.text .text.*)
    * (.rodata)
    * (EXCLUDE_FILE(*metadata.o) .rodata.*)
    *metadata.o (.rodata.str1.1)
  } : CODE_RO

  .sentinel : {
    * (.rodata.sentinel)
  } : CODE_RO

  .metadata_check : {
    *metadata.o (.rodata.*)
    ASSERT_FATAL(SIZEOF(.metadata_check) == 0, "New metadata not accounted for here");
  } : CODE_RO

  .data ALIGN(4096): {
    * (.data TZAPPENTRYSTACK .bss COMMON)
  } : DATA
  RW_DATA : {
    *(RW_DATA)
  }
  SVC_STACK : {
    *(SVC_STACK)
  }
  UND_STACK : {
    *(UND_STACK)
  }
  ABT_STACK : {
    *(ABT_STACK)
  }
  FIQ_STACK : {
    *(FIQ_STACK)
  }
  IRQ_STACK : {
    *(IRQ_STACK)
  }
  L2_TT_MEM : {
    *(L2_TT_MEM)
  }
  .rel.text : {
    *(.rel.text)
  } : DATA
  .rel.rodata : {
    *(.rel.rodata)
  } : DATA
  .data.rel.ro.local : {
    *(.data.rel.ro.local)
  } : DATA
  .data.rel.ro : {
    *(.data.rel.ro)
  } : DATA
  .rel.data : {
    *(.rel.data)
  } : DATA
  .rel.plt : {
    *(.rel.plt)
  } : DATA
  .data.rel : {
    *(.data.rel)
  } : DATA
  .data.rel.local : {
    *(.data.rel.local)
  } : DATA

  TZ_TEE_TEST_APP_HEAP ALIGN(4096): {
    Image$$TZ_TEE_TEST_APP_HEAP$$ZI$$Base = .;
    . = . + 0x18000;
    Image$$TZ_TEE_TEST_APP_HEAP$$ZI$$Limit = .;
  } : DATA

  .got : ALIGN(4096) { *(.got.plt) *(.igot.plt) *(.got) *(.igot) } : GOT

  .dynamic : ALIGN(4096) { *(.dynamic) }: REL_H : REL_H_DYN

  .rel.dyn : ALIGN(4096) {*(.rel.dyn)} : REL_D

  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
  /DISCARD/ : { *(.hash) *(.dynsym) *(.dynstr) *(.ARM.exidx*) *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) *(.init) *(.fini) }
}
