# Flags from BoardConfigVendor.mk
ifneq ($(TARGET_USES_QMAA),true)
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := default
else ifneq ($(TARGET_USES_QMAA_OVERRIDE_GPS),false)
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := default
endif

ifneq ($(TARGET_FWK_SUPPORTS_FULL_VALUEADDS),true)
BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := true
else
BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := false
endif

