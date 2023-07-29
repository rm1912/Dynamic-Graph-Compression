import matplotlib.pyplot as plt

# Define x and y
#Graph density represents the ratio between the edges present in a graph and the maximum number of edges that the graph can contain
x=[0.058,0.077,0.095,0.095,0.18,0.18,0.32,0.32,0.42,0.42,0.48,0.48,0.5]
y=[0.945348,0.939907,1.04193,0.940097,1.01879,0.952099,1.0089,1.00554,0.973512,0.984462,1.00159,0.991666,0.997428]
# Plot x and y
plt.scatter(x, y, c=['red', 'green', 'blue', 'purple','yellow','black','grey','red', 'green', 'blue', 'purple','yellow','red'])
plt.plot(x, y)

# Add labels and title

plt.ylabel('Compression-ratio')
plt.xlabel('number of edges to attach from a new node to existing nodes')
plt.title('Plotting number of edges to attach from a new node to existing nodes Vs Compression-ratio')

# Show the plot
plt.show()