import sys
import time
import math
from numpy import linalg as LA
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
import numpy as np

inf_locs = open('../../../data/aswp_correct_nodeids_adjusted.txt', 'r')

################## load node location ##################
node_locs = []
lines = inf_locs.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		node_locs.append([float(s[4]), float(s[5])])
inf_locs.close()


i = 3
j = 0
k = 9
m = 20
print node_locs[j][0]-node_locs[i][0]
print node_locs[j][1]-node_locs[i][1]
plt.plot([node_locs[i][0]],[node_locs[i][1]], color='red', marker='.')
plt.plot([node_locs[j][0]],[node_locs[j][1]], color='red', marker='.')
plt.plot([node_locs[k][0]],[node_locs[k][1]], color='red', marker='.')

plt.plot([node_locs[m][0]],[node_locs[m][1]], color='red', marker='.')

dx = node_locs[j][0]-node_locs[i][0]
dy = node_locs[j][1]-node_locs[i][1]

plt.arrow(node_locs[i][0], node_locs[i][1], dx, dy,
						color='blue', width=0.0000002, head_width=0.000005, 
						head_length=0.00001, fc='b', ec='b')

#t = node_locs[i][0] - node_locs[j][0]
#plt.axis([0, 2*t, 0, 2*t])
#plt.arrow(0.00005, 0.00005, -0.00003, 0.00003, color='blue', width=0.0000002, head_width=0.000002, 
#				head_length=0.000003, fc='b', ec='b')


plt.show()
