
module RctpRoutInstrumP {
  provides interface RctpRoutInstrum;
}

implementation {

  typedef nx_struct rt_neigh 
	{
    nx_uint16_t id;
    nx_uint16_t petx;
    nx_uint16_t parent;
  } rt_neigh;

  typedef nx_struct RoutInstum 
	{
    nx_uint8_t routingTableActive;
    nx_uint16_t parentParent;
		rt_neigh neighbors[ROUTINSTRUM_NEIGHBORS];		

  } RoutInstum;

  RoutInstum stats_routInstum;

	#if defined(PRINTF_ENABLED)  
	bool dbg_rtInstum = FALSE;
	#endif	


  command error_t RctpRoutInstrum.init() {
		uint8_t count = 0;    
		stats_routInstum.routingTableActive = 0xFF;
		stats_routInstum.parentParent = 0xFFFF;

		for(count=0;count<ROUTINSTRUM_NEIGHBORS;count++){
			stats_routInstum.neighbors[count].id = INVALID_ADDR;
			stats_routInstum.neighbors[count].petx = MAX_METRIC;
			stats_routInstum.neighbors[count].parent = INVALID_ADDR;
		}			
    return SUCCESS;
  }
    
  command error_t RctpRoutInstrum.getPkt(nx_uint8_t *buf) {
    memcpy(buf, &stats_routInstum, sizeof(RoutInstum));
    return SUCCESS;
  }

  command uint8_t RctpRoutInstrum.routInst_size() {
    return sizeof(RoutInstum);
  }


  command error_t  RctpRoutInstrum.set_routingTableActive(uint8_t routingTableActive){
		stats_routInstum.routingTableActive = routingTableActive;
		return SUCCESS;
	}

  command uint8_t RctpRoutInstrum.get_routingTableActive(){
		return 	stats_routInstum.routingTableActive;
	}

  command error_t RctpRoutInstrum.set_parentParent(uint16_t parentParent){
		stats_routInstum.parentParent = parentParent;
		return SUCCESS;
	}

  command uint16_t 	RctpRoutInstrum.get_parentParent(){
		return stats_routInstum.parentParent;
	}


  command error_t RctpRoutInstrum.set_rctp_neighbor(uint8_t i, uint16_t id, uint16_t petx,uint16_t parent){
		if(i<ROUTINSTRUM_NEIGHBORS){		
			stats_routInstum.neighbors[i].id = id;
			stats_routInstum.neighbors[i].petx = petx;
			stats_routInstum.neighbors[i].parent = parent;
		}
		return SUCCESS;		
	}


  command uint16_t 	RctpRoutInstrum.get_rctp_neighbor(uint8_t i){
		return	stats_routInstum.neighbors[i].id;
	}

  command uint16_t 	RctpRoutInstrum.get_rctp_neighbor_petx(uint8_t i){
		return	stats_routInstum.neighbors[i].petx;
	}

  command uint16_t 	RctpRoutInstrum.get_rctp_neighbor_parent(uint8_t i){
		return	stats_routInstum.neighbors[i].parent;
	}

	#if defined(PRINTF_ENABLED)  
	command error_t RctpRoutInstrum.printAll(){
		uint8_t count = 0;    
		printf("\nRtInst: active: %u\n",stats_routInstum.routingTableActive);
		printfflush();

		for(count=0;count<ROUTINSTRUM_NEIGHBORS;count++){			

			if(dbg_rtInstum){
				printf("RtInst: i:%u neig:%u petx:%u parent:%u \n",
								count, 
								stats_routInstum.neighbors[count].id,
								stats_routInstum.neighbors[count].petx,
								stats_routInstum.neighbors[count].parent);
				printfflush();
			}

		}		
		printf("\n");
		printfflush();
		return SUCCESS;
	}
	#endif

	
	// ------------------  Parameters from the flash  -------------------------------
	/*
	command error_t RctpRoutInstrum.set_flash_node_id(uint16_t id){
		stats_routInstum.flash_node_id = id;
		return SUCCESS;
	}
	command uint16_t RctpRoutInstrum.get_flash_node_id(){
		return stats_routInstum.flash_node_id;
	}

	command error_t RctpRoutInstrum.set_flash_wdt_resets(uint8_t count){
		stats_routInstum.flash_wdt_resets = count;
		return SUCCESS;
	}

	command uint8_t RctpRoutInstrum.get_flash_wdt_resets(){
		return stats_routInstum.flash_wdt_resets;
	}
	*/ 
}
