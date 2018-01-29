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

N = 93 # including sink

inf = open('20160818-rctp_all_packets.txt', 'r')
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
			time_string = s[0] + ' ' + s[1][0:8]
			cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
			pre_time = cur_time
		if not node_pkts.has_key(s[SRC]):
			continue
		
		# compute current time use CS packet. Use CS packet as the cycle delimiter
		if s[2] == '69':
			time_string = s[0] + ' ' + s[1][0:8]
			cur_time = time.mktime(time.strptime(time_string,'%Y-%m-%d %H:%M:%S'))
	
		if cur_time - pre_time > 60*60*2:
			# end of pre day, start of the next day
			# process previous day's data 
			round_count += 1
			prr = [0 for i in range(N)]
			outf.writelines(time_string + ': cycle ' + str(round_count) +'\n')
			for key in node_pkts:
				if node_pkts[key][1] > 0:
					prr[idx(key)] = 1.0*node_pkts[key][2] / node_pkts[key][1]
				else:
					prr[idx(key)] = 0
#				outf.writelines('\t' + key + ': ' + str(node_pkts[key]) + '\n')

			for i in range(N):
				outf.writelines('\t' + nodeids[i] + ': ' + str(prr[idx(nodeids[i])]) + 
								'\t' + str(prnt_set[idx(nodeids[i])]) + '\n')
			
			tmp = []
			for p in prr:
				if p != 0:
					tmp.append(p)
			# calculate PRR only for connected nodes
			outf.writelines('\n\tAvg PRR: ' + str(np.mean(tmp)) + '\tstd: ' + str(np.std(tmp)) + '\n\n')
			print np.mean(tmp)
			for key in node_pkts:
				node_pkts[key] = [[], 0, 0]
			
			for i in range(N):
				prnt_set[i] = 0
			
			pre_time = cur_time
			
		# add cur day data

		if len(node_pkts[s[SRC]][0]) > 0:
			pre_generated = node_pkts[s[SRC]][0][len(node_pkts[s[SRC]][0]) - 1]
			
			if int(s[GENERATED]) == pre_generated and pre_generated > 10:
				# this is a duplicate, don't count
				continue
			
			
			if int(s[GENERATED]) <= pre_generated:
				# a smaller sequence number is encountered
#				print s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)
				if pre_generated <= 10:
					## mote rebooted very often
					node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + int(s[GENERATED])
#					print '\t<10 ' + s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)
				elif pre_generated - int(s[GENERATED]) > 10:
					# packet disorder may also cause a smaller generated_num, but
					# if the difference is larger than 10, it is not a disorder
					node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + int(s[GENERATED])
#					print '\t>10 ' + s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)
#				elif pre_generated != int(s[GENERATED]):
					# not a duplicate, it is disordered packet, no need to count here
					# the packet is counted by cur_generated - pre_generated
			#		node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + 1
#					print '\tdisorder ' + s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)
			else:
				## current sequence number is larger
				node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + int(s[GENERATED]) - pre_generated

		else:
			# the first packet of each node
			node_pkts[s[SRC]][1] = 1
	
		node_pkts[s[SRC]][0].append(int(s[GENERATED]))
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
outf.writelines('\n\tAvg PRR: ' + str(np.mean(tmp)) + '\tstd: ' + str(np.std(tmp)) + '\n\n')


inf.close()
outf.close()
	
	


