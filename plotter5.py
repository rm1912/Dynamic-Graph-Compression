import matplotlib.pyplot as plt

# Define x and y
#Graph density represents the ratio between the edges present in a graph and the maximum number of edges that the graph can contain
x=[50,100,200,300,400,500,600,700,800,900,950,960,970]
y=[1.04193,1.01879,1.0089,1.00554,1.00159,0.997428,0.991666,0.984462,0.973512,0.952099,0.940097,0.939907,0.945348]
# Plot x and y
plt.scatter(x, y, c=['red', 'green', 'blue', 'purple','yellow','black','grey','red', 'green', 'blue', 'purple','yellow','red'])
plt.plot(x, y)

# Add labels and title

plt.ylabel('Compression-ratio')
plt.xlabel('number of edges to attach from a new node to existing nodes')
plt.title('Plotting number of edges to attach from a new node to existing nodes Vs Compression-ratio')

# Show the plot
plt.show()