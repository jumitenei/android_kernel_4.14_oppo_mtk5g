include $(CLEAR_VARS)

LOCAL_MODULE := $(WIFI_NAME).ko
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
LOCAL_INIT_RC := init.wlan_drv.rc

ifeq ($(CONNAC_VER), 2_0)
LOCAL_REQUIRED_MODULES := conninfra.ko
else
LOCAL_REQUIRED_MODULES := wmt_drv.ko
endif

WIFI_ADAPTOR_OPTS := CONNAC_VER=$(CONNAC_VER) MODULE_NAME=$(WIFI_NAME)
include $(MTK_KERNEL_MODULE)
$(linked_module): OPTS += $(WIFI_ADAPTOR_OPTS)
