'''
compare the results of ctp, ctp+eer, and orw

Since all the results only has one test, use bar chart
'''

import numpy as np
import matplotlib.pyplot as plt


def compare_metric(metric_name, infname, idx_avg, idx_std, merge, f, has_legend=False):
	"""	
	A function to compare the network metric
	
	metric_name:	the name of the network metric 
	idx_avg: the index of the metric in the analysis file
	idx_std: the stdev of the metric in the analysis file 
	merge:	Bool, if True, the figure will be merged to a larger figure; otherwise
			a separate figure will be generated
	f:		If merge == True, f is the figure handler
	
	"""
	inf = open('ctp/' + infname, 'r')

	metric_ctp = []
	errs_ctp = []
	line_count = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if s[idx_avg] == 'nan':
					s[idx_avg] = 0
				if s[idx_std] == 'nan':
					s[idx_std] = 0
				metric_ctp.append(float(s[idx_avg]))
				errs_ctp.append(float(s[idx_std]))
	inf.close()

	inf = open('rctp/' + infname, 'r')

	metric_rctp = []
	errs_rctp = []
	line_count = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if s[idx_avg] == 'nan':
					s[idx_avg] = 0
				if s[idx_std] == 'nan':
					s[idx_std] = 0
				metric_rctp.append(float(s[idx_avg]))
				errs_rctp.append(float(s[idx_std]))
	inf.close()
	
	inf = open('orw/' + infname, 'r')

	metric_orw = []
	errs_orw = []
	line_count = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if s[idx_avg] == 'nan':
					s[idx_avg] = 0
				if s[idx_std] == 'nan':
					s[idx_std] = 0
				metric_orw.append(float(s[idx_avg]))
				errs_orw.append(float(s[idx_std]))
	inf.close()
	
	inf = open('orw_lpl1024/' + infname, 'r')

	metric_orw_lpl1024 = []
	errs_orw_lpl1024 = []
	line_count = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				if s[idx_avg] == 'nan':
					s[idx_avg] = 0
				if s[idx_std] == 'nan':
					s[idx_std] = 0
				metric_orw_lpl1024.append(float(s[idx_avg]))
				errs_orw_lpl1024.append(float(s[idx_std]))
	inf.close()

	print len(metric_ctp)
	print len(metric_rctp)

	x = np.arange(len(metric_ctp))
	bar_width = 0.35

	if not merge:
		plt.figure(figsize=(12, 3.5))

		bar_ctp = f.bar(x, metric_ctp, bar_width, color='r', yerr=errs_ctp, label='ctp')
		bar_rctp = f.bar(x+bar_width, metric_rctp, bar_width, color='g', yerr=errs_rctp, label='rctp')
		bar_orw = f.bar(x+2*bar_width, metric_orw, bar_width, color='b', yerr=errs_orw, label='orw')
		bar_orw_lpl1024 = f.bar(x+3*bar_width, metric_orw_lpl1024, bar_width, color='c', yerr=errs_orw_lpl1024, label='orw_lpl1024')
		
		
		plt.legend()
		plt.title(metric_name)
#		plt.xlabel('Noise traces')
		plt.ylabel(metric_name)
		
#		if metric_name == 'Trickle_reset':
#			plt.ylimit(0, 70)

		#for i in range(len(entropies)):
		#	plt.annotate(str(entropies[i]), xy=(x[i], entropies[i]+0.01))

		plt.savefig(metric_name + '_vs_noise_level_ctp_vs_rctp.png', dpi=300)
		plt.clf()
	else:
#		f.errorbar(x, metric_ctp, yerr=errs_ctp, capsize=5, fmt='o-', label='ctp')
#		f.errorbar(x, metric_rctp, yerr=errs_rctp, capsize=5, fmt='^-', label='ctp+eer')

		bar_ctp = f.bar(x, metric_ctp, bar_width, color='r', yerr=errs_ctp, label='ctp')
		bar_rctp = f.bar(x+bar_width, metric_rctp, bar_width, color='g', yerr=errs_rctp, label='rctp')
		bar_orw = f.bar(x+2*bar_width, metric_orw, bar_width, color='b', yerr=errs_orw, label='orw')
		bar_orw_lpl1024 = f.bar(x+3*bar_width, metric_orw_lpl1024, bar_width, color='c', yerr=errs_orw_lpl1024, label='orw_lpl1024')
		
		if metric_name == 'PRR':
			f.set_ylim([0.5, 1.0])
		elif metric_name == 'Fwd_entropy':
			f.set_ylim([1.5, 3.2])
		
		autolabel(f, bar_ctp)
		autolabel(f, bar_rctp)
		autolabel(f, bar_orw)
		autolabel(f, bar_orw_lpl1024)
		
		if has_legend:
			f.legend()
#		f.legend()
		f.set_title(metric_name)
		f.set_ylabel(metric_name)


def autolabel(axx, rects):
	"""
    Attach a text label above each bar displaying its height
    """
	for rect in rects:
		height = rect.get_height()
		axx.text(rect.get_x() + rect.get_width()/2., 1.02*height,
                '%.2f' % (height),
                ha='center', va='bottom')


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
	xfig = 5
	yfig = 2
	figheight = xfig*2

	##### draw figure about entropy and hop length
	merge = True
	if merge == True:
		f, ax = plt.subplots(xfig, yfig, sharex=True, figsize=(7.5, figheight))
		
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
	figname = 'Merge_entropy.png'
	compare_metric("Entropy", 'analysis_result_entropy_noLoop.txt', 1, 2, merge, ax[i, j])
	
	j += 1
	compare_metric("Fwd_entropy", 'analysis_result_entropy_noLoop.txt', 3, 4, merge, ax[i, j])
	
	i += 1
	j = 0
	compare_metric("Protocol_Metric", 'metric_analysis_result_all_entropy_no_loop.txt', 3, 4, merge, ax[i, j])
	
	'''
	### test	cycle_prr_avg	std	duplicates	dup_std	loop_avg	loop_std	loop_sum	
	   	  0           1          2    3           4       5           6            7
	   	hop_avg	std	loopy_hop_avg	std	link_usage_avg	std
	   	8        9     10           11      12           13
	###
	'''
	j += 1
	compare_metric("PRR", 'prr_analysis_result_all_withLoop.txt', 1, 2, merge, ax[i, j])
	
	i += 1
	j = 0
	compare_metric("Duplicates", 'prr_analysis_result_all_withLoop.txt', 3, 4, merge, ax[i, j], has_legend=True)
	j += 1
	compare_metric("Loop", 'prr_analysis_result_all_withLoop.txt', 5, 6, merge, ax[i, j])
	
	i += 1
	j = 0
	compare_metric("PathLen", 'prr_analysis_result_all_withLoop.txt', 8, 9, merge, ax[i, j])
	
	j += 1
	compare_metric("LinkUsage", 'prr_analysis_result_all_withLoop.txt', 12, 13, merge, ax[i, j])
	
	i += 1
	j = 0
	compare_metric("Loopy_PathLen", 'prr_analysis_result_all_withLoop.txt', 10, 11, merge, ax[i, j])
	
	j += 1
	compare_metric('PrntSet_Size', 'prntSet_analysis_result_withLoop.txt', 1, 2, merge, ax[i, j])
	
	
	
	
	''' merge figure 2, figsize=(7.5, 10)'''
#	compare_metric("LinkUsage", 'prr_analysis_result_all.txt', 12, 13, merge, ax[1])
#	

#	
	#######  trickle_analysis_result_all.txt 
	## test	fwd_entropy_avg	std	trickle_reset_avg	std	trickle_better_path	std
#	compare_metric("Fwd_entropy", 'trickle_analysis_result_all.txt', 1, 2, merge, ax[3])
#	

	''' protocol metric '''
#	compare_metric('Protocol_Metric', 'metric_analysis_result_all_no_loop.txt', 3, 4, merge, ax[1])

	''' size of parent set '''
#	figname='Parent_set_size_vs_noise.png'
#	compare_metric('PrntSet_Size', 'prntSet_analysis_result_withLoop.txt', 1, 2, merge, ax, has_legend=True)
##	compare_metric("PathLen", 'prr_analysis_result_all.txt', 8, 9, merge, ax[2])
	
	
	
	if merge:
		plt.savefig(figname, dpi=300)
		
