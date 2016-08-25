#include <stdio.h>
#include <assert.h>
#include "queue.h"

void testEmpty();
void testFront();
void testBack();
void testFIFOFront();
void testFIFOBack();

int main() {
  testEmpty();
  testFront();
  testBack();
  testFIFOFront();
  testFIFOBack();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  queue<int> q;
  assert(q.empty());
  try {
    q.pop_front();
    assert(0);
  } catch (...) {}
  try {
    q.pop_back();
    assert(0);
  } catch (...) {}
}

void testFront() {
  queue<int> q;
  q.push_front(0);
  q.push_front(1);
  q.push_front(2);
  q.push_front(3);

  assert(!q.empty());
  assert(q.pop_front() == 3);
  assert(q.pop_front() == 2);
  assert(q.pop_front() == 1);
  assert(q.pop_front() == 0);

  assert(q.empty());
}

void testBack() {
  queue<int> q;
  q.push_back(0);
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);

  assert(!q.empty());
  assert(q.pop_back() == 3);
  assert(q.pop_back() == 2);
  assert(q.pop_back() == 1);
  assert(q.pop_back() == 0);

  assert(q.empty());
}

void testFIFOFront() {
  queue<int> q;
  q.push_front(0);
  q.push_front(1);
  q.push_front(2);
  q.push_front(3);

  assert(!q.empty());
  assert(q.pop_back() == 0);
  assert(q.pop_back() == 1);
  assert(q.pop_back() == 2);
  assert(q.pop_back() == 3);

  assert(q.empty());
}

void testFIFOBack() {
  queue<int> q;
  q.push_back(0);
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);

  assert(!q.empty());
  assert(q.pop_front() == 0);
  assert(q.pop_front() == 1);
  assert(q.pop_front() == 2);
  assert(q.pop_front() == 3);

  assert(q.empty());
}
