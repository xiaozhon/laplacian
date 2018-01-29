interface CtpInstrumentation {
  command error_t ctrl_txpkt();
  command error_t ctrl_rxpkt();
  command error_t ctrl_parentchange();
  command error_t ctrl_tricklereset();
  command error_t data_txpkt();
  command error_t data_rxpkt();
  command error_t data_rxack();
  command error_t data_queuedrop();
  command error_t data_pktdup();
  command error_t data_inconsistent();

  command error_t init();
  command error_t summary(nx_uint8_t *buf);
  command uint8_t summary_size();

  command error_t set_total_time(nx_uint32_t t);
  //command error_t set_dutycycle(nx_uint16_t dc);
  //command error_t set_flash_node_id(nx_uint16_t fnid);
  //command error_t set_flash_wdt_resets(nx_uint8_t fwdtr);
}
