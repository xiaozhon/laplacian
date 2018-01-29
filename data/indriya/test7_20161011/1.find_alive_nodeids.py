'''
find node ids of the good periods

result_time total_time node_id parent_id rctp_psetsize rctp_parent rctp_retxs options thl etx origin_seqnum packet_type stats_petx stats_letx stats_raw_frssi stats_raw_brssi health_generated health_forwarded health_retransmissions health_dropped ctrl_ntxpkt ctrl_nrxpkt ctrl_nparentchange ctrl_ntricklereset data_ntxpkt data_nrxpkt data_nrxacks data_nqueuedrops data_ndups data_ninconsistencies
   0, 1			2		3		4				5			6

'''


import sys
import time

DAY = 0
TIME = 1
SRC = 3
PARENT = 4
HOP = 9
PATH = 29


inf = open('20161011-rctp_indriya_all_packets.txt', 'r')
#inf = open("cs_pkt_indriya_20161006_formatted.txt", "r")

outf = open("nodeids.txt", "w")
outf_err = open("err_ids.txt", "w")

rcvd_ids = []
err_ids = []

line_count = 0
lines = inf.readlines()

for line in lines:
	line_count += 1
	if line_count == 1:
		continue
	s = line.split()
	
	
	if int(s[HOP]) > 13:
		# if the path is too long, the other nodes are lost
		path_len = 12
	else:
		path_len = int(s[HOP]) - 1
	
	path = [s[SRC], s[PARENT]]
	
	## only add path for cs packet
	if s[2] == '69':
#		print line
		for i in range(PATH, PATH + path_len):
			if s[i] != '0':
				## for German's test nodes, the path is not recorded, thus those are 0s
				path.append(s[i])

	for nodeid in path:
		
		if int(nodeid) not in rcvd_ids and int(nodeid) < 139:
			rcvd_ids.append(int(nodeid))

rcvd_ids.sort()
for nodeid in rcvd_ids:
	outf.writelines(str(nodeid) + '\n')
	
inf.close()
outf.close()
outf_err.close()
	
