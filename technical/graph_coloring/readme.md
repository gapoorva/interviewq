# Graph Coloring

Graph coloring is a famous NP-complete problem. The idea is that you have a graph, and a set of colors, and you need to color each node on the graph in a way that no two adjacent nodes (aka have an edge between them) has the same color. Note that in graph with `N` nodes, coloring it with `M` colors results in `N^M` possibilities, making exploring the solution space difficult using a brute force technique.

Given a graph `G` as an adjacency list, the number of nodes `N`, and a number of colors to color the graph, return a mapping of nodes to colors that satisfy the graph coloring property. If there is no such mapping, return an empty map. Assume nodes are numbered 0 through N-1 and colors are number

Bonus: explain how you could use your graph coloring solution to build a Sudoko puzzle solver.

## Solutions

Let `N` be the number of nodes, and `C` be the number of colors.

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | N^C    | N     | gapoorva |