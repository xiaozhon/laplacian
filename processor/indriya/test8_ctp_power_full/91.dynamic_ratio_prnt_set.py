'''
find the static parent set, and compute the links that are not in the prnt set as the
env

2016-10-15 10:21:19.751 69 24 31 1 31 0 0 1 10 3 222 10 10 219 232 4 0 0 0 0 1572902 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

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
N = 97
INTERVAL = 1	# two cycles

#inf = open("../../../data/indriya/test7_power_full/cs_pkt_indriya_20161015_formatted.txt", "r")
inf = open("../../../data/indriya/test8_ctp_power_full/20161013-ctp_indriya_all_packets.txt", "r")

inf_ids = open("../../../data/indriya/test8_ctp_power_full/nodeids.txt", "r")

outf = open('dynamic_ratio_per_cycle.txt', 'w')
#################### load node ids #############################################
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
################################# initial version
### compare the received links (out degree) with the prnt set size
### protocol = sum(prnt_size)		all = sum(out_degree)	env = all - protocol
# all
pm = [[0 for row in range(N)] for col in range(N)]
degrees = [0 for i in range(N)]	
# protocol
prnt_set = [0 for i in range(N)]

# dynamic ratio for each cycle (ratio_protocol)
dr = []

lines = inf.readlines()
cur_time = 0
pre_time = 0
round_count = 0
line_count = 0

for line in lines:
	s = line.split()
	line_count += 1
		
	if line_count == 1:
		time_string = s[0] + ' ' + s[1][0:8]
		cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
		pre_time = cur_time
	
	# compute current time
	time_string = s[0] + ' ' + s[1][0:8]
	cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
	
	if cur_time - pre_time > 60*5*INTERVAL:	
		#### analysis for the last cycle
		round_count += 1*INTERVAL
		outf.writelines(time_string + ' Round: ' + str(round_count) + '\n')
		
		print round_count
#		print pm
		for i in range(N):
		## compute the out degree
			degrees[i] = sum(pm[i])
			if degrees[i] > 0:
				## this node is not isolated, find its prnt set, otherwise ignore it
				prnt_set[i] = 1
		### all links
		edges = sum(degrees)
		p_edges = sum(prnt_set)
		
		ratio = 1.0 * p_edges / edges
		dr.append(ratio)
		outf.writelines('\tprnt_set:\t\t' + str(prnt_set) + '\n')
		outf.writelines('\tout_degrees:\t' + str(degrees) + '\n')
		outf.writelines('\tall_edges:\t' + str(edges) + '\tratio_protocol:\t' 
							+ str(ratio) + '\tratio_env:\t' + str(1-ratio)
							+ '\n')
		
		for i in range(N):
			degrees[i] = 0
			prnt_set[i] = 0
			for j in range(N):
				pm[i][j] = 0
		
		pre_time = cur_time
		

	# build the prnt matrix
	# set the matrix cell to be 1 if the child-parent pair exists
	path_len = 0
	if int(s[HOP]) > 13:
		# if the path is too long, the other nodes are lost
		path_len = 12
	else:
		path_len = int(s[HOP]) - 1
	
	pm[idx(s[SRC])][idx(s[PARENT])] = 1
	
	### print the parents
#	if s[SRC] == '1':
#		print time_string + ' ' + s[SRC] + ' ' + s[PARENT]
	
	#### the rest only for cs packets
	if s[2] != '69':
		continue
	
#	if s[1] == '15:03:28.744':
#		print s[SRC] + ' ' + s[PARENT]
	
	if path_len >= 1:
		# only two hops
		
		pm[idx(s[PARENT])][idx(s[PATH])] = 1
		
		### print the parents
#		if s[PARENT] == '1':
#			print '\tpath: ' + time_string + ' ' + s[PARENT] + ' ' + s[PATH]
		
		for i in range(PATH, PATH + path_len-1):
			if s[i] != '0':
				## for German's test nodes, the path is not recorded, thus those are 0s
				pm[idx(s[i])][idx(s[i+1])] = 1
				
				### print the parents
#				if s[i] == '1':
#					print '\tpath: ' + time_string + ' ' + s[i] + ' ' + s[i+1]	


##### end of for
### plot the figure
print 'plotting dynamic ratio'
fig, ax = plt.subplots(figsize=(3.45, 2.0))
#fig, ax = plt.subplots()

ax.spines['top'].set_linewidth(0.8)
ax.spines['right'].set_linewidth(0.8)
ax.spines['bottom'].set_linewidth(0.8)
ax.spines['left'].set_linewidth(0.8)

#ax.plot(total_trees, 'ko')
protocol, = ax.plot([dr[i] * 100 for i in range(len(dr))], 'k', linestyle='solid', marker='*', markersize=1, linewidth=0.5)

env, = ax.plot([(1-dr[i])*100 for i in range(len(dr))], 'b', linestyle=':', marker = '+', markersize=1, linewidth=0.5)

ax.set_title("Dynamic ratios", family='Times New Roman', size=8 )
ax.set_ylabel("Percentage", family='Times New Roman', size=8, labelpad=0.7)
ax.set_xlabel("Cycle count", family='Times New Roman', size=8, labelpad=0.7)


x_ticks = [i for i in range(0, len(dr)+5, 50)]
ax.set_xticks(x_ticks)
ax.set_xticklabels(x_ticks,size=7)

yticks = [i for i in range(-10, 110, 10)]
ax.set_yticks(yticks)
ax.set_yticklabels(yticks, size=7)	# this to reduce y label font

lg = ax.legend((protocol, env), 
		('Protocol', 'Environment'),
		loc='best', prop={'size':7})
lg.get_frame().set_linewidth(0.3)
plt.tight_layout(pad=0.3)

fig.savefig('91.Prnt_set_dynamic_ratio.png', dpi=300)
plt.clf()


inf.close()
outf.close()



