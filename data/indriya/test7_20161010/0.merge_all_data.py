'''
this script put all rctp packets together, into one file.

sensor_data, routing_data, summary_data, cs_data => rctp_all_data

## cs packet
result_time pkt_length node_id parent_id rctp_psetsize rctp_parent rctp_retxs options thl etx origin_seqnum packet_type stats_petx stats_letx stats_raw_frssi stats_raw_brssi health_generated health_forwarded health_retransmissions health_dropped flag linkid_sum temp_cs temp hum_cs hum adc_cs adc path0 path1 path2 path3 path4 path5 path6 path7 path8 path9 path10 path11

## data packet
result_time appversion motetype node_id parent_id voltage indicator dutycycle rctp_psetsize rctp_parent rctp_retxs origin_seqnum etx thl options packet_type health_generated health_forwarded health_retransmissions health_dropped stats_petx stats_letx stats_frssi stats_brssi flash_node_id flash_wdt_resets humidity temperature adc0 adc1 adc2 adc3 adc4 adc5 adc6 msp2_temperature msp2_waterpotential
    0, 1         2        -3-     4         5       -6-      -7-     -8-         [9            10            11]      12          13  14    15       16             17             18                   19                20             21        22          23          24
	s[0~1] + s[2] + s[4, 5] + s[9~11] + s[15] + s[14] + s[13] + s[12] + s[16] + s[21~24] + s[17~20] + s[25]

result_time pkt_length appversion motetype node_id parent_id voltage indicator dutycycle rctp_psetsize rctp_parent rctp_retxs origin_seqnum etx thl options packet_type health_generated health_forwarded health_retransmissions health_dropped stats_petx stats_letx stats_frssi stats_brssi flash_node_id flash_wdt_resets humidity temperature adc0 adc1 adc2 adc3 adc4 adc5 adc6 msp2_temperature msp2_waterpotential
    0, 1         2        -3-       -4-         5       6      -7-     -8-         -9-        10            11            12      13         14  15    16       17             18             19                   20                21             22        23          24          25
	s[0~1] + s[2] + s[5, 6] + s[10~12] + s[16] + s[15] + s[14] + s[13] + s[17] + s[22~25] + s[18~21] + s[26]

## summary packet
result_time pkt_length total_time node_id parent_id rctp_psetsize rctp_parent rctp_retxs options thl etx origin_seqnum packet_type stats_petx stats_letx stats_raw_frssi stats_raw_brssi health_generated health_forwarded health_retransmissions health_dropped ctrl_ntxpkt ctrl_nrxpkt ctrl_nparentchange ctrl_ntricklereset data_ntxpkt data_nrxpkt data_nrxacks data_nqueuedrops data_ndups data_ninconsistencies
	0,1       -2-        3
## Routing packet 
result_time node_id parent_id rctp_psetsize rctp_parent rctp_retxs options thl etx origin_seqnum packet_type stats_petx stats_letx stats_raw_frssi stats_raw_brssi health_generated health_forwarded health_retransmissions health_dropped ctrl_ntxpkt ctrl_nrxpkt ctrl_nparentchange ctrl_ntricklereset data_ntxpkt data_nrxpkt data_nrxacks data_nqueuedrops data_ndups data_ninconsistencies


'''
import sys
inf_sensor = open("data_pkt_indriya_20161010_formatted.txt", "r")
inf_summary = open("summary_pkt_indriya_20161010_formatted.txt", "r")
 
inf_cs = open("cs_pkt_indriya_20161010_formatted.txt", "r")

outf = open("20161010-rctp_indriya_all_packets.txt", "w")

all_packets = []

sensor_lines = inf_sensor.readlines()

line_count = 0
for line in sensor_lines:
	s = line.split()
	line_count += 1
	if line_count > 1 and len(s) > 0:
		newline = s[0] + ' '  + s[1] + ' ' + s[2] + ' ' + s[5] + ' ' + s[6] + ' '
		newline = newline + s[10] + ' ' + s[11] + ' ' + s[12] + ' ' + s[16] + ' '
		newline = newline + s[15] + ' ' + s[14] + ' ' + s[13] + ' ' + s[17] + ' '
		newline = newline + s[22] + ' ' + s[23] + ' ' + s[24] + ' ' + s[25] + ' '
		newline = newline + s[18] + ' ' + s[19] + ' ' + s[20] + ' ' + s[21] + ' '
		for i in range(26, len(s)):
			newline += s[i] + ' '
		newline += '\n'
		all_packets.append(newline)
		
inf_sensor.close()

###########################################################
summary_lines = inf_summary.readlines()

line_count = 0
for line in summary_lines:
	s = line.split()
	line_count += 1
	if line_count > 1 and len(s) > 0:
		newline = s[0] + ' ' + s[1] + ' '
		for i in range(3, len(s)):
			newline += s[i] + ' '
		newline += '\n'
		all_packets.append(newline)
		
inf_summary.close()

############################################################
#routing_lines = inf_routing.readlines()

#line_count = 0
#for line in routing_lines:
#	s = line.split()
#	line_count += 1
#	if line_count > 1 and len(s) > 0:
#		newline = s[0] + ' ' + s[1] + ' 255 '
#		for i in range(2, len(s)):
#			newline += s[i] + ' '
#		newline += '\n'
#		all_packets.append(newline)
#		
#inf_routing.close()

##############################################################

cs_lines = inf_cs.readlines()

line_count = 0
for line in cs_lines:
	s = line.split()
	line_count += 1
	if line_count > 1 and len(s) > 0:
		all_packets.append(line)
		
inf_cs.close()

#################################################################
all_packets.sort()

for packet in all_packets:
	outf.writelines(packet)
	
outf.close()
