import matplotlib.pyplot as plt

# Define x and y
#Graph density represents the ratio between the edges present in a graph and the maximum number of edges that the graph can contain
x=[200,300,400,500,600,700,800,900]
y=[0.99955,0.996647,0.952099,0.989406,0.98423,0.97351,0.952101,0.940097]
# Plot x and y
plt.scatter(x, y, c=['yellow','black','grey','red', 'green', 'blue', 'purple','pink'])
plt.plot(x, y)

# Add labels and title

plt.ylabel('Compression-ratio')
plt.xlabel('each node having x random edges')
plt.title('Plotting each node having x random edges Vs Compression-ratio')

# Show the plot
plt.show()