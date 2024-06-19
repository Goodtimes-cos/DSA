import collections

"""
A depth first search, or depth first traversal, is a recursive
algorithm for searching all the vertices of a graph or tree data
structure.

A standard implementation puts each vertex of the graph into one of
two states:
- Visited
- Unvisited

The purpose of the algorithm is to mark each vertex as visited
while avoiding cycles.

The DFS algorithm works as follows:
1. Start by putting any one of the graph's vertices on top of a stack,
2. Take the top item of the stack and add it to the visited list,
3. Create a list of that vertex's adjacent nodes. Add the ones which
aren't in the visited list to the top of the stack.
4. Keep repeating steps 2 and 3 until the stack is empty.
"""

def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)

    print(start)

    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited


graph = {'0': set(['1', '2']),
         '1': set(['0', '3', '4']),
         '2': set(['0']),
         '3': set(['1']),
         '4': set(['2', '3'])}

dfs(graph, '0')