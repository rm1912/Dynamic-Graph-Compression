import matplotlib.pyplot as plt

# Define x and y
#Graph density represents the ratio between the edges present in a graph and the maximum number of edges that the graph can contain
x=[0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.99]
y=[1.05626,1.02714,1.0172,1.01237,1.00941,1.00744,1.00604,1.00499,1.0042,1.00364]
# Plot x and y
plt.scatter(x, y, c=['red', 'green', 'blue', 'purple','yellow','black','grey','red', 'green', 'blue'])
plt.plot(x, y)

# Add labels and title

plt.ylabel('Compression-ratio')
plt.xlabel('Density')
plt.title('Plotting Density Vs Compression-ratio')

# Show the plot
plt.show()