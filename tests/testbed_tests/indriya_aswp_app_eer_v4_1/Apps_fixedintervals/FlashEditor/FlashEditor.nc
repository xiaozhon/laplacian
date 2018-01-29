/**
 * Init, Read, and write the flash of a certain type <t>
 * 
 *
 * @author Xiaoyang Zhong
 *
 * @date   7-21-2014
 */ 


interface FlashEditor<t> {

	/**
	 * Initialize the flash volume. Mount it and make it valid.
	 *
	 */
	command void init();
	
	/**
	 * Event to indicate whether the initialization is SUCCESS or FAIL.
	 *
	 */
	event void initDone(error_t err);

	/**
	 * Read the data from the flash.
	 *
	 * @return A const pointer to the variable.
	 */
	command void read();
	
	/**
	 * readDone event
	 *
	 */
	event void readDone( error_t err, void* p, uint8_t len);
	
	/**
	 * Write the data to the flash
	 */
	command void write( const t* );
	
	/**
	 * writeDone event
	 **/
	event void writeDone(error_t err, void* buf, uint8_t len);
	
//	command t* readConfig();

}

