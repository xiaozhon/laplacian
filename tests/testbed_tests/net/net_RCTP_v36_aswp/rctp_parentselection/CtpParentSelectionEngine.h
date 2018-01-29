/*
 *  @author Miguel Navarro
 */

#ifndef CTP_PARENT_SELECTION_H
#define CTP_PARENT_SELECTION_H


typedef struct {
  routing_table_entry * candidate;
} ParentTableEntry;

typedef nx_struct parentSet {
  nx_uint8_t  	setSize;
  nx_uint16_t 	maxPathETX;
	nx_uint16_t 	bestNeighbor;
	nx_uint8_t  	maxPathETXPos;
  nx_uint16_t 	setETX;

  nx_uint16_t 	previousFwder;
} parentSet;


#endif
