module CtpHealthP {
  provides interface CtpHealth;
	uses interface CtpParentSelectionHealth;
}

implementation {

  typedef nx_struct HealthCounters {
		nx_uint16_t generated;
		nx_uint16_t forwarded;
		nx_uint16_t total_retx;
		nx_uint16_t dropped;
		//nx_uint8_t  current_retx;
  } HealthCounters;

  HealthCounters hlth;

	command error_t CtpHealth.init() {
		hlth.generated 		= 0;
		hlth.forwarded 		= 0;
		hlth.total_retx 	= 0;
		hlth.dropped 			= 0;
		//hlth.current_retx = 0;
		return SUCCESS;
	}

  command error_t CtpHealth.hlth_generated(){
		hlth.generated++;
		return SUCCESS;
	}

	command error_t CtpHealth.get_hlth_generated(nx_uint16_t * gen){
		*gen = hlth.generated;
		return SUCCESS;
	}

  command error_t CtpHealth.hlth_forwarded(){
		hlth.forwarded++;
		return SUCCESS;
	}

  command error_t CtpHealth.get_hlth_forwarded(nx_uint16_t * fwd){
		*fwd = hlth.forwarded;
		return SUCCESS;
	}

  command error_t CtpHealth.hlth_retx(){
		hlth.total_retx++;
		return SUCCESS;
	}

  command error_t CtpHealth.get_hlth_retx(nx_uint16_t * retx){
		*retx = hlth.total_retx;
		return SUCCESS;
	}

  command error_t CtpHealth.hlth_dropped(){
		hlth.dropped++;
		return SUCCESS;
	}

  command error_t CtpHealth.get_hlth_dropped(nx_uint16_t * drp){
		*drp = hlth.dropped;
		return SUCCESS;
	}

	/*
  command error_t CtpHealth.hlth_current_retx(){
		hlth.current_retx++;
		return SUCCESS;
	}

  command error_t CtpHealth.get_hlth_current_retx(nx_uint8_t * cretx){
		*cretx = hlth.current_retx;
		return SUCCESS;
	}
	*/

	command error_t CtpHealth.get_hlth_psetSize(nx_uint8_t * psetSize){
		*psetSize = call CtpParentSelectionHealth.getCandiateSetSize();
		return SUCCESS;
	}

	command error_t CtpHealth.get_hlth_rctpParent(nx_uint16_t * rctpParent){
		*rctpParent = call CtpParentSelectionHealth.getBestNeighborFromParentSet();
		return SUCCESS;
	}

}
