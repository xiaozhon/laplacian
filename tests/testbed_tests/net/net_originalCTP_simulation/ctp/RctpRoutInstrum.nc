interface RctpRoutInstrum 
{

  command error_t  	set_routingTableActive(uint8_t routingTableActive);
  command uint8_t 	get_routingTableActive();

  command error_t  	set_parentParent(uint16_t parentParent);
  command uint16_t 	get_parentParent();

  command error_t  	set_rctp_neighbor(uint8_t i, uint16_t id, uint16_t petx, uint16_t parent);
  command uint16_t 	get_rctp_neighbor(uint8_t i);
  command uint16_t 	get_rctp_neighbor_petx(uint8_t i);
  command uint16_t 	get_rctp_neighbor_parent(uint8_t i);

  command error_t init();
  command error_t getPkt(nx_uint8_t *buf);
  command uint8_t routInst_size();

			
	#if defined(PRINTF_ENABLED)  
	command error_t printAll();			
	#endif


	/*
	command error_t set_flash_node_id(uint16_t id);
	command uint16_t get_flash_node_id();

	command error_t set_flash_wdt_resets(uint8_t count);
	command uint8_t get_flash_wdt_resets();
	*/

}
