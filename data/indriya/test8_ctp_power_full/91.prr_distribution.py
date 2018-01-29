'''
find the distribution of prr
'''

inf = open('cycle_avg_prr.txt', 'r')
outf = open('cycle_prr_distribution.txt', 'w')



prr = []

for line in inf:
	s = line.split()
	if len(s) > 0:
		prr.append(float(s[0]))

inf.close()

step = 0.02
minn = min(prr) - step/2
maxx = max(prr) + step/2
 #### the step to count the frequency in PRR

n = int((maxx - minn) / step)
dis = [0 for i in range(n+1)]
print maxx

for i in range(len(prr)):
	idx = int((prr[i] - minn)/step)
#	print idx
#	print prr[i]
	dis[idx] += 1

for i in range(n):
	outf.writelines(str(i) + '\t' + str(dis[i]) + '\n')

outf.close()


