'''
read in the adjacent matrix and parent matrix, and get the network size statistics
for each cycle
'''

import sys
import numpy as np
import matplotlib.pyplot as plt

# the total number of node ids
N = 98

inf_am = open('Adjacent_matrix_series.txt','r')
inf_pm = open('parent_matrix_series.txt', 'r')

# the isolated nodes for each cycle, number of shortcuts each cycle, parent set size
outf_st = open('network_statistics.txt', 'w')

# the pure adjacent matrix
#am = [[0 for row in range(N)] for col in range(N)]
am = []		# each element is a matrix

# the parent matrix
#pm = [[0 for row in range(N)] for col in range(N)]
pm = []		# each element is a matrix

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

# read in the parent matrix
lines = inf_pm.readlines()
line_count = 0
idx = 0
tmp = [[0 for row in range(N)] for col in range(N)]

for line in lines:
	s = line.split()
	if len(s) > 0:
		line_count += 1
		if len(s) == 4:
			## the start of a new round, the end of last round
			if line_count > 1:
				pm.append(tmp)
				idx = 0
				tmp = [[0 for row in range(N)] for col in range(N)]
		else:
			# read in the matrix
			for i in range(1, len(s)):
				tmp[idx][i-1] = int(s[i])
			idx += 1
pm.append(tmp)		# the last matrix
inf_pm.close()


isolated_count = [0 for i in range(matrix_count)]		# if a node's degree is 0, it is isolated
shortcut_count = [0 for i in range(matrix_count)]		# the number of shortcuts in a cycle
prnt_count = [0 for i in range(N)]	# the size of the prnt set of each node
degrees = [0 for i in range(N)]
for i in range(matrix_count):
	outf_st.writelines("Round: " + str(i+1) + '\n')
	# for each cycle, calculate the statistics
	# Get the degree
	for j in range(N):
		for k in range(N):
			degrees[j] += am[i][j][k]
		
		if degrees[j] == 0:
			isolated_count[i] += 1
	
	outf_st.writelines('\tisolated: ' + str(isolated_count[i]) + '\n')
	
	for j in range(N):
		for k in range(N):
			prnt_count[j] += pm[i][j][k]
	
	outf_st.writelines('\tprnt_set_avg_size: ' + str(np.mean(prnt_count)) + '\tstdev: ' + str(np.std(prnt_count)) + '\n')
	
	for j in range(N):
		if prnt_count[j] > 0:
			shortcut_count[i] += prnt_count[j] - 1
	
	outf_st.writelines('\tshortcut_count: ' + str(shortcut_count[i]) + '\n')
	
	outf_st.writelines('\n')
	
	for j in range(N):
		degrees[j] = 0

		prnt_count[j] = 0
		
outf_st.close()

#### draw a figure about the isolated count, the shortcuts, and the second smallest eigenvalue
inf_eig = open('Laplacian_eigenvalue.txt', 'r')

first_eig = []	# the second smallest eigenvalues

lines = inf_eig.readlines()

line_count = 0
idx = 0
for line in lines:
	s = line.split()
	if len(s) > 0:
		line_count += 1
		if line_count % 2 == 1:
			idx += 1
		else:
			# read the second smallest eigenvalue
			i = 0
			while float(s[i]) < 0.001:
				i += 1
			first_eig.append(float(s[i]))

#for i in range(N):
#	shortcut_count[i] = shortcut_count[i] * 1.0 / 100
#	isolated_count[i] = isolated_count[i] * 1.0 / 100
print len(shortcut_count)
f, axarr = plt.subplots(3, sharex=True)

axarr[0].plot(first_eig, 'ro')
axarr[0].plot(first_eig, 'b')
axarr[0].set_title('smallest_non-zero_eigenvalue')
#plt.axis([0, 100, 0, 2.0])
axarr[1].plot(shortcut_count, 'k*')
axarr[1].plot(shortcut_count, 'b')
axarr[1].set_title('shortcuts')
axarr[2].plot(isolated_count, 'g+')
axarr[2].plot(isolated_count, 'b')
axarr[2].set_title('isolated_nodes')

plt.savefig('figures/eigen_isolated_shortcut.png')
plt.clf()

### plot less cycles
f, axarr = plt.subplots(3, sharex=True)
axarr[0].plot(first_eig[0:76], 'ro')
axarr[0].plot(first_eig[0:76], 'b')
axarr[0].set_title('smallest_non-zero_eigenvalue_76cycles')
#plt.axis([0, 100, 0, 2.0])
axarr[1].plot(shortcut_count[0:76], 'k*')
axarr[1].plot(shortcut_count[0:76], 'b')
axarr[1].set_title('shortcuts')
axarr[2].plot(isolated_count[0:76], 'g+')
axarr[2].plot(isolated_count[0:76], 'b')
axarr[2].set_title('isolated_nodes')

plt.savefig('figures/eigen_isolated_shortcut_76cycles.png')
plt.clf()
	

