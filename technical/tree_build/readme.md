# Tree Build

Binary Search Trees implement the binary search property that makes them "sorted" data structure that allows them to have efficient insertion, retrieval and search. Take an ordinary sorted array of numbers and use it to build a binary search tree that maintains the same oder of elements on an in-order traversal.

Assume that the tree structure is implemented by the following c-style struct. Your method should return a reference to the root of the tree you create.
```C

template <typename T>
struct node {
  node* left;
  node* right;
  T data;
};
```

## Solutions

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | N      | N     | gapoorva |
