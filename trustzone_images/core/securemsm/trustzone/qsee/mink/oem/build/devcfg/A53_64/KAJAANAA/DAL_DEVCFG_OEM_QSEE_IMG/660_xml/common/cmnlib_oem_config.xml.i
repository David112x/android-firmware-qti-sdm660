<driver name="NULL">
  <global_def>
    <var_seq name="gppo_root_path" type=DALPROP_DATA_TYPE_STRING>
      "/persist/data/"
    </var_seq>
  </global_def>
  <device id="commonlib">
    <props name="cmnlib_gppo_rpmb_enablement" type=DALPROP_ATTR_TYPE_UINT32>
      1
    </props>
    <props name="cmnlib_gppo_root_path" type=DALPROP_ATTR_TYPE_STRING_PTR>
      gppo_root_path
    </props>
  </device>
</driver>
