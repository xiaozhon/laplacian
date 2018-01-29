'''
find the statistics of the base noise trace
'''
import numpy as np
from matplotlib import pyplot as plt
from scipy.stats.kde import gaussian_kde
from scipy.stats import norm


### the base noise file
inf = open('meyer-heavy-add-10.txt', 'r')
outf = open('base_noise_statistics.txt', 'w')

noise = []

for line in inf:
	s = line.split()
	noise.append(float(s[0]))

inf.close()

avg = np.mean(noise)
std = np.std(noise)

outf.writelines('noise Max: %.4f, min: %.4f\n\n' % (max(noise), min(noise)))
outf.writelines('noise average: %.4f, std: %.4f\n\n' % (avg, std))

num_bins = 25
p, x = np.histogram(noise, bins=num_bins)	
print len(p)
print len(x)

outf.writelines('noise\tprobability\n')
for i in range(len(p)):
	outf.writelines('%.4f\t%.4f\t%.4f\n' % (x[i], p[i], p[i] * 1.0 / len(noise)))



n, bins, patches = plt.hist(noise, num_bins, normed=1, facecolor='green', alpha=0.5)
plt.savefig('base_noise_distribution.png')

outf.close()
