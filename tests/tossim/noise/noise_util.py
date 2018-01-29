'''
functions for noise generator
'''


import numpy as np
from matplotlib import pyplot as plt

def draw_f_hist(f, fig_name, title, num_bins=20):
	""" 
	draw the histogram of a noise trace from a file
	f: the file name
	result: a figure about the distribution of the noise trace
	"""
	
	inf = open(f, 'r')
	noise = []
	for line in inf:
		s = line.split()
		noise.append(float(s[0]))

	inf.close()
	draw_hist(noise, fig_name, title, num_bins)


def draw_hist(trace, fig_name, title, num_bins=20):
	""" 
	draw the histogram of a noise trace from a list
	trace: a list of the noise trace
	result: a figure about the distribution of the noise trace
	"""
	avg = np.mean(trace)
	std = np.std(trace)
	ll = 'avg: %.4f\nstd: %.4f' % (avg, std)
	n, bins, patches = plt.hist(trace, num_bins, normed=1, facecolor='green', alpha=0.5, label=ll)
	plt.legend()
	plt.title(title)
	plt.savefig(fig_name)		
	plt.clf()
