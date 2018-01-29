'''
analyze the average size of the parent set, based on the hop number.

e.g, at hop 3, the average size of the parent set is 3.4

For RCTP, merge three cycles data
'''

import sys, os 
import matplotlib.pyplot as plt
from util import *
from lapops import *
from numpy import linalg as LA
import numpy as np

### to compute centrality
import networkx as nx



SRC = 4
HOP = 6
PARENT = 7
PATH = 8

NO_LOOP = False

def run_analyzer(testname, infile, outfile, alloutput, numCycles):
	inf = open(infile, 'r')
	outf = open(outfile, 'w')
	
	outf.writelines('cycle_count\tprnt_set_size\n')
	
	nodeids = find_ids('nodeids.txt')
	N = len(nodeids)
	
#	### the parent set of each node 
#	### key = nodeid, value = {'hop', [list of hop number], 'prnt_set', [prnt list]}
#	node_prnt = {}
#	
#	### key = hop number, value = a list of average number of parents of each cycle
#	### e.g., 
#	hop_prnt = {}
	
	### 1. find the average size of the parent set of all the nodes
	cycle_prntSet = []
	### 2. find the average size of the parent set based on the hop number 
	

	cycle_count = 0
	for cycle in multi_blocks(inf, numCycles):	### merge 3 cycles to compute the parent set
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""

		cycle_count += 1
#		if cycle_count < 2: # or cycle_count > 10:	### Use two cycle data to verify the code
#			continue
		
	#	if cycle_count < 0 or cycle_count > 1000:
	#		## now only process a few cycles in the middle
	#		continue
	
#		print '---------------------------------- cycle_count: %d' % cycle_count
		## initialization
		### idx = node id, value = latest hop number 
		node_hop = [0 for i in range(N)]
	
		### key = node id, value = [prnt_list]
		node_prnt = {}
		
		for pkt in cycle:
#			if cycle_count == 573:
#				print pkt
			
			s = pkt.split()
			if len(s) < 6:
				continue
				
#			print pkt
			src = int(s[SRC])
			hop = int(s[HOP])
		
			node_hop[idx(nodeids, src)] = hop
					
			path = []
			path.append(src)
			
			is_loop = False
			
			for i in range(PARENT, PARENT + hop):
				if i < len(s)-1:
					if int(s[i]) not in nodeids:
						### err packets
						continue
					path.append(int(s[i]))
			
			for i in range(len(path)-1):
				### build the matrix
				## link = path[i] -> path[i+1]
				if path[i] == path[i+1]:
	#				print str(path[i])+ ' -> ' + str(path[i+1])
					continue
				
				if cycle_count == 10:
					print str(path[i])+ ' -> ' + str(path[i+1])
				
				if node_prnt.has_key(path[i]):
					if path[i+1] not in node_prnt[path[i]]:
						### this is a new parent of node 'path[i]
						node_prnt[path[i]].append(path[i+1])
				else:
					### the node is not stored yet
					node_prnt[path[i]] = []
					node_prnt[path[i]].append(path[i+1])
					
		### finished storing parent list, compute average size of parent set
		total = 0
		node_count = 0
		for node in node_prnt:
			if cycle_count == 10:
				print str(node) + ': ' + str(node_prnt[node])
			node_count += 1
			total = total + len(node_prnt[node])
#			print '\ttotal: %d' % total
			
		avg_size = total*1.0 / node_count
		
		outf.writelines('%d\t%.4f\n' % (cycle_count, avg_size))
		
		cycle_prntSet.append(avg_size)
			
	outf.close()
	
	alloutput.writelines('%s\t%.4f\t%.4f\n\n' % (testname, np.mean(cycle_prntSet), np.std(cycle_prntSet)))
	
	### plot the figure if necessary

if __name__ == "__main__":
#	outf_all = open('prntSet_analysis_result_withLoop.txt', 'w')
#	outf_all = open('result_prntSet_debug.txt', 'w')

	outf_all = open('plot_cycles_prntSet_analysis_result_withLoop.txt', 'w')
	outf_all.writelines('test\tavg_prntSet\tstd\n')
	for i in range(1, 40, 1):
		infname = '../../../../data/indriya/protocol_metrics/orw/20170222_indriya_orw_LPL1024_sink31_1min_incycle_sink_always_on_test1.txt'
		
		
#		outfname = 'prnt_set_analysis_result_' + str(i) + '.txt'
		outfname = 'prnt_set_analysis_result_1.txt'
		
		testname = 'Orw-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all, i)
		
#	for i in range(1, 16):
#		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_trace' + str(i) + '.txt'
#		outfname = 'analysis_result_entropy_noise_test_trace' + str(i) + '.txt'
#		
#		testname = 'trace-' + str(i)
#		
#		print testname + ': ' + infname + '\n\n'
#		
#		run_analyzer(testname, infname, outfname, outf_all)
	
	outf_all.close()
	
