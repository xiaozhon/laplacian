'''
this script is used to change all the ids in the topology file to 
odd numbers
'''
# uniform_121nodes_2.3m.txt
import sys

for i in range (15, 16):
	inf = open("uniform/uniform_" + str(i*i) + "nodes_2.3m_2.txt", "r")
	outf = open("odd_nodeid/uniform_" + str(i*i) + "nodes_2.3m_odd_nodeid_2.txt", "w")
	
	lines = inf.readlines()
	
	
	for line in lines:
		s = line.split()
		if s[0] == "gain":
			id1 = int(s[1])*2 + 1
			id2 = int(s[2])*2 + 1
			newline = s[0] + '\t' + str(id1) + '\t' + str(id2) + '\t' + s[3] + '\n'
			outf.writelines(newline)
		if s[0] == "noise":
			id1 = int(s[1])*2 + 1
			newline = s[0] + '\t' + str(id1) + '\t' + s[2] + '\t' + s[3] + '\n'
			outf.writelines(newline)
	outf.close()
	inf.close()
