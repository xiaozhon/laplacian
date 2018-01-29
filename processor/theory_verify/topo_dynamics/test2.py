'''
What happens to remove a link with bad weight?

test Laplacian eigenvalue, eigenvector, and matrix tree theorem using a simple
topology

Basic topology: With all weight 1.
	1
  /   \
  2   3
  |   |
  4	  5--6

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
am = [ [0, 1, 1, 0, 0],
	   [1, 0, 0, 1, 0],
	   [1, 0, 0, 0, 1],
	   [0, 1, 0, 0, 0],
	   [0, 0, 1, 0, 0]
	 ]

### basic parent matrix
pm = [ [0, 0, 0, 0, 0],
	   [1, 0, 0, 0, 0],
	   [1, 0, 0, 0, 0],
	   [0, 1, 0, 0, 0],
	   [0, 0, 1, 0, 0]
	 ]

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
print 'Adding edge 4->5'
am[3][4] = 1
am[4][3] = 1
pm[3][4] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Adding edge 5->2, together with 4->5'
am[1][4] = 1
am[4][1] = 1
pm[4][1] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Adding edge 4->3, together with 5->2, 4->5'
am[2][3] = 1
am[3][2] = 1
pm[3][2] = 1
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

### the following edge has little effect to the connectivity
#print '\n----------------------------------------------------------------------'
#print 'Adding edge 3->2, 4->3, 5->2, 4->5'
#am[1][2] = 1
#am[2][1] = 1
#pm[2][1] = 1
#print 'adjacent matrix is: %r' % am
#print 'parent matrix is: %r' % pm
#print '\nLaplacian eigenvalue and eigenvector of am is: '
#vals, vt = lp.eigen(am)
#for i in range(len(vals)):
#	print '\t%r: %r' % (vals[i], vt[i])

#det = lp.mtt(pm)
#print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'Reduce the weight of 4->5 to 0.3'		### reduced the connectivity
am[3][4] = 0.3
am[4][3] = 0.3
pm[3][4] = 0.3
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det

print '\n----------------------------------------------------------------------'
print 'remove edge 4->5 '		### reduced the connectivity
am[3][4] = 0
am[4][3] = 0
pm[3][4] = 0
print 'adjacent matrix is: %r' % am
print 'parent matrix is: %r' % pm
print '\nLaplacian eigenvalue and eigenvector of am is: '
vals, vt = lp.eigen(am)
for i in range(len(vals)):
	print '\t%r: %r' % (vals[i], vt[i])

det = lp.mtt(pm)
print '\nThe number of spanning tree of pm is: %r' % det


