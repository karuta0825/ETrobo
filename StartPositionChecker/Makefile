# nxtOSEK
NXTOSEK_ROOT = ../../nxtOSEK

#TARGET = model_impl
TARGET = ModelTest

USER_INC_PATH= $(NXTOSEK_ROOT)/ecrobot/nxtway_gs_balancer

USER_LIB = nxtway_gs_balancer

TARGET_SOURCES = UI.c Runner.c TouchSensor.c Motor.c main.c LightSensor.c StartPositionChecker.c

# TOPPERS/ATK1(OSEK)
TOPPERS_OSEK_OIL_SOURCE = model_impl.oil

O_PATH ?= build

include $(NXTOSEK_ROOT)/ecrobot/ecrobot.mak
