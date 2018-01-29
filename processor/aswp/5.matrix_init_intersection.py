'''
Use matrix intersection to find out the static part of the network

Use matrix union and intersection to find out the dynamic part of the network

The dynamic ratio = |m1 U m2| - |m1 AND m2| / |m1 U m2|
'''

import sys
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import math
from matplotlib.patches import Rectangle

################################################################################
# google map html figures
import imp

color = imp.load_source('color_dicts', '../gmplot/color_dicts.py')
gmplot = imp.load_source('gmplot', '../gmplot/gmplot.py')

#gmap = gmplot.GoogleMapPlotter(40.544004, -79.905891, 19)
################################################################################


N = 93

outf_im = open('Intersect_2_adjacent_matrix.txt', 'w')
outf_um = open('Union_2_adjacent_matrix.txt', 'w')
outf_dr = open('Intersect_2_dynamic_ratio.txt', 'w')

ratios = []
################################################################################
inf_ids = open("nodeids.txt", "r")
inf_locs = open('../../data/aswp_correct_nodeids_adjusted.txt', 'r')
inf_ids_new = open('../../data/aswp_new_nodes.txt', 'r')

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
			node_locs.append([float(s[5]), float(s[4])])
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

########################## read in the matrix ##################################
inf_am = open('Adjacent_matrix_series.txt','r')

# the pure adjacent matrix
am = []		# each element is a matrix

# read in the adjacent matrix
lines = inf_am.readlines()
line_count = 0
matrix_count = 0
idx = 0
tmp = [[0 for row in range(N)] for col in range(N)]

for line in lines:
	s = line.split()
	if len(s) > 0:
		line_count += 1
		if len(s) == 4:
			## the start of a new round, the end of last round
			if line_count > 1:
				am.append(tmp)
				matrix_count += 1
				idx = 0
				tmp = [[0 for row in range(N)] for col in range(N)]
		else:
			# read in the matrix
			for i in range(1, len(s)):
				tmp[idx][i-1] = int(s[i])
			idx += 1
am.append(tmp)		# the last matrix
matrix_count += 1
inf_am.close()
################################################################################
# m1: matrix 1
# m2: matrix 2
# n:  number of rows
def intersect(m1, m2, n):
	ret = [[0 for row in range(n)] for col in range(n)]
	for i in range(n):
		for j in range(n):
			if m1[i][j] == 1 and m2[i][j] == 1:
				ret[i][j] = 1
	
	return ret

### the union of a matrix
def union(m1, m2, n):
	ret = [[0 for row in range(n)] for col in range(n)]
	for i in range(n):
		for j in range(n):
			if m1[i][j] == 1 or m2[i][j] == 1:
				ret[i][j] = 1
	
	return ret

# m: the adjacent matrix to count the number of edges
# n: the number of rows
def count_edges(m, n):
	ret = 0
	for i in range(n):
		for j in range(i, n):
			ret += m[i][j]
	return ret

################################################################################
# find the intersection of neighbor matrices in the matrix series
pre_matrix = [[0 for row in range(N)] for col in range(N)]
cur_matrix = [[0 for row in range(N)] for col in range(N)]
inter_matrix = []
union_matrix = []
tmp =  [[0 for row in range(N)] for col in range(N)]
eigenvalues = []
for i in range(matrix_count):
	if i == 0:
		for j in range(N):
			for k in range(N):
				pre_matrix[j][k] = am[i][j][k]
		
	else:
		for j in range(N):
			for k in range(N):
				cur_matrix[j][k] = am[i][j][k]
		
		inter_matrix = intersect(cur_matrix, pre_matrix, N)
		union_matrix = union(cur_matrix, pre_matrix, N)
		
		outf_im.writelines('Intersection: ' + str(i) + '_' + str(i+1) + '\n')
		outf_um.writelines('Intersection: ' + str(i) + '_' + str(i+1) + '\n')
		outf_dr.writelines('Intersection: ' + str(i) + '_' + str(i+1) + '\n')
		### Draw an A-tree based on the Adjacent matrix, using motes' location information
		gmap = gmplot.GoogleMapPlotter(40.544004, -79.905891, 19)
#		for j in range(N):
#			## plot the nodes as dots
#			plt.plot([node_locs[j][0]],[node_locs[j][1]], color='lightgrey', marker='o')
		for j in range(N):
			## plot the nodes as dots
			if nodeids[j] in new_nodes:
				### use a different color for new nodes
				plt.plot([node_locs[j][1]],[node_locs[j][0]], color='red', marker='.')
				img_src = "http://cs.iupui.edu/~xiaozhon/aswp/icons/iris.png"
#				gmap.plot_point([node_locs[i][0]], [node_locs[i][1]], img_src=img_src, 
#						scaledSize=7, title=nodeids[i], label=nodeids[i])
			else:
				plt.plot([node_locs[j][1]],[node_locs[j][0]], color='k', marker='.')
				img_src = "http://cs.iupui.edu/~xiaozhon/aswp/icons/telosb.png"
				
			gmap.plot_point([node_locs[j][0]], [node_locs[j][1]], img_src=img_src, 
					scaledSize=7, title=nodeids[j], label=nodeids[j])
		
		degrees = [0 for row in range(N)]
		for j in range(N):
			for k in range(N):
				outf_im.writelines(str(inter_matrix[j][k]) + ' ')
				outf_um.writelines(str(union_matrix[j][k]) + ' ')
			
				if inter_matrix[j][k] == 1:
					## if two nodes are connected, write a line between them
					plt.plot([node_locs[j][1], node_locs[k][1]], [node_locs[j][0], node_locs[k][0]], 'blue', linewidth=0.5)
					
					link = [(node_locs[j][0], node_locs[k][0]), (node_locs[j][1], node_locs[k][1]) ]
					gmap.plot(link[0], link[1], "cyan", edge_width=1.5)
			
			outf_im.writelines('\n')
			outf_um.writelines('\n')
			degrees[j] = sum(inter_matrix[j])
		
		outf_im.writelines('\n')
		outf_um.writelines('\n')
		
		#### compute the laplacian matrix 
		lm = [[0 for row in range(N)] for col in range(N)]
		for j in range(N):
			for k in range(N):
				if j == k:
					lm[j][k] = 1
					######### for isolated nodes
					if degrees[j] == 0:
						lm[j][k] = 0
				else:
					if inter_matrix[j][k] > 0:
						lm[j][k] = -1*inter_matrix[j][k]*1.0 / math.sqrt(degrees[j]*degrees[k])
				
		
		tmp_eig = LA.eigvalsh(lm)
		tmp_eig.sort()
		eigenvalues.append(tmp_eig)
		
		#### get the connectivity
		j = 0
		while tmp_eig[j] < 0.001:
			j += 1
		connectivity = tmp_eig[j]
		
		#### compute isolated nodes
		isolated_count = 0
		for j in range(N):
			if degrees[j] == 0:
				isolated_count += 1
		
		#### compute the dynamic ratio:
		edges1 = count_edges(union_matrix, N)
		edges2 = count_edges(inter_matrix, N)
		d_ratio = 1.0 * (edges1 - edges2) / edges1
		outf_dr.writelines('\tdynamic_ratio: ' + str(d_ratio) + '\n')
		
		ratios.append(d_ratio)
		
		extra_dr = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_dr_label = "dynamic_ratio: " + str("{0:.4f}".format(d_ratio)) 
		
		extra_isolated = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_isolated_label = "isolated: " + str(isolated_count) 
		
		extra_conn = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
		extra_conn_label = "connectivity: " + str("{0:.4f}".format(connectivity)) 
		
		plt.legend([extra_dr, extra_isolated, extra_conn], 
				[extra_dr_label, extra_isolated_label, extra_conn_label],
				loc='best')
		plt.title('Intersect_' + str(i) + '_' + str(i+1))
		plt.savefig('figures_intersect_2/intersect_' + str(i) + '_' + str(i+1) + '.png', dpi=300)
		plt.clf()
		
		gmap.draw('figures_intersect_2/intersect_' + str(i) + '_' + str(i+1) + '.html')
		
		for j in range(N):
			for k in range(N):
				pre_matrix[j][k] = cur_matrix[j][k]

outf_im.close()
outf_um.close()

### draw the figure of the second smallest eigenvalues
first_eig = []
count = 0
connected_parts = []
for eig in eigenvalues:
	i = 0
	count += 1
	print 'intersect: ' + str(count) + '\n' + str(eig) + '\n\n'
	while eig[i] < 0.0001:
		i += 1
	connected_parts.append(i)
	first_eig.append(eig[i])

#print first_eig
f, axarr = plt.subplots(2, sharex=True)

axarr[0].plot(first_eig, 'ro')
axarr[0].plot(first_eig, 'b')
axarr[0].set_title('smallest_non_zero_eigenval')

axarr[1].plot(connected_parts, 'k*')
axarr[1].plot(connected_parts, 'b')
axarr[1].set_title('number_of_graph_paritions')

plt.savefig('figures_intersect_2/smallest_non_zero_eigenvalue.png', dpi=300)
plt.clf()

#### dynamic ratio
plt.plot(ratios, 'ro')
plt.plot(ratios, 'b')
plt.title('Dynamic ratio')

extra_dr = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
extra_dr_label = "avg: " + str("{0:.4f}".format(np.mean(ratios))) 

extra_dr_std = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
extra_dr_std_label = "std: " + str("{0:.4f}".format(np.std(ratios))) 


plt.legend([extra_dr, extra_dr_std], 
				[extra_dr_label, extra_dr_std_label],
				loc='best')

plt.savefig('figures_intersect_2/dynamic_ratio.png', dpi=300)
plt.clf()

