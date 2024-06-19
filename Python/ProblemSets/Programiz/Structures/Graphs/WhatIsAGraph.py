"""
What is a graph?

A graph is a collection of nodes that have data and are connected to
other nodes.

(0) <---> (3)
|   \
|    (2)
|   /
(1)

The above graph can be written with the notation:
V = {0, 1, 2, 3} # Our vertices
E = {(0,1), (0,2), (0,3), (1,2)}
G = {V, E}

The following terminology is important for a graph:
- Adjacency: A vertex is said to be adjacent to another if there is an edge connecting them.
Vertices 2 and 3 are not adjacent because there is no edge between them.

- Path: A sequence of edges that allows you to go from vertex A to vertex B is called a path.
0-1, 1-2, and 0-2 are paths from vertex 0 to vertex 2.

- Directed Graph: A graph in which an edge (u,v) doesn't necessarily mean that there is an edge
(v,u) as well. The edges in such a graph are represented by arrows to show the direction of the
edge.

We can represent an adjacency matrix in the following manners:
# Adjacency matrix
    - A 2D array of V x V vertices. Each row and column
    represent a vertex.
    - If the value of any element a[i][j] is 1, it represents that there is an edge connecting vertex
    i and vertex j.
    - Each look-up is extremely fast, but we have to reserve space, due to it requiring so much.

# Adjacency List
An adjacency list represents a graph as an array of linked lists.

The index of the array represents a vertex and each element in its linked list represents
the other vertices that form an edge with the vertex.

An adjacency list is efficinet in terms of storage, cause we only need to store the values
for the edges.
"""

# We now implement some of the above concepts below!
# Adjacency List representation in Python

class AdjNode:
    def __init__(self, value):
        self.vertex = value
        self.next = None

class Graph:
    def __init__(self, num):
        self.V = num
        self.graph = [None] * self.V

    # Add edges
    def add_edge(self, s, d):
        node = AdjNode(d)
        node.next = self.graph[s]
        self.graph[s] = node

        node = AdjNode(s)
        node.next = self.graph[d]
        self.graph[d] = node

    # Print the graph
    def print_agraph(self):
        for i in range(self.V):
            print("Vertex " + str(i) + ":", end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next
            print(" \n")

# Adjacency matrix in Python
class Graph2(object):

    # Initialize the matrix
    def __init__(self, size):
        self.adjMatrix = []
        for i in range(size):
            self.adjMatrix.append([0 for i in range(size)])
        self.size = size

    # Add edges
    def add_edge(self, v1, v2):
        if v1 == v2:
            print("Same vertex %d and %d" % (v1, v2))
        self.adjMatrix[v1][v2] = 1
        self.adjMatrix[v2][v1] = 1

    # Remove edges
    def remove_edge(self, v1, v2):
        if self.adjMatrix[v1][v2] == 0:
            print("No edge between %d and %d" % (v1, v2))
            return
        self.adjMatrix[v1][v2] = 0
        self.adjMatrix[v2][v1] = 0

    def __len__(self):
        return self.size

    # Print the matrix
    def print_matrix(self):
        for row in self.adjMatrix:
            for val in row:
                print('{:4}'.format(val)),
            print



if __name__ == "__main__":
    V = 5

    # Create graph and edges
    graph = Graph(V)
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(0, 3)
    graph.add_edge(1, 2)

    graph.print_agraph()