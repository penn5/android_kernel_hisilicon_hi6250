ifneq ($(TARGET_BUILD_VARIANT),user)
EXTRA_CFLAGS += -DDEBUG_HISI_CAMERA
endif
ccflags-y += -Idrivers/media/huawei/camera/hisp
ccflags-y += -Idrivers/media/huawei/camera
ccflags-y += -Wno-error=incompatible-pointer-types

obj-y += hisp110.o
