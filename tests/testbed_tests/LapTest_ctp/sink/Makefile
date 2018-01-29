COMPONENT=LapTestAppC

#CFLAGS += -I$(TOSDIR)/lib/net \
#          -I$(TOSDIR)/lib/net/4bitle \
#          -I$(TOSDIR)/lib/net/ctp

### figure out later
appEER = net/net_originalCTP_simulation
CFLAGS += -I../../$(appEER)\
          -I../../$(appEER)/4bitle \
          -I../../$(appEER)/ctp


#appEER = net/net_EER_sim
#CFLAGS += -I../$(appEER) \
#         -I../$(appEER)/4bitle \
#          -I../$(appEER)/eer \
#          -I../$(appEER)/eer_parentselection \

# (R-CTP) Maximum parent set size
CFLAGS += -DMAX_PARENTSET_SIZE=5

# (R-CTP) Allowed retransmissions without penalization in the link estimator
# This value should be less than the default retransmission for each forwarder node
#CFLAGS += -DRCTP_ALLOWED_RETXS=1
CFLAGS += -DEER_ALLOWED_RETXS=1

####################
#### Configure LPL and CCA checks for Telosb mote. Without this, the node-to-node
#### PRR is very poor, 60~70%
# Define hardware ACKs
CFLAGS += -DCC2420_HW_ACKNOWLEDGEMENTS

# Timeout for acks in CC2420 (telosb and micaz motes). Defined in CCA checks. 
# The time for each CCA check varies depending on the platform.
CFLAGS += -DMAX_LPL_CCA_CHECKS=1800


CFLAGS += -DTOSH_DATA_LENGTH=100
# Printf (comment to remove printf)
CFLAGS += -I$(TOSDIR)/lib/printf
CFLAGS += -DNEW_PRINTF_SEMANTICS
CFLAGS += -DPRINTF_INDRIYA_ENABLED			# FOR OSR
CFLAGS += -DPRINTF_BUFFER_SIZE=700

CFLAGS += -DLOW_POWER_LISTENING
CFLAGS += -DLPL_DEF_LOCAL_WAKEUP=0
CFLAGS += -DLPL_DEF_REMOTE_WAKEUP=1024
CFLAGS += -DDELAY_AFTER_RECEIVE=30

include $(MAKERULES)
