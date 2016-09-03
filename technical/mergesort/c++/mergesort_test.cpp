#include <stdio.h>
#include <assert.h>

void mergesort(int*, unsigned);

void testEmpty();
void testOne();
void testTwo();
void testThree();
void testLargeEven();
void testLargeOdd();

int main() {
  testEmpty();
  testOne();
  testTwo();
  testThree();
  testLargeEven();
  testLargeOdd();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  int a[1] = {1};
  mergesort(a, 0);
  assert(a[0] == 1);
}

void testOne() {
  int a[1] = {1};
  mergesort(a, 1);
  assert(a[0] == 1);
}

void testTwo() {
  int a[2] = {1, 0};
  mergesort(a, 2);
  assert(a[0] == 0);
  assert(a[1] == 1);
}

void testThree() {
  int a[3] = {2, 1, 0};
  mergesort(a, 3);
  assert(a[0] == 0);
  assert(a[1] == 1);
  assert(a[2] == 2);
}

void testLargeEven() {
  int a[10] = {9, 2, 1, 6, 4, 8, 7, 5, 0, 3};
  mergesort(a, 10);
  for(int i = 0; i < 10; i++) {
    assert(a[i] == i);
  }
}

void testLargeOdd() {
  int a[9] = {2, 1, 6, 4, 8, 7, 5, 0, 3};
  mergesort(a, 9);
  for(int i = 0; i < 9; i++) {
    assert(a[i] == i);
  }
}