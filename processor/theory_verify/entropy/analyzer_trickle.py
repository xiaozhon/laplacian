'''
use the test packet data to analyze the laplacian of the network

** Trickle reset: better path and others
	- entropy and average
	
** Forwarded packets: workload of each node. 
	- entropy 


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

def run_analyzer(testname, infile, outfile, alloutput):
	inf = open(infile, 'r')
#	outf = open(outfile, 'w')
#	
#	outf.writelines('cycle_count\ttrickle_reset\ttrickle_reset_entropy\tnode_fwd_entropy\n')

	N = 36

	### trickle reset at each node
	node_trickle = [0 for i in range(0, N-1)]		### do not consider sink, shift the idx
	node_trickle_bp = [0 for i in range(0, N-1)]	### trickle reset due to better path 
	
	### number of forwarded packets each node
	node_fwd = [0 for i in range(0, N-1)]			### do not consider sink

	cycle_trickle = []			### total trickle reset in each cycle 
	cycle_trickle_bp = []
	cycle_trickle_percent = []
		
	cycle_entropy_fwd = []
	
	cycle_count = 0
	
	for cycle in blocks(inf):
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""
		cycle_count += 1
		if cycle_count < 2:
			### the first cycle has initialization
			## now only process a few cycles in the middle
			continue
	
	#	print cycle_count
		## initialization
		for i in range(N-1):
			node_trickle[i] = 0
			node_trickle_bp[i] = 0
			node_fwd[i] = 0		### the number of packets each node forwarded
				
		for pkt in cycle:
			s = pkt.split()
		
			if s[2] == 'trickle_reset':
				### this line is about trickle reset
				# DEBUG (27): trickle_reset all
				# DEBUG (27): trickle_reset better paths
				dbg_node = int(s[1][1:len(s[1])-2])
				node_trickle[dbg_node-1] += 1
				
				if s[3] == 'better':
					node_trickle_bp[dbg_node-1] += 1
				
				if dbg_node == 0:
					print testname + ': ' + pkt
				continue
			
			src = int(s[SRC])
			hop = int(s[HOP])
		
			path = []
			path.append(src)
		
			for i in range(PARENT, PARENT + hop):
				if i < len(s)-1:
					path.append(int(s[i]))
		
			for i in range(len(path)-1):
				### build the matrix
				## link = path[i] -> path[i+1]
				if path[i] == path[i+1]:
	#				print str(path[i])+ ' -> ' + str(path[i+1])
					continue
				
				node_fwd[path[i]-1] += 1		###
	
		###
		
		cycle_entropy_fwd.append(list_entropy(node_fwd))
		cycle_trickle.append(sum(node_trickle))
		cycle_trickle_bp.append(sum(node_trickle_bp))
		
		
		if sum(node_trickle) > 0:
			cycle_trickle_percent.append(sum(node_trickle_bp)*1.0/sum(node_trickle))
		else:
			cycle_trickle_percent.append(0)
		
#	outf.close()
	
	alloutput.writelines('%s\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n\n' % (testname, 
								np.mean(cycle_entropy_fwd), 
								np.std(cycle_entropy_fwd),
								np.mean(cycle_trickle),
								np.std(cycle_trickle),
								np.mean(cycle_trickle_bp),
								np.std(cycle_trickle_bp),
								np.mean(cycle_trickle_percent),
								np.std(cycle_trickle_percent)
								))
	
	### plot the figure if necessary

if __name__ == "__main__":
	outf_all = open('trickle_analysis_result_debug.txt', 'w')
#	outf_all = open('analysis_result_entropy_all_debug.txt', 'w')
	outf_all.writelines('test\tfwd_entropy_avg\tstd\ttrickle_reset_avg\tstd\ttrickle_better_path\tstd\tbetter_path_percent\tstd\n')
#	for i in range(8, 28, 2):
#		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_add-' + str(i) + '.txt'
#		outfname = 'analysis_result_entropy_noise_add_' + str(i) + '.txt'
#		
#		testname = 'add-' + str(i)
#		
#		print testname + ': ' + infname + '\n\n'
#		
#		run_analyzer(testname, infname, outfname, outf_all)
#		
	for i in range(7, 8):
		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_trace' + str(i) + '.txt'
		outfname = 'analysis_result_entropy_noise_test_trace' + str(i) + '.txt'
		
		testname = 'trace-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all)
	
	outf_all.close()
	
