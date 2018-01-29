'''
test Laplacian eigenvalue, eigenvector, and matrix tree theorem using a simple
topology

Basic topology: With all weight 1.

	1---2---3
	|   |   |
	4   5   6
	|   |   
	7   8---9


Change topology by adding links or change the weight of the link

'''


import sys
import time
import math
from numpy import linalg as LA
import numpy as np

### laplacian operator
import lapops as lp

### basic adjacent matrix
am = [[0 for i in range(9)] for j in range(9)]
am[0][1] = 1
am[1][0] = 1
am[0][3] = 1
am[3][0] = 1
am[1][2] = 1
am[2][1] = 1
am[1][4] = 1
am[4][1] = 1
am[2][5] = 1
am[5][2] = 1
am[3][6] = 1
am[6][3] = 1
am[4][7] = 1
am[7][4] = 1
am[7][8] = 1
am[8][7] = 1

### basic parent matrix
pm = [[0 for i in range(9)] for j in range(9)]
pm[1][0] = 1
pm[3][0] = 1
pm[2][1] = 1
pm[4][1] = 1
pm[5][2] = 1
pm[6][3] = 1
pm[7][4] = 1
pm[8][7] = 1


print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm

print 'the degree of am is: %r' % lp.find_degrees(am)
print 'the degree of pm is: %r' % lp.find_degrees(pm)

vals, vt = lp.eigen(am)

print '\nLaplacian eigenvalue and eigenvector of am is: '
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Adding edge 5->4'
am[3][4] = 1
am[4][3] = 1
pm[4][3] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Adding edge 8->7, together with 5->4'
am[6][7] = 1
am[7][6] = 1
pm[7][6] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Adding edge 8->4, together with 8->7, 5->4'
am[7][3] = 1
am[3][7] = 1
pm[7][3] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

## the following edge has little effect to the connectivity
print '\n----------------------------------------------------------------------'
print 'Adding edge 9->5, together with 8->4,  8->7, 5->4'
am[8][4] = 1
am[4][8] = 1
pm[8][4] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Reduce the weight of 8->7 to 0.7'		### reduced the connectivity
am[7][6] = 0.7
am[6][7] = 0.7
pm[7][6] = 0.7
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Reduce the weight of 8->7 to 0.3'		### reduced the connectivity
am[7][6] = 0.3
am[6][7] = 0.3
pm[7][6] = 0.3
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'remove edge 8->7 '		### reduced the connectivity
am[7][6] = 0
am[6][7] = 0
pm[7][6] = 0
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Ading back edge 8->7 '		### reduced the connectivity
am[7][6] = 1
am[6][7] = 1
pm[7][6] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det


print '\n----------------------------------------------------------------------'
print 'Reduce 8->4 to 0.7 '		### reduced the connectivity
am[7][3] = 0.7
am[3][7] = 0.7
pm[7][3] = 0.7
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det


print '\n----------------------------------------------------------------------'
print 'Reduce 8->4 to 0.3 '		### reduced the connectivity
am[7][3] = 0.3
am[3][7] = 0.3
pm[7][3] = 0.3
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Remove edge 8->4  '		### reduced the connectivity
am[7][3] = 0
am[3][7] = 0
pm[7][3] = 0
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det



