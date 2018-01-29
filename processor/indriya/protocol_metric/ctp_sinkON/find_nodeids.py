'''
find the node ids in the test 

# Sink Received: data: 0 30 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
'''

from util import *
import sys

SRC = 4

### 20170214_indriya_ctp_lpl1024_sink31_1min_caa1800_incycle_test1

SINK_ID = 31
inf = open('../../../../data/indriya/protocol_metrics/ctp/20170222_indriya_ctp_lpl1024_sink31_1min_caa1800_incycle_sink_alwaysON_test1.txt','r')
outf = open('nodeids.txt', 'w')

ids = [SINK_ID]

counter = 0
for block in blocks(inf):
		
	for pkt in block:
		s = pkt.split()
		
		if int(s[SRC]) not in ids:
			ids.append(int(s[SRC]))
inf.close()

for node in sorted(ids):
	outf.writelines('%d\n' % node)

outf.close()
