COMPONENT=SnifferAppC
CFLAGS += -DIEEE154_SCAN_DISABLED -DIEEE154_BEACON_SYNC_DISABLED -DIEEE154_BEACON_TX_DISABLED -DIEEE154_RXENABLE_DISABLED -DIEEE154_ASSOCIATION_DISABLED -DIEEE154_DISASSOCIATION_DISABLED -DIEEE154_COORD_REALIGNMENT_DISABLED -DIEEE154_COORD_BROADCAST_DISABLED


# define sniffer channel (11 ~ 26)
CFLAGS += -DSNIFFER_CHANNEL=20

BUILD_EXTRA_DEPS += PacketParser
CLEAN_EXTRA = PacketParser.o PacketParser

PacketParser: PacketParser.o
	gcc -o $@ $< $(TOSDIR)/../support/sdk/c/sf/libmote.a

PacketParser.o: PacketParser.c
	gcc -c -o $@ -I$(TOSDIR)/../support/sdk/c/sf -I$(TOSDIR)/lib/serial -I$(TOSDIR)/types $<

include Makefile.include
