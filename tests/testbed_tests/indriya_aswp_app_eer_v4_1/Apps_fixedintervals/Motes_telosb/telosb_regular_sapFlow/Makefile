COMPONENT=../../MotesAppC

##################### Application Version #######################################################
# The default is 1, defined in health_ctp.h. 
# (Update this value every time the application is updated)
CFLAGS += -DAPP_VERSION=41
#################################################################################################

# Wireless reprogramming
CFLAGS += -DREPROGRAMMER
BOOTLOADER=tosboot
CFLAGS += -I../../../MobileDeluge/Reprogrammer
CFLAGS += -I../../../MobileDeluge/Deluge
CFLAGS += -I../../../MobileDeluge/SimpleDrip

# Watchdog threshold
CFLAGS += -DWDT_THRESHOLD=5

# Define max packet size, including in-network processing layer
CFLAGS += -DTOSH_DATA_LENGTH=61

# TRAFFIC MONITOR
CFLAGS += -DTRAFFIC_MONITOR


##################### Set timer parameters ######################################################
# Set initial sampling time (milliseconds)
CFLAGS += -DBEGINNING_INTERVAL=1024*60							# 60 secs

# Set number of rounds for the initial sampling time
CFLAGS += -DBEGIN_ROUNDS=5		 												# 5 rounds

# Set stable sampling rate (milliseconds)
CFLAGS += -DSTABLE_INTERVAL=1024*60*30  							# 1x

# Enable/Disable summary packets from ctp Instrumentation 
# also define the interval between each summary packet (in milliseconds)
CFLAGS += -DSUMMARY_PACKET
CFLAGS += -DSUMMARY_INTERVAL=1024*60*30*4 						# 4x

#################################################################################################

# Enable/disable LEDs (Comment it out to disable LEDs)
#CFLAGS += -DLED_ENABLED

# Set the number of ADCs, we can use 0~6. (If you use 0, it's better to use relay_node for that)
CFLAGS += -DADC_NUMBER=3

# Add Flash access
CFLAGS += -DFLASH_ACCESS
CFLAGS += -I../../FlashEditor
CFLAGS += -DRESET_CODE=41		# if the RESET_CODE stored in the flash does not match 
														# this, the FlashConfig will write default values to the
														# flash. flash_node_id = TOS_NODE_ID, flash_wdt_resets = 0,
														# flash_flag = RESET_CODE


##### ADC0 and ADC1 limit for Sap Flow sensor, DEFAULE: 40 and 1000
### 	value_in_mV = ((2500 * rawAdc) / 4096), rawAdc = value_in_mV*4096/2500
###		e.g., if the limit is 400 mV, you should put 1093 here

CFLAGS += -DADC0_MIN=40				# The raw ADC value
CFLAGS += -DADC0_MAX=1000		

CFLAGS += -DADC1_MIN=40	
CFLAGS += -DADC1_MAX=1000	


##################### Set radio parameters ######################################################
# SET RADIO CHANNEL (channel at ASWP: 26)
# CC2420 default channel is 26, we can use 11~26
CFLAGS += -DCC2420_DEF_CHANNEL=26

# RF230  default channel is 11, we can use 11~26
CFLAGS += -DRF230_DEF_CHANNEL=26

# SET RADIO POWER
# CC2420 default is 31(MAX), we can use 31,27,23,19,15,11,7,3(MIN)
CFLAGS += -DCC2420_DEF_RFPOWER=31
# RF230  default is 0(MAX), we can use 0~15(MIN)
CFLAGS += -DRF230_DEF_RFPOWER=0
#################################################################################################


##################### LPL and compiling path ####################################################
# Default LPL
CFLAGS += -DLOW_POWER_LISTENING
CFLAGS += -DLPL_DEF_LOCAL_WAKEUP=1024
CFLAGS += -DLPL_DEF_REMOTE_WAKEUP=1024
CFLAGS += -DDELAY_AFTER_RECEIVE=20

# Path for new cc2420 lpl (includes the traffic monitor)
CFLAGS += -I../../../lpl_cc2420

# Define hardware ACKs
CFLAGS += -DCC2420_HW_ACKNOWLEDGEMENTS

# Timeout for acks in CC2420 (telosb and micaz motes). Defined in CCA checks. 
# The time for each CCA check varies depending on the platform.
CFLAGS += -DMAX_LPL_CCA_CHECKS=1500




# ROUTING PROTOCOL:

appEER = net_EER
CFLAGS += -I../../../$(appEER) \
          -I../../../$(appEER)/4bitle \
          -I../../../$(appEER)/eer \
          -I../../../$(appEER)/eer_parentselection \
					-I../../



#appEER = net_originalCTP_simulation
#CFLAGS += -I../../../$(appEER) \
#          -I../../../$(appEER)/4bitle \
#          -I../../../$(appEER)/ctp \
#					-I../../




# (EER) Maximum parent set size
CFLAGS += -DMAX_PARENTSET_SIZE=5

# (EER) Allowed retransmissions without penalization in the link estimator
# This value should be less than the default retransmission for each forwarder node
CFLAGS += -DEER_ALLOWED_RETXS=1

# Maximum beacon interval (milliseconds)
CFLAGS += -DEER_MAX_BEACON_INT=1024*60*40

# Path for msp430 (telosb sensor driver)
CFLAGS += -I../msp430


###############################################################################################

# Added for In-network processing layer, comment these out to disable this layer
#
CFLAGS += -DIN_NET_PROCESSING
CFLAGS += -DIN_NET_PROCESSING_INTERVAL=1024*60*30*5 				# 5x
###############################################################################################


# Printf (comment to remove printf)
#CFLAGS += -I$(TOSDIR)/lib/printf
#CFLAGS += -DNEW_PRINTF_SEMANTICS
#CFLAGS += -DPRINTF_ENABLED
#CFLAGS += -DPRINTF_BUFFER_SIZE=450

include $(MAKERULES)

