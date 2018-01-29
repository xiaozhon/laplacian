'''
this file compute several parameters for the uniform topology

the baseline is 225 nodes in 32.2 *32.2 square meters space
'''

import sys
import math
import random

outf = open("uniformTopo_parameters.txt", "w")

# keep the density, generate parameter for 100 to 500 nodes.

outf.writelines("1. parameters to keep the density:\n")
for i in range (10, 16):
	area = i*i*32.2*32.2 / 225
	dimension = math.sqrt(area)
	
	outf.writelines("\t" + str(i*i) + " nodes, dimension is: " + str(dimension) + " m\n")
	

# keep the space increase the density, generate parameter for 100 to 500 nodes.

outf.writelines("2. parameters to keep the space and increase the density:\n")
for i in range (1, 6):
	density = 100*i / (32.2*32.2)
	
	outf.writelines("\t" + str(100*i) + " nodes, dimension is: 32.2 m, density is : " + str(density) + '\n' + "\n \n")
	

outf.close()