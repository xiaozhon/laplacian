'''
** Compute the target metric of each cycle 
   target_metric = (PRR * link_entropy) / Path_length

DEBUG (0): data: 0 35 10 3 27 21 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 10

DEBUG (0): data: rounds, source, seqno, hopCounter, rcm->parent, rcm->path[1]


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

NO_LOOP = True

def run_analyzer(testname, infile, outfile, alloutput):
	inf = open(infile, 'r')
#	outf = open(outfile, 'w')
#	
#	outf.writelines('cycle_count\tentropy\tPRR\tPathLen\tmetric\n')

	N = 36
	pm = [[0 for i in range(N)] for j in range(N)]

	## count the usage of each link to compute link entropy
	entropy_pm = [[0 for i in range(N)] for j in range(N)]
	
	
	#### store the metric of each cycle 
	cycle_entropy = []
	cycle_metric = []
	

	cycle_count = 0
	for cycle in blocks(inf):
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""
		cycle_count += 1
		if cycle_count < 2 or cycle_count > 4:
			continue
		
	#	if cycle_count < 0 or cycle_count > 1000:
	#		## now only process a few cycles in the middle
	#		continue
	
	#	print cycle_count
		## initialization
		for i in range(N):
			for j in range(N):
				pm[i][j] = 0
				entropy_pm[i][j] = 0
				
		rcvd = []
		hops = []	### the hop count of this cycle, for unloopy packets

		for pkt in cycle:
#			if cycle_count == 573:
#				print pkt
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
				if i < len(s)-1:
					
					path.append(int(s[i]))
		
			for i in range(len(path)-1):
				### build the matrix
				## link = path[i] -> path[i+1]
				if path[i] == path[i+1]:
	#				print str(path[i])+ ' -> ' + str(path[i+1])
					continue
				
				if not NO_LOOP:
					entropy_pm[path[i]][path[i+1]] += 1
			
				pm[path[i]][path[i+1]] = 1
				
#				if cycle_count == 976:
#					print '%d -> %d' % (path[i], path[i+1])
				
				
				if i > 0 and (path[i] in path[:i-1]):
					is_loop = True
				
			if NO_LOOP and not is_loop:
				### if we don't consider loopy packets for the entropy
#				if cycle_count == 573:
#					print path 
				for i in range(len(path)-1):
					### build the matrix
					## link = path[i] -> path[i+1]
					if path[i] == path[i+1]:
		#				print str(path[i])+ ' -> ' + str(path[i+1])
						continue
				
					entropy_pm[path[i]][path[i+1]] += 1
#			else: 
#				### loopy packets
#				print cycle_count
#				print pkt
			
#			if not is_loop:
#				hops.append(hop)
			hops.append(hop)
			
			## check PRR in a simple way
			if src not in rcvd:
				rcvd.append(src)
	
		#### entropy analysis
#		print entropy_pm
		entropy, entropy_avg = link_entropy(entropy_pm)
		
		cur_prr = len(rcvd)*1.0 / (N-1)
		avg_pathlen = np.mean(hops)
		
		metric = cur_prr*entropy / avg_pathlen
		
#		outf.writelines('%d\t%.4f\t%.4f\t%.4f\t%.4f\n' % (cycle_count, 
#										entropy, 
#										cur_prr, 
#										avg_pathlen,
#										metric))
		
		cycle_metric.append(metric)
		cycle_entropy.append(entropy)
		
#	outf.close()
	
	alloutput.writelines('%s\t%.4f\t%.4f\t%.4f\t%.4f\n\n' % (testname, 
								np.mean(cycle_entropy), 
								np.std(cycle_entropy),
								np.mean(cycle_metric),
								np.std(cycle_metric)
								))
	
	### plot the figure if necessary

if __name__ == "__main__":
	outf_all = open('metric_analysis_result_withLoop.txt', 'w')
#	outf_all = open('metric_analysis_result_no_loop_debug.txt', 'w')
	outf_all.writelines('test\tentropy_avg\tstd\tmetric\tstd\n')
	for i in range(8, 28, 2):
		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_add-' + str(i) + '.txt'
		outfname = 'analysis_result_entropy_noise_add_' + str(i) + '.txt'
		
		testname = 'add-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all)
		
	for i in range(1, 16):
		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_trace' + str(i) + '.txt'
		outfname = 'analysis_result_entropy_noise_test_trace' + str(i) + '.txt'
		
		testname = 'trace-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all)
	
	outf_all.close()
	
