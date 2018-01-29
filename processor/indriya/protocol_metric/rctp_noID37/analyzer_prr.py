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

def run_analyzer(testname, infile, outfile, alloutput):
	inf = open(infile, 'r')
	outf = open(outfile, 'w')
#	
	outf.writelines('cycle\tcycle_prr\tduplicates' + 
						'\tloop_count' + 
						'\thop_avg\tstd\tloopy_hop_avg\tstd' + 
						'\tlink_usage\terr_count\n')
	outf_dup = open('duplicated_src_seq_pairs.txt', 'w')
	nodeids = find_ids('nodeids.txt')
	N = len(nodeids)
	am = [[0 for i in range(N)] for j in range(N)]
	
	
	
	### node's sequence number
	### key = nodeid, value = [seq list]
	node_seq = {}
	
	### the prr of each cycle
	cycle_prr = []
	cycle_dup = []
	cycle_loop = []
	cycle_hop = []		### the hop number of all the path without loop
	cycle_loop_hop = []		### the hop number of all the path with loop
	
	cycle_link_usage = []	### the number of link usages of each cycle
	
	cycle_count = 0
	for cycle in blocks(inf):
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""
		cycle_count += 1
		if cycle_count < 2:
	#		## now only process a few cycles in the middle
			continue
	
		print cycle_count
		## initialization
		for i in range(N):
			for j in range(N):
				am[i][j] = 0
				
		rcvd = []	## value is node id 
		rcvd_dup_check = []	 ## value is (nodeid, seq)
		duplicates = 0
		loop = 0
		link_usage = 0
		hops = []
		loopy_hops = []
		err_pkts = []
		
		for pkt in cycle:
			s = pkt.split()
			
			if len(s) < 4:
				continue
			
			src = int(s[SRC])
			hop = int(s[HOP])
			seq = int(s[SEQ])
		
			### check duplicates using (src, seq)
			if [src, seq] not in rcvd_dup_check:
				rcvd_dup_check.append([src, seq])
			else:
				outf_dup.writelines(str(src) + ' ' + str(seq) + '\n')

				duplicates += 1
			
			
			path = []
			path.append(src)
			
			is_loop = False
		
			for i in range(PARENT, PARENT + hop):	
				### detect loopy packets here
				if i < len(s)-1:
				
					if int(s[i]) not in nodeids:
						### error packets
						err_pkts.append(pkt)
						continue
					
					path.append(int(s[i]))
			if cycle_count == 10 or cycle_count == 11:
				print pkt 
				print '\t' + str(path)
		
			for i in range(len(path)-1):
				### build the matrix
				## link = path[i] -> path[i+1]
				if path[i] == path[i+1]:
					### self loop
	#				print str(path[i])+ ' -> ' + str(path[i+1])
					continue
				
#				print 'node: %d, idx: %d' % (path[i], idx(nodeids, path[i]))
#				print 'node: %d, idx: %d' % (path[i+1], idx(nodeids, path[i+1]))
				am[idx(nodeids, path[i])][idx(nodeids, path[i+1])] = 1
				am[idx(nodeids, path[i+1])][idx(nodeids, path[i])] = 1
				
				if i > 0 and (path[i] in path[:i-1]):
					is_loop = True
					
				link_usage += 1
			
			
			if not node_seq.has_key(int(s[SRC])):
				node_seq[int(s[SRC])] = []
			
			if int(s[SEQ]) not in node_seq[int(s[SRC])]:
				node_seq[int(s[SRC])].append(int(s[SEQ]))
			
			## check PRR in a simple way
			if src not in rcvd:
				rcvd.append(src)
#			else:
#				### duplicates from the same source node
#				duplicates += 1
						
			
			if is_loop:
				loop += 1
#				print testname + ': ' + pkt
#				print '\t\t' + str(path)
				cycle_loop_hop.append(hop)
				loopy_hops.append(hop)
#			else:
				
			if not NO_LOOP:
				cycle_hop.append(hop)	### hop count with loop
				hops.append(hop)	### the hops of this cycle
			else:
				## hop count without loop
				if not is_loop:
					cycle_hop.append(hop)
					hops.append(hop)
		
		if cycle_count == 10:
			for i in range(N):
				print str(nodeids[i]) + ': ' + str(am[i])
			
			print rcvd
		
		outf.writelines('%d\t%.4f\t%d\t%d\t%.4f\t%.4f\t%.4f\t%.4f\t%d\t%d\n' % (
								cycle_count,
								len(rcvd)*1.0 / (N-1),
								duplicates,
								loop,
								np.mean(hops),
								np.std(hops),
								np.mean(loopy_hops),
								np.std(loopy_hops),
								link_usage,
								len(err_pkts)
									))
		
		for pkt in err_pkts:
			
			outf.writelines(pkt)
		
		
		cycle_dup.append(duplicates)
		cycle_prr.append(len(rcvd)*1.0 / (N-1))
		cycle_loop.append(loop)
		cycle_link_usage.append(link_usage)
	
	outf_dup.close()
#	outf.close()
	
	alloutput.writelines('%s\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n\n' % (testname, 
											np.mean(cycle_prr), 
											np.std(cycle_prr),
											np.mean(cycle_dup),
											np.std(cycle_dup),
											np.mean(cycle_loop),
											np.std(cycle_loop),
											sum(cycle_loop),
											np.mean(cycle_hop),
											np.std(cycle_hop),
											np.mean(cycle_loop_hop),
											np.std(cycle_loop_hop),
											np.mean(cycle_link_usage),
											np.std(cycle_link_usage)
											))
	
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
	outf_all = open('prr_analysis_result_all_withLoop.txt', 'w')
	outf_all.writelines('test\tcycle_prr_avg\tstd\tduplicates' + 
						'\tdup_std\tloop_avg\tloop_std\tloop_sum' + 
						'\thop_avg\tstd\tloopy_hop_avg\tstd' + 
						'\tlink_usage_avg\tstd\n')
	for i in range(1, 2, 1):


		infname = '../../../../data/indriya/protocol_metrics/rctp/20170221_indriya_rctp_lpl1024_sink31_1min_caa1800_incycle_noID37_test1.txt'
		
#		infname = '../../../../data/indriya/protocol_metrics/rctp/20170222_indriya_rctp_lpl1024_sink31_1min_caa1800_incycle_noID37_test2.txt'
		
		outfname = 'prr_analysis_result_' + str(i) + '.txt'
		
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
	outf_all.close()
	
