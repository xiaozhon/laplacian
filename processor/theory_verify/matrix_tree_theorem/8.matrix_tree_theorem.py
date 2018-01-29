'''
Compute the number of spanning trees using the matrix tree theorem.

Verify using a simple example

topology 1: test_data1.txt		*** correct
	1
   / \
  2   3
   \ /
    4
    |
    5
   
topology 2: test_data2.txt		*** correct
	 1
   / | \
  2  3  4
   \ | /
     5
    / \
   6   7
   
topology 3: test_data3.txt		*** correct
	 1
   / | \
  2  3  4
   \/ \/
   5   6
    \ /
     7
    / \
   8   9
   
topology 4: test_data4.txt		*** If network is partitioned, the answer is wrong
	 1
   / | \
  2  3  4
   \   /
   5   6
     
     7
    / \
   8   9
   

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
N = 9

inf = open("test_data4.txt", "r")

outf = open("Number_of_spanning_trees.txt", "w")


#################### load node ids #####################
inf_ids = open('nodeids.txt','r')
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
		
	## read each packet and build adjacent matrix for every two hours
	if line_count == 2:
		time_string = s[0] + ' ' + s[1][0:8]
		cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
		pre_time = cur_time
	
	# compute current time
	time_string = s[0] + ' ' + s[1][0:8]
	cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
	
#	print cur_time - pre_time
	
	if cur_time - pre_time > 60*5:
		# larger than 2 hours, compute and output the laplacian matrix
		round_count += 1
		outf.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		
		########################################################################
		print '-------adjacent matrix is: '		
		k = 1
		for i in range(N):
			degrees[i] = sum(pm[i])		# the out degree
			print am[i]
			if degrees[i] > 0:
				k = k * degrees[i]
		
		print '-------parent matrix is: '
		for i in range(N):
			print pm[i]
		
		print '------- laplacian matrix is: '
		### compute Laplacian matrix for directed graph
		newline = ''
		for i in range(N):
			for j in range(N):
				if i == j:
					lm[i][j] = degrees[i]
				else:
					if pm[i][j] > 0:
						lm[i][j] = -1*pm[i][j]
			print lm[i]
#		print lm
		### matrix for matrix tree theorem
		### remove the isolated nodes from the laplacian matrix
		mtt = []	
		print '------matrix tree is: '
		for i in range(N):
			if degrees[i] != 0:
				row = []
				for j in range(N):
					if degrees[j] != 0:
						row.append(lm[i][j])
				mtt.append(row)
				print row
#		print len(mtt)
		### compute the determinant of the mtt
		det = LA.det(mtt)
		print det
		outf.writelines('Number_of_spanning_trees: ' + str(det) + '\n')
		
		print 'degrees product: ' + str(k) + '\tmtt_det: ' + str(det)
		
		########################################################################
		
		
		# reset the matrix
		for i in range(N):
			for j in range(N):
				am[i][j] = 0
				lm[i][j] = 0
				pm[i][j] = 0
			degrees[i] = 0
			eigenvals[i] = 0
			prnt_set[i] = 0
			
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
		
#		if s[1] == '15:03:28.744':
#			print s[SRC] + ' ' + s[PARENT]
		
		if path_len >= 1:
			# only two hops
			am[idx(s[PARENT])][idx(s[PATH])] = 1
			am[idx(s[PATH])][idx(s[PARENT])] = 1
			
			pm[idx(s[PARENT])][idx(s[PATH])] = 1
			
#			if s[1] == '15:03:28.744':
#				print s[PARENT] + ' ' + s[PATH]
			
			for i in range(PATH, PATH + path_len-1):
				if s[i] != '0':
					## for German's test nodes, the path is not recorded, thus those are 0s
					am[idx(s[i])][idx(s[i+1])] = 1
					am[idx(s[i+1])][idx(s[i])] = 1
					
					pm[idx(s[i])][idx(s[i+1])] = 1
					
#					if s[1] == '15:03:28.744':
#						print s[i] + ' ' + s[i+1]
		
		
### last cycle is less than 2 hours, ingore it

inf.close()
outf.close()



