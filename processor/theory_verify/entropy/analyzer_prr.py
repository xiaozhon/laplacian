'''
find the network statistics of the simulations

	- PRR
	- duplicates from the same source node
	- loops
	- trickle resets
	- forwarded (node workload, although this can also be found using the path)
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
#	outf.writelines('cycle_count\tconnectivity\tlinks\ttrees\tentropy\tlink_entropy_avg\n')

	N = 36
	am = [[0 for i in range(N)] for j in range(N)]
	
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
		if cycle_count <2 or cycle_count > 2:
			## now only process a few cycles in the middle
			continue
	
	#	print cycle_count
		## initialization
		for i in range(N):
			for j in range(N):
				am[i][j] = 0
				
		rcvd = []
		duplicates = 0
		loop = 0
		link_usage = 0
		
		for pkt in cycle:
			s = pkt.split()
			
			if len(s) < 6:
				continue
			
#			print pkt
			
			src = int(s[SRC])
			hop = int(s[HOP])
		
			path = []
			path.append(src)
			
			is_loop = False
		
			for i in range(PARENT, PARENT + hop):	
				### detect loopy packets here
				if i < len(s)-1:
					
					path.append(int(s[i]))
		
			for i in range(len(path)-1):
				### build the matrix
				## link = path[i] -> path[i+1]
				if path[i] == path[i+1]:
					### self loop
	#				print str(path[i])+ ' -> ' + str(path[i+1])
					continue
				
				am[path[i]][path[i+1]] = 1
				am[path[i+1]][path[i]] = 1
				
				if i > 0 and (path[i] in path[:i-1]):
					is_loop = True
					
				link_usage += 1
			
			## check PRR in a simple way
			if src not in rcvd:
				rcvd.append(src)
			else:
				### duplicates from the same source node
				duplicates += 1
#				print '\t\tduplicated: ' + pkt
			
			if is_loop:
				loop += 1
#				print testname + ': ' + pkt
#				print '\t\tloop: ' + pkt
				cycle_loop_hop.append(hop)
			else:
				cycle_hop.append(hop)
		
		cycle_dup.append(duplicates)
		cycle_prr.append(len(rcvd)*1.0 / (N-1))
		cycle_loop.append(loop)
		cycle_link_usage.append(link_usage)
		
		print '\tlink_usage: ' + str(link_usage) + '\tloops: ' + str(loop) + '\tduplicates: ' + str(duplicates) + '\tprr: ' + str(len(rcvd)*1.0 / (N-1))
		print cycle_hop
		print np.mean(cycle_hop)
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
	
	### plot the figure if necessary

if __name__ == "__main__":
	outf_all = open('prr_analysis_result_debug.txt', 'w')
	outf_all.writelines('test\tcycle_prr_avg\tstd\tduplicates' + 
						'\tdup_std\tloop_avg\tloop_std\tloop_sum' + 
						'\thop_avg\tstd\tloopy_hop_avg\tstd' + 
						'\tlink_usage_avg\tstd\n')
	for i in range(26, 28, 2):
		infname = '../../../data/tossim/ctp_uniform/noise_sim/uniform_36nodes_ctp_noise_test_add-' + str(i) + '.txt'
		outfname = 'prr_analysis_result_noise_add_' + str(i) + '.txt'
		
		testname = 'add-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all)
		
#	for i in range(7, 8):
#		infname = '../../../data/tossim/ctp_uniform/noise_sim/uniform_36nodes_ctp_noise_test_trace' + str(i) + '.txt'
#		outfname = 'prr_analysis_result_noise_trace' + str(i) + '.txt'
#		
#		testname = 'trace-' + str(i)
#		
#		print testname + ': ' + infname + '\n\n'
#		
#		run_analyzer(testname, infname, outfname, outf_all)
	
	outf_all.close()
	
