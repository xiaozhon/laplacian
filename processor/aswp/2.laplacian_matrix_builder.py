'''
buil laplacian matrix based on the good periods,

2016-08-18	89
2016-08-19	89
2016-08-20	89
2016-08-21	88
2016-08-22	88
2016-08-23	86
2016-08-24	84

Generate a laplacian matrix every two hours
'''

import sys
import time
import math
from numpy import linalg as LA
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
import numpy as np


DAY = 0
TIME = 1
SRC = 3
PARENT = 4
PRNT_SIZE = 5
HOP = 9
PATH = 29

# the total number of node ids
N = 93

inf = open("../../data/aswp/cs_pkt_20160818_formatted.txt", "r")
#inf = open("../data/aswp/test_data.txt", "r")
# use all data instead of only the cs_pkt
#inf = open("../../data/aswp/20160818-rctp_all_packets.txt", "r")

inf_ids = open("nodeids.txt", "r")
inf_locs = open('../../data/aswp_correct_nodeids_adjusted.txt', 'r')
inf_ids_new = open('../../data/aswp_new_nodes.txt', 'r')

inf_cycle_prr = open('../../data/aswp/node_prr_per_cycle.txt', 'r')

outf = open("Laplacian_matrix_series.txt", "w")
outf_am = open('Adjacent_matrix_series.txt','w')
outf_eig = open('Laplacian_eigenvalue.txt', 'w')

# if j is i's parent, pm[i][j] == 1, different from adjacent matrix
outf_pm = open('parent_matrix_series.txt', 'w')

# network statistics
outf_st = open('cycle_statistics.txt', 'w')

### statistics of the leaf nodes
outf_leaf = open('leaf_statistics.txt', 'w')
### Store the size of the prnt set of the leaf node. If leaf_prnt_set[i] == 0, it is not leaf node
leaf_prnt_set = [0 for i in range(N)]
leaf_prnt_avg_cycle = []
leaf_prnt_std_cycle = []

#################### load node ids #####################
nodeids = []
lines = inf_ids.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		nodeids.append(s[0])

inf_ids.close()

# find the index of a node id in the list
def idx(nodeid):
	for i in range(N):
		if nodeid == nodeids[i]:
			return i
	return -1

################## load node location ##################
node_locs = []
lines = inf_locs.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		if s[0] in nodeids:
			node_locs.append([float(s[4]), float(s[5])])
inf_locs.close()

################## load new nodes ######################
new_nodes = []
lines = inf_ids_new.readlines()
for line in lines:
	s = line.split()
	if len(s) == 3:
		if (s[0] in nodeids) and (s[0] not in new_nodes):
			new_nodes.append(s[0])
inf_ids_new.close()

################## load cycle prr #######################
cycle_prr = []
cycle_prr_per_nodes = [[] for i in range(76)]
lines = inf_cycle_prr.readlines()
cycle_count = 0
for line in lines:
	s = line.split()
	if len(s) == 5 and s[0] == 'Avg':
		# Avg PRR: 0.952937475803	std: 0.0878043511455
		cycle_prr.append([float(s[2]), float(s[4])])
		cycle_count += 1
	elif len(s) == 3:
		print cycle_count
		cycle_prr_per_nodes[cycle_count].append([float(s[1]), float(s[2])])

#########################################################

# the pure adjacent matrix
am = [[0 for row in range(N)] for col in range(N)]

# the parent matrix
pm = [[0 for row in range(N)] for col in range(N)]

# the laplacian matrix
# row: src, col: parent
lm = [[0 for row in range(N)] for col in range(N)]
degrees = [0 for i in range(N)]		# the degree of each node
eigenvals = [0 for i in range(N)]

prnt_set = [0 for i in range(N)]	# the size of the parent set
isolated_count = 0
shortcut_count = 0


for i in range(N):
	for j in range(N):
		am[i][j] = 0
		lm[i][j] = 0
	degrees[i] = 0

line_count = 0
cur_time = 0
pre_time = 0
round_count = 0

lines = inf.readlines()
for line in lines:
	line_count += 1
	if line_count == 1:
		continue
	
	s = line.split()
	if s[0] > '2016-08-24':
		# ignore the packets when there are fewer nodes
		continue
		
	## read each packet and build adjacent matrix for every two hours
	if line_count == 2:
		time_string = s[0] + ' ' + s[1][0:8]
		cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
		pre_time = cur_time
	
	# compute current time
	time_string = s[0] + ' ' + s[1][0:8]
	cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
	
#	print cur_time - pre_time
	
	if cur_time - pre_time > 60*60*2:
		# larger than 2 hours, compute and output the laplacian matrix
		round_count += 1
		outf.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		outf_am.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		outf_eig.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		
		outf_pm.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		outf_st.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		
		## write out the adjacent matrix
		newline = ''
		for i in range(N):
			newline = nodeids[i] + ': '
			for j in range(N):
				newline += str(am[i][j]) + ' '
				if am[i][j] == 1:
					## if two nodes are connected, write a line between them
					plt.plot([node_locs[i][0], node_locs[j][0]], [node_locs[i][1], node_locs[j][1]], 'blue', linewidth=0.5)
			newline += '\n'
			outf_am.writelines(newline)
			degrees[i] = sum(am[i])
			
		outf_am.writelines('\n')
		
		### Draw an A-tree based on the Adjacent matrix, using motes' location information
		for i in range(N):
			## plot the nodes as dots
			if nodeids[i] in new_nodes:
				### use a different color for new nodes
				plt.plot([node_locs[i][0]],[node_locs[i][1]], color='red', marker='.')
			else:
				plt.plot([node_locs[i][0]],[node_locs[i][1]], color='k', marker='.')
		
		########################################################################
		# Network statistics of this cycle
		isolated_count = 0
		shortcut_count = 0
		prnt_count = [0 for row in range(N)]
		
		outf_st.writelines('\tavg_PRR: ' + str(cycle_prr[round_count-1][0]) 
							+ '\tstdev: ' + str(cycle_prr[round_count-1][1])
							+ '\n')
		
		## count the number of isolated nodes					
		for j in range(N):
			if degrees[j] == 0:
				isolated_count += 1
			if degrees[j] == 1:
				## the leaf nodes
				leaf_prnt_set[j] = cycle_prr_per_nodes[round_count-1][j][1]
		
		##### write out the parent set of the leaf nodes
		outf_leaf.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		outf_leaf.writelines('nodeid\tprnt_size\n')
		leaf_tmp = []
		for j in range(N):
			if leaf_prnt_set[j] > 0:
				leaf_tmp.append(leaf_prnt_set[j])
				outf_leaf.writelines(nodeids[j] + '\t' + str(leaf_prnt_set[j]) + '\n')
		
		outf_leaf.writelines('number of leaf nodes: ' + str(len(leaf_tmp)) 
								+ '\tavg_prnt_size: ' + str(np.mean(leaf_tmp)) + '\tstdev: ' + str(np.std(leaf_tmp)) + '\n')
		outf_leaf.writelines('\n')
		leaf_prnt_avg_cycle.append(np.mean(leaf_tmp))
		leaf_prnt_std_cycle.append(np.std(leaf_tmp))
		
		### write out isolated nodes
		outf_st.writelines('\tisolated: ' + str(isolated_count) + '\n')
		
		### overall parent set size
		for j in range(1, N):
			prnt_set[j] = cycle_prr_per_nodes[round_count-1][j][1]
			
		outf_st.writelines('\tavg_prnt_set_size: ' + str(np.mean(prnt_set)) + '\tstdev: ' + str(np.std(prnt_set)) + '\n')
		
		for j in range(N):
			for k in range(N):
				prnt_count[j] += pm[j][k]
		for j in range(N):
			if prnt_count[j] > 0:
				shortcut_count += prnt_count[j] - 1
		outf_st.writelines('\tshortcut_count: ' + str(shortcut_count) + '\n')
		
		
		### shortcut ratio:
		st_ratio = 1.0*shortcut_count / (N - isolated_count - 1)
		outf_st.writelines('\tshortcut_ratio: ' + str(st_ratio) + '\n')
		
		outf_st.writelines('\n\tnode\tPRR\tprnt_size\n')
		for j in range(1, N):
			outf_st.writelines('\t' + nodeids[j] + '\t' + str(cycle_prr_per_nodes[round_count-1][j][0])+ 
							   '\t' + str(cycle_prr_per_nodes[round_count-1][j][1]) + '\n')
							   
		outf_st.writelines('\n')
		
		
		## write out the parent matrix
		newline = ''
		for i in range(N):
			newline = nodeids[i] + ': '
			for j in range(N):
				newline += str(pm[i][j]) + ' '
			newline += '\n'
			outf_pm.writelines(newline)
		outf_pm.writelines('\n')
		
		## compute symmetric normalized Laplacian matrix
		## The eigenvalues are in range 0~2
		newline = ''
		for i in range(N):
			newline = nodeids[i] + ': '
			for j in range(N):
				if i == j:
					lm[i][j] = 1
					######### for isolated nodes
					if degrees[i] == 0:
						lm[i][j] = 0
				else:
					if am[i][j] > 0:
						lm[i][j] = -1*am[i][j]*1.0 / math.sqrt(degrees[i]*degrees[j])
				
				newline += str(lm[i][j]) + ' ' 
			newline += '\n'
			outf.writelines(newline)
		outf.writelines('\n')
		
		### compute the original Laplacian matrix
		### In this laplacian matrix, the eigenvalues are at random range, many 0s 
#		newline = ''
#		for i in range(N):
#			newline = nodeids[i] + ': '
#			for j in range(N):
#				if i == j:
#					lm[i][j] = degrees[i]
#				else:
#					if am[i][j] > 0:
#						lm[i][j] = -1*am[i][j]
#				
#				newline += str(lm[i][j]) + ' ' 
#			newline += '\n'
#			outf.writelines(newline)
#		outf.writelines('\n')
		
		### Now we can compute the eigen values of the laplacian matrix
		eigenvals = LA.eigvalsh(lm)
		eigenvals.sort()
		newline = ''
		for i in range(N):
			newline += str(eigenvals[i]) + ' '
		newline += '\n\n'
		outf_eig.writelines(newline)
		
		########################################################################
		
		### add a label about the PRR, isolated nodes, avg prnt size, number of 
		### shortcuts, and smallest non-zero eigenvalue for each cycle 
		connectivity = 0
		i = 0
		while eigenvals[i] < 0.001:
			i += 1
		connectivity = eigenvals[i]
		
		
		
		extra_prr = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_prr_label = "prr: " + str("{0:.4f}".format(cycle_prr[round_count-1][0])) 
		extra_prr_label += ", std: " + str("{0:.4f}".format(cycle_prr[round_count-1][1]))
		
#		extra_std = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
#			linewidth=0)
#		extra_std_label = "std: " + str("{0:.4f}".format(cycle_prr[round_count-1][1]))
		
		extra_isolated = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_isolated_label = "isolated: " + str(isolated_count) 
		
		extra_prnt = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_prnt_label = "Avg_Prnt_S: " + str("{0:.2f}".format(np.mean(prnt_set)))
		extra_prnt_label += ", std: " + str("{0:.2f}".format(np.std(prnt_set)))
		
		extra_shortcuts = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_shortcuts_label = "shortcuts: " + str(shortcut_count)
		extra_shortcuts_label += ", ratio: " + str("{0:.4f}".format(st_ratio))
		
		extra_conn = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_conn_label = "connectivity: " + str("{0:.4f}".format(connectivity)) 
		
		plt.legend([extra_prr, extra_isolated, extra_prnt, extra_shortcuts, extra_conn], 
				[extra_prr_label, extra_isolated_label, extra_prnt_label, extra_shortcuts_label, extra_conn_label],
				loc='best')
		
		plt.title(time_string + ': Cycle ' + str(round_count))
		plt.savefig('figures/A-tree_' + s[0] + '_' + s[1]+ '.png', dpi=300)
		plt.clf()
		
		
		# reset the matrix
		for i in range(N):
			for j in range(N):
				am[i][j] = 0
				lm[i][j] = 0
				pm[i][j] = 0
			degrees[i] = 0
			eigenvals[i] = 0
			prnt_set[i] = 0
			leaf_prnt_set[i] = 0
			
		pre_time = cur_time
	else:
		# build the adjacent matrix
		
		# set the matrix cell to be 1 if the child-parent pair exists
		path_len = 0
		if int(s[HOP]) > 13:
			# if the path is too long, the other nodes are lost
			path_len = 12
		else:
			path_len = int(s[HOP]) - 1
		
		am[idx(s[SRC])][idx(s[PARENT])] = 1
		am[idx(s[PARENT])][idx(s[SRC])] = 1
		
		pm[idx(s[SRC])][idx(s[PARENT])] = 1
		
		#### the rest only for cs packets
		if s[2] != '69':
			continue
		
		if s[1] == '15:03:28.744':
			print s[SRC] + ' ' + s[PARENT]
		
		if path_len >= 1:
			# only two hops
			am[idx(s[PARENT])][idx(s[PATH])] = 1
			am[idx(s[PATH])][idx(s[PARENT])] = 1
			
			pm[idx(s[PARENT])][idx(s[PATH])] = 1
			
			if s[1] == '15:03:28.744':
				print s[PARENT] + ' ' + s[PATH]
			
			for i in range(PATH, PATH + path_len-1):
				if s[i] != '0':
					## for German's test nodes, the path is not recorded, thus those are 0s
					am[idx(s[i])][idx(s[i+1])] = 1
					am[idx(s[i+1])][idx(s[i])] = 1
					
					pm[idx(s[i])][idx(s[i+1])] = 1
					
					if s[1] == '15:03:28.744':
						print s[i] + ' ' + s[i+1]
		
		
### last cycle is less than 2 hours, ingore it
ind = [i for i in range(76)]
plt.errorbar(ind, leaf_prnt_avg_cycle, yerr=leaf_prnt_std_cycle, color='k', marker='o')
plt.title("Avg. Prnt Set Size Of Leaf Nodes")
plt.xlabel("Cycle")
plt.savefig('Leaf_prnt_size.png', dpi=300)
plt.clf()
		
inf.close()
outf.close()
outf_am.close()
outf_eig.close()


