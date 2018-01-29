'''
The trickle reset is caused by the link failures, or loop. It indicates the dynamics of
the network. Which is independent of the protocol.

USE summary packet

result_time pkt_length total_time node_id parent_id rctp_psetsize rctp_parent rctp_retxs options thl 
	0,1       	2			3		4			5				6		7			8		9	  10
etx origin_seqnum packet_type stats_petx stats_letx stats_raw_frssi stats_raw_brssi health_generated 
11		12			13			14			15			16				17				18

health_forwarded health_retransmissions health_dropped ctrl_ntxpkt ctrl_nrxpkt ctrl_nparentchange 
	19				20						21				22			23			24

ctrl_ntricklereset data_ntxpkt data_nrxpkt data_nrxacks data_nqueuedrops data_ndups data_ninconsistencies
	25					26			27			28			29				30			31
	

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
SRC = 4
PARENT = 5
PRNT_SIZE = 6
HOP = 10
DROP = 21		## packet drop due to transmission failure 
ROUT_TX = 22
PRNT_CHANGE = 24
TRICKLE = 25
QUEUE_DROP = 29		### packet drop due to queue overflow
LOOP = 31

# the total number of node ids
N = 97
TOTAL_CYCLES = 299

inf = open("../../../data/indriya/test7_power_full/summary_pkt_indriya_20161015_formatted.txt", "r")
#inf = open("../data/indriya/test_data.txt", "r")
# use all data instead of only the cs_pkt
#inf = open("../../data/indriya/20160818-rctp_all_packets.txt", "r")

inf_ids = open("../../../data/indriya/test7_power_full/nodeids.txt", "r")
inf_trees = open('Number_of_spanning_trees.txt', 'r')

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

##################### the number of trees per cycle ############
trees = []
lines = inf_trees.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		if s[0] == 'Number_of_spanning_trees:':
			trees.append(float(s[1]))
			if len(trees) == 298:
				break
			
inf_trees.close()

################################################################
### draw the figure of the trickle reset
cur_reset = [0 for i in range(N)]
pre_reset = [0 for i in range(N)]
cycle_reset = []
### the last reset of the node (the largest, in the test there is no reboot)
last_reset = [0 for i in range(N)]

last_loop = [0 for i in range(N)]
cur_loop = [0 for i in range(N)]
pre_loop = [0 for i in range(N)]
cycle_loop = []


#pre_drop = 
#cur_drop = 
#cycle_drop = []		## the number of packet drops each cycle
dropped = [0 for i in range(N)]	## the number of dropped packets for each node


round_count = 0
lines = inf.readlines()
line_count = 0
cur_time = 0
pre_time = 0
for line in lines:
	s = line.split()
	line_count += 1
	if line_count == 1:
		continue
	
	## read each packet and build adjacent matrix for every two hours
	if line_count == 2:
		time_string = s[0] + ' ' + s[1][0:8]
		cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
		pre_time = cur_time
	
	# compute current time
	time_string = s[0] + ' ' + s[1][0:8]
	cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
	
	if cur_time - pre_time > 60*5:
		### get trickle reset of this cycle
		round_count += 1
		
		if round_count == 1:
			cycle_reset.append(0)
			cycle_loop.append(0)
			
		else:
			tmp = 0
			## the difference from the last cycle
			for i in range(N):
				if cur_reset[i] > 0 and pre_reset[i] > 0:
					## if either of these is 0, then the node's data is missing for 
					## at least one cycle, cannot be seen.
					tmp += cur_reset[i] - pre_reset[i]
					if round_count == 135:
						print '\t' + nodeids[i] + ': ' + str(cur_reset[i]) + ', ' + str(pre_reset[i])
					
			print str(round_count) + ': ' + str(tmp)
			cycle_reset.append(tmp)
			
			tmp = 0
			for i in range(N):
				if cur_loop[i] > 0 and pre_loop[i] > 0:
					## if either of these is 0, then the node's data is missing for 
					## at least one cycle, cannot be seen.
					tmp += cur_loop[i] - pre_loop[i]
#					if round_count == 135:
#						print '\t' + nodeids[i] + ': ' + str(cur_loop[i]) + ', ' + str(pre_loop[i])
					
#			print str(round_count) + ': ' + str(tmp)
			cycle_loop.append(tmp)
			
			
		
		### reset cycle
		for i in range(N):
			pre_reset[i] = cur_reset[i]
			cur_reset[i] = 0
			
			pre_loop[i] = cur_loop[i]
			cur_loop[i] = 0
			
		pre_time = cur_time
	
	if s[SRC] not in nodeids:
		print line
		continue	
	cur_reset[idx(s[SRC])] = int(s[TRICKLE])
	cur_loop[idx(s[SRC])] = int(s[LOOP])
	
	
	
	
	last_reset[idx(s[SRC])] = int(s[TRICKLE])
	last_loop[idx(s[SRC])] = int(s[LOOP])
	
#	if s[SRC] == '138':
#		print s[TRICKLE]
	
	## store the latest number of dropped packet in each node
	dropped[idx(s[SRC])] = int(s[DROP])

#### draw figures
f, axarr = plt.subplots(2, sharex=True)

for i in range(len(trees)):
	trees[i] = math.log(trees[i], 10)

#print len(trees)
#print len(cycle_reset)
#for i in range(len(trees)):
#	print str(trees[i]) + '\t' + str(cycle_reset[i])

axarr[0].plot(trees, 'r+', )
axarr[0].set_title('log of spanning trees')

axarr[1].plot(cycle_reset, 'b+')
axarr[1].set_title('trickle resets')

plt.savefig('11.trickle_resets_trees.png', dpi=300)
plt.clf()

print 'total_number of dropped packets: ' + str(sum(dropped))


outf = open('trickle_resets_per_cycle.txt', 'w')
outf.writelines("total_resets after initial sum(cycle_resets): %d\n" % (sum(cycle_reset)))
outf.writelines("total_resets including initial: %d\n" % (sum(last_reset)))
outf.writelines("total_loops: %d\n" % (sum(last_loop)))

for i in range(len(cycle_reset)):
	outf.writelines("cycle: %d, resets:\t%d\tloop:\t%d\n" % (i, cycle_reset[i], cycle_loop[i]))



print last_reset

print sum(last_loop)


