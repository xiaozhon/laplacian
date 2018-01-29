/*
 * Copyright (c) 2011, University of Szeged
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the copyright holder nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Miklos Maroti
 */

interface TrafficMonitor
{
	/**
	 * Returns the number of times the radio driver was started.
	 */
	async command uint32_t getStartCount();

	/**
	 * Returns the current time (same as LocalTime<TMilli>.get)
	 */
	async command uint32_t getCurrentTime();

	/**
	 * Returns the total number of milliseconds the radio driver
	 * was operating (between start() and stopDone()).
	 */
	async command uint32_t getActiveTime();

	/**
	 * Returns the number of messages the radio driver has 
	 * transmitted (those for which send() returned with SUCCESS, 
	 * even though sendDone() might have returned with an error).
	 */
	async command uint32_t getTxMessages();

	/**
	 * Returns the number of messages the radio driver has 
	 * received. 
	 */
	async command uint32_t getRxMessages();

	/**
	 * Returns the sum of the lengths of all transmitted 
	 * messages (those for which send() returned with SUCCESS,
	 * even though sendDone() might have returned with an error).
	 * This count includes all preamble, STD and CRC bytes.
	 */
	async command uint32_t getTxBytes();

	/**
	 * Returns the sum of the lengths of all received 
	 * messages. This count includes all preamble, STD 
	 * and CRC bytes.
	 */
	async command uint32_t getRxBytes();

	/**
	 * Returns the number of times send() or sendDone()
	 * returned with an error.
	 */
	async command uint32_t getTxErrors();



	#if defined(PLATFORM_IRIS)
	#else
	async command void getCurrentTime_ActiveTime(uint32_t* currentTime_ptr, uint32_t* activeTime_ptr);
	#endif

}