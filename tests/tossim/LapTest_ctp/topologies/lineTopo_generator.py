'''
the python script is used to generate the coordinates of the nodes in a 
line topology
'''

import sys

outf = open("lineTopo.txt", "w")

nodeCount = 15	# the total number of nodes in the line. 1 node is sink
distance = 2.3	# the distance between neighbor nodes

for i in range (0, nodeCount):
	line = str(i) + " 1.0 " + str(distance*i) + '\n'
	outf.writelines(line)
	

outf.close()