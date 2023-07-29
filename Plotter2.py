import matplotlib.pyplot as plt

# Define x and y
#Graph density represents the ratio between the edges present in a graph and the maximum number of edges that the graph can contain
x=[0.000525299,0.000529323,0.000939974,0.00227975,0.00359299]
y=[1.65801,1.31692,1.08573,1.54611,1.15255]
# Plot x and y
plt.scatter(x, y, c=['red', 'green', 'blue', 'purple','yellow'])
plt.plot(x, y)

# Add labels and title
plt.ylabel('Compression-ratio')
plt.xlabel('Density')
plt.title('Plotting Density Vs Compression-ratio')

# Show the plot
plt.show()