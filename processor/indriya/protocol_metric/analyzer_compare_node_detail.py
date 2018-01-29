'''
compare the details of the node performance of ctp, eer, and orw

such as:
	PRR
	workload
	duplicates

'''
from types import *
import numpy as np
import matplotlib.pyplot as plt


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

def compare_metric(metric_name, infname, idx_value, merge, f, has_legend=False):
	"""	
	A function to compare the network metric
	
	metric_name:	the name of the network metric 
	idx_value: the index of the metric in the analysis file
	merge:	Bool, if True, the figure will be merged to a larger figure; otherwise
			a separate figure will be generated
	f:		If merge == True, f is the figure handler
	
	"""
	### read in the node id
	in_node = open('rctp/nodeids.txt', 'r')
	nodeids = []
	for line in in_node:
		s = line.split()
		if len(s) > 0:
			if s[0] == '31':
				continue
			nodeids.append(int(s[0]))

	

	N = len(nodeids)
		
	value_name = ''
	if metric_name == 'Duplicates':
		value_name = 'dup_count'
	elif metric_name == 'Wordload':
		value_name = 'fwd_count'
	elif metric_name == 'PRR':
		value_name = 'prr'
	elif metric_name == 'Dup_Fwd_ratio':
		value_name = 'dup_fwd_ratio'
	
	inf = open('ctp/' + infname, 'r')

	metric_ctp = [0 for i in range(N)]
	line_count = 0
	
	value_start = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if len(s) < 2:
					value_start = 0
				if s[0] == 'nodeid':
					if s[1] == value_name:
						value_start = 1
						continue				
				
				if value_start == 1:
					print line
#					metric_ctp.append(float(s[idx_value]))
					metric_ctp[idx(nodeids, int(s[0]))] = float(s[idx_value])
					
			else:
				value_start = 0
				
	inf.close()

	inf = open('rctp/' + infname, 'r')

	metric_rctp = [0 for i in range(N)]
	line_count = 0
	
	value_start = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if len(s) < 2:
					value_start = 0
				if s[0] == 'nodeid':
					if s[1] == value_name:
						value_start = 1
						continue				
				
				if value_start == 1:
#					metric_rctp.append(float(s[idx_value]))
					metric_rctp[idx(nodeids, int(s[0]))] = float(s[idx_value])
				
			else:
				value_start = 0
				
	inf.close()
	
	inf = open('orw/' + infname, 'r')

	metric_orw = [0 for i in range(N)]
	line_count = 0
	
	value_start = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if len(s) < 2:
					value_start = 0
					
				if s[0] == 'nodeid':
					if s[1] == value_name:
						value_start = 1
						continue				
				
				if value_start == 1:
#					metric_orw.append(float(s[idx_value]))
					metric_orw[idx(nodeids, int(s[0]))] = float(s[idx_value])
				
			else:
				value_start = 0
				
	inf.close()
	
	inf = open('orw_lpl1024/' + infname, 'r')

	metric_orw_lpl1024 = [0 for i in range(N)]
	line_count = 0
	
	value_start = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if len(s) < 2:
					value_start = 0
					
				if s[0] == 'nodeid':
					if s[1] == value_name:
						value_start = 1
						continue				
				
				if value_start == 1:
#					metric_orw_lpl1024.append(float(s[idx_value]))
					metric_orw_lpl1024[idx(nodeids, int(s[0]))] = float(s[idx_value])
				
				
			else:
				value_start = 0
				
	inf.close()

	print metric_ctp
	print metric_rctp

	x = np.arange(len(metric_ctp))
	x = [i for i in range(1, N+1)]
	bar_width = 0.35

	if not merge:
		plt.figure(figsize=(12, 3.5))

#		bar_ctp = f.bar(x, metric_ctp, bar_width, color='r', yerr=errs_ctp, label='ctp')
#		bar_rctp = f.bar(x+bar_width, metric_rctp, bar_width, color='g', yerr=errs_rctp, label='rctp')
#		bar_orw = f.bar(x+2*bar_width, metric_orw, bar_width, color='b', yerr=errs_orw, label='orw')
#		bar_orw_lpl1024 = f.bar(x+3*bar_width, metric_orw_lpl1024, bar_width, color='c', yerr=errs_orw_lpl1024, label='orw_lpl1024')
#		
#		
#		plt.legend()
#		plt.title(metric_name)
##		plt.xlabel('Noise traces')
#		plt.ylabel(metric_name)
#		
##		if metric_name == 'Trickle_reset':
##			plt.ylimit(0, 70)

#		#for i in range(len(entropies)):
#		#	plt.annotate(str(entropies[i]), xy=(x[i], entropies[i]+0.01))

#		plt.savefig(metric_name + '_vs_noise_level_ctp_vs_rctp.png', dpi=300)
#		plt.clf()
	else:
		f.plot(nodeids, metric_ctp, 'ro-', label='ctp')
		f.plot(nodeids, metric_rctp, 'g^-', label='ctp+eer')
		f.plot(nodeids, metric_orw, 'b+-', label='orw')
		f.plot(nodeids, metric_orw_lpl1024, 'c*-', label='orw_lpl1024')

		
		if metric_name == 'PRR':
			f.set_ylim([0.5, 1.0])
		elif metric_name == 'Fwd_entropy':
			f.set_ylim([1.5, 3.2])
		
		if has_legend:
			f.legend()
#		f.legend()
		
		f.set_title(metric_name)
		
		f.set_ylabel(metric_name)
		
		
		f.set_xticks(nodeids)
#		f.set_xticklabels(nodeids)#, family='Calibri',size=8)	
		

                


if __name__ == '__main__':

	"""
	files:
		metric_analysis_result_all_no_loop.txt
		metric_analysis_result_all_entropy_no_loop
		metric_analysis_result_all_pathLen_no_loop
		metric_analysis_result_all_withLoop
		
		analysis_result_entropy_withLoop
		analysis_result_entropy_noLoop
		
		prr_analysis_result_all_noLoop	: loop only affects path length
		prr_analysis_result_all_withLoop
		
		
		trickle_analysis_result_all
		prntSet_analysis_result_withLoop
		
	"""
	xfig = 4
	yfig = 0
	figheight = xfig*2

	##### draw figure about entropy and hop length
	merge = True
	if merge == True:
		f, ax = plt.subplots(xfig, sharex=False, figsize=(7.5, figheight))
		
		###
#		plt.margins(x=0.2, y=0.2)		## margin between plotted lines to the axis
		plt.tight_layout(pad=2)		### the distance between the actual figure and the border
	else:
		ax = [0 for i in range(10)]
	
	i = 0
	j = 0

	
	'''
	merge four Entropy and protocol metric figures 
	'''
#	figname = 'ctp_eer_orw_node_details_noID37.png'
	figname = 'ctp_eer_orw_node_details_2.png'
	
	compare_metric("PRR", 'prr_analysis_result_1.txt', 1, merge, ax[i])
	
	i += 1
	compare_metric("Wordload", 'dup_analysis_result.txt', 2, merge, ax[i], has_legend=True)
	
	i += 1
	compare_metric("Duplicates", 'dup_analysis_result.txt', 1, merge, ax[i])

	
	
#	figname = 'Dup_Fwd_ratio_ctp_eer_orw_node_details.png'
	i += 1
	compare_metric("Dup_Fwd_ratio", 'dup_analysis_result.txt', 1, merge, ax[i])

	
	if merge:
		plt.savefig(figname, dpi=300)
		
