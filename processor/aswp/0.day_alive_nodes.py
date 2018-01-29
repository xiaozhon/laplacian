'''
Find out how many nodes in each day

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
'''

import sys
import time

DAY = 0
TIME = 1
SRC = 3
PARENT = 4

#inf = open("../data/aswp/cs_pkt_20160818.txt", "r")
inf = open("../../data/aswp/20160818-rctp_all_packets.txt", "r")
# store the number of nodes of each day
outf = open("node_number_per_day.txt", "w")		
outf_good_period = open("good_periods.txt", "w")

# store the nodes: key = nodeid, value = "Y" or "N"
all_nodes = {}

# the alive nodes each day 
# key = day, value: alive count
daily_alive = {}

line_count = 0
cur_day = ""
pre_day = ""
alive_count = 0
lines = inf.readlines()

for line in lines:
	line_count += 1
	if line_count == 1:
		continue
		
	s = line.split()
	if len(s) > 0:
		src = s[SRC]
		if line_count == 2:
			# the first packet
			pre_day = cur_day = s[DAY]
			
		cur_day = s[DAY]
		if pre_day != cur_day:
			# for each day, count the number of alive nodes
			# if the value is "Y" in all_nodes, then the node is alive
			
			alive_count = 0
			for id in all_nodes:
				if all_nodes[id] == "Y":
					alive_count += 1
			
			newline = pre_day + '\t' + str(alive_count) + '\n'
			outf.writelines(newline)
			
			daily_alive[pre_day] = alive_count
			
			pre_day = cur_day
			
			for id in all_nodes:
				all_nodes[id] = "N"
				
		else:
			# the same day
			if not all_nodes.has_key(src):
				# the node is not in the dict yet
				
				all_nodes[src] = "Y"
			
			all_nodes[src] = "Y"

print line_count

inf.close()
outf.close()

start_date = ""
end_date = ""
days_count = 0

sorted_days = sorted(daily_alive)
for day in sorted_days:
	
	if daily_alive[day] >= 30:
		# if there are more than 30 nodes alive, consider it as good period
		if days_count == 0:
			start_date = day
		
		days_count += 1
	else:
		# the alive nodes is less than 30, period ends
		end_date = day 
		if days_count == 0:
			start_date = end_date
			continue
		newline = start_date + ' ' + end_date + '\t' + str(days_count) + '\n'
		outf_good_period.writelines(newline)
		
		start_date = end_date
		days_count = 0

newline = start_date + " " + sorted_days[len(sorted_days)-1] + '\t' + str(days_count) + '\n'
outf_good_period.writelines(newline)

outf_good_period.close()
		

























