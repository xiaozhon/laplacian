'''
Use matrix intersection to find out the static part of the network
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

N = 98

outf_im = open('Intersect_3_adjacent_matrix.txt', 'w')
outf_dr = open('Intersect_3_dynamic_ratio.txt', 'w')

ratios = []
################################################################################
inf_ids = open("../../data/indriya/nodeids.txt", "r")

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


########################## read in the matrix ##################################
inf_im = open('Intersect_2_adjacent_matrix.txt','r')

# the pure adjacent matrix
im = []		# each element is a matrix

# read in the adjacent matrix
lines = inf_im.readlines()
line_count = 0
matrix_count = 0
idx = 0
tmp = [[0 for row in range(N)] for col in range(N)]

for line in lines:
	s = line.split()
	if len(s) > 0:
		line_count += 1
		if len(s) == 2:
			## the start of a new round, the end of last round
			if line_count > 1:
				im.append(tmp)
				matrix_count += 1
				idx = 0
				tmp = [[0 for row in range(N)] for col in range(N)]
		else:
			# read in the matrix
			for i in range(0, len(s)):
				tmp[idx][i] = int(s[i])
			idx += 1
im.append(tmp)		# the last matrix
#print len(im)
matrix_count += 1
inf_im.close()

####################### read in the union matrix ###############################
inf_um = open('Union_2_adjacent_matrix.txt','r')

# the pure adjacent matrix
um = []		# each element is a matrix

# read in the adjacent matrix
lines = inf_um.readlines()
line_count = 0
idx = 0
tmp = [[0 for row in range(N)] for col in range(N)]

for line in lines:
	s = line.split()
	if len(s) > 0:
		line_count += 1
		if len(s) == 2:
			## the start of a new round, the end of last round
			if line_count > 1:
				um.append(tmp)
				idx = 0
				tmp = [[0 for row in range(N)] for col in range(N)]
		else:
			# read in the matrix
			for i in range(0, len(s)):
				tmp[idx][i] = int(s[i])
			idx += 1
um.append(tmp)		# the last matrix
inf_um.close()
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

pre_um = [[0 for row in range(N)] for col in range(N)]
cur_um = [[0 for row in range(N)] for col in range(N)]

inter_matrix = []
union_matrix = []
tmp =  [[0 for row in range(N)] for col in range(N)]

eigenvalues = []

for i in range(matrix_count):
	if i == 0:
		for j in range(N):
			for k in range(N):
				pre_matrix[j][k] = im[i][j][k]
				pre_um[j][k] = um[i][j][k]
		
	else:
		for j in range(N):
			for k in range(N):
				cur_matrix[j][k] = im[i][j][k]
				cur_um[j][k] = um[i][j][k]
		
#		if i == 1:
#			print cur_matrix[0]
#			print pre_matrix[0]
		
		inter_matrix = intersect(cur_matrix, pre_matrix, N)
		union_matrix = union(cur_um, pre_um, N)
		
#		if i == 1:
#			print inter_matrix[0]
		
		degrees = [0 for row in range(N)]
		outf_im.writelines('Intersection: ' + str(i+1) + '\n')
		for j in range(N):
			for k in range(N):
				outf_im.writelines(str(inter_matrix[j][k]) + ' ')

			outf_im.writelines('\n')
			degrees[j] = sum(inter_matrix[j])
		
		outf_im.writelines('\n')
		
		#### compute the laplacian matrix 
		lm = [[0 for row in range(N)] for col in range(N)]
		for j in range(N):
			for k in range(N):
				if j == k:
					lm[j][k] = 1
					if degrees[j] == 0:	## for isolated nodes
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
		
		for j in range(N):
			for k in range(N):
				pre_matrix[j][k] = cur_matrix[j][k]
				pre_um[j][k] = cur_um[j][k]

outf_im.close()

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

plt.savefig('figures_intersect_3/smallest_non_zero_eigenvalue.png', dpi=300)
plt.clf()

### the first 76 cycles
f, axarr = plt.subplots(2, sharex=True)

axarr[0].plot(first_eig[:76], 'ro')
axarr[0].plot(first_eig[:76], 'b')
axarr[0].set_title('smallest_non_zero_eigenval_76cycles')

axarr[1].plot(connected_parts[:76], 'k*')
axarr[1].plot(connected_parts[:76], 'b')
axarr[1].set_title('number_of_graph_paritions')

plt.savefig('figures_intersect_3/smallest_non_zero_eigenvalue_76cycles.png', dpi=300)
plt.clf()


## dynamic ratio
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

plt.savefig('figures_intersect_3/dynamic_ratio.png', dpi=300)
plt.clf()


plt.plot(ratios[:76], 'ro')
plt.plot(ratios[:76], 'b')
plt.title('Dynamic ratio')


extra_dr = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
extra_dr_label = "avg: " + str("{0:.4f}".format(np.mean(ratios[:76]))) 

extra_dr_std = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
			linewidth=0)
extra_dr_std_label = "std: " + str("{0:.4f}".format(np.std(ratios[:76]))) 


plt.legend([extra_dr, extra_dr_std], 
				[extra_dr_label, extra_dr_std_label],
				loc='best')

plt.savefig('figures_intersect_3/dynamic_ratio_76cycles.png', dpi=300)
plt.clf()
