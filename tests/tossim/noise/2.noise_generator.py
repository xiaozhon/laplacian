'''
generate noise trace for more simulation
'''

import numpy as np

from random import *
from noise_util import *

LIMIT = 0.02	## 5 pecent
LOW_NOISE = -80

inf_base = open('meyer-heavy-add-10.txt', 'r')

outf_all = open('all_noise_statistics.txt', 'w')

#### get the base noise
base_noise = []
for line in inf_base:
	s = line.split()
	base_noise.append(int(float(s[0])))
inf_base.close()

### generate 10 noise traces by shifting all the values in the noise trace
min_offs = -1
max_offs = 19
for i in range(min_offs, max_offs, 2):
	### the files are "meyer-heavy-add-8 ~ 26
	filename = 'meyer-heavy-add-' + str(10+i) + '.txt'
	outf = open(filename, 'w')
	new_noise = []
	for n in base_noise:
		new_noise.append(n+i)	### shift all the noises by i
		outf.writelines(str(n+i) + '\n')
	outf.close()
	
	### find the statistics of the noise traces
	outf_all.writelines(filename + '\n')
	
	bins=25
	avg = np.mean(new_noise)
	std = np.std(new_noise)
	draw_hist(new_noise, 'meyer-heavy-add-'+str(10+i)+ '.png', 'meyer-heavy-add-'+str(10+i), num_bins=bins)
	
	outf_all.writelines('noise Max: %.4f, min: %.4f\n\n' % (max(new_noise), min(new_noise)))
	outf_all.writelines('noise average: %.4f, std: %.4f\n\n' % (avg, std))

	
	p, x = np.histogram(new_noise, bins=bins)	

	outf_all.writelines('\tnoise\tprobability\n')
	for i in range(len(p)):
		outf_all.writelines('\t%.4f\t%.4f\t%.4f\n' % (x[i], p[i], p[i]*1.0/len(new_noise)))
	
	outf_all.writelines('\n\n\n')
	
	print len(new_noise)

#for i in range(1, 16):
#	### generate 15 other noise trace by change the distribution of the noises.
#	
#	filename = 'meyer-heavy-sim-trace' + str(i) + '.txt'
#	outf = open(filename, 'w')
#	limit = LIMIT * i		### (limit) percent of the low noise would be changed
#	new_noise = []
#	for n in base_noise:
#		if n < LOW_NOISE:
#			#### if this is a low noise, change it to a high noise based on some probability
#			r = random()	# generate a random number
#			if r < limit:
#				### this value needs to be changed
#				### for 90%, change it to -80 ~ -70
#				### for 10%, change it to -70 ~ -25
#				
#				r2 = random()
#				if r2 < 0.1:
#					new_noise.append(int(uniform(-69, -25)))
#				else:	
#					new_noise.append(int(uniform(-79, -70)))
#			else:
#				### this value don't need to be changed
#				new_noise.append(n)
#		else:
#			new_noise.append(n)
#	
#	for n in new_noise:
#		outf.writelines(str(n) + '\n')
#	outf.close()
#	
#	outf_all.writelines(filename + '\n')
#	#### find the statistics of the new noise
#	
#	bins=25
#	avg = np.mean(new_noise)
#	std = np.std(new_noise)
#	draw_hist(new_noise, 'meyer-heavy-sim-trace'+str(i)+ '.png', 'meyer-heavy-sim-trace'+str(i), num_bins=bins)
#	
#	outf_all.writelines('noise Max: %.4f, min: %.4f\n\n' % (max(new_noise), min(new_noise)))
#	outf_all.writelines('noise average: %.4f, std: %.4f\n\n' % (avg, std))


#	p, x = np.histogram(new_noise, bins=bins)	

#	outf_all.writelines('\tnoise\tprobability\n')
#	for i in range(len(p)):
#		outf_all.writelines('\t%.4f\t%.4f\t%.4f\n' % (x[i], p[i], p[i]*1.0/len(new_noise)))
#	
#	print len(new_noise)
#	
#	outf_all.writelines('\n\n\n')

outf_all.close()

	
	



