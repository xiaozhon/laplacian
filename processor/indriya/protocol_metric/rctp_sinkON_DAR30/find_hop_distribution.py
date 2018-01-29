'''
find the network statistics of the simulations

	- PRR
	- duplicates from the same source node
	- loops
	- trickle resets
	- forwarded (node workload, although this can also be found using the path)

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

def run_analyzer(testname, infile, alloutput):
	inf = open(infile, 'r')
	
	nodeids = find_ids('nodeids.txt')
	N = len(nodeids)
	
	### key = node id, value = [hop list from received packets]
	node_hop = {}
	hop_packets = [0 for i in range(N)]		### the number of packets on each hop
	
	cycle_count = 0
	for cycle in blocks(inf):
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""
		cycle_count += 1
		
		for pkt in cycle:
			s = pkt.split()
			
			if len(s) < 4:
				continue
			
			src = int(s[SRC])
			hop = int(s[HOP])
			seq = int(s[SEQ])
			
			if src not in nodeids:
				continue
			
			if not node_hop.has_key(src):
				node_hop[src] = []
				
			node_hop[src].append(hop)
			
			hop_packets[hop] += 1
	
	avg_hops = [0 for i in range(N)]
	hop_node_count = [0 for i in range(N)]
	for i in range(N):
		### compute the average hop of each node 
		if nodeids[i] != 31:
			avg_hops[i] = np.mean(node_hop[nodeids[i]])
		
			hop_node_count[int(round(avg_hops[i]))] += 1
		
		alloutput.writelines('%d\t%.4f\n' % (nodeids[i], avg_hops[i]))
	
	hop_bars = []
	
	for i in range(N):
		if hop_node_count[i] > 0:
			hop_bars.append(hop_node_count[i])
	print hop_bars
	
#	x = [i+1 for i in range(len(hop_bars))]
	x = np.arange(len(hop_bars)) 
	bar_width = 0.35
	print x
	f, ax = plt.subplots()
	plt.tight_layout(pad=2)
	ax.bar(x, hop_bars, bar_width, color='b')
	
	ax.set_xticks(x)
	ax.set_xticklabels(x+1)
	
	ax.set_ylabel('Node Count')
	ax.set_xlabel('Hop')
	plt.savefig('node_hop_distribution.png')
	
	plt.clf()
	
	######### packet distribution
	hop_bars = []
	
	for i in range(N):
		if hop_packets[i] > 0:
			hop_bars.append(hop_packets[i])
	print hop_bars
	
#	x = [i+1 for i in range(len(hop_bars))]
	x = np.arange(len(hop_bars)) 
	bar_width = 0.35
	print x
	f, ax = plt.subplots()
#	plt.tight_layout(pad=2)
	ax.bar(x, hop_bars, bar_width, color='b')
	
	ax.set_xticks(x)
	ax.set_xticklabels(x+1)
	
	ax.set_ylabel('Packet Count')
	ax.set_xlabel('Hop')
	plt.savefig('packet_hop_distribution.png')
	
	
	### plot the figure if necessary

if __name__ == "__main__":
	outf_all = open('hop_distribution_analysis.txt', 'w')
	outf_all.writelines('node\tavg_hops\n')	### use node's average hop count
	
	for i in range(1, 2, 1):
#		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_add-' + str(i) + '.txt'
#		outfname = 'prr_analysis_result_' + str(i) + '.txt'
#		
#		testname = 'add-' + str(i)

#		infname = '../../../../data/indriya/protocol_metrics/orw/20170209_indriya_orw_default_sinkn31_30sec_test1.txt'
		
		infname = '../../../../data/indriya/protocol_metrics/rctp/20170222_indriya_rctp_lpl1024_sink31_1min_caa1800_incycle_sink_alwaysON_test1_DAR30.txt'
		
		
		outfname = 'hop_distribution_analysis_result_' + str(i) + '.txt'
		
		testname = 'Ctp-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outf_all)
		
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
	outf_all.close()
	
