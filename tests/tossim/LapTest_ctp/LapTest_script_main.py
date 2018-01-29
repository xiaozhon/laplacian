'''
The main loop of the python script to run multiple simulation
'''
import os
from LapTest_script import *

for i in range(8, 27, 1):
	noise_file = '../noise/meyer-heavy-add-' + str(i) + '.txt'
	outf_name = 'uniform_36nodes_ctp_noise_test_add-' + str(i) + '_test2.txt'
	
	os.system('python LapTest_script.py ' + noise_file + ' ' + outf_name)


#for i in range(1, 16):
#	noise_file = '../noise/meyer-heavy-sim-trace' + str(i) + '.txt'
#	outf_name = 'uniform_36nodes_ctp_noise_test_trace' + str(i) + '.txt'
#	
#	os.system('python LapTest_script.py ' + noise_file + ' ' + outf_name)
	
	

