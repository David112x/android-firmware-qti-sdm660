ifneq ($(BUILD_TINY_ANDROID),true)

ROOT_DIR := $(call my-dir)
LOCAL_PATH := $(ROOT_DIR)
include $(CLEAR_VARS)

# ------------------------------------------------------------------------------
#       Product calib
# ------------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE:= product_calib_mtp_ref1.dat
LOCAL_MODULE_CLASS := DATA
LOCAL_SRC_FILES := $(LOCAL_MODULE)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/persist/usf/epos/ref1
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= product_calib_mtp_ref3.dat
LOCAL_MODULE_CLASS := DATA
LOCAL_SRC_FILES := $(LOCAL_MODULE)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/persist/usf/epos/ref3
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

# ------------------------------------------------------------------------------
#       Unit calib
# ------------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE:= unit_calib_mtp_ref1.dat
LOCAL_MODULE_CLASS := DATA
LOCAL_SRC_FILES := $(LOCAL_MODULE)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/persist/usf/epos/ref1
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= unit_calib_mtp_ref3.dat
LOCAL_MODULE_CLASS := DATA
LOCAL_SRC_FILES := $(LOCAL_MODULE)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/persist/usf/epos/ref3
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

endif #BUILD_TINY_ANDROID

