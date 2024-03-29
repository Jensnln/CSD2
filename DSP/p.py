import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv

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

min = -2*3.1415926535897
max = 2*3.1415926535897
step = 3.1415926535897 / 4
yname = "Phase shift"
name = "Phase Response"

plt.yticks([-3.14, -2.36, -1.57, -0.79, 0, 0.79, 1.57, 2.36, 3.14], ["-π", "-0.75π", "-0.5π", "-0.25π", "0", "0.25π", "0.5π", "0.75π", "π"])

amount = len(data)-1
plt.xticks([0, amount/4, amount/2, amount/4*3, amount], ["0", "0.25π", "0.5π", "0.75π", "π"])
ax.set(xlabel='Frequency', ylabel=yname,
       title=name)
ax.grid()

# To save the result, outcomment the line below:
# fig.savefig("data_plot.png")
plt.show()
