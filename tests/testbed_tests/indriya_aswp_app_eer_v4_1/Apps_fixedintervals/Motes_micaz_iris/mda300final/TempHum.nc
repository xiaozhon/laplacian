/*									tab:4
 * "Copyright (c) 2000-2003 The Regents of the University  of California.  
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
 * Copyright (c) 2002-2003 Intel Corporation
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached INTEL-LICENSE     
 * file. If you do not find these files, copies can be found by writing to
 * Intel Research Berkeley, 2150 Shattuck Avenue, Suite 1300, Berkeley, CA, 
 * 94704.  Attention:  Intel License Inquiry.
 */
/*
 *
 * Authors:		Mohammad Rahmim, Joe Polastre
 *
 * $Id: TempHum.nc,v 1.1 2004/05/11 21:07:44 jdprabhu Exp $
 */

configuration TempHum {
  provides {
    //update to read
    //interface SplitControl as TempHumControl;
    interface Read<uint16_t> as Temperature;
    interface Read<uint16_t> as Humidity;
    //don't seem to be wired to anything
    //interface ADCError as TempError;
    //interface ADCError as HumError;
  }
}
implementation {
  components TempHumM, MainC;
  components MicaBusC, HplAtm128InterruptC;
  MainC.SoftwareInit -> TempHumM.Init;
  TempHumM.Clock -> MicaBusC.PW0;
  TempHumM.Data ->  MicaBusC.Int3;
  //Atm128 int 7 == mica int3
  TempHumM.Int7 -> HplAtm128InterruptC.Int7;
  Temperature = TempHumM.Temperature;
  Humidity = TempHumM.Humidity;
  //TempHumControl = TempHumM.TempHumControl;
  

  //don't seem to actually exist
  //TempError = TempHumM.TempError;
  //HumError = TempHumM.HumError;

  //TempHumM.TimerControl -> TimerC;
  //TempHumM.Timer -> TimerC.Timer[unique("Timer")];
}

