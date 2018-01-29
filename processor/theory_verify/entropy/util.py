'''
the helper functions to read files
'''
import matplotlib.pyplot as plt
import math
import scipy.stats as st 


def lines(inf):
	"""
	store the full text file, and add an empty line in the end
	"""
	
	for line in inf: yield line
	yield '\n'

def blocks(inf):
	"""
	split the full file in to paragraphs (blocks)
	
	Modify the code for the input file format
	"""
	block = []
	count = 0
	for line in lines(inf):
		s = line.split()
		if len(s) > 0:
			# DEBUG (0): data: 0 32 5 3 19 21 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5
			# DEBUG (27): trickle_reset all
			# DEBUG (27): trickle_reset better paths
			
			if s[2] == 'trickle_reset':
				block.append(line)
			if len(s) > 5:
				if int(s[3]) == count:
					# the cycle counter
					block.append(line)
				elif block:
					yield block 
					block = []
					block.append(line)
					count = int(s[3])
				
				
				
#		if line.strip():
#			### if the line is not empty, add the line into the paragraph
#			block.append(line)
#		elif block:
#			### an empty line, make all the lines as a single string
#			yield ''.join(block).strip()
#			block = []

def multi_blocks(inf, num):
	"""
	split the full file in to paragraphs (blocks)
	
	Modify the code for the input file format
	
	It is merge multiple cycles and return as a single block
	
	inf: the input file
	num: the number of blocks to be merged
	"""
	block = []
	count = 0
	for cycle in blocks(inf):
		count += 1
		if count % num == 0:
			for line in cycle:
				block.append(line)
			yield block
			block = []
		else:
			for line in cycle:
				block.append(line)
	
#	for line in lines(inf):
#		s = line.split()
#		if len(s) > 0:
#			# DEBUG (0): data: 0 32 5 3 19 21 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5
#			# DEBUG (27): trickle_reset all
#			# DEBUG (27): trickle_reset better paths
#			
#			if s[2] == 'trickle_reset':
#				block.append(line)
#			if len(s) > 5:
#				if int(s[3]) == count:
#					# the cycle counter
#					block.append(line)
#				elif block:
#					yield block 
#					block = []
#					block.append(line)
#					count = int(s[3])


def draw(in_m, locs, focus_v, figname, centrality=-1):
	"""
	Draw the figure of the nodes in the matrix using the edge information (in_m) 
	and location information (locs), and store it as 'figname'
	locs are in the format: locs[id][0] = x, locs[id][1] = y
	
	focus_v: the nodes should be draw using a different color
	central: the index of the node with max centrality
	"""
	n = len(locs)
	
	fig = plt.figure()
	ax = fig.add_subplot(111)
	
	for i in range(n):
		## draw nodes
#		print focus_v[i]
		if focus_v[i] == 0:
			ax.plot([locs[i][0]],[locs[i][1]], color='black', marker='o', markersize=10)
		elif focus_v[i] == 1:
			ax.plot([locs[i][0]],[locs[i][1]], color='green', marker='^', markersize=10)
		elif focus_v[i] == 2:
			ax.plot([locs[i][0]],[locs[i][1]], color='red', marker='*', markersize=13)
		else:
			ax.plot([locs[i][0]],[locs[i][1]], color='black', marker='.')	## leaf nodes
			
		ax.annotate(str(i), xy=(locs[i][0], locs[i][1]))
		
		for j in range(n):
			## draw the edges
			if in_m[i][j] == 1:
				## if two nodes are connected, write a line between them
				ax.plot([locs[i][0], locs[j][0]], [locs[i][1], locs[j][1]], 'cyan')
	
	if centrality != -1:
		ax.plot([locs[centrality][0]],[locs[centrality][1]], color='red', marker='D', markersize=13, alpha=0.5)
	
	plt.savefig(figname + '.png')
	plt.clf()

def draw_vec(vec, figname):
	"""
	draw the vector
	[val, id]
	"""
	fig = plt.figure()
	ax = fig.add_subplot(111)
	
	fig.set_figheight(6)
	fig.set_figwidth(10)
	
	tmpv = []
	
	ax.set_xlim([-1, len(vec) + 1])
	
	for i in range(len(vec)):
		tmpv.append(vec[i][0])
#		ax.plot([i],[vec[i][0]], color='lightgrey', marker='o')
		ax.annotate(str(vec[i][1]), xy=(i-0.3, vec[i][0]+0.02))
	
	ax.plot(tmpv, color='red', marker='o')
	## draw a line at 0
	ax.plot([-1, len(vec)+1], [0, 0], 'cyan')
#	ax.plot(vec, color='red', marker='o')
	plt.savefig(figname + '.png')
	plt.clf()

def draw_line(l, figname):
	"""
	Draw a line using a single list
	"""
	fig = plt.figure()
	ax = fig.add_subplot(111)
	
	fig.set_figheight(6)
	fig.set_figwidth(10)
	
	ax.set_xlim([-1, len(l) + 1])
	ax.set_ylim([0, 10])
	ax.plot(l, color='red', marker='o')

	plt.savefig(figname + '.png')
	plt.clf()

def get_locs(inf):
	"""
	find the node locations from the input file
	12	0.76	6.90
	id   x       y
	
	The code can be modified based on the format of the location file
	"""
	
	locs = []
	for line in inf:
		s = line.split()
		if len(s) > 0:
			## suppose the nodes are ordered, otherwise
			locs.append([float(s[1]), float(s[2])])
		
	return locs

#def link_entropy(pm):
#	"""
#	compute the link entropy using the giving link information
#	pm: the weighted parent matrix containing the link information. The weight is W
#		if a link has been used for W times in this cycle.
#		The entropy formula: entropy = -sum(p * log(p))
#	return: the entropy as a float number, normalize using the total number of possible links
#	"""
#	N = len(pm)
#	total_links = N*(N-1)*1.0		### total possible links for a directed graph
#	ret = 0
#	for i in range(N):
#		for j in range(i, N):
#			### compute the entropy for each link, and sum up
#			if pm[i][j] > 0:
#				pi = pm[i][j]*1.0 / total_links
#				ret = ret + (-1*pi*math.log(pi, 2))
#			
#	return ret


def link_entropy(pm):
	"""
	compute the link entropy using the giving link information
	pm: the weighted parent matrix containing the link information. The weight is W
		if a link has been used for W times in this cycle.
		The entropy formula: entropy = -sum(p * log(p))
	return: the entropy as a float number, use the total number of link usages as the dominator
			The average entropy of the link
	"""
	N = len(pm)
	total_usages = 0
	for i in range(N):
		total_usages += sum(pm[i])
	
#	print '\t\t\t--- total usages: ' + str(total_usages)
	
#	print pm
#	tmp = []
	ret = 0
	for i in range(N):
		for j in range(N):		### previsouly it is in range (i, N), which is wrong
			### compute the entropy for each link, and sum up
			if pm[i][j] > 0:
				pi = pm[i][j]*1.0 / total_usages
				
#				print '\t\t\t\t\ti: %d, j: %d, pi: %.4f' %(i, j, pi)
#				tmp.append(pi)
				
				ret = ret + (-1*pi*math.log(pi))	### previously use 2 as base, now use e
	avg = ret / total_usages
	
#	print '\t\t\t--- %r' % tmp
	return ret,avg


def list_entropy(l):
	"""
	compute the entropy of the given list
	
	l:	a list, which is used to compute the probability distribution and entropy
	return: the entropy in floating number
	"""
	N = len(l)
	total = sum(l)
	ret = 0
	
	for i in range(N):
		if l[i] > 0:
			pi = l[i] * 1.0 / total 
			ret = ret + (-1*pi*math.log(pi))
			
	return ret


def frobenius_norm(pm):
	"""
	the Frobenius norm of a matrix
		= sqrt(sum of the squre of all entries)
	
	pm: the parent matrix, n by n matrix.
	
	return: the norm as a float number 
	"""
	
	N = len(pm)
	tmp = 0
	for i in range(N):
		for j in range(N):
			tmp += pm[i][j]*pm[i][j]
	ret = math.sqrt(tmp)
	
	return ret




if __name__ == '__main__':
#	testfile = open('../../../data/tossim/rctp_uniform/uniform_36nodes_rctp_test1.txt','r')
#	counter = 0
#	for block in blocks(testfile):
#		
#		counter += 1
#		if counter == 70:
#			for line in block:
#				print line
#				
#	print 'the total number of cycle is: %d' % counter


#	pm = [[1, 2], [1, 1]]
#	print frobenius_norm(pm)

	t = [0.15, 0.05, 0.01, 0.01, 0.01, 0.05, 0.04, 0.04, 0.02, 0.04, 0.02, 0.01, 0.03, 0.02, 0.01, 0.02, 0.01, 0.03, 0.01, 0.09, 0.02, 0.01, 0.01, 0.01, 0.04, 0.02, 0.01, 0.04, 0.02, 0.02, 0.01, 0.01, 0.02, 0.02, 0.02, 0.01, 0.01, 0.01, 0.01, 0.01]
	print st.entropy(t)

