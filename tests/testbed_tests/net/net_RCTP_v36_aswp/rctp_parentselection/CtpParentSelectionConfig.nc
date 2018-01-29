/*
 *  @author Miguel Navarro
 */

interface CtpParentSelectionConfig {

	command void initializeParentSet();

  command error_t addParentCandidate( routing_table_entry* entry, nx_uint16_t candETX );

	command am_addr_t drawRandomParent();

	command error_t getParentSetETX( nx_uint16_t* parentSetETX, nx_uint8_t* parentSetSize );

	command nx_uint8_t getParentSetSize();

}
