import networkx as nx
import matplotlib.pyplot as plt

n = 1000 # number of nodes
m = 700 # number of edges to attach from a new node to existing nodes
seed = 10 # random seed

G = nx.barabasi_albert_graph(n, m,seed=seed)
# print(G.nodes())
# print(G.edges())
# Open file for writing
with open("/Users/Prince/Documents/CP/input41.txt", "w") as f:
    f.write("("+str(len(G.nodes())) + ", ")
    f.write(str(len(G.edges())) + ")\n")
    # Write edges to file
    for edge in G.edges():
        f.write(str(edge) + "\n")
    f.flush()
# Print a message indicating that the file was written
print("Output written to output.txt")

# nx.draw(G, with_labels=True)
# plt.show()
