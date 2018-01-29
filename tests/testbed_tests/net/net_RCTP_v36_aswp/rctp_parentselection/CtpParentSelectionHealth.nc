/*
 *  @author Miguel Navarro
 */

interface CtpParentSelectionHealth {

	command nx_uint8_t getCandiateSetSize();

	command nx_uint16_t getBestNeighborFromParentSet();

}
