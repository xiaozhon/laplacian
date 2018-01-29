'''
Compute the number of spanning trees using the matrix tree theorem, for the direct tree 

Draw the figure of the total number of trees for each timer interval, also the trees 
caused by the protocol or the environment

sensor data: 2013-11-14 15:34:07.189 10401 1 1350303544 259784502 10201 0 0 0 0 0 0 0 0 0 0 
0		1		2			3			4  5    6          7        8


'''

import sys
import time
import math
from numpy import linalg as LA
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
import numpy as np


DAY = 2
TIME = 3
SRC = 4
PARENT = 8
HOP = 5
PATH = 8


# the total number of node ids
N = 48

CYCLES = 1 # divide data by the number of CYCLES

inf = open("../../data/aswp_201312/parsed_all_data.txt", "r")
#inf = open("../data/aswp/test_data.txt", "r")
# use all data instead of only the cs_pkt
#inf = open("../../data/aswp/20160818-rctp_all_packets.txt", "r")

inf_ids = open("../../data/aswp_201312/nodeids.txt", "r")

outf = open("Number_of_spanning_trees_" + str(CYCLES)+ "cycles_division.txt", "w")


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
		ret += sum(m[i])
	return ret


#########################################################

# the parent matrix, directed adjacent matrix
cur_pm = [[0 for row in range(N)] for col in range(N)]
pre_pm = [[0 for row in range(N)] for col in range(N)]

# the laplacian matrix
# row: src, col: parent
lm = [[0 for row in range(N)] for col in range(N)]
degrees = [0 for i in range(N)]		# the degree of each node

prnt_set = [0 for i in range(N)]	# the size of the parent set

for i in range(N):
	for j in range(N):
		cur_pm[i][j] = 0
		lm[i][j] = 0
	degrees[i] = 0

### the number of trees of each round
total_trees = []		# = protocol_trees + env_trees
protocol_trees = []		# trees introduced by the protocol
env_trees = []			# trees introduced by the environment
dynamic_ratio = []

### The number of trees for the intersection matrix
inter_trees = []
inter_ratio = []		### considered to be the protocol introduced, static trees

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
	if s[0] == 'summary':
		# ignore the summary packets for now
		break
		
	## read each packet and build adjacent matrix for every two hours
	if line_count == 2:
		time_string = s[DAY] + ' ' + s[TIME][0:8]
		cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
		pre_time = cur_time
	
	# compute current time
	time_string = s[DAY] + ' ' + s[TIME][0:8]
	cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
	
#	print cur_time - pre_time
	
	if cur_time - pre_time > 60*15*CYCLES:
		# larger than 2 hours, compute and output the laplacian matrix
		round_count += 1
#		print round_count
		outf.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		
		########################################################################
		# for a single cycle
#		# compute number of spanning trees
#		for i in range(N):
#			degrees[i] = sum(cur_pm[i])		# use out degree for digraph
#		
#		### compute Laplacian matrix for directed graph
#		for i in range(N):
#			for j in range(N):
#				if i == j:
#					lm[i][j] = degrees[i]
#				else:
#					if cur_pm[i][j] > 0:
#						lm[i][j] = -1*cur_pm[i][j]
#	#	print lm
#		### matrix for matrix tree theorem
#		### remove the isolated nodes from the laplacian matrix
#		mtt = []	
#		for i in range(N):
#			if degrees[i] != 0:
#				row = []
#				for j in range(N):
#					if degrees[j] != 0:
#						row.append(lm[i][j])
#				mtt.append(row)
#	#	print len(mtt)
#		### compute the determinant of the mtt
#		det = LA.det(mtt)		## use determinant for digraph
#		print det
		
		########################################################################
		# compute matrix tree and dynamic ratio
		# matrix tree is computed using the union of two matrices
		if round_count == 1:
			# first round, no need to compute
			for i in range(N):
				for j in range(N):
					pre_pm[i][j] = cur_pm[i][j]
		else:
			# compute the dynamic ratio of compare to the last round
			
			
			
			union_matrix = union(pre_pm, cur_pm, N)	
			inter_matrix = intersect(pre_pm, cur_pm, N)
			
#			print union_matrix
			
			i_edges = count_edges(inter_matrix, N)
			u_edges = count_edges(union_matrix, N)
			# procotol introduced dynamics ratio 
			dt = 1.0 * i_edges / u_edges
#			print dt
			dynamic_ratio.append(dt)
			# compute number of spanning trees
			k = 1
			for i in range(N):
				degrees[i] = sum(union_matrix[i])		# use out degree for digraph
				if degrees[i] > 0:
					k = k * degrees[i]
#			print k
			
			
		
			### compute Laplacian matrix for directed graph
			for i in range(N):
				for j in range(N):
					if i == j:
						lm[i][j] = degrees[i]
					else:
						if union_matrix[i][j] > 0:
							lm[i][j] = -1*union_matrix[i][j]
#			if round_count == 51:
#				print 'Union laplacian matrix:'
#				for i in range(N):
#					print lm[i]
#				print '_________________________________'

			### matrix for matrix tree theorem
			### remove the isolated nodes from the laplacian matrix
			mtt = []	
			for i in range(N):
				if degrees[i] != 0:
					row = []
					for j in range(N):
						if degrees[j] != 0:
							row.append(lm[i][j])
					mtt.append(row)
#					if round_count == 51:
#						print nodeids[i]
#			if round_count == 51:
#				print 'Union MTT matrix:'
#				for i in range(len(mtt)):
#					print mtt[i]
#				print '_________________________________'

			### compute the determinant of the mtt
			det = LA.det(mtt)		## use determinant for digraph
#			print det
			
			total_trees.append(det)
			
			## spanning trees introduced by protocol and environment
			protocol_trees.append(det*dt)
			env_trees.append(det*(1-dt))
			
#			if k != det:
				### if the number of spanning trees of Matrix Tree Theorem, print out 
#			print str(round_count) + ': degree_product:\t' + str(k) + '\tMTT_det:\t' + str(det)
#			
			newline = 'Number_of_spanning_trees: ' + str(det) + '\tprotocol: ' + str(det*dt)
			newline += '\tenvironment: ' + str(det*(1-dt)) + '\n'
			
			outf.writelines(newline)
			
			
			### find the number of spanning trees of the intersection matrix, and compare to 
			### the total number of spanning trees
			for i in range(N):
				degrees[i] = sum(inter_matrix[i])		# use out degree for digraph
			
#			if round_count == 51:
#				print 'Intersection matrix:'
#				for i in range(N):
#					print inter_matrix[i]
#				print '_________________________________'
			
#				if round_count == 52:
#					print nodeids[i] + ': ' + str(inter_matrix[i])
			### inter matrix Laplacian matrix 
			
			for i in range(N):
				for j in range(N):
					lm[i][j] = 0
					if i == j:
						lm[i][j] = degrees[i]
					else:
						if inter_matrix[i][j] > 0:
							lm[i][j] = -1*inter_matrix[i][j]
				
			
#			if round_count == 51:
#				print 'Intersection laplacian matrix:'
#				for i in range(N):
#					print lm[i]
#				print '_________________________________'
	#		print lm
			### inter matrix for matrix tree theorem
			### remove the isolated nodes from the laplacian matrix
			inter_mtt = []	
			for i in range(N):
				if degrees[i] != 0:
					row = []
					for j in range(N):
						if degrees[j] != 0:
							row.append(lm[i][j])
#					if round_count == 52:
#						print row
					inter_mtt.append(row)
					
			### compute the determinant of the mtt
#			print str(len(inter_mtt)) + '\t' + str(len(inter_mtt[0]))
			if len(inter_mtt) > 0:
				inter_det = LA.det(inter_mtt)		## use determinant for digraph
			else:
				inter_det = -1
#			print str(round_count) + ': ' + str(inter_det)
			
#			if inter_det == 0:
#				for i in range(len(inter_mtt)):
#					print inter_mtt[i]
#				
#				print '\n\n'	
			inter_trees.append(inter_det)
			if det != 0:
				inter_ratio.append(1.0 * inter_det / det)
			else:
				inter_ratio.append(-1)
			newline = '\tSpanning trees for intersection matrix: ' + str(inter_det) + '\n\n'
			outf.writelines(newline)
			###################################################################
			
			# store current matrix as previous matrix
			for i in range(N):
				for j in range(N):
					pre_pm[i][j] = cur_pm[i][j]
			
		# reset the matrix
		for i in range(N):
			for j in range(N):
				lm[i][j] = 0
				cur_pm[i][j] = 0
			degrees[i] = 0
			prnt_set[i] = 0
			
		pre_time = cur_time
	else:
		# build the adjacent matrix
		
		# set the matrix cell to be 1 if the child-parent pair exists
		path_len = 0
		if int(s[HOP]) > 13:
			# if the path is too long, the other nodes are lost
			path_len = 12
		elif int(s[HOP]) > 0:
			path_len = int(s[HOP])
		
		if path_len == 0:
			cur_pm[idx(s[SRC])][idx('1')] = 1
		else:
			cur_pm[idx(s[SRC])][idx(s[PARENT])] = 1
		
		#### the rest only for cs packets
			
#		if s[1] == '15:03:28.744':
#			print s[SRC] + ' ' + s[PARENT]
		
		if path_len >= 1:
			# only two hops
			
#			if s[1] == '15:03:28.744':
#				print s[PARENT] + ' ' + s[PATH]
			
			for i in range(PATH, PATH + path_len):
				if s[i+1] != '0':
					cur_pm[idx(s[i])][idx(s[i+1])] = 1
				else:
					cur_pm[idx(s[i])][idx('1')] = 1
					
				if s[TIME] == '15:37:11.871':
					print s[i] + ' ' + s[i+1]


for i in range(0, len(total_trees)):
	if total_trees[i] > 0:
		total_trees[i] = math.log(total_trees[i], 10)
#	protocol_trees[i] = math.log(protocol_trees[i], 10)
#	env_trees[i] = math.log(env_trees[i], 10)
	
	##
#	print str(i) + ': ' + str(inter_trees[i])
#	inter_trees[i] = math.log(inter_trees[i], 10)
	

## draw the figure of the number of spanning trees
print 'plotting the number of spanning trees'
#fig, ax = plt.subplots(figsize=(3.45, 2.0))
fig, ax = plt.subplots()
ax.spines['top'].set_linewidth(0.8)
ax.spines['right'].set_linewidth(0.8)
ax.spines['bottom'].set_linewidth(0.8)
ax.spines['left'].set_linewidth(0.8)

#ax.plot(total_trees, 'ko')
total, = ax.plot(total_trees, 'k', linestyle='solid', marker='o', markersize=3, linewidth=1)

#protocol, = ax.plot(protocol_trees, 'k', linestyle='dashed', marker='*', markersize=1.5, linewidth=0.5)

#env, = ax.plot(env_trees, 'k', linestyle='dashdot', marker = '+', markersize=1.5, linewidth=0.5)

ax.set_title("Number of spanning trees", family='Times New Roman', size=8 )

ax.set_ylabel("log(# of spanning trees)", family='Times New Roman', size=8, labelpad=0.7)
ax.set_xlabel("Interval count", family='Times New Roman', size=8, labelpad=0.7)


#x_ticks = [i for i in range(0, len(total_trees)+5, 5)]
#ax.set_xticks(x_ticks)
#ax.set_xticklabels(x_ticks,size=8)

#yticks = [i for i in range(int(min(total_trees)), int(max(total_trees)) + 4, 2)]
#ax.set_yticks(yticks)
#ax.set_yticklabels(yticks, size=8)	# this to reduce y label font


#if CYCLES == 1:
#	lg = ax.legend((total, protocol, env), 
#		('Total', 'Protocol', 'Environment'),
#		loc=(0.5, 0.7), prop={'size':7})
#else:
#	lg = ax.legend((total, protocol, env), 
#		('Total', 'Protocol', 'Environment'),
#		loc='best', prop={'size':7})
		
#lg.get_frame().set_linewidth(0.3)
plt.tight_layout(pad=0.3)


fig.savefig('MTT_Number_of_trees_interval_' + str(CYCLES) + 'cycles.png', dpi=300)
plt.clf()
##################################################################################
# Draw the figure of dynamic raio
print 'plotting dynamic ratio'
#fig, ax = plt.subplots(figsize=(3.45, 2.0))
fig, ax = plt.subplots()

ax.spines['top'].set_linewidth(0.8)
ax.spines['right'].set_linewidth(0.8)
ax.spines['bottom'].set_linewidth(0.8)
ax.spines['left'].set_linewidth(0.8)

#ax.plot(total_trees, 'ko')
protocol, = ax.plot([dynamic_ratio[i] * 100 for i in range(len(dynamic_ratio))], 'k', linestyle='solid', marker='*', markersize=3, linewidth=1)

env, = ax.plot([(1-dynamic_ratio[i])*100 for i in range(len(dynamic_ratio))], 'b', linestyle=':', marker = '+', markersize=3, linewidth=1)

ax.set_title("Dynamic ratios", family='Times New Roman', size=8 )
ax.set_ylabel("Percentage", family='Times New Roman', size=8, labelpad=0.7)
ax.set_xlabel("Interval count", family='Times New Roman', size=8, labelpad=0.7)


#x_ticks = [i for i in range(0, len(dynamic_ratio)+5, 5)]
#ax.set_xticks(x_ticks)
#ax.set_xticklabels(x_ticks,size=8)

#yticks = [i for i in range(0, 100, 10)]
#ax.set_yticks(yticks)
#ax.set_yticklabels(yticks, size=8)	# this to reduce y label font


lg = ax.legend((protocol, env), 
		('Protocol', 'Environment'),
		loc='best', prop={'size':7})
lg.get_frame().set_linewidth(0.3)
plt.tight_layout(pad=0.3)


fig.savefig('MTT_protocol_and_env_ratios_' + str(CYCLES) + 'cycles.png', dpi=300)
plt.clf()

##################################################################################
# figure of the number of spanning trees of the intersection matrix
#fig, ax = plt.subplots(figsize=(3.45, 2.0))
fig, ax = plt.subplots()

ax.spines['top'].set_linewidth(0.8)
ax.spines['right'].set_linewidth(0.8)
ax.spines['bottom'].set_linewidth(0.8)
ax.spines['left'].set_linewidth(0.8)

#ax.plot(inter_trees, 'ko')
inter, = ax.plot(inter_trees, 'k', linestyle='solid', marker='o', markersize=3, linewidth=1)

ax.set_title("Number of spanning trees of Intersection Matrix", family='Times New Roman', size=8 )

ax.set_ylabel("# of spanning trees", family='Times New Roman', size=8, labelpad=0.7)
ax.set_xlabel("Interval count", family='Times New Roman', size=8, labelpad=0.7)


#x_ticks = [i for i in range(0, len(inter_trees)+5, 5)]
#ax.set_xticks(x_ticks)
#ax.set_xticklabels(x_ticks,size=8)

#yticks = [i for i in range(int(min(inter_trees)), int(max(inter_trees)) + 4, 2)]
#ax.set_yticks(yticks)
#ax.set_yticklabels(yticks, size=8)	# this to reduce y label font

#lg = ax.legend((inter, protocol, env), 
#		('Total', 'Protocol', 'Environment'),
#		loc='best', prop={'size':7})
		
#lg.get_frame().set_linewidth(0.3)
plt.tight_layout(pad=0.3)

fig.savefig('MTT_trees_of_intersection_matrix_interval_' + str(CYCLES) + 'cycles.png', dpi=300)
plt.clf()

#########
# Draw the figure of dynamic raio
#fig, ax = plt.subplots(figsize=(3.45, 2.0))
fig, ax = plt.subplots()

ax.spines['top'].set_linewidth(0.8)
ax.spines['right'].set_linewidth(0.8)
ax.spines['bottom'].set_linewidth(0.8)
ax.spines['left'].set_linewidth(0.8)

#ax.plot(total_trees, 'ko')
protocol, = ax.plot([inter_ratio[i] * 100 for i in range(len(inter_ratio))], 'k', linestyle='solid', marker='*', markersize=3, linewidth=1)

ax.set_title("Intersection Tree ratios", family='Times New Roman', size=8 )
ax.set_ylabel("Percentage", family='Times New Roman', size=8, labelpad=0.7)
ax.set_xlabel("Interval count", family='Times New Roman', size=8, labelpad=0.7)


#x_ticks = [i for i in range(0, len(inter_ratio)+5, 5)]
#ax.set_xticks(x_ticks)
#ax.set_xticklabels(x_ticks,size=8)

#yticks = [i for i in range(0, 100, 10)]
#ax.set_yticks(yticks)
#ax.set_yticklabels(yticks, size=8)	# this to reduce y label font


#lg = ax.legend((protocol, env), 
#		('Protocol', 'Environment'),
#		loc='best', prop={'size':7})
#lg.get_frame().set_linewidth(0.3)
plt.tight_layout(pad=0.3)


fig.savefig('MTT_intersection_ratios_' + str(CYCLES) + 'cycles.png', dpi=300)
plt.clf()



inf.close()
outf.close()



