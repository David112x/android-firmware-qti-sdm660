# 1 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/dal/config/build/rpm/rpm/AAAAANAZR/DevCfg_master_660.xml"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 324 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/dal/config/build/rpm/rpm/AAAAANAZR/DevCfg_master_660.xml" 2
# 1 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/api/dal/DALPropDef.h" 1
# 2 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/dal/config/build/rpm/rpm/AAAAANAZR/DevCfg_master_660.xml" 2
# 1 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/api/dal/DALDeviceId.h" 1
# 3 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/dal/config/build/rpm/rpm/AAAAANAZR/DevCfg_master_660.xml" 2
# 1 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/dal/config/dalconfig.h" 1
# 4 "/local/mnt/workspace/CRMBuilds/RPM.BF.1.8-00067-SDM660AAAAANAZR-1_20200203_034924/b/rpm_proc/core/dal/config/build/rpm/rpm/AAAAANAZR/DevCfg_master_660.xml" 2

<?xml version="1.0"?>
<dal>
<module name="rpm">

<!--
-->
<driver name="NULL">
  <device id="/dev/core/mproc/glink/ssr">
    <props name="config" type=0x00000012>
      glink_ssr_devcfg_config
    </props>
  </device>
</driver>

<!--
-->
<driver name="NULL">
  <device id="/dev/core/mproc/glink/xport_rpm">
    <props name="proc_info" type=0x00000012>
      xport_rpm_devcfg_proc_info
    </props>
    <props name="remote_procs" type=0x00000012>
      xport_rpm_devcfg_remote_procs
    </props>
    <props name="toc" type=0x00000012>
      xport_rpm_devcfg_toc
    </props>
  </device>
</driver>

<!--
-->
<driver name="NULL">
  <global_def>
    <var_seq name="core_top_csr_str" type=0x00000001>
      CORE_TOP_CSR
    </var_seq>
    <var_seq name="mutex_offsets_data" type=0x00000003>
      ((0x00040000) + 0x00000000 + 0x1000 * (0)),
      ((0x00040000) + 0x00000000 + 0x1000 * (1)),
      ((0x00040000) + 0x00000000 + 0x1000 * (2)),
      ((0x00040000) + 0x00000000 + 0x1000 * (3)),
      ((0x00040000) + 0x00000000 + 0x1000 * (4)),
      ((0x00040000) + 0x00000000 + 0x1000 * (5)),
      ((0x00040000) + 0x00000000 + 0x1000 * (6)),
      ((0x00040000) + 0x00000000 + 0x1000 * (7)),
      end
    </var_seq>
    <var_seq name="wonce_offsets_data" type=0x00000003>
      ((0x000c0000) + 0x00014000 + 0x4 * (0)),
      ((0x000c0000) + 0x00014000 + 0x4 * (1)),
      end
    </var_seq>
  </global_def>
  <device id="/dev/core/mproc/smem">
    <!-- tcsr_base_name, which is TCSR base name used to get
         the virtual address -->
    <props name="tcsr_base_name" type=0x00000011>
      core_top_csr_str
    </props>
    <!-- tcsr_base, TCSR base physical address -->
    <props name="tcsr_base" type=0x00000002>
      0x01F00000
    </props>
    <props name="mutex_offsets" type=0x00000014>
      mutex_offsets_data
    </props>
    <props name="wonce_offsets" type=0x00000014>
      wonce_offsets_data
    </props>
  </device>
</driver>

<driver name=NULL>
<device id="/rpm/pmic/common">
<props id=1 type=0x00000012>
clk_reg
</props>
<props id=2 type=0x00000012>
smps_reg
</props>
<props id=3 type=0x00000012>
ldo_reg
</props>
<props id=4 type=0x00000012>
vs_reg
</props>
<props id=5 type=0x00000012>
boost_reg
</props>
<props id=51 type=0x00000012>
bob_reg
</props>
<props id=50 type=0x00000012>
fg_reg
</props>
<props id=45 type=0x00000012>
pbs_client_reg
</props>
<props id=6 type=0x00000012>
fts_volt
</props>
<props id=30 type=0x00000012>
fts2p5_volt
</props>
<props id=7 type=0x00000012>
hfs_volt
</props>
<props id=8 type=0x00000012>
boost_volt
</props>
<props id=9 type=0x00000012>
nmos_volt
</props>
<props id=10 type=0x00000012>
n600_volt
</props>
<props id=11 type=0x00000012>
n1200_volt
</props>
<props id=12 type=0x00000012>
pmos_volt
</props>
<props id=13 type=0x00000012>
ln_volt
</props>
<props id=14 type=0x00000012>
fts_range
</props>
<props id=31 type=0x00000012>
fts2p5_range
</props>
<props id=15 type=0x00000012>
hfs_range
</props>
<props id=16 type=0x00000012>
boost_range
</props>
<props id=17 type=0x00000012>
nmos_range
</props>
<props id=18 type=0x00000012>
n600_range
</props>
<props id=19 type=0x00000012>
n1200_range
</props>
<props id=20 type=0x00000012>
pmos_range
</props>
<props id=21 type=0x00000012>
ln_range
</props>
<props id=39 type=0x00000012>
ult_nmos_volt
</props>
<props id=37 type=0x00000012>
ult_pmos_volt
</props>
<props id=38 type=0x00000012>
ult_nmos_range
</props>
<props id=36 type=0x00000012>
ult_pmos_range
</props>
<props id=32 type=0x00000012>
ult_buck_range_1
</props>
<props id=33 type=0x00000012>
ult_buck_volt_1
</props>
<props id=34 type=0x00000012>
ult_buck_range_2
</props>
<props id=35 type=0x00000012>
ult_buck_volt_2
</props>
<props id=48 type=0x00000012>
unified_rails_stepper_rate
</props>
<props id=43 type=0x00000012>
ult_ldo_stepper_rate
</props>
<props id=44 type=0x00000012>
ult_smps_stepper_rate
</props>
<props id=46 type=0x00000012>
ldo_stepper_rate
</props>
<props id=52 type=0x00000012>
bob_stepper_rate
</props>
<props id=47 type=0x00000012>
smps_stepper_rate
</props>
<props id=22 type=0x00000012>
ldo_vreg_ok_time
</props>
<props id=23 type=0x00000012>
smps_vreg_ok_time
</props>
<props id=24 type=0x00000012>
vs_vreg_ok_time
</props>
<props id=53 type=0x00000012>
bob_vreg_ok_time
</props>
<props id=49 type=0x00000012>
clk_ok_time
</props>
<props id=26 type=0x00000012>
clk_sleep_reg
</props>
<props id=27 type=0x00000012>
clk_xo_reg
</props>
<props id=28 type=0x00000012>
clk_common
</props>
</device>
</driver>

<driver name=NULL>
<device id="/rpm/pmic/target">
<props id=101 type=0x00000012 >
num_of_smps
</props>
<props id=103 type=0x00000012 >
num_of_ldo
</props>
<props id=104 type=0x00000012 >
num_of_vs
</props>
<props id=141 type=0x00000012 >
num_of_bob
</props>
<props id=142 type=0x00000012 >
bob_pin_mapping
</props>
<props id=114 type=0x00000012>
pm_npa_rpm_pam_node_rsrcs
</props>
<props id=115 type=0x00000012>
num_of_pm_rpm_nodes
</props>
<props id=134 type=0x00000012>
ldo_rail
</props>
<props id=135 type=0x00000012>
smps_rail
</props>
<props id=136 type=0x00000012>
vs_rail
</props>
<props id=116 type=0x00000012>
clk_info
</props>
<props id=139 type=0x00000012>
bob_rail
</props>
<props id=110 type=0x00000012>
smps_dep
</props>
<props id=109 type=0x00000012>
ldo_dep
</props>
<props id=112 type=0x00000012>
vs_dep
</props>
<props id=113 type=0x00000012>
clk_dep
</props>
<props id=140 type=0x00000012>
bob_dep
</props>
<props id=301 type=0x00000012>
pm_mpm_active_cfg
</props>
<props id=302 type=0x00000012>
pm_mpm_sleep_cfg
</props>
<props id=303 type=0x00000012>
pm_mpm_cmd_index
</props>
<props id=304 type=0x00000012>
pm_mpm_rails_info
</props>
<props id=117 type=0x00000012>
sleep_enter_info
</props>
<props id=118 type=0x00000012>
sleep_exit_info
</props>
</device>
</driver>

<driver name="Clock">
   <device id=0x02000145>
      <!-- Clock sources -->
      <props name="ClockSources" type=0x00000012>
        SourceConfig
      </props>
      <!-- RPM Clocks -->
      <props name="gcc_rpm_proc_hclk" type=0x00000012>
        RPMClockConfig
      </props>
      <!-- System NOC Clocks -->
      <props name="gcc_sys_noc_axi_clk" type=0x00000012>
        SystemNOCClockConfig
      </props>
     <!-- Aggre2NOC Clocks -->
      <props name="gcc_aggre2_snoc_axi_clk" type=0x00000012>
        SystemNOCClockConfig
      </props>
     <!-- System NOC Clocks -->
     <props name="gcc_sys_noc_pimem_axi_clk" type=0x00000012>
       PIMEMClockConfig
     </props>
     <!-- System NOC HS Clocks -->
     <props name="gcc_sys_noc_hs_axi_clk" type=0x00000012>
       SYSNOCHSAXIClockConfig
     </props>
     <!-- Config NOC Clocks -->
      <props name="gcc_cfg_noc_ahb_clk" type=0x00000012>
        ConfigNOCClockConfig
      </props>
      <!-- Peripheral NOC Clocks -->
      <props name="gcc_cnoc_periph_north_ahb_clk" type=0x00000012>
        PeriphNOCClockConfig
      </props>
     <!-- QDSS ATBA Clocks -->
      <props name="gcc_sys_noc_at_clk" type=0x00000012>
        QDSSATBAClockConfig
      </props>
     <!-- QDSS ATBB Clocks -->
      <props name="gcc_bimc_at_clk" type=0x00000012>
        QDSSATBBClockConfig
      </props>
     <!-- QDSS ATBC Clocks -->
      <props name="gcc_lpass_at_clk" type=0x00000012>
        QDSSATBCClockConfig
      </props>
      <!-- QDSS Trace Clocks -->
      <props name="gcc_qdss_traceclkin_clk" type=0x00000012>
        QDSSTraceClockConfig
      </props>
      <!-- QDSS STM Clocks -->
      <props name="gcc_qdss_stm_clk" type=0x00000012>
        QDSSSTMClockConfig
      </props>
      <!-- QDSS TSCTR Div2 Clocks -->
      <props name="gcc_qdss_tsctr_div2_clk" type=0x00000012>
        QDSSTSCTRDiv2ClockConfig
      </props>
      <!-- QDSS Trig Clocks -->
      <props name="gcc_qdss_trig_clk" type=0x00000012>
        QDSSAPBTRIGClockConfig
      </props>
      <!-- IPA Clocks -->
      <props name="gcc_ipa_clk" type=0x00000012>
        IPAClockConfig
      </props>
      <!-- CE1 Clocks -->
      <props name="gcc_ce1_clk" type=0x00000012>
        CEClockConfig
      </props>
      <!-- SPMI AHB Clocks -->
      <props name="gcc_spmi_ahb_clk" type=0x00000012>
        SPMIAHBClockConfig
      </props>
      <!-- SPMI SER Clocks -->
      <props name="gcc_spmi_ser_clk" type=0x00000012>
        SPMISERClockConfig
      </props>
      <!-- HMSS AHB Clocks -->
      <props name="gcc_hmss_ahb_clk" type=0x00000012>
        HMSSAHBClockConfig
      </props>
     <!-- VSense VDDA Clocks -->
     <props name="gcc_vdda_vs_clk" type=0x00000012>
       VSenseClockConfig
     </props>
     <!-- VSense VDD Cx Clocks -->
     <props name="gcc_vddcx_vs_clk" type=0x00000012>
       VSenseClockConfig
     </props>
     <!-- VSense VDD Mx Clocks -->
     <props name="gcc_vddmx_vs_clk" type=0x00000012>
       VSenseClockConfig
     </props>
     <!-- VSense VDD MSS Clocks -->
     <props name="gcc_mss_vs_clk" type=0x00000012>
       VSenseClockConfig
     </props>
     <!-- MMSS NOC AXI Clocks -->
     <props name="mmss_mnoc_axi_clk" type=0x00000012>
       MMSSAXIClockConfig
     </props>
     <!-- Clock Log Defaults -->
      <props name="ClockLogDefaults" type=0x00000012>
        ClockLogDefaultConfig
      </props>
   </device>
</driver>

<driver name="icb_rpm">
   <global_def>
   </global_def>
   <device id="/dev/icb/rpm">
     <props name="system" type=0x00000012>
        icb_rpm_system
     </props>
   </device>
</driver>

<driver name="Timetick">
  <device id=0x0200009B>
     <props name="DEFAULT_FREQUENCY" type=0x00000002>
       19200000
     </props>
     <props name="QTIMER_AC_BASE" type=0x00000002>
       0x00082000
     </props>
     <props name="QTIMER_BASE" type=0x00000002>
       0x00084000
     </props>
  </device>
</driver>

</module>
</dal>
