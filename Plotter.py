import matplotlib.pyplot as plt
# Define x and y
#Graph density represents the ratio between the edges present in a graph and the maximum number of edges that the graph can contain
x=[17262,52310,89455,206259,819306]
y=[1.54611,1.65801,1.15255,1.31692,1.08573]
# Plot x and y
plt.scatter(x, y, c=['red', 'green', 'blue', 'purple','yellow'])
plt.plot(x, y)

# Add labels and title
plt.ylabel('Compression-ratio')
plt.xlabel('Edges')
plt.title('Plotting Edges Vs Compression-ratio')

# Show the plot
plt.show()