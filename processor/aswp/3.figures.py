'''
Plot the figures of the eigenvalues

## one figure for each matrix with all eigenvalues

## one figure for the smallest non-zero eigenvalues


2016-08-18 15:09:22, Round: 1
-6.36900551579e-17 0.0527088525451 0.0854691440617 0.0970630453621 0.154245145145 0.163430332898 0.172246633341 0.195276808389 0.200642308741 0.237499996039 0.250148778815 0.263848404593 0.283251643338 0.305509464794 0.340807168919 0.394005479532 0.421655087611 0.429617344278 0.469444887356 0.53188046326 0.53908314218 0.553669893474 0.597349132346 0.607789119623 0.617749045399 0.642039559793 0.653913302522 0.709394090861 0.73031428775 0.833428829393 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.20202724579 1.27119618643 1.29575499435 1.33332364337 1.36459369199 1.38284687017 1.40000143022 1.43668062081 1.44342312946 1.45711566187 1.47440524245 1.53010516593 1.54004791626 1.57120374703 1.59303701296 1.66648974603 1.70264582545 1.71891072462 1.74182598996 1.75441129829 1.76879790255 1.78830154017 1.79784790023 1.83166316316 1.83970292492 1.84448489839 1.89514927257 1.90337281421 1.94315454787 1.97399750014 

'''

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Rectangle

import sys
import os

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
			first_eig.append(float(s[i]))	## smallest non-zero eigenvalu
			print str(times[idx-1]) + ': ' + str(i) + 'th eigen: ' + s[i]
			
			fig_t = plt.plot(eigs, 'ro')
			plt.plot(eigs, 'b')
			plt.title('Laplacian eigenvalues ' + times[idx-1])
			plt.axis([0, 100, 0, 2.0])
			
			plt.savefig('figures/' + times[idx-1] + '.png')
			plt.clf()

fig_t = plt.plot(first_eig, 'ro')
plt.plot(first_eig, 'b')
#plt.axis([0, 100, 0, 2.0])

plt.savefig('figures/smallest_non-zero_eigen.png')
plt.clf()

			
inf.close()













