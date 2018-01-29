'''
Draw the figure of the dynamic ratio and the connectivity (lamda_2)
'''

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Rectangle

import sys
import os


inf_dr = open('Intersect_2_dynamic_ratio.txt', 'r')
dynamic_ratio = []
#dynamic_ratio.append(0)		# in the beginning, dynamic ratio is 0
lines = inf_dr.readlines()
line_count = 0
for line in lines:
	s = line.split()
	if len(s) > 0:
		 if s[0] == 'dynamic_ratio:':
		 	dynamic_ratio.append(float(s[1]))
#		 	print s[1]

##########################################################################

inf = open('Laplacian_eigenvalue.txt', 'r')

times = []
rounds = []
first_eig = []	# the smallest eigenvalues

lines = inf.readlines()

line_count = 0
idx = 0
for line in lines:
	s = line.split()
	if len(s) > 0:
		line_count += 1
		if line_count % 2 == 1:
			times.append(s[0] + '_' + s[1])
			rounds.append(int(s[3]))
			idx += 1
		else:
			# read all the eigen values, and plot the figure of each matrix
			eigs = []
			for i in range(0, len(s)):
				eigs.append(float(s[i]))
			
			i = 0
			while float(s[i]) < 0.001:
				i += 1
#			print i
			first_eig.append(float(s[i]))	## smallest non-zero eigenvalu
			print str(times[idx-1]) + ': ' + str(i) + 'th eigen: ' + s[i]
#			print s[i]
			
f, axarr = plt.subplots(2, sharex=True)

axarr[0].plot(first_eig, 'ro')
axarr[0].plot(first_eig, 'b')
axarr[0].set_title('smallest_non-zero_eigenvalue')
#plt.axis([0, 100, 0, 2.0])
axarr[1].plot(dynamic_ratio, 'k*')
axarr[1].plot(dynamic_ratio, 'b')
axarr[1].set_title('dynamic_ratio')


plt.savefig('figures_intersect_2/dynamic_ratio_lamda_2.png')
plt.clf()

