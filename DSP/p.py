import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv
import sys

# create a list and import data from output.csv file
data = list()
with open('./p.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        data.append(float(row[0]))

# transform list to numpy array
np_data = np.array(data)

# create samples for x axis
t = np.arange(0, len(data), 1)

# create plot
fig, ax = plt.subplots()
ax.plot(t, np_data)
amount = len(data) -1
plt.yticks([-3.14, -2.36, -1.57, -0.79, 0, 0.79, 1.57, 2.36, 3.14], ["-π", "-3π/4", "-π/2", "-π/4", "0", "π/4", "π/2", "3π/4", "π"])
plt.xticks([0, amount /4, amount / 2, amount ], ["0", "π/4", "π/2", "π"])
ax.set(xlabel='sample', ylabel='output',
       title='Phase')
ax.grid()

# To save the result, outcomment the line below:
# fig.savefig("data_plot.png")
plt.show()
