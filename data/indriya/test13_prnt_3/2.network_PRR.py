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
from numpy import linalg as LA
import matplotlib.pyplot as plt

DAY = 0
TIME = 1
SRC = 3
PARENT = 4
HOP = 9
GENERATED = 17

N = 97 # including sink, sink is 31

inf = open('20161101-rctp_indriya_all_packets.txt', 'r')
#inf = open('cs_pkt_indriya_20161006_formatted.txt', 'r')
inf_ids = open('nodeids.txt', 'r')

outf = open('node_prr.txt', 'w')
outf_hop = open('Packet_distribution.txt', 'w')

# key = nodeid, value = [[generated_seqno], generated, received_count]
node_pkts = {}
nodeids = []

# the number of packets on each hop
hop_packets = [0 for i in range(256)]

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
for line in lines:
	s = line.split()
	if len(s) > 0:
	
		if not node_pkts.has_key(s[SRC]):
			# error id
			continue
		
		if len(node_pkts[s[SRC]][0]) >= 1:
			
#			pre_generated = node_pkts[s[SRC]][0][len(node_pkts[s[SRC]][0]) - 1]
			pre_generated = max(node_pkts[s[SRC]][0])
			
#			if s[SRC] == '40':
#				print str(pre_generated) + '\t' + str(node_pkts[s[SRC]][1]) + '\t' + str(pre_generated - node_pkts[s[SRC]][1])
					
			
			if int(s[GENERATED]) <= pre_generated:
				## if current sequence number is smaller, do nothing.
				## This sequence number is alreay counted in the previous
				## e.g., 			seq = 50, 53, 52, 54
				##      total should be = 50, 53, 53, 54
				##		sequence number 52 is simply ignored
#				if s[SRC] == '40':
#					print '\t\t\t**pre: ' + str(pre_generated) + '\tcur: ' + s[GENERATED] + '\tpre_total: ' + str(node_pkts[s[SRC]][1])
				### do nothing
				a = 100
				# a smaller sequence number is encountered
#				print s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)
#				if pre_generated <= 10:
#					## mote rebooted very often
#					node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + int(s[GENERATED])
##					print '\t<10 ' + s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)
#				elif pre_generated - int(s[GENERATED]) > 10:
#					# packet disorder may also cause a smaller generated_num, but
#					# if the difference is larger than 10, it is not a disorder
#					node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + int(s[GENERATED])
#					print '\t>10 ' + s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)
#				elif pre_generated != int(s[GENERATED]):
					# not a duplicate, it is disordered packet, no need to count here
					# the packet is counted by cur_generated - pre_generated
			#		node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + 1
#					print '\tdisorder ' + s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[GENERATED] + ' ' + str(pre_generated)

#				if s[SRC] == '40':
#					print '\t\t\t\t\t\t\t**cur_total: ' + str(node_pkts[s[SRC]][1])
					
			else:
#				## current sequence number is larger
#				if s[SRC] == '40':
#					print 'ELSE: pre: ' + str(pre_generated) + '\tcur: ' + s[GENERATED] + '\tpre_total: ' + str(node_pkts[s[SRC]][1])
#				
				node_pkts[s[SRC]][1] = node_pkts[s[SRC]][1] + int(s[GENERATED]) - pre_generated
#				if s[SRC] == '40':
#					print '\t\t\t\tcur_total: ' + str(node_pkts[s[SRC]][1])
#					
		else:
			# the first packet of each node
			node_pkts[s[SRC]][1] = 1
		## remove duplicate
		if int(s[GENERATED]) not in node_pkts[s[SRC]][0]:
			node_pkts[s[SRC]][0].append(int(s[GENERATED]))
		
			
			node_pkts[s[SRC]][2] += 1
			
			hop_packets[int(s[HOP])] += 1
			
			if s[SRC] == '119':
				print line
			
#		if s[SRC] == '10011':
#			print s[0] + ' ' + s[1] + ' ' + s[SRC] + ' ' + s[PARENT] + ' ' + s[GENERATED] 
		
#		print s[HOP]
		

total_sent = 0
total_packets = 0
prr = [0 for i in range(N)]
for key in node_pkts:
	if node_pkts[key][1] > 0:
		generated = max(node_pkts[key][0]) - min(node_pkts[key][0]) + 1
		prr[idx(key)] = 1.0*node_pkts[key][2] / generated
		total_sent += node_pkts[key][1]
#		total_packets += node_pkts[key][2]
#		print key + '\tsent\t' + str(node_pkts[key][1]) + '\trcvd\t' + str(node_pkts[key][2])
		
	else:
		prr[idx(key)] = 0
	outf.writelines(key + ': ' + str(node_pkts[key]) + '\n')

for i in range(len(nodeids)):
#	print str(i) + ': ' + str(nodeids[i])
#	print nodeids[i]
	outf.writelines(nodeids[i] + '\t' + str(prr[idx(nodeids[i])]) + '\n')

total_packets = sum(hop_packets)
outf_hop.writelines('Total packets are: ' + str(total_packets) + '\t' + str(1.0*total_packets/total_sent) + '\n\n')
outf_hop.writelines('hop\tpackets\t%\n')
for i in range(0, len(hop_packets)):
	if hop_packets[i] > 0:
		outf_hop.writelines(str(i) + '\t' + str(hop_packets[i]) + '\t' + str(1.0*hop_packets[i] / total_packets)+ '\n')
outf_hop.close()

inf.close()
outf.close()
	
	


