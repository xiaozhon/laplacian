'''
use the test packet data to analyze the laplacian of the network


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
#	outf.writelines('cycle_count\tlinks\tentropy\tlink_usage\n')

	N = 36
	am = [[0 for i in range(N)] for j in range(N)]
	pm = [[0 for i in range(N)] for j in range(N)]

	## count the usage of each link to compute link entropy
	entropy_pm = [[0 for i in range(N)] for j in range(N)]

	cycle_entropy = []
	
	
	### number of forwarded packets each node
	node_fwd = [0 for i in range(0, N-1)]			### do not consider sink

	cycle_entropy_fwd = []
	
	
	
	## store the second eigenvalue of the cycle 
	second_eigval = []

	## the second eigenvector
	second_vector = []

	## second_vector_sorted = [[id, vec]]
	second_vector_sorted = []

	## trees
	trees = []

	hops = [0 for i in range(N)]

	hops[0] = [0, 0]


	cycle_count = 0
	for cycle in blocks(inf):
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""
		cycle_count += 1
		if cycle_count < 2:
			continue
		
		print cycle_count
	#	if cycle_count < 0 or cycle_count > 1000:
	#		## now only process a few cycles in the middle
	#		continue
	
	#	print cycle_count
		## initialization
		for i in range(N):
			for j in range(N):
				am[i][j] = 0
				pm[i][j] = 0
				entropy_pm[i][j] = 0
		
		for i in range(N-1):
			node_fwd[i] = 0
			
		rcvd = []
		link_usage = 0
		for pkt in cycle:
#			if cycle_count == 573:
#				print pkt
			s = pkt.split()
			if len(s) < 6:
				continue
#			print pkt
			
			src = int(s[SRC])
			hop = int(s[HOP])
		
			hops[src] = [hop, src]
		
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
				
				am[path[i]][path[i+1]] = 1
				am[path[i+1]][path[i]] = 1
			
				if not NO_LOOP:
					entropy_pm[path[i]][path[i+1]] += 1
					node_fwd[path[i]-1] += 1
			
				pm[path[i]][path[i+1]] = 1
				
#				if cycle_count == 976:
#					print '%d -> %d' % (path[i], path[i+1])
				
				
				if i > 0 and (path[i] in path[:i-1]):
					is_loop = True
				
				link_usage += 1
			
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
					node_fwd[path[i]-1] += 1
#			else: 
#				### loopy packets
#				print cycle_count
#				print pkt
			
			
			## check PRR in a simple way
			if src not in rcvd:
				rcvd.append(src)
	
		## the matrix are ready
		(eig, vec) = eigen(am)
		det = mtt(pm)
	
		second_eigval.append(eig[1])
		second_vector.append(vec[1])
		trees.append(det)
	
		edges = sum(find_degrees(pm))
	
		#### entropy analysis
#		print entropy_pm
		entropy, entropy_avg = link_entropy(entropy_pm)
	#	outf.writelines('\tlink entropy: %.4f\n' % entropy)
	
	#	outf.writelines(str(cycle_count) + ':\t' + str(eig[1]) + '\t' + str(edges) + '\t' + str(det) + '\n')


	
		###
		# compute the centrality of the node, and find the most influencial one
		###
		G = nx.Graph()
		G.add_nodes_from(i for i in range(N))	## add the node list
		for i in range(N):
			for j in range(N):
				if am[i][j] != 0:
					G.add_edge(i, j)	## add edge


#		centrality = nx.eigenvector_centrality_numpy(G)	## key = node, value = centrality
#		max_centrality = [0, 0]		## node, centrality
#	
#		for node in centrality:
#			if node == 0:
#				continue
#			if centrality[node] > max_centrality[1]:
#				max_centrality[0] = node
#				max_centrality[1] = centrality[node]


#		outf.writelines(str(cycle_count) + ':\t' + str(edges) 
#						+ '\t' + str(entropy) + '\t' + str(link_usage)
#						+ '\n')
	
#		if cycle_count == 100:
#			print entropy_pm
		cycle_entropy.append(entropy)
		
		cycle_entropy_fwd.append(list_entropy(node_fwd))
		
#	outf.close()
	
	alloutput.writelines('%s\t%.4f\t%.4f\t%.4f\t%.4f\n\n' % (testname, 
								np.mean(cycle_entropy), 
								np.std(cycle_entropy),
								np.mean(cycle_entropy_fwd), 
								np.std(cycle_entropy_fwd)
								))
	
	### plot the figure if necessary

if __name__ == "__main__":
	outf_all = open('analysis_result_entropy_noLoop.txt', 'w')
#	outf_all = open('analysis_result_entropy_odd_debug.txt', 'w')
	outf_all.writelines('test\tentropy_avg\tstd\tnode_entropy\tstd\n')
	for i in range(24, 26, 2):
		infname = '../../../data/tossim/rctp_uniform/noise_sim/uniform_36nodes_rctp_noise_test_add-' + str(i) + '.txt'
		outfname = 'analysis_result_entropy_noise_add_' + str(i) + '.txt'
		
		testname = 'add-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outfname, outf_all)
		
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
	
