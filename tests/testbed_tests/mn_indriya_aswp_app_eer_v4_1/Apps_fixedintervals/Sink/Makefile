COMPONENT=BaseStationAppC
CFLAGS += -DTOSH_DATA_LENGTH=69							# DEFINE THE MAXIMUM PAYLOAD SIZE

CFLAGS += -DLOW_POWER_LISTENING
CFLAGS += -DLPL_DEF_LOCAL_WAKEUP=0				  # BASE STATION SHOULD NOT BE SLEEPING (Value should be 0)***
CFLAGS += -DLPL_DEF_REMOTE_WAKEUP=1024			# Other motes are sleeping
CFLAGS += -DDELAY_AFTER_RECEIVE=20


# Added for In-network processing layer, comment these out to disable this layer
#
CFLAGS += -DIN_NET_PROCESSING


# Path for new cc2420 lpl (includes the traffic monitor) - ENABLE FOR TELOSB BASE STATION - MICAZ CANNOT BE USED AS A BASE STATION
CFLAGS += -I../../lpl_cc2420


# Routing protocol
#appEER = net_EER
#CFLAGS += -I../../$(appEER) \
#          -I../../$(appEER)/4bitle \
#          -I../../$(appEER)/eer \
#          -I../../$(appEER)/eer_parentselection \
#	 				-I../ \
#					-I../../rf230 \
#					-I../../rfxlink/layers \
#					-I../../rfxlink/util 

appEER = net_originalCTP_simulation
CFLAGS += -I../../$(appEER) \
          -I../../$(appEER)/4bitle \
          -I../../$(appEER)/ctp \
					 -I../ \
					 -I../../rf230 \
					 -I../../rfxlink/layers \
					 -I../../rfxlink/util 





# Maximum beacon interval (milliseconds)
CFLAGS += -DEER_MAX_BEACON_INT=1024*60*30		# 30 minutes

# (EER) Allowed retransmissions without penalization in the link estimator
# This value should be less than the default retransmission for each forwarder node
CFLAGS += -DEER_ALLOWED_RETXS=1


# Timeout for acks in IRIS motes (microseconds)
CFLAGS += -DSOFTWAREACK_TIMEOUT=2000


# Timeout for acks in CC2420 (telosb and micaz motes). Defined in CCA checks. 
# The time for each CCA check varies depending on the platform.
CFLAGS += -DMAX_LPL_CCA_CHECKS=1500


# Path for new cc2420 lpl (includes the traffic monitor)
#CFLAGS += -I../../lpl_cc2420






#**************************************************************************************

# CC2420,default channel is 26, we can use 11~26
CFLAGS += -DCC2420_DEF_CHANNEL=26

# RF230,default channel is 11, we can use 11~26
CFLAGS += -DRF230_DEF_CHANNEL=26

#**************************************************************************************

# set radio power
# CC2420, default is 31(MAX), we can use 31,27,23,19,15,11,7,3(MIN)  [dBm]
# 31 0
# 27 -1 
# 23 -3 
# 19 -5 
# 15 -7 
# 11 -10 
# 7  -15 
# 3 -25 
CFLAGS += -DCC2420_DEF_RFPOWER=31 # LAB: mininum TX power

# RF230, default is 0(MAX), we can use 0~15(MIN)   [dBm]
#	0 +3.0 
# 1 +2.6 
# 2 +2.1 
# 3 +1.6 
# 4 +1.1 
# 5 +0.5 
# 6 -0.2 
# 7 -1.2 
# 8 -2.2 
# 9 -3.2 
# 10 -4.2
# 11 -5.2 
# 12 -7.2 
# 13 -9.2 
# 14 -12.2 
# 15 -17.2
CFLAGS += -DRF230_DEF_RFPOWER=0

#**************************************************************************************



include $(MAKERULES)
