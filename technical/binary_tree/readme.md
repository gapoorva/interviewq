# Binary Search Tree Problem

In computer science, a binary search tree is a subset of a mathematical structure called a tree. In trees, data is represented in nodes. These nodes are organized in a hierarchy, with each node containing 0 or more subtrees. Trees are often defined as recursive data structure.

A binary search tree holds several special properties:

1. Each node has exactly 2 children (binary tree)
2. Each element in the tree is organized such that every element in its left subtree compare less than the value of the element itself, and every element in its right subtree compare greater than the value of the element itself. (search property)

These two above properties simplifies the tree structure and enables us to implement an efficient data structure for storing and retrieving values with a natural strict ordering.

Implement a binary tree with the following methods/functionality. Comment on assumptions and implementation-level approaches you take.
```
binary_tree:
  add(elt)
  find(elt)
  printInOrder()
  delete(elt)
```

Iterators are objects that model pointers on data structures. Iterators allow us to traverse a data structure incrementally (like in a loop.)

Implement an iterator on that tree, such that one can traverse the tree in order. An "end" iterator should also be implemented so that the iterator can be used in a for loop. To specify, implement the following:
```
binary_tree.iterator:
  reference_at_iterator()
  next_value()
  is_at_end()
```

## Solutions

**Add**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | logN   | 1     | gapoorva |

**Find**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | logN   | 1     | gapoorva |

**Print In Order**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | logN   | N     | gapoorva |

**Delete**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | logN   | 1     | gapoorva |

**Traversal**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | logN   | N     | gapoorva |