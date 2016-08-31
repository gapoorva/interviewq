# Depth First Search

Depth first search is a popular graph search algorithm. It's basic approach can be characterized by exploring on path completely before trying other possible paths. In graph problems, a common way to represent a graph is by using an adjacency matrix. For a simple directed, graph, we can represent the graph:

```
A ----- B
 \
  \
   \
    C
```

With the following adjacency matrix:
```
A: [ 0 1 1 ]
B: [ 1 0 0 ]
C: [ 1 0 0 ]
```

Where `A`, `B`, and `C` correspond to row/column `0`, `1`, `2` respectively. Note there is no edge on the diagonal (top left to bottom right) because the diagonal represents connections between one node and itself.

Design an algorithm such to implement a breadth first search to find if a path exists a target node T, from a source node S given an undirected graph G described as an adjacency matrix of pointers. Return the path as an array of nodes/node pointers.

Example:

Given the above shown graph, the path from source node `C` to destination node `B` is:
```
[C, A, B]
```

## Solutions


