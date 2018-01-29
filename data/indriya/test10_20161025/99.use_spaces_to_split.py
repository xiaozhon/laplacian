'''
replace the " in sql data to empty
replace the ; in sql data to ' '

'''
import sys
inf_sensor = open("data_pkt_indriya_20161025.txt", "r")
inf_summary = open("summary_pkt_indriya_20161025.txt", "r")
inf_cs = open("cs_pkt_indriya_20161025.txt", "r")

outf_sensor = open("data_pkt_indriya_20161025_formatted.txt", "w")
outf_summary = open("summary_pkt_indriya_20161025_formatted.txt", "w")
outf_cs = open("cs_pkt_indriya_20161025_formatted.txt", "w")

sensor_lines = inf_sensor.readlines()

line_count = 0
for line in sensor_lines:
	newline = ''
	for s in line:
		if s == '"':
			continue
		elif s == ';':
			newline += ' '
		else:
			newline += s
	outf_sensor.writelines(newline)
		
inf_sensor.close()
outf_sensor.close()

###########################################################
summary_lines = inf_summary.readlines()

line_count = 0
for line in summary_lines:
	newline = ''
	for s in line:
		if s == '"':
			continue
		elif s == ';':
			newline += ' '
		else:
			newline += s
	outf_summary.writelines(newline)
		
inf_summary.close()
outf_summary.close()

############################################################
#routing_lines = inf_routing.readlines()

#line_count = 0
#for line in routing_lines:
#	newline = ''
#	for s in line:
#		if s == '"':
#			continue
#		elif s == ';':
#			newline += ' '
#		else:
#			newline += s
#	outf_routing.writelines(newline)
#		
#inf_routing.close()
#outf_routing.close()

###########################################################
cs_lines = inf_cs.readlines()

line_count = 0
for line in cs_lines:
	newline = ''
	for s in line:
		if s == '"':
			continue
		elif s == ';':
			newline += ' '
		else:
			newline += s
	outf_cs.writelines(newline)
		
inf_cs.close()
outf_cs.close()

