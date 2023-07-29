import networkx as nx
import matplotlib.pyplot as plt

G = nx.powerlaw_cluster_graph(1000, 200, 0.9)
# print(G.edges()) 
# nx.draw(G)
# plt.show()
with open("/Users/Prince/Documents/CP/input39.txt", "w") as f:
    f.write("("+str(len(G.nodes())) + ", ")
    f.write(str(len(G.edges())) + ")\n")
    # Write edges to file
    for edge in G.edges():
        f.write(str(edge) + "\n")
    f.flush()
# Print a message indicating that the file was written
print("Output written to output.txt")