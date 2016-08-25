#include <stdio.h>
#include <assert.h>
#include <cstring>

void testEmpty();
void testOne();
void testEven();
void testOdd();
void testExtraNulls();

void reverse(char*);

int main() {
  testEmpty();
  testOne();
  testEven();
  testOdd();
  testExtraNulls();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  char empty[] = "";
  reverse(empty);
  assert(strcmp(empty, "") == 0);
}

void testOne() {
  char one[] = "1";
  reverse(one);
  assert(strcmp(one, "1") == 0);
}

void testEven() {
  char even[] = "even";
  reverse(even);
  assert(strcmp(even, "neve") == 0);
}

void testOdd() {
  char odd[] = "odd";
  reverse(odd);
  assert(strcmp(odd, "ddo") == 0);
}

void testExtraNulls() {
  char foo[] = "hello";
  foo[4] = 0;
  reverse(foo);
  assert(strcmp(foo, "lleh") == 0);
}