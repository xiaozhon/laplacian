'''
draw the figure of the entropies of all the test, includes error bar

## 	test	cycle_prr_avg	std		duplicates	dup_std		loop_avg	loop_std	loop_sum	
				1			2			3			4			5			6			7
	hop_avg	std		loopy_hop_avg	std		link_usage_avg	std
		8	9			10			11			12			13

add-8	0.5676	0.1743

add-10	0.5692	0.1890

add-12	0.5150	0.1618
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
#	inf = open('ctp_36nodes_noise/prr_analysis_result_all.txt', 'r')
	inf = open('orw_lpl1024_sinkON/' + infname, 'r')

	metric_orw = []
	errs_orw = []
	line_count = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:
				metric_orw.append(float(s[idx_avg]))
				errs_orw.append(float(s[idx_std]))
	inf.close()

#	inf = open('rctp_36nodes_noise/prr_analysis_result_all.txt', 'r')
	inf = open('rctp_sinkON_DAR30/' + infname, 'r')

	metric_rctp = []
	errs_rctp = []
	line_count = 0
	for line in inf:
		line_count += 1
		if line_count > 1:
			s = line.split()
			if len(s) > 0:

				metric_rctp.append(float(s[idx_avg]))
				errs_rctp.append(float(s[idx_std]))
	inf.close()

	print len(metric_orw)
	print len(metric_rctp)

	x = np.arange(1, len(metric_orw)+1)

	if not merge:
#		fig, ax = plt.figure(figsize=(6, 2.5))

		fig, ax = plt.subplots(figsize=(6, 3))

		plt.tight_layout(pad=2)
		
		ax.errorbar(x, metric_orw, yerr=errs_orw, capsize=5, fmt='o-', label='orw', markersize=4)
		ax.errorbar(x, metric_rctp, yerr=errs_rctp, capsize=5, fmt='^-', label='ctp+eer', markersize=4)
		ax.legend()
		ax.set_title(metric_name + " v.s. cycle_length")
		ax.set_xlabel('Cycle Length')
		ax.set_ylabel(metric_name)
		
#		if metric_name == 'Trickle_reset':
#			plt.ylimit(0, 70)

		#for i in range(len(entropies)):
		#	plt.annotate(str(entropies[i]), xy=(x[i], entropies[i]+0.01))

#		plt.savefig(metric_name + '_vs_noise_level_ctp_vs_rctp.png', dpi=300)
#		plt.clf()
	else:
		f.errorbar(x, metric_ctp, yerr=errs_ctp, capsize=5, fmt='o-', label='ctp')
		f.errorbar(x, metric_rctp, yerr=errs_rctp, capsize=5, fmt='^-', label='ctp+eer')
		if has_legend:
			f.legend()
#		f.legend()
		f.set_title(metric_name + " v.s. noise")
		f.set_ylabel(metric_name)



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
	fignum = 5
	figheight = fignum*2

	##### draw figure about entropy and hop length
	merge = False
	if merge == True:
		f, ax = plt.subplots(fignum, sharex=True, figsize=(7.5, figheight))
		
		###
#		plt.margins(x=0.2, y=0.2)		## margin between plotted lines to the axis
		plt.tight_layout(pad=2)		### the distance between the actual figure and the border
	else:
		ax = [0 for i in range(10)]
	
#	plt.tight_layout(pad=2)	

	'''
	merge four Entropy and protocol metric figures 
	'''
	
	figname = 'sinkON_PrntSetSize_vs_cycle_length_1min.png'
#	
	compare_metric('PrntSet_Size', 'plot_cycles_prntSet_analysis_result_withLoop.txt', 1, 2, merge, ax, has_legend=True)
##	compare_metric("PathLen", 'prr_analysis_result_all.txt', 8, 9, merge, ax[2])
	
#	if merge:
	plt.savefig(figname, dpi=300)
		
