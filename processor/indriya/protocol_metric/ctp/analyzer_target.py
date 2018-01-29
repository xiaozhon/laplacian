'''
** Compute the target metric of each cycle 
   target_metric = (PRR * link_entropy) / Path_length


Use entropy/prr result files to compute the metric, instead of reading the raw data
file.

	entropy: no loop, with loop 
	prr:	 not related
	pathLen: no loop, with loop


* analysis_result_entropy_noLoop.txt 
  analysis_result_entropy_withLoop.txt 
	test	entropy_avg	std	node_entropy	std

* prr_analysis_result_all_noLoop.txt
  prr_analysis_result_all_withLoop.txt
	test	cycle_prr_avg	std	duplicates	dup_std	loop_avg	loop_std	loop_sum	hop_avg	std	loopy_hop_avg	std	link_usage_avg	std

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


def run_analyzer(testname, infile, outfile, alloutput, entropy_no_loop, pathLen_no_loop):
	"""
	testname: string, the name of the test 
	infile: 	input file handler
	alloutput:	overall output file handler
	entropy_no_loop:	bool, True if entropy computed without loop
	pathLen_no_loop:	bool, True if path len computed without loop
	"""
	inf = open(infile, 'r')
	
	outf = open(outfile, 'w')
	outf.writelines('cycle_count\tentropy\tprr\tpathlen\tmetric\n')
	
	nodeids = find_ids('nodeids.txt')

	N = 33
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
#		if cycle_count < 2:
#			continue
		
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
		hops = []	### the hop count of this cycle

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
					
					if int(s[i]) not in nodeids:
						continue
					path.append(int(s[i]))
		
			for i in range(len(path)-1):
				### build the matrix
				## link = path[i] -> path[i+1]
				if path[i] == path[i+1]:
	#				print str(path[i])+ ' -> ' + str(path[i+1])
					continue
				
				if not entropy_no_loop:
					### include loopy packets here
					entropy_pm[idx(nodeids, path[i])][idx(nodeids, path[i+1])] += 1
			
				pm[idx(nodeids, path[i])][idx(nodeids, path[i+1])] = 1
				
				if i > 0 and (path[i] in path[:i-1]):
					## check loop
					is_loop = True
				
			if entropy_no_loop:
				### if we don't consider loopy packets for the entropy
				if not is_loop:
					### this is not a loopy packet
					for i in range(len(path)-1):
						### build the matrix
						## link = path[i] -> path[i+1]
						if path[i] == path[i+1]:
			#				print str(path[i])+ ' -> ' + str(path[i+1])
							continue
				
						entropy_pm[idx(nodeids, path[i])][idx(nodeids, path[i+1])] += 1
#				else:
					## Loopy packets
#			else:
				## include loopy packets	
						
			if pathLen_no_loop:
				### do not consider loop when computing average path length
				
				if not is_loop:
					hops.append(hop)
#				else:
					### loopy packets
			else:
				## if loopy packets are included
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
		
		outf.writelines('%d\t%.4f\t%.4f\t%.4f\t%.4f\n' % (cycle_count, 
										entropy, 
										cur_prr, 
										avg_pathlen,
										metric))
		
		print str(cycle_count) + ':\t' + str(metric)
		
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

	#### both with loop
#	entropy_no_loop = False		## entropy includes loopy packets
#	pathLen_no_loop = False		## path length includes loopy packets
#	outf_all = open('metric_analysis_result_all_withLoop.txt', 'w')

	#### entropy with loop, pathLen without loop
#	entropy_no_loop = False		## entropy includes loopy packets
#	pathLen_no_loop = True		## path length includes loopy packets
#	outf_all = open('metric_analysis_result_all_pathLen_no_loop.txt', 'w')
#	
#	#### entropy without loop, pathlen with loop
	entropy_no_loop = True		## entropy includes loopy packets
	pathLen_no_loop = False		## path length includes loopy packets
	outf_all = open('metric_analysis_result_all_entropy_no_loop.txt', 'w')

#	#### both no loop
#	entropy_no_loop = True		## entropy includes loopy packets
#	pathLen_no_loop = True		## path length includes loopy packets
#	outf_all = open('metric_analysis_result_all_no_loop.txt', 'w')
	
	
#	outf_all = open('metric_analysis_result_no_loop_debug.txt', 'w')
	outf_all.writelines('test\tentropy_avg\tstd\tmetric\tstd\n')
	for i in range(1, 2, 1):
#		infname = '../../../../data/indriya/protocol_metrics/ctp/20170209_indriya_ctp_lpl1024_sink31_30sec_test1.txt'
	
#		infname = '../../../../data/indriya/protocol_metrics/ctp/20170212_indriya_ctp_lpl1024_sink31_30sec_caa1800_test1.txt'
		
		infname = '../../../../data/indriya/protocol_metrics/ctp/20170214_indriya_ctp_lpl1024_sink31_1min_caa1800_incycle_test1.txt'		
		
		outfname = 'metric_analysis_result_' + str(i) + '.txt'
		
		
		testname = 'Ctp-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all, entropy_no_loop, pathLen_no_loop)
		
#	for i in range(1, 16):
#		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_trace' + str(i) + '.txt'
#		outfname = 'analysis_result_entropy_noise_test_trace' + str(i) + '.txt'
#		
#		testname = 'trace-' + str(i)
#		
#		print testname + ': ' + infname + '\n\n'
#		
#		run_analyzer(testname, infname, outf_all, entropy_no_loop, pathLen_no_loop)
	
	outf_all.close()
	
