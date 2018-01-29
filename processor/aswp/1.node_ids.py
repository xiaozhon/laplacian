'''
find the node ids of the good periods, using the full path


####

result_time pkt_length node_id parent_id 
0, 1		2			3		4

rctp_psetsize rctp_parent rctp_retxs options thl etx origin_seqnum packet_type stats_petx stats_letx stats_raw_frssi stats_raw_brssi 
	5			6			7			8	  9   10	11				12			13			14			15				16
	
health_generated health_forwarded health_retransmissions health_dropped 
	17				18					19					20

# CS packet starts
flag linkid_sum temp_cs temp hum_cs hum adc_cs adc path0 path1 path2 path3 path4 path5 path6 path7 path8 path9 path10 path11
21		22			23	 24		25  26   27		28  29   


# path:
	[src, parent, path0, path1, ...]
	
2016-08-18	89
2016-08-19	89
2016-08-20	89
2016-08-21	88
2016-08-22	88
2016-08-23	86
2016-08-24	84


'''

import sys
import time

DAY = 0
TIME = 1
SRC = 3
PARENT = 4
HOP = 9
PATH = 29


#inf = open("../data/aswp/cs_pkt_20160818.txt", "r")
inf = open("../../data/aswp/20160818-rctp_all_packets.txt", "r")

inf_ids = open("../../data/aswp_correct_nodeids.txt","r")

outf = open("nodeids.txt", "w")
outf_err = open("err_ids.txt", "w")

### load the correct aswp node ids
all_ids = []
lines = inf_ids.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		all_ids.append(s[0])
inf_ids.close()

rcvd_ids = []
err_ids = []

line_count = 0
lines = inf.readlines()

for line in lines:
	line_count += 1
	if line_count == 1:
		continue
	s = line.split()
	
	## only compute the nodeids in the good periods
	if s[0] > '2016-08-24':
		continue
	
	if int(s[HOP]) > 13:
		# if the path is too long, the other nodes are lost
		path_len = 12
	else:
		path_len = int(s[HOP]) - 1
	
	path = [s[SRC], s[PARENT]]
	
	## only add path for cs packet
	if s[2] == '69':
		for i in range(PATH, PATH + path_len):
			if s[i] != '0':
				## for German's test nodes, the path is not recorded, thus those are 0s
				path.append(s[i])

	for nodeid in path:
		if nodeid not in all_ids:
			## this is an error id
			if nodeid not in err_ids:
				err_ids.append(nodeid)
				outf_err.writelines(nodeid + '\n')
		else:
			if nodeid not in rcvd_ids:
				rcvd_ids.append(nodeid)

rcvd_ids.sort()
for nodeid in rcvd_ids:
	outf.writelines(nodeid + '\n')
	
inf.close()
outf.close()
outf_err.close()
	

