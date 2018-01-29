'''
compute the network PRR for each cycle. If a node is isolated, don't count it.

PRR = sent_packet / received_packets

'''


import sys
import time
import math
import numpy as np
import matplotlib.pyplot as plt

DAY = 0
TIME = 1
SRC = 3		# if split using ' ', idx is 3
PARENT = 4	#							 4
PRNT_SIZE = 5
HOP = 9		#							 9
GENERATED = 17

N = 97 # including sink

inf = open('20161010-rctp_indriya_all_packets.txt', 'r')
#inf = open('test_data.txt', 'r')
inf_ids = open('nodeids.txt', 'r')

outf = open('node_prr_per_cycle.txt', 'w')

# key = nodeid, value = [[generated_seqno], generated, received_count]
node_pkts = {}
nodeids = []

lines = inf_ids.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		nodeids.append(s[0])
		node_pkts[s[0]] = [[], 0, 0]

inf_ids.close()

# find the index of a node id in the list
def idx(nodeid):
	for i in range(N):
		if nodeid == nodeids[i]:
			return i
	return -1
################################################################################

lines = inf.readlines()
pre_generated = 0
#pre_day = ''
#cur_day = ''

cur_time = 0
pre_time = 0
round_count = 0
prnt_set = [0 for i in range(N)]

line_count = 0
for line in lines:
	s = line.split()
	
	if len(s) > 0:
		line_count += 1
		if line_count == 1:
			continue
			
		if line_count == 2:
			time_string = s[0] + ' ' + s[1][0:8]
			cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
			pre_time = cur_time
		if not node_pkts.has_key(s[SRC]):
			continue
		
		if int(s[GENERATED]) > 250:
			continue
		
		# compute current time use CS packet. Use CS packet as the cycle delimiter
		if s[2] == '69':
			time_string = s[0] + ' ' + s[1][0:8]
			cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
	
		if cur_time - pre_time > 60*5:
			# end of pre day, start of the next day
			# process previous day's data 
			round_count += 1
			prr = [0 for i in range(N)]
			outf.writelines(time_string + ': cycle ' + str(round_count) +'\n')
			
#			generated = max(node_pkts[s[SRC]][0]) - min(node_pkts[s[SRC]][0]) + 1
			
			for key in node_pkts:
				if node_pkts[key][1] > 0:
					generated = max(node_pkts[key][0]) - min(node_pkts[key][0]) + 1
					prr[idx(key)] = 1.0*node_pkts[key][2] / generated
				else:
					prr[idx(key)] = 0
#				outf.writelines('\t' + key + ': ' + str(node_pkts[key]) + '\n')

			for i in range(N):
				outf.writelines('\t' + nodeids[i] + ': ' + str(prr[idx(nodeids[i])]) + 
								'\t' + str(prnt_set[idx(nodeids[i])]) + '\n')
			
				if nodeids[i] == '138':
					print node_pkts[nodeids[i]]
				
			
			tmp = []
			for p in prr:
				if p != 0:
					tmp.append(p)
			# calculate PRR only for connected nodes
			outf.writelines('\n\tAvg PRR: ' + str(np.mean(tmp)) + '\tstd: ' + str(np.std(tmp)) + '\n')
			outf.writelines('\tAverage Parent Set size: ' + str(np.mean(prnt_set)) + '\tstd: ' + str(np.std(prnt_set)) + '\n\n' )
#			print np.mean(prnt_set)
			
#			print np.mean(tmp)
			
			for key in node_pkts:
				node_pkts[key] = [[], 0, 0]
			
			for i in range(N):
				prnt_set[i] = 0
				node_pkts[key][1] = 0
				node_pkts[key][2] = 0
				node_pkts[s[SRC]][0] = []
			pre_time = cur_time
			
		# add cur day data

		if len(node_pkts[s[SRC]][0]) >= 1:
			
#			pre_generated = node_pkts[s[SRC]][0][len(node_pkts[s[SRC]][0]) - 1]
			pre_generated = max(node_pkts[s[SRC]][0])
			
			if int(s[GENERATED]) <= pre_generated:
				## if current sequence number is smaller, do nothing.
				## This sequence number is alreay counted in the previous
				## e.g., 			seq = 50, 53, 52, 54
				##      total should be = 50, 53, 53, 54
				##		sequence number 52 is simply ignored
				### do nothing
				a = 100
					
			else:
#				## current sequence number is larger
#				
				node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + int(s[GENERATED]) - pre_generated
					
		else:
			# the first packet of each node
#			node_pkts[s[SRC]][1] = int(s[GENERATED])
			node_pkts[s[SRC]][1] = 1
		
		if int(s[GENERATED]) not in node_pkts[s[SRC]][0]:
			node_pkts[s[SRC]][0].append(int(s[GENERATED]))
		
			## remove duplicate
			node_pkts[s[SRC]][2] += 1
		
		prnt_set[idx(s[SRC])] = int(s[PRNT_SIZE])
		
#		if s[SRC] == '10011':
#			print s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[PARENT] + ' ' + s[GENERATED] 
	
# the last day's data
round_count += 1
outf.writelines(time_string + ': cycle ' + str(round_count) +'\n')
prr = [0 for i in range(N)]
for key in node_pkts:
	if node_pkts[key][1] > 0:
		prr[idx(key)] = 1.0*node_pkts[key][2] / node_pkts[key][1]
	else:
		prr[idx(key)] = 0
#	outf.writelines(key + ': ' + str(node_pkts[key]) + '\n')

for i in range(N):
	outf.writelines(nodeids[i] + ': ' + str(prr[idx(nodeids[i])]) + '\n')
	
tmp = []
for p in prr:
	if p != 0:
		tmp.append(p)

# calculate PRR only for connected nodes
outf.writelines('\n\tAvg PRR: ' + str(np.mean(tmp)) + '\tstd: ' + str(np.std(tmp)) + '\n')
outf.writelines('\tAverage Parent Set size: ' + str(np.mean(prnt_set)) + '\tstd: ' + str(np.std(prnt_set)) + '\n\n' )


inf.close()
outf.close()
	
	


