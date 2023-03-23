import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv
import sys


# create a list and import data from output.csv file
data = list()
with open('./a.csv', 'r') as file:
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



if min(data) > -78:
    min = round(min(data) - 6, -1)
    step = round(min / -7)
    step = 1
else:
    min = -78
    plt.ylim(-78, 6)
    step = 6.
if (max(data) > 6.0):
    max = max(data)
else:
    max = 6.0
yname = "Gain (dB)"
name = "Amplitude Response"



plt.yticks(np.arange(min, max, step))

amount = len(data)-1
plt.xticks([0, amount/4, amount/2, amount/4*3, amount], ["0", "0.25π", "0.5π", "0.75π", "π"])
ax.set(xlabel='Frequency', ylabel=yname,
       title=name)
ax.grid()

# To save the result, outcomment the line below:
# fig.savefig("data_plot.png")
plt.show()