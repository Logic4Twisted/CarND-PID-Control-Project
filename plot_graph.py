import numpy as np
import matplotlib.pyplot as plt

data = []
with open('output.txt') as f:
	lines = f.readlines()
	for line in lines:
		if line.startswith("CTE:"):
			sline = line.split(" ")
			data.append((float(sline[1]), float(sline[4]), float(sline[6]), float(sline[8])))
		if line.startswith("Total Error: "):
			print line

x_ = np.arange(len(data))

plt.figure()
plt.subplot(211)
plt.title('CTE:')
plt.plot(x_, [x[0] for x in data], 'b')

plt.subplot(212)
plt.title('Steering value: ')
plt.plot(x_, [x[1] for x in data], 'r')
plt.show()