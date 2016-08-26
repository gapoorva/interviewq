#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "binary_tree.h"

void testEmpty();
void testAdd();
void testFind();
void testTraverse1();
void testTraverse2();
void testTraverse3();
void testTraverse4();
void testTraverse5();
void testTraverse6();
void testRemove1();
void testRemove2();
void testRemove3();
void testRemove4();
void testRemove5();
void testRemove6();

int main() {
  testEmpty();
  testAdd();
  testFind();
  testTraverse1();
  testTraverse2();
  testTraverse3();
  testTraverse4();
  testTraverse5();
  testTraverse6();
  testRemove1();
  testRemove2();
  testRemove3();
  testRemove4();
  testRemove5();
  testRemove6();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  BinaryTree<int> tree;
  int three = 3;
  tree.remove(three);
  int ten = 10;
  assert(!tree.find(ten));
  auto i = tree.first();
  assert(i != tree.end());
}

void testAdd() {
  BinaryTree<int> tree;
  tree.add(30);
  tree.add(17);
  tree.add(213);
  tree.add(0);
  assert(!tree.empty());
}

void testFind() {
  BinaryTree<int> tree;
  tree.add(30);
  tree.add(17);
  tree.add(213);
  tree.add(19);
  assert(tree.find(19));
  assert(!tree.find(20));
}

/*
  Traversal cases:
  (1) traverse a complete tree
  (2) traverse a line (left)
  (3) traverse a line (right)
  (4) traverse something that looks like this:

             a
           /   \
          b     c
         / \     \
        d   e     f
       / \   \     \
      g   h   i     j

      ....

  (5) traverse the reflection of (4)
  (6) traverse a zig-zag
*/

void testTraverse1() {
  BinaryTree<int> tree;
  tree.add(4);
  tree.add(2);
  tree.add(6);
  tree.add(1);
  tree.add(3);
  tree.add(5);
  tree.add(7);
  // complete tree created
  int value = 1;
  for(auto i = tree.first(); i != tree.end(); ++i, ++value) {
    assert(value == *i);
  }
}

void testTraverse2() {
  BinaryTree<int> tree;
  tree.add(7);
  tree.add(6);
  tree.add(5);
  tree.add(4);
  tree.add(3);
  tree.add(2);
  tree.add(1);
  // left line created
  int value = 1;
  for(auto i = tree.first(); i != tree.end(); ++i, ++value) {
    assert(value == *i);
  }
}

void testTraverse3() {
  BinaryTree<int> tree;
  tree.add(1);
  tree.add(2);
  tree.add(3);
  tree.add(4);
  tree.add(5);
  tree.add(6);
  tree.add(7);
  // right line created
  int value = 1;
  for(auto i = tree.first(); i != tree.end(); ++i, ++value) {
    assert(value == *i);
  }
}

void testTraverse4() {
  BinaryTree<int> tree;
  tree.add(7);
  tree.add(8);
  tree.add(9);
  tree.add(10);
  tree.add(4);
  tree.add(5);
  tree.add(6);
  tree.add(2);
  tree.add(3);
  tree.add(1);
  // right line created
  int value = 1;
  for(auto i = tree.first(); i != tree.end(); ++i, ++value) {
    assert(value == *i);
  }
}

void testTraverse5() {
  BinaryTree<int> tree;
  tree.add(4);
  tree.add(3);
  tree.add(2);
  tree.add(1);
  tree.add(7);
  tree.add(6);
  tree.add(5);
  tree.add(9);
  tree.add(8);
  tree.add(10);
  // right line created
  int value = 1;
  for(auto i = tree.first(); i != tree.end(); ++i, ++value) {
    assert(value == *i);
  }
}

void testTraverse6() {
  BinaryTree<int> tree;
  tree.add(5);
  tree.add(10);
  tree.add(1);
  tree.add(9);
  tree.add(2);
  tree.add(8);
  tree.add(3);
  tree.add(7);
  tree.add(4);
  tree.add(6);
  // right line created
  int value = 1;
  for(auto i = tree.first(); i != tree.end(); ++i, ++value) {
    assert(value == *i);
  }
}

/*
  Removal cases:
  (1) remove root
  (2) remove middle node (with both children there)
  (3) remove middle node (with 1 child)
  (4) remove leaf node
  (5) remove all
  (6) remove root on zigzag
*/

void testRemove1() {
  BinaryTree<int> tree;
  tree.add(4);
  tree.add(2);
  tree.add(6);
  tree.add(1);
  tree.add(3);
  tree.add(5);
  tree.add(7);
  // complete tree created
  assert(tree.find(4));
  tree.remove(4);
  assert(!tree.find(4));
}

void testRemove2() {
  BinaryTree<int> tree;
  tree.add(4);
  tree.add(2);
  tree.add(6);
  tree.add(1);
  tree.add(3);
  tree.add(5);
  tree.add(7);
  // complete tree created
  assert(tree.find(3));
  tree.remove(3);
  assert(!tree.find(3));
  assert(tree.find(6));
  tree.remove(6);
  assert(!tree.find(6));
}

void testRemove3() {
  BinaryTree<int> tree;
  tree.add(4);
  tree.add(2);
  tree.add(6);
  tree.add(1);
  tree.add(3);
  tree.add(5);
  tree.add(7);
  tree.add(8);
  tree.add(0);
  // node 1, 7 have single children
  assert(tree.find(1));
  tree.remove(1);
  assert(!tree.find(1));
  assert(tree.find(0));
  assert(tree.find(7));
  tree.remove(7);
  assert(!tree.find(7));
  assert(tree.find(8));
}

void testRemove4() {
  BinaryTree<int> tree;
  tree.add(4);
  tree.add(2);
  tree.add(6);
  tree.add(1);
  tree.add(3);
  tree.add(5);
  tree.add(7);
  // complete tree created
  assert(tree.find(1));
  tree.remove(1);
  assert(!tree.find(1));
}

void testRemove5() {
  // remove all by repeatedly removing root
  BinaryTree<int> tree;
  tree.add(4);
  tree.add(2);
  tree.add(6);
  tree.add(1);
  tree.add(3);
  tree.add(5);
  tree.add(7);
  tree.remove(4);
  tree.remove(5);
  tree.remove(6);
  tree.remove(7);
  tree.remove(3);
  tree.remove(2);
  tree.remove(1);
  assert(tree.empty());
}

void testRemove6() {
  BinaryTree<int> tree;
  tree.add(5);
  tree.add(10);
  tree.add(1);
  tree.add(9);
  tree.add(2);
  tree.add(8);
  tree.add(3);
  tree.add(7);
  tree.add(4);
  tree.add(6);
  assert(tree.find(5));
  tree.remove(5);
  assert(!tree.find(5));
}