COMPONENT=BasestationAppC
BOOTLOADER=tosboot

# Define radio channel
CFLAGS += -DCC2420_DEF_CHANNEL=26
CFLAGS += -DRF230_DEF_CHANNEL=26
#CFLAGS += -DTOSH_DATA_LENGTH=75
CFLAGS += -DDELUGE_BASESTATION


#CFLAGS += -DLOW_POWER_LISTENING
#CFLAGS += -DLPL_DEF_LOCAL_WAKEUP=1024
#CFLAGS += -DLPL_DEF_REMOTE_WAKEUP=1024
#CFLAGS += -DDELAY_AFTER_RECEIVE=20



# path to SimpleDrip
#CFLAGS += -I../../SimpleDrip
include $(MAKERULES)
