# BFS algorithm in Python
"""
A standard BFS implementation puts each vertex of the graph into one
of two categories:
1. Visited
2. Not Visited

The purpose of the algorithm is to mark each vertex as visited while
avoiding cycles.

The algorithm works as follows:
1. Start by putting any one of the graph's vertices at the back of the
queue.
2. Take the front item of the queue and add it to the visited list.
3. Create a list of that vertex's adjacent nodes. Add the ones which
aren't in the visited list to the back of the queue.
4. Keep repeating steps 2 and 3 until the queue is empty.
"""


import collections

# BFS algorithm
def bfs(graph, root):

    visited, queue = set(), collections.deque([root])
    visited.add(root)

    while queue:

        # Dequeue a vertex from queue
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")

        # If not visited, mark it as visited, and
        # enqueue it
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


if __name__ == '__main__':
    graph = {0: [1, 2], 1: [2], 2: [3], 3: [1, 2]}
    print("Following is Breadth First Traversal: ")
    bfs(graph, 0)
