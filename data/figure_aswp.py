'''
draw a figure of the aswp testbed using adjusted coordinates

The scale of adjusting: 
	x_scale: 0.00005
	y_scale: 0.00005
'''

import sys
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

N = 93

inf_ids = open("aswp/nodeids.txt", "r")
inf_locs = open('aswp_correct_nodeids_re_coordinates.txt', 'r')
inf_ids_new = open('aswp_new_nodes.txt', 'r')


#################### load node ids #####################
nodeids = []
lines = inf_ids.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		nodeids.append(s[0])

inf_ids.close()

# find the index of a node id in the list
def idx(nodeid):
	for i in range(N):
		if nodeid == nodeids[i]:
			return i
	return -1

################## load node location ##################
node_locs = []
lines = inf_locs.readlines()
for line in lines:
	s = line.split()
	if len(s) > 0:
		if s[0] in nodeids:
			node_locs.append([float(s[4]), float(s[5])])
inf_locs.close()

################## load new nodes ######################
new_nodes = []
lines = inf_ids_new.readlines()
for line in lines:
	s = line.split()
	if len(s) == 3:
		if (s[0] in nodeids) and (s[0] not in new_nodes):
			new_nodes.append(s[0])
inf_ids_new.close()


###### draw the figure 
### Draw an A-tree based on the Adjacent matrix, using motes' location information
for i in range(N):
	## plot the nodes as dots
	if nodeids[i] in new_nodes:
		### use a different color for new nodes
		plt.plot([node_locs[i][0]],[node_locs[i][1]], color='red', marker='o')
	else:
		plt.plot([node_locs[i][0]],[node_locs[i][1]], color='lightgrey', marker='o')
		
plt.title('aswp_adjusted')
plt.savefig('aswp_adjust.png', dpi=300)
plt.clf()
		

