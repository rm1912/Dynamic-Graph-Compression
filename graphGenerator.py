import networkx as nx

n = 1000   # number of nodes
p = 0.99  # density of edges

G = nx.gnp_random_graph(n, p)

# Open file for writing
with open("/Users/Prince/Documents/CP/input18.txt", "w") as f:
    f.write("("+str(len(G.nodes())) + ", ")
    f.write(str(len(G.edges())) + ")\n")
    # Write edges to file
    for edge in G.edges():
        f.write(str(edge) + "\n")
    f.flush()
# Print a message indicating that the file was written
print("Output written to output.txt")