'''
analysis the duplicates

Duplicates are identified using <src, seq> pairs. They may differ in the path, find 
out the statistics of duplicates with/without the same path.

# store the [src, seq, hop, path] 

# find the work load of each node near the sink
# check whether some nodes generated most of the duplicated packets

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
	
	inf_duped_nodes = open('duplicated_src_seq_pairs.txt', 'r')
	
	
	outf_pkts = open('duped_packets.txt', 'w')
	
#	
	
	nodeids = find_ids('nodeids.txt')
	N = len(nodeids)
	
	
	duped_pairs = []	# [src, seq]
	for line in inf_duped_nodes:
		s = line.split()
		if len(s) > 0:
			## s[0] = src, s[1] = seq 
			duped_pairs.append([int(s[0]), int(s[1])])
			
	
	### all distinct duplicat packets
	duped_pkts = []		# [src, seq, hop, [path]]
	
	### the duplicate packets already in duped_pkts
	true_dup = []
	
	
	## The node id that has duplicates 
	## key = node id with duplicates, value = the number of duplicates
	duped_id = {}
	
	## the workload (number of forwarded packets) for each node, including the packets 
	## generated by itself
	## key = nodeid, value = fwd count
	node_workload = {}
	total_workload = 0
	
	## the nodes in each hop 
	## we focus on the nodes near the sink, i.e., the first hop
	## idx = hop count, value = [list of nodes ever be in this hop]
	hop_nodeid = [[] for i in range(N)]
	
	cycle_count = 0
	
	for cycle in blocks(inf):
		"""
		For each cycle, get the adjacent matrix and the parent matrix, counting the 
		algebraic connectivity, Fielder vector, and the number of spanning trees
	
		"""
		cycle_count += 1
		if cycle_count < 2:# or cycle_count > 71:
	#		## now only process a few cycles in the middle
			continue
	
		print cycle_count
		## initialization
		
		for pkt in cycle:
			s = pkt.split()
			
			if len(s) < 4:
				continue
			
			src = int(s[SRC])
			hop = int(s[HOP])
			seq = int(s[SEQ])
		

			path = []
			path.append(src)
			
			
			# node work load
			if not node_workload.has_key(src):
				node_workload[src] = 0
			node_workload[src] += 1
			total_workload += 1
			
			## node id at each hop 
			if src not in hop_nodeid[hop]:
				hop_nodeid[hop].append(src)
			
			for i in range(PARENT, PARENT + hop):	
				### detect loopy packets here
				if i < len(s)-1:
				
					if int(s[i]) not in nodeids:
						### error packets
						continue
					
					path.append(int(s[i]))
					
					if int(s[i]) != 31:
						# sink is not counted
						if not node_workload.has_key(int(s[i])):
							node_workload[int(s[i])] = 0
						node_workload[int(s[i])] += 1
						total_workload += 1
			
			### check duplicates using (src, seq)
			if [src, seq] in duped_pairs:
				### this is a duplicated packet
#				if not duped_id.has_key(src):
#					duped_id[src] = 0
#				duped_id[src] += 1		### the number of duplicated packets from this node 
				
				
				#### compute the number of times a nodes has been involved in a duplicate packets
				### e.g., for duplicate path [3, 5, 21, 31], then node 3, 5, 21 all count once
				###     as in the duplicate packets 
				for i in range(len(path)):
					if path[i] != 31:
						if not duped_id.has_key(path[i]):
							duped_id[path[i]] = 0
						duped_id[path[i]] += 1
				
				outf_pkts.writelines(str([src, seq, hop, path]) + '\n')
				### store the packets
				if [src, seq, hop] not in duped_pkts:
					### duplicate packets with different hops 
					duped_pkts.append([src, seq, hop])
				else:
					### this packet is a duplicate, and has same hop number
					true_dup.append([src, seq, hop])
			
	outf_pkts.close()
#	outf.close()

	alloutput.writelines('%s\t%d\t%d\t%d\n\n' % (testname, 
											len(duped_pairs),
											len(true_dup),
											len(duped_pkts)
											
											))

	
	## duped_id = {}
	## the node ids that has duplicated packets 
	alloutput.writelines('nodeid\tdup_count\n')
	for i in range(N):
		if duped_id.has_key(nodeids[i]):
#			newline = '%d\t%d\n' % (nodeids[i], duped_id[nodeids[i]])
			newline = '%d\t%.4f\n' % (nodeids[i], duped_id[nodeids[i]]*1.0 / (len(true_dup) + len(duped_pkts)))
			alloutput.writelines(newline)
	alloutput.writelines('\n')
	
	
	
	## hop_nodeid = [[] for i in range(N)]
	## the number of nodes at each hop, and the node ids 
	alloutput.writelines('hop\tnode_count\tnodeids\n')
	for i in range(N):
		if len(hop_nodeid[i]) > 0:
			newline = '%d\t%d\t%r\n' % (i, len(hop_nodeid[i]), sorted(hop_nodeid[i]))
			alloutput.writelines(newline)
	alloutput.writelines('\n')
	
	## node_workload = {}
	## the workload of each node 
	alloutput.writelines('nodeid\tfwd_count\tpercent\n')
	for i in range(N):
		if node_workload.has_key(nodeids[i]):
			newline = '%d\t%d\t%.4f\n' % (nodeids[i], node_workload[nodeids[i]], 
											node_workload[nodeids[i]]*1.0 / total_workload)
			alloutput.writelines(newline)
	alloutput.writelines('\n')
		
	
	### plot the figure if necessary

if __name__ == "__main__":
	outf_all = open('dup_analysis_result.txt', 'w')
	outf_all.writelines('test\tall_dups\tdups_same_path\tdups_diff_path\n')
	
	for i in range(1, 2, 1):

		infname = '../../../../data/indriya/protocol_metrics/orw/20170221_indriya_orw_default_sink31_1min_incycle_noID37_test1.txt'
		
		testname = 'Orw-' + str(i)
		
		print testname + ': ' + infname + '\n\n'
		
		run_analyzer(testname, infname, outf_all)
		
	outf_all.close()
	
