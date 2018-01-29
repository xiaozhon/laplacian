'''
plot the relationship between parent set size and the length of time interval 

'''
import numpy as np
import matplotlib.pyplot as plt

inf = open('plot_cycles_prntSet_analysis_result_withLoop.txt', 'r')

sizes = []	## the size of parent set
err = []

line_count = 0

for line in inf:
	s = line.split()
	line_count += 1
	if line_count < 2:
		continue
	if len(s) > 0:
		## Orw-5	3.6068	0.2388
		sizes.append(float(s[1]))
		err.append(float(s[2]))
inf.close()

print sizes

f, ax = plt.subplots(figsize=(6, 3))

plt.tight_layout(pad=2)

x = np.arange(1, len(sizes)+1)

ax.errorbar(x, sizes, yerr=err, capsize=4, fmt='o-', markersize=4, label="CTP+EER")
ax.legend()

ax.set_title('Size of PrntSet v.s. Cycle Length')
ax.set_ylabel('Size')
ax.set_xlabel('Cycle Length')
plt.savefig('PrntSetSize_and_cycle_length.png', dpi=300)
