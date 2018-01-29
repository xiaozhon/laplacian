/*
 * "Copyright (c) 2005 The Regents of the University  of California.  
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
 * CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 */
/*
 * Copyright (c) 2006 Stanford University.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the Stanford University nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL STANFORD
 * UNIVERSITY OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Ctp.h"

/**
 * A data collection service that uses a tree routing protocol
 * to deliver data to collection roots, following TEP 119.
 *
 * @author Rodrigo Fonseca
 * @author Omprakash Gnawali
 * @author Kyle Jamieson
 * @author Philip Levis
 */


configuration CtpP {
  provides {
    interface StdControl;
    interface Send[uint8_t client];
    interface Receive[collection_id_t id];
    interface Receive as Snoop[collection_id_t];
    interface Intercept[collection_id_t id];

    interface Packet;
    interface CollectionPacket;
    interface CtpPacket;

    interface CtpInfo;
    interface LinkEstimator;
    interface CtpCongestion;
    interface RootControl;
  }

  uses {
    interface CollectionId[uint8_t client];
    interface CollectionDebug;
  }
}

implementation {
  enum {
    CLIENT_COUNT = uniqueCount(UQ_CTP_CLIENT),
    FORWARD_COUNT = 12,
    TREE_ROUTING_TABLE_SIZE = 10,
    QUEUE_SIZE = CLIENT_COUNT + FORWARD_COUNT,
    CACHE_SIZE = 4,
  };

  components ActiveMessageC;
  components new CtpForwardingEngineP() as Forwarder;
  components MainC, LedsC;
  
  Send = Forwarder;
  StdControl = Forwarder;
  Receive = Forwarder.Receive;
  Snoop = Forwarder.Snoop;
  Intercept = Forwarder;
  Packet = Forwarder;
  CollectionId = Forwarder;
  CollectionPacket = Forwarder;
  CtpPacket = Forwarder;
  CtpCongestion = Forwarder;
  
  components new PoolC(message_t, FORWARD_COUNT) as MessagePoolP;
  components new PoolC(fe_queue_entry_t, FORWARD_COUNT) as QEntryPoolP;
  Forwarder.QEntryPool -> QEntryPoolP;
  Forwarder.MessagePool -> MessagePoolP;

  components new QueueC(fe_queue_entry_t*, QUEUE_SIZE) as SendQueueP;
  Forwarder.SendQueue -> SendQueueP;

  components new LruCtpMsgCacheC(CACHE_SIZE) as SentCacheP;
  Forwarder.SentCache -> SentCacheP;

  components new TimerMilliC() as RoutingBeaconTimer;
  components new TimerMilliC() as RouteUpdateTimer;
  components LinkEstimatorP as Estimator;
  Forwarder.LinkEstimator -> Estimator;

  components new AMSenderC(AM_CTP_DATA);
  components new AMReceiverC(AM_CTP_DATA);
  components new AMSnooperC(AM_CTP_DATA);


#if defined(RCTP_MAX_BEACON_INT)  
  #warning " * USING SPECIFIC MAXIMUM BEACON INTERVAL *"
  components new CtpRoutingEngineP( TREE_ROUTING_TABLE_SIZE, 128, 
																		 (uint32_t) RCTP_MAX_BEACON_INT) as Router;
#else
  components new CtpRoutingEngineP(TREE_ROUTING_TABLE_SIZE, 128, 1843200) as Router; // 30 Mins
#endif


  StdControl = Router;
  StdControl = Estimator;
  RootControl = Router;
  MainC.SoftwareInit -> Router;
  Router.BeaconSend -> Estimator.Send;
  Router.BeaconReceive -> Estimator.Receive;
  Router.LinkEstimator -> Estimator.LinkEstimator;

  Router.CompareBit -> Estimator.CompareBit;

  Router.AMPacket -> ActiveMessageC;
  Router.RadioControl -> ActiveMessageC;
  Router.BeaconTimer -> RoutingBeaconTimer;
  Router.RouteTimer -> RouteUpdateTimer;
  Router.CollectionDebug = CollectionDebug;
  Forwarder.CollectionDebug = CollectionDebug;
  Forwarder.CtpInfo -> Router;
  Router.CtpCongestion -> Forwarder;
  CtpInfo = Router;

  
  components new TimerMilliC() as RetxmitTimer;
  Forwarder.RetxmitTimer -> RetxmitTimer;

  components RandomC;
  Router.Random -> RandomC;
  Forwarder.Random -> RandomC;

  MainC.SoftwareInit -> Forwarder;

// /*
#if defined(IN_NETWORK_PROCESSING)
  components InNetworkProcessingP;
  Forwarder.SubSend -> InNetworkProcessingP.AMSend;  
  Forwarder.SubPacket -> InNetworkProcessingP.Packet;
  Forwarder.SubReceive -> InNetworkProcessingP.Receive;

  InNetworkProcessingP.SubSend -> AMSenderC;  
  InNetworkProcessingP.AMPacket -> AMSenderC;
  InNetworkProcessingP.SubReceive -> AMReceiverC;
  InNetworkProcessingP.SubPacket -> AMSenderC;

  components InNetworkProcessingC;
//  components RoutInfoC;
//  InNetworkProcessingP.RoutInfo -> RoutInfoC;

#else
  Forwarder.SubSend -> AMSenderC;  
  Forwarder.SubPacket -> AMSenderC;
  Forwarder.SubReceive -> AMReceiverC;

#endif
// */

//  Forwarder.SubSend -> AMSenderC;  
//  Forwarder.SubPacket -> AMSenderC;
//  Forwarder.SubReceive -> AMReceiverC;  

  Forwarder.SubSnoop -> AMSnooperC;
  Forwarder.RootControl -> Router;
  Forwarder.UnicastNameFreeRouting -> Router.Routing;
  Forwarder.RadioControl -> ActiveMessageC;
  Forwarder.PacketAcknowledgements -> AMSenderC.Acks;
  Forwarder.AMPacket -> AMSenderC;
  Forwarder.Leds -> LedsC;
  
  components new AMSenderC(AM_CTP_ROUTING) as SendControl;
  components new AMReceiverC(AM_CTP_ROUTING) as ReceiveControl;

  LinkEstimator = Estimator;
  
  Estimator.Random -> RandomC;

  Estimator.AMSend -> SendControl;
  Estimator.SubReceive -> ReceiveControl;
  Estimator.SubPacket -> SendControl;
  Estimator.SubAMPacket -> SendControl;

#if defined(PLATFORM_TELOSB) || defined(PLATFORM_MICAZ)
#ifndef TOSSIM
  components CC2420ActiveMessageC as PlatformActiveMessageC;
#else
  components DummyActiveMessageP as PlatformActiveMessageC;
#endif
#elif defined (PLATFORM_MICA2) || defined (PLATFORM_MICA2DOT)
  components CC1000ActiveMessageC as PlatformActiveMessageC;
#elif defined(PLATFORM_EYESIFXV1) || defined(PLATFORM_EYESIFXV2)
  components WhiteBitAccessorC as PlatformActiveMessageC;    
#else
  components DummyActiveMessageP as PlatformActiveMessageC;
#endif

  Estimator.LinkPacketMetadata -> PlatformActiveMessageC;

  // eventually
  //  Estimator.LinkPacketMetadata -> ActiveMessageC;

  MainC.SoftwareInit -> Estimator;
  
  // ADD: ctp instru
   components CtpInstrumentationP;

  Forwarder.CtpInstrumentation -> CtpInstrumentationP;
  Router.CtpInstrumentation -> CtpInstrumentationP;

#if defined(ROUTINSTRUM_PACKET)
	// MN: Rctp routing instrumentation
  components RctpRoutInstrumP;
  Router.RctpRoutInstrum -> RctpRoutInstrumP;
#endif


#if defined(PLATFORM_IRIS)
  components RF230ActiveMessageC;
  Forwarder.PacketRSSI -> RF230ActiveMessageC.PacketRSSI;
  Estimator.PacketRSSI -> RF230ActiveMessageC.PacketRSSI;

#else
  components CC2420ActiveMessageC;
  //Forwarder.CC2420Packet -> CC2420ActiveMessageC;
  Estimator.CC2420Packet -> CC2420ActiveMessageC;
#endif

#if defined(PRINTF_ENABLED_REAL_EXPERIMENT)  
	components PowerCycleP as LPLTrafficMonitor;
	Forwarder.TrafficMonitor -> LPLTrafficMonitor;
#endif
  

//  components new CounterToLocalTimeC(T32khz);
//  components new TransformCounterC(T32khz, uint32_t, T32khz, uint16_t, 0, uint32_t) as Transform;
//  components Msp430Counter32khzC;
//  CounterToLocalTimeC.Counter -> Transform;
//  Transform.CounterFrom -> Msp430Counter32khzC;
  //CtpInstrumentationP.LocalTime -> CounterToLocalTimeC;

}
