# 1 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/bsp/rpm/target/660/rpm.scl"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 324 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/bsp/rpm/target/660/rpm.scl" 2
# 428 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/bsp/rpm/target/660/rpm.scl"
ENTRY(__main)
PHDRS {
  RPMSS_CODE PT_LOAD;
  RPMSS_DATA PT_LOAD;
}

SECTIONS
{
 CODE_RAM_START 0x0:
 {
  Image$$CODE_RAM$$Base = .;
  KEEP(*\startup.o(.text))
  *(InRoot$$Sections)
 }: RPMSS_CODE

 CODE_RAM_DAL : { *rpm_proc?core?dal*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_DEBUGTOOLS : { *rpm_proc?core?debugtools*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_DEBUGTRACE : { *rpm_proc?core?debugtrace*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_KERNEL : { *rpm_proc?core?kernel*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_MPROC_GLINK : { *rpm_proc?core?mproc?glink*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_MPROC : { *rpm_proc?core?mproc*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_POWER_ACC : { *rpm_proc?core?power?acc*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_POWER_CPR : { *rpm_proc?core?power?cpr*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_POWER_MPM : { *rpm_proc?core?power?mpm*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_POWER_NPA : { *rpm_proc?core?power?npa*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_POWER_RAILWAY : { *rpm_proc?core?power?railway*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_POWER_RPM : { *rpm_proc?core?power?rpm*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_POWER_SLEEP : { *rpm_proc?core?power?sleep*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_POWER_ULOG : { *rpm_proc?core?power?ulog*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_POWER : { *rpm_proc?core?power?*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_SYSDRV_CLOCK : { *rpm_proc?core?systemdrivers?clock*.lib (.text* .rodata*)
        *rpm_proc?core?systemdrivers?hal*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_SYSDRV_ICB : { *rpm_proc?core?systemdrivers?icb*.lib (.text* .rodata*) }: RPMSS_CODE
 CODE_RAM_SYSDRV : { *rpm_proc?core?systemdrivers?*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_SYSDRV_PMIC : { *rpm_proc?core?pmic?pm*.lib (.text* .rodata*) }: RPMSS_CODE
    CODE_RAM_SYSDRV_SPMI : { *rpm_proc?core?pmic?spmi*.lib (.text* .rodata*) }: RPMSS_CODE


 CODE_RAM_DDR : { Image$$CODE_RAM_DDR$$Base =.;
        *(ddr_init_funcs)
        *rpm_proc?core?boot?ddr*.lib (.text* .rodata*) }: RPMSS_CODE


 660_630_xml_DEVCONFIG_CODE : { *660_devcfg*.o (.rodata*) } : RPMSS_CODE



 CODE_RAM_RECLAIM_POOL Image$$CODE_RAM_DDR$$Base + (0x6400) :
 { Image$$CODE_RAM_RECLAIM_POOL$$Base =.;
  *(pm_cram_reclaim_pool)
  *(clk_cram_reclaim_pool)
  *(icb_cram_reclaim_pool)
  *(qdss_cram_reclaim_pool)
  *(railway_cram_reclaim_pool)
  *(rpmserver_cram_reclaim_pool)
  *(sleep_cram_reclaim_pool)
  *(mpm_cram_reclaim_pool)
  *(proxy_cram_reclaim_pool)
  *(glink_cram_reclaim_pool)
  Image$$CODE_RAM_RECLAIM_POOL$$Limit =.; }: RPMSS_CODE


 CODE_RAM_SMEM_INIT_RECLAIM_POOL Image$$CODE_RAM_RECLAIM_POOL$$Limit :
 { Image$$CODE_RAM_SMEM_INIT_RECLAIM_POOL$$Base =.;
  *(smem_init_cram_reclaim_pool)
  Image$$CODE_RAM_SMEM_INIT_RECLAIM_POOL$$Limit =.; }: RPMSS_CODE


 CODE_RAM : { *(.text .text*)
     *(.rodata .rodata*)

     *(ddr_abort_funcs)

CODE_RAM_SIZE=.;
    }: RPMSS_CODE

 INITIAL_CODE_RAM_HEAP : { Image$$INITIAL_CODE_RAM_HEAP$$Base =.; }: RPMSS_CODE


 CODE_RAM_SAVE ((0x0 + 0x28000) - 0x200) : { Image$$CODE_RAM_SAVE$$Base =.;
           *(cram_save_pool)
           Image$$CODE_RAM_SAVE$$Limit =.; }: RPMSS_CODE

 CODE_RAM_SAVE_END Image$$CODE_RAM_SAVE$$Limit : { Image$$CODE_RAM_SAVE_END$$Base=0x27FFF; }: RPMSS_CODE

 ASSERT(CODE_RAM_SIZE <= 0x27FFF, "RPMSS_CODE oversized");



  IMAGE_INFO_HEADER 0x90000:ALIGN (4) { Image$$IMAGE_INFO_HEADER$$Base =.;
        *(image_info_header) }: RPMSS_DATA

  RPM_IMAGE_ID : { Image$$RPM_IMAGE_ID$$Base =.;
        *oem_uuid.o(.data*)
        *qc_version.o(.data*)
        *oem_version.o(.data*) } : RPMSS_DATA

  RAIL_RESIDENCIES :ALIGN (4) { Image$$RAIL_RESIDENCIES$$Base =.;
        *(rail_residencies) }: RPMSS_DATA

  SLEEP_STATS : { Image$$SLEEP_STATS$$Base =.;
        *(sleep_stats) }: RPMSS_DATA

  CPR_STATS : { Image$$CPR_STATS$$Base =.;
        *(cpr_stats) }: RPMSS_DATA

  RPM_CORE_DUMP : { *(rpm_core_dump) }: RPMSS_DATA
  DATA_RAM_DDR : { Image$$DATA_RAM_DDR$$Base = .;
        *rpm_proc?core?boot?ddr*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_DEBUGTOOLS : { *rpm_proc?core?debugtools*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_DEBUGTRACE : { *rpm_proc?core?debugtrace*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_MPROC_GLINK : { *rpm_proc?core?mproc?glink*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_MPROC : { *rpm_proc?core?mproc*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_ACC : { *rpm_proc?core?power?acc*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_CPR : { *rpm_proc?core?power?cpr*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_MPM : { *rpm_proc?core?power?mpm*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_NPA : { *rpm_proc?core?power?npa*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_RAILWAY :{ *rpm_proc?core?power?railway*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_RPM : { *rpm_proc?core?power?rpm*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_SLEEP : { *rpm_proc?core?power?sleep*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER_ULOG : { *rpm_proc?core?power?ulog*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_POWER : { *rpm_proc?core?power*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_SYSDRV_CLOCK : { *rpm_proc?core?systemdrivers?clock*.lib (.data* .bss*)
          *rpm_proc?core?systemdrivers?hal*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_SYSDRV_ICB : { *rpm_proc?core?systemdrivers?icb*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_SYSDRV : { *rpm_proc?core?systemdrivers*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_SYSDRV_PMIC : { *rpm_proc?core?pmic?pm*.lib (.data* .bss*) }: RPMSS_DATA
  DATA_RAM_SYSDRV_SPMI : { *rpm_proc?core?pmic?spmi*.lib (.data* .bss*) }: RPMSS_DATA



  660_630_xml_DEVCONFIG_DATA : { Image$$660_630_xml_DEVCONFIG_DATA$$Base = .;
         *660_devcfg*.o(.data* .bss*)
         Image$$660_630_xml_DEVCONFIG_DATA$$ZI$$Limit = .; }: RPMSS_DATA

  660_xml_DEVCONFIG_DATA : { Image$$660_xml_DEVCONFIG_DATA$$Base = .;
         *660_devcfg_icb*.o(.data* .bss* .rodata* )
         Image$$660_xml_DEVCONFIG_DATA$$ZI$$Limit = .; }: RPMSS_DATA


  630_xml_DEVCONFIG_DATA : { Image$$630_xml_DEVCONFIG_DATA$$Base = .;
         *630_devcfg_icb*.o(.data* .bss* .rodata* )
         Image$$630_xml_DEVCONFIG_DATA$$ZI$$Limit = .; }: RPMSS_DATA
# 580 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/bsp/rpm/target/660/rpm.scl"
  STACK_OVERFLOW :ALIGN (32) { Image$$STACK_OVERFLOW$$Base = .; }: RPMSS_DATA

  STACK Image$$STACK_OVERFLOW$$Base + 0x20 :
  { Image$$STACK$$Base = .; }: RPMSS_DATA
# 593 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/bsp/rpm/target/660/rpm.scl"
  VECTOR_TABLE Image$$STACK$$Base + 0xA00:
    { Image$$VECTOR_TABLE$$Base = .;
     *rpm_vector_table.o(.data* .bss*) }: RPMSS_DATA


  DATA_RAM_RECLAIM_POOL :
  {
 Image$$DATA_RAM_RECLAIM_POOL$$Base = .;

    *DALConfig*.o(.data* .bss* .rodata*)

    *(exceptions_dram_reclaim_pool)
    *(dog_dram_reclaim_pool)

    *(pm_dram_reclaim_pool)
    *(railway_dram_reclaim_pool)
    *(swevent_dram_reclaim_pool)
    *(mpm_dram_reclaim_pool)
    *(npa_dram_reclaim_pool)
    *(cpr_dram_reclaim_pool)
    *(dal_dram_reclaim_pool)
    *(acc_dram_reclaim_pool)
 Image$$DATA_RAM_RECLAIM_POOL$$Limit = .; }: RPMSS_DATA

  DATA_RAM : { Image$$DATA_RAM$$Base = .;
    KEEP(*\datetime.o (.data.gBuild*))
    *(.data .data*)
    *(.bss .bss*) } : RPMSS_DATA

  DATA_RAM_HEAP :ALIGN(4) { Image$$DATA_RAM_HEAP$$Base = .; }: RPMSS_DATA
  RPM_LOG (((0x90000 + 0x14000) - 0x2000) - 0x2400) : { Image$$RPM_LOG$$Base = .; }: RPMSS_DATA


  DDR_STRUCT_DATA ((0x90000 + 0x14000) - 0x2000) : {
    Image$$DDR_STRUCT_DATA$$Base = .;
    Image$$DDR_STRUCT_DATA$$ZI$$Limit = . + 0x2000;

    }: RPMSS_DATA

  ASSERT(SIZEOF(DATA_RAM) <= 0x14000, "RPMSS_DATA oversized");

  /DISCARD/ : {
    * (.ARM.extab*)
    * (.ARM.exid*)
    * (.got)
  }
}
