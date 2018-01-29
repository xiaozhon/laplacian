'''
test the correctness of defined functions
'''
############################ FUNCTIONS ####################################
# m1: matrix 1
# m2: matrix 2
# n:  number of rows
def intersect(m1, m2, n):
	ret = [[0 for row in range(n)] for col in range(n)]
	for i in range(n):
		for j in range(n):
			if m1[i][j] == 1 and m2[i][j] == 1:
				ret[i][j] = 1
	
	return ret

### the union of a matrix
def union(m1, m2, n):
	ret = [[0 for row in range(n)] for col in range(n)]
	for i in range(n):
		for j in range(n):
			if m1[i][j] == 1 or m2[i][j] == 1:
				ret[i][j] = 1
	
	return ret

# m: the adjacent matrix to count the number of edges
# n: the number of rows
def count_edges(m, n):
	ret = 0
	for i in range(n):
		for j in range(i, n):
			ret += m[i][j]
	return ret

###########################################################################
N = 5
a1 = [[0, 1, 0, 0, 0], 
	  [0, 0, 1, 0, 0],
	  [0, 0, 0, 1, 0],
	  [0, 0, 0, 0, 1],
	  [1, 0, 0, 0, 0],
	]

a2 = [[0, 0, 0, 1, 0], 
	  [0, 0, 1, 0, 0],
	  [0, 1, 0, 0, 0],
	  [1, 0, 0, 0, 0],
	  [0, 0, 0, 0, 1],
	]

inter = intersect(a1, a2, N)
u_matrix = union(a1, a2, N)
print inter
print u_matrix
print count_edges(inter, N)
print count_edges(u_matrix, N)
