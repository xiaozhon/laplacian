'''
# PRR for each node, for every cycle of 2 hours

2016-08-18	89
2016-08-19	90
2016-08-20	89
2016-08-21	88
2016-08-22	88
2016-08-23	86
2016-08-24	84

-2016-08-25	83
-2016-08-26	75
-2016-08-27	66
-2016-08-28	62

## cs packet
result_time pkt_length node_id parent_id rctp_psetsize rctp_parent rctp_retxs options thl etx 
	0,1			2		3		4			5				6			7		8		9  10

origin_seqnum packet_type stats_petx stats_letx stats_raw_frssi stats_raw_brssi health_generated 
	11			12			13			14			15				16				17			

health_forwarded health_retransmissions health_dropped flag linkid_sum temp_cs temp hum_cs hum adc_cs adc path0 path1 path2 path3 path4 path5 path6 path7 path8 path9 path10 path11	
	18				19						20			21

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
HOP = 9		#							 9
GENERATED = 17

N = 105 # including sink

inf = open('20160624_20160918-rctp_all_packets.txt', 'r')
#inf = open('test_data.txt', 'r')
inf_ids = open('nodeids.txt', 'r')

outf = open('node_prr_perday.txt', 'w')

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
pre_day = ''
cur_day = ''
line_count = 0
for line in lines:
	s = line.split()
	
	if len(s) > 0:
		line_count += 1
		if line_count == 1:
			pre_day = s[0]
		if not node_pkts.has_key(s[SRC]):
			continue
#		if s[SRC] == '20031':
#			print s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[PARENT] + ' ' + s[GENERATED] 
	
		
		cur_day = s[0]
		if cur_day > pre_day:
			# end of pre day, start of the next day
			# process previous day's data 
			prr = [0 for i in range(N)]
			outf.writelines(pre_day + ':\n')
			for key in node_pkts:
				if node_pkts[key][1] > 0:
					prr[idx(key)] = 1.0*node_pkts[key][2] / node_pkts[key][1]
					if prr[idx(key)] > 1:
						print '****************************************************'
				else:
					prr[idx(key)] = 0
				outf.writelines('\t' + key + ': ' + str(node_pkts[key]) + '\n')

			for i in range(N):
				outf.writelines('\t' + nodeids[i] + ': ' + str(prr[idx(nodeids[i])]) + '\n')

			outf.writelines('\n\tAvg PRR: ' + str(np.mean(prr)) + '\tstd: ' + str(np.std(prr)) + '\n\n')
			for key in node_pkts:
				node_pkts[key] = [[], 0, 0]
			
			pre_day = cur_day
			
		# add cur day data

		if len(node_pkts[s[SRC]][0]) > 0:
			pre_generated = node_pkts[s[SRC]][0][len(node_pkts[s[SRC]][0]) - 1]
			
#			if s[SRC] == '20031':
#				print '\tlen>0'
			
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
		
#		if s[SRC] == '20031':
#			print node_pkts[s[SRC]]
	
# the last day's data
outf.writelines(pre_day + ':\n')
prr = [0 for i in range(N)]
for key in node_pkts:
	if node_pkts[key][1] > 0:
		prr[idx(key)] = 1.0*node_pkts[key][2] / node_pkts[key][1]
		if prr[idx(key)] > 1:
			print '****************************************************'
	else:
		prr[idx(key)] = 0
	outf.writelines(key + ': ' + str(node_pkts[key]) + '\n')

for i in range(N):
	outf.writelines(nodeids[i] + ': ' + str(prr[idx(nodeids[i])]) + '\n')



inf.close()
outf.close()
	
	


