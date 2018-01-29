'''
find the network statistics of the simulations

	Only compute the node prr by reading data line by line

file:
	/opt/github/laplacian/data/cooja/OrwTest/OrwTest_2_feed_positions_larger_test1.txt
	   
	# DEBUG (0): data: 0 32 5 3 19 21 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5
	     0   1    2
	#Sink Received: data: 0 30 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
	  0       1      2    3  4
	  
	
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
SEQ = 5
HOP = 6
PARENT = 7
PATH = 8

NO_LOOP = False

def run_analyzer(testname, infile, outfile, alloutput):
	inf = open(infile, 'r')
	outf = open(outfile, 'w')
#	
	nodeids = find_ids('nodeids.txt')
	N = len(nodeids)
	
	### node's sequence number
	### key = nodeid, value = [seq list]
	node_seq = {}
	
	for i in range (1):
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""
	
		
		for pkt in inf:
			s = pkt.split()
			
			if len(s) < 15:
				continue
			print pkt
			
			src = int(s[SRC])
			hop = int(s[HOP])
			seq = int(s[SEQ])
			
			if src not in nodeids:
				continue
		
			
			if not node_seq.has_key(int(s[SRC])):
				node_seq[int(s[SRC])] = []
			
			if int(s[SEQ]) not in node_seq[int(s[SRC])]:
				node_seq[int(s[SRC])].append(int(s[SEQ]))
			
	
	outf.writelines('\nnodeid\tprr\tseq_list\n')
	node_prr = []
	for i in range(N):
		if not node_seq.has_key(nodeids[i]):
			continue
		max_seq = max(node_seq[nodeids[i]])
		min_seq = min(node_seq[nodeids[i]])
		node_prr.append(len(node_seq[nodeids[i]]) * 1.0 / (max_seq - min_seq + 1))
		outf.writelines(str(nodeids[i]) + ' ' + str(node_prr[len(node_prr)-1]) + '\t' + str(node_seq[nodeids[i]]) + '\n')
		
	outf.writelines(str(np.mean(node_prr)))
	
	### plot the figure if necessary

if __name__ == "__main__":
	for i in range(1, 2, 1):

		outf_all = 0
#		infname = '../../../../data/indriya/protocol_metrics/rctp/20170222_indriya_rctp_lpl1024_sink31_1min_caa1800_incycle_sink_alwaysON_test1.txt'
		infname = '../../../../data/indriya/protocol_metrics/rctp/20170222_indriya_rctp_lpl1024_sink31_1min_caa1800_incycle_sink_alwaysON_test2.txt'
		
		outfname = 'node_prr_analysis_result_' + str(i) + '.txt'
		
		testname = 'Rctp-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all)
		
#	for i in range(1, 16):
#		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_trace' + str(i) + '.txt'
#		outfname = 'prr_analysis_result_noise_trace' + str(i) + '.txt'
#		
#		testname = 'trace-' + str(i)
#		
#		print testname + ': ' + infname + '\n\n'
#		
#		run_analyzer(testname, infname, outfname, outf_all)
#	
	
