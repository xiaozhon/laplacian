'''
feed to cooja the positions from a position file

'''

inf_pos = open('../../data/tossim/topologies/positions_uniform_36nodes.txt', 'r')
#inf_sim = open('OrwTest/OrwTest_2_feed_positions_larger_udgm.csc', 'r') 

#outf = open('OrwTest/OrwTest_2_feed_positions_larger_udgm_scale5.csc', 'w') 

inf_sim = open('LapTest_ctp/Ctp_2_feed_positions_larger_udgm.org.csc', 'r') 

outf = open('LapTest_ctp/Ctp_2_feed_positions_larger_udgm_scale5.csc', 'w') 

posx = []
posy = []

for line in inf_pos:
	s = line.split()
	posx.append(float(s[1]))
	posy.append(float(s[2]))
inf_pos.close()

#SCALE = 70 ### for MRM
SCALE = 5 ### for UDGM

idxx = 0
idxy = 0
for line in inf_sim:
	s = line.split()
	if len(s) > 0:
		if s[0][:3] == '<x>':
			newline = '        <x>'
			newline += str(posx[idxx]*SCALE) + '</x>\n'
			idxx += 1
			outf.writelines(newline)
		elif s[0][:3] == '<y>':
			newline = '        <y>'
			newline += str(posy[idxy]*SCALE) + '</y>\n'
			idxy += 1
			outf.writelines(newline)
		else:	
			outf.writelines(line)
	else:
		outf.writelines(line)
outf.close()
