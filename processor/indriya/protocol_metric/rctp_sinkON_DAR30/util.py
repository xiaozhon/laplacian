'''
the helper functions to read files
'''

from types import *
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
#	count = 20
	count = 1
	err_line = []
	
	SRC = 4
	DATA_LINE = 1
	COUNTER = 5
	err_count = 0
	for line in lines(inf):
		s = line.split()
		if len(s) > 0:
			# DEBUG (0): data: 0 32 5 3 19 21 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5
			# DEBUG (27): trickle_reset all
			# Sink Received: data: 0 30 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
#			print line
			## for Indriya Ctp test, there are many incomplete reception of data lines 
			## for example:
			##		Sink Received: data: 0 30 1 1 1..	
			
			if len(s) > 15 and s[DATA_LINE] == "Received:":
				### data line
				
				##### original block
				'''
				if int(s[COUNTER]) == count:

					# the cycle counter
					block.append(line)
				elif block:
					yield block 
					block = []
					block.append(line)

					count = int(s[COUNTER])
				else:
					### if there is a emply block
					count = int(s[COUNTER])
				'''
				
				### deal with misorder 
				### the packets usually delayed in one or two cycles. 
				
				### So, read in 3 cycles' packets, then return the first cycle 
				###		e.g., pkt 1, pkt 1, pkt 2, pkt 1, pkt 3, 
				### 	return pkt 1, and rests are pkt 2, read in pkt 3
				
				### 1. node 35 always delay two cycles 
				
				if int(s[COUNTER]) - count < 1:
					## read in two cycles data 
					# the cycle counter
					block.append(line)
				elif block:
					### yield the data in the first cycle, leave the data in the 
					### second cycle
#					print 'cur_round: %d, count: %d\n' % (int(s[COUNTER]), count) 
					newBlock = []
					for pkt in block:
						t = pkt.split()
						
#						if int(t[SRC]) == 35:
#							### node 35 delayed a lot, just include it
#							newBlock.append(pkt)
						
						if int(t[COUNTER]) == count:
							newBlock.append(pkt)
							
#						if int(t[COUNTER]) == count-1:
#							### a packet has delayed for two cycles 
#							err_count += 1
##							newBlock.append(pkt)
#							err_line.append(line)
							
						
					
					for pkt in newBlock:
						block.remove(pkt)
						
					yield newBlock 
					block.append(line)

					count = int(s[COUNTER])
				else:
					### if there is a emply block
					count = int(s[COUNTER])
				

			else:
				err_count += 1
				
			
#	print '+++++++++++++++++++++++++++= err count: ' + str(err_count)
#	for line in err_line:
#		print line
		
				
#	yield block
				
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

def idx(l, e):
	"""
	return the index of element 'e' in list 
	l: the target list 
	e: the element to be checked 
	ret: the index of the element e in the list 
	"""
	if type(l) != ListType:
		# TODO: raise an exception
		return "idxError: input not a list"
	
	for i in range(len(l)):
		if l[i] == e:
			return i
	
	return len(l) + 10

def find_ids(nodefile):
	'''
	find the node ids in the file nodeids.txt, and return as a list.
	in nodeids.txt, each line is a node id
	'''
	in_node = open(nodefile, 'r')
	l = []
	for line in in_node:
		s = line.split()
		if len(s) > 0:
			l.append(int(s[0]))
	return l



if __name__ == '__main__':
# /opt/github/laplacian/data/indriya/protocol_metrics/rctp/20170209_indriya_rctp_lpl1024_sink31_30sec_test1.txt
	infname = '../../../../data/indriya/protocol_metrics/rctp/20170222_indriya_rctp_lpl1024_sink31_1min_caa1800_incycle_sink_alwaysON_test2_DAR30.txt'
	
	testfile = open(infname,'r')
	counter = 0
	pkt_count = 0
	for block in blocks(testfile):
		
		counter += 1
		print 'print block: ' + str(counter) + '\n'
#		if counter == 12:
		for line in block:
			print line
		print '----------------------------- pkts: ' + str(len(block))
		print '\n\n'
		pkt_count += len(block)
				
	print 'the total number of cycle is: %d' % counter
	print 'total packets is: ' + str(pkt_count)

	
#	testlist = [1, 2, 4, 3, 5]
#	testlist = 10
#	print idx(testlist, 10)


#	print find_ids("nodeids.txt")

#	pm = [[1, 2], [1, 1]]
#	print frobenius_norm(pm)

#	t = [0.15, 0.05, 0.01, 0.01, 0.01, 0.05, 0.04, 0.04, 0.02, 0.04, 0.02, 0.01, 0.03, 0.02, 0.01, 0.02, 0.01, 0.03, 0.01, 0.09, 0.02, 0.01, 0.01, 0.01, 0.04, 0.02, 0.01, 0.04, 0.02, 0.02, 0.01, 0.01, 0.02, 0.02, 0.02, 0.01, 0.01, 0.01, 0.01, 0.01]
#	print st.entropy(t)

