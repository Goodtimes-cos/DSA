"""
Before going onto spanning trees, and minimum spanning trees, we
need to understand undirected graphs and connected graphs:

* An undirected graph is one which has edges that do not point in
any direction.

* A connect graph is a graph in which there is always a path from
a vertex to any other vertex


A spanning tree is a sub-graph of an undirected connected graph, which
includes all the vertices of the graph with a minimum possible number
of edges.

If a vertex is missed, then it is not a spanning tree. The edges may
or may not have weights assigned to them.

``` The total number of spanning trees with n vertices that can be
created from a complete graph is equal to n^(n-2) -- Proof?```

A minimum spanning tree is a spanning tree in which the sum of the
weight of the edges is as minimum as possible.
"""