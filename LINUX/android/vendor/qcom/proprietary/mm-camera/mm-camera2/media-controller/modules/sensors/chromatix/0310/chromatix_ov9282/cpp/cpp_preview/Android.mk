OV7251_CHROMATIX_PREVIEW_CPP_PATH := $(call my-dir)

# ---------------------------------------------------------------------------
#                      Make the shared library (libchromatix_ov9282_preview_cpp)
# ---------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_PATH := $(OV7251_CHROMATIX_PREVIEW_CPP_PATH)
LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS:= -DAMSS_VERSION=$(AMSS_VERSION) \
        $(mmcamera_debug_defines) \
        $(mmcamera_debug_cflags) \
        -include camera_defs_i.h

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../../../../../../../mm-camerasdk/sensor/includes/$(CHROMATIX_VERSION)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../module/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../../common/
LOCAL_C_INCLUDES += chromatix_ov9282_preview_cpp.h

LOCAL_SRC_FILES:= chromatix_ov9282_preview_cpp.c

LOCAL_MODULE           := libchromatix_ov9282_cpp_preview
LOCAL_SHARED_LIBRARIES := libcutils
include $(LOCAL_PATH)/../../../../../../../../../local_additional_dependency.mk

ifeq ($(MM_DEBUG),true)
LOCAL_SHARED_LIBRARIES += liblog
endif

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

ifeq ($(32_BIT_FLAG), true)
LOCAL_32_BIT_ONLY := true
endif

include $(BUILD_SHARED_LIBRARY)
