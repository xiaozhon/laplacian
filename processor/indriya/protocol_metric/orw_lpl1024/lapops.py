'''
The operators for Laplacian matrix
'''
import sys
import math
from numpy import linalg as LA


'''
in_am: 	the matrix that need to be computed, for undirected graph
		Must be the symmetrical Adjacency Matrix
return:	the eigenvalues and the eigenvector
'''
def eigen(in_am):
	## build laplacian matrix from 
	n = len(in_am)
	d = find_degrees(in_am)
	lm = [[0 for row in range(n)] for col in range(n)]
#	print '\nLaplacian matrix is: '
	for i in range(n):
		for j in range(n):
			if i == j:
#				lm[i][j] = d[i]
				lm[i][j] = 1
				######## for isolated nodes
				if d[i] == 0:
					lm[i][j] = 0
			else:
				if in_am[i][j] > 0:
					lm[i][j] = -1*in_am[i][j]*1.0 / math.sqrt(d[i]*d[j])
	
#		print lm[i]
		
	vals, vt = LA.eigh(lm)
	
	return (vals, vt)
	

'''
in_pm:	the parent matrix (asymmetrical adjacency matrix) for digraph
return:	the number of spanning trees
'''

def mtt(in_pm):
	n = len(in_pm)
	d = find_degrees(in_pm)
	lm = [[0 for row in range(n)] for col in range(n)]
	
#	print '\nThe directed laplacian matrix is: ' 
	for i in range(n):
		for j in range(n):
			if i == j:
				lm[i][j] = d[i]
			else:
				if in_pm[i][j] > 0:
					lm[i][j] = -1*in_pm[i][j]	### the out degree
#		print lm[i]
	
	m = []	
#	print '\n\tmatrix for tree is: '
	for i in range(n):
		if d[i] != 0:
			row = []
			for j in range(n):
				if d[j] != 0:
					row.append(lm[i][j])
			m.append(row)
#			print row
	
	det = LA.det(m)
	return det
	


'''
find the degrees of each nodes in the matrix
in_m:	the matrix, either an adjacency matrix or parent matrix
		It should be a row matrix, one row for one node
return:	the degrees of the nodes, in a list
'''
def find_degrees(in_m):
	d = [0 for i in range(len(in_m))]

	for i in range(len(in_m)):
		d[i] = sum(in_m[i])
		
	return d

'''
expand the matrix for more rows and columns
in_m:	the matrix needs to be expanded
n:		the number of rows and columns need to be expanded
return:	the new matrix
'''
def expand(in_m, num):
	# first expand each row
	n = len(in_m)
	for i in range(n):
		for j in range(num):
			in_m[i].append(0)
	
	# add more rows
	for i in range(num):
		newrow = [0 for j in range(n + num)]
		in_m.append(newrow)
	


