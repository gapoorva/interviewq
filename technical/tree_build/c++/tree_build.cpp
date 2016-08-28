#include <stdio.h>
#include <assert.h>
#include "tree_build.h"

void testEmpty();
void testOne();
void testTwo();
void testThree();

int main() {
  testEmpty();
  testOne();
  testTwo();
  testThree();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  int a[1];
  node<int>* n = createtree(a, 0, 0);
  if(n != nullptr) {
    delete n;
    assert(0);
  }
}

void testOne() {
  int a[1];
  a[0] = 10;
  node<int>* n = createtree(a, 0, 1);
  assert(n);
  assert(n->data == 10);
  assert(!n->left);
  assert(!n->right);
  delete n;
}

void testTwo() {
  int a[2];
  a[0] = 10;
  a[1] = 20;
  node<int>* n = createtree(a, 0, 2);
  assert(n);
  assert(n->data == 20);
  assert(n->left);
  assert(n->left->data == 10);
  assert(!n->right);
  delete n->left;
  delete n;
}

void testThree() {
  int a[3];
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;
  node<int>* n = createtree(a, 0, 3);
  assert(n);
  assert(n->data == 20);
  assert(n->left);
  assert(n->left->data == 10);
  assert(n->right);
  assert(n->right->data == 30);
  delete n->left;
  delete n->right;
  delete n;
}