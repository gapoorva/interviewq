#include <stdio.h>
#include <assert.h>
#include <cstring>

void remove(char*);

void testEmpty();
void testOne();
void testSome();
void testAll();
void testUnique();

int main() {
  testEmpty();
  testOne();
  testSome();
  testAll();
  testUnique();
  printf("PASS\n");
}

void testEmpty() {
  char empty[] = "";
  remove(empty);
  assert(strcmp(empty, "") == 0);
}

void testOne() {
  char one[] = "1";
  remove(one);
  assert(strcmp(one, "1") == 0);
}

void testSome() {
  char some[] = "aabaadsseeddsddww";
  remove(some);
  assert(strcmp(some, "abdsew") == 0);
}

void testAll() {
  char all[] = "aaaaa";
  remove(all);
  assert(strcmp(all, "a") == 0);
}

void testUnique() {
  char unique[] = "abcde";
  remove(unique);
  assert(strcmp(unique, "abcde") == 0);
}