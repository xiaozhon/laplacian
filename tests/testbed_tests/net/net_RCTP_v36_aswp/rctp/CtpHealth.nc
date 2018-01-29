
interface CtpHealth {
	command error_t init() ;

  command error_t hlth_generated();
	command error_t get_hlth_generated(nx_uint16_t * gen);

  command error_t hlth_forwarded();
  command error_t get_hlth_forwarded(nx_uint16_t * fwd);

  command error_t hlth_retx();
  command error_t get_hlth_retx(nx_uint16_t * retx);

  command error_t hlth_dropped();
  command error_t get_hlth_dropped(nx_uint16_t * drp);

  //command error_t hlth_current_retx();
  //command error_t get_hlth_current_retx(nx_uint8_t * cretx);

	command error_t get_hlth_psetSize(nx_uint8_t * psetSize);

	command error_t get_hlth_rctpParent(nx_uint16_t * rctpParent);
}
