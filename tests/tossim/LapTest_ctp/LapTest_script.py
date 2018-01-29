	 
import sys
import math
import time

from TOSSIM import *
from tinyos.tossim.TossimApp import *

topo_file = "topologies/uniform/uniform_36nodes.txt"

def run_sim(noise_file, outf_name):

	N = 36
	#outf_name = "uniform_36nodes_rctp_test2.txt"
#	outf_name = "uniform_36nodes_rctp_noise_test1.txt"

	n = NescApp()
	t = Tossim(n.variables.variables())
	m = t.mac()
	r = t.radio()

	t.addChannel('Boot', sys.stdout);
	t.addChannel('DATA', sys.stdout);


	outf = open(outf_name,"w")
	t.addChannel('Boot', outf);
	t.addChannel('DATA', outf);
	t.addChannel('XY_trickle', outf)

	in_topo = open(topo_file, "r");

	lines = in_topo.readlines()
	for line in lines:
		s = line.split()
		if (len(s) > 0):
			if(s[0] == "gain"):
				r.add(int(s[1]), int(s[2]), float(s[3]))

#	noise = open("../noise/meyer-heavy-add-8.txt", "r")
	noise = open(noise_file, 'r')
	lines = noise.readlines()
	for line in lines:
		s = line.strip()
		if(s != ""):
			val = int(s)
			for i in range(N):
				t.getNode(i).addNoiseTraceReading(val)
	#			t.getNode(i).addNoiseTraceReading(-100)	### very low noise

	for i in range(N):
	#	print "Creating noise model for ",i;
		t.getNode(i).createNoiseModel()
	 
	for i in range (N):
		t.getNode(i).bootAtTime((31 + t.ticksPerSecond() / 10) * i + 1);


	#sf.process();
	#throttle.initialize();

	round_count = t.getNode(0).getVariable("LapTestC.rounds")


	while (round_count.getData() < 1001):
	
	#	throttle.checkThrottle();
		t.runNextEvent();
	#	sf.process();
	
	outf.close()
#throttle.printStatistics()



if sys.argv[0] == "LapTest_script_main.py":
	print "test"
else:
	noise_file = sys.argv[1]
	outf_name = sys.argv[2]
	print noise_file
	print outf_name
	
	run_sim(noise_file, outf_name)

#noise_file = files[0]	
#outf_name = files[1]
#run_sim(noise_file, outf_name)

