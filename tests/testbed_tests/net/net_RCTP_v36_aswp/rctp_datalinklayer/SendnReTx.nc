/**
* Author: Miguel Navarro
*/

interface SendnReTx {

	command error_t cancel(message_t *msg);

	command void *getPayload(message_t *msg, uint8_t len);

	command uint8_t maxPayloadLength();

  // Defines the number of retransmissions
	command error_t send(am_addr_t addr, message_t *msg, uint8_t len, uint8_t numretx);

	event void sendDone(message_t *msg, error_t error);

}
