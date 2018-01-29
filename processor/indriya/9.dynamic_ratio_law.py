'''
Plot the law of dynamic ratio
First, union Adjacent matrix of all the cycle, as the denominator 

Second, union the Adjacent matrix one after another, record the dynamic ratio

Third, draw the figure
'''

import sys
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import math
from matplotlib.patches import Rectangle

################################################################################


N = 98


ratios = []		## partial union to all union 
static_ratios = []		## static part to union part
all_edges = 0
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
inter_matrix = [[0 for row in range(N)] for col in range(N)]
union_matrix = [[0 for row in range(N)] for col in range(N)]
tmp =  [[0 for row in range(N)] for col in range(N)]
eigenvalues = []

### find the number of edges of all unions
for i in range(matrix_count):
	if i > 76: 	# to compare with ASWP, only 76 cycles are used
		continue
	if i == 0:
		for j in range(N):
			for k in range(N):
				union_matrix[j][k] = am[i][j][k]
	else:
		for j in range(N):
			for k in range(N):
				cur_matrix[j][k] = am[i][j][k]
		union_matrix = union(union_matrix, cur_matrix, N)
		
all_edges = count_edges(union_matrix, N)
print 'total edges: ' + str(all_edges)
		
### find the dynamic ratio of sequential unions
for i in range(matrix_count):
	if i > 76:
		continue
	if i == 0:
		for j in range(N):
			for k in range(N):
				inter_matrix[j][k] = am[i][j][k]
				union_matrix[j][k] = am[i][j][k]
	else:
		for j in range(N):
			for k in range(N):
				cur_matrix[j][k] = am[i][j][k]
		union_matrix = union(union_matrix, cur_matrix, N)
		inter_matrix = intersect(inter_matrix, cur_matrix, N)
		
		#### compute the dynamic ratio:
		union_edges = count_edges(union_matrix, N)
		
		d_ratio = union_edges*1.0 / all_edges
		ratios.append(d_ratio)
		
		inter_edges = count_edges(inter_matrix, N)
		s_ratio = inter_edges*1.0 / union_edges	## the static part
		static_ratios.append(s_ratio)
		
print ratios

#### dynamic ratio
plt.plot(ratios, 'ro')
plt.plot(ratios, 'b')
plt.title('Edge Union Law')

#extra_dr = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
#			linewidth=0)
#extra_dr_label = "avg: " + str("{0:.4f}".format(np.mean(ratios))) 

#extra_dr_std = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
#			linewidth=0)
#extra_dr_std_label = "std: " + str("{0:.4f}".format(np.std(ratios))) 


#plt.legend([extra_dr, extra_dr_std], 
#				[extra_dr_label, extra_dr_std_label],
#				loc='best')

plt.savefig('figures/edge_union_law.png', dpi=300)
plt.clf()


plt.plot(static_ratios, 'ro')
plt.plot(static_ratios, 'b')
plt.title('Static Edge Law')

#extra_dr = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
#			linewidth=0)
#extra_dr_label = "avg: " + str("{0:.4f}".format(np.mean(ratios))) 

#extra_dr_std = Rectangle((0, 0), 1, 1, fc="w", fill=False, edgecolor='none', 
#			linewidth=0)
#extra_dr_std_label = "std: " + str("{0:.4f}".format(np.std(ratios))) 


#plt.legend([extra_dr, extra_dr_std], 
#				[extra_dr_label, extra_dr_std_label],
#				loc='best')

plt.savefig('figures/edge_static_law.png', dpi=300)
plt.clf()


