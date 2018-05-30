LOCAL_PATH := $(call my-dir)

SERIAL_SRC_FILES := \
    findme.c \
    popt.c \
    poptconfig.c \
    popthelp.c \
    poptparse.c \
    glob.c \
    basenames.c \
    config.c \
    log.c \
    logrotate.c \

SERIAL_C_INCLUDES := \
    $(LOCAL_PATH)/include

include $(CLEAR_VARS)

LOCAL_MODULE    := logrorate
LOCAL_C_INCLUDES := $(SERIAL_C_INCLUDES)
LOCAL_SRC_FILES := $(SERIAL_SRC_FILES)

LOCAL_CFLAGS        := -std=c99 -D_MYNOBZIP
LOCAL_C_INCLUDES	+= external/zlib
LOCAL_SHARED_LIBRARIES	+= libz
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_MODULE := logdate
LOCAL_SRC_FILES := logdate.c
include $(BUILD_EXECUTABLE)

