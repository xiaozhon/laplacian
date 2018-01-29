COMPONENT=LapTestAppC

#CFLAGS += -I$(TOSDIR)/lib/net \
#          -I$(TOSDIR)/lib/net/4bitle \
#          -I$(TOSDIR)/lib/net/ctp

### figure out later
appEER = net/net_originalCTP_simulation
CFLAGS += -I../$(appEER)\
          -I../$(appEER)/4bitle \
          -I../$(appEER)/ctp


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


CFLAGS += -DTOSH_DATA_LENGTH=100

#BUILD_EXTRA_DEPS = SimMsg.py SimMsg.class SimMsg.java

## MIG: serial message
#SimMsg.py: OsrTest.h
#	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=SimMsg OsrTest.h SimMsg -o $@
#	

#SimMsg.class: SimMsg.java
#	javac SimMsg.java

#SimMsg.java: OsrTest.h
#	mig java -target=$(PLATFORM) $(CFLAGS) -java-classname=SimMsg OsrTest.h SimMsg -o $@

# MIG: serial reply message

include $(MAKERULES)
