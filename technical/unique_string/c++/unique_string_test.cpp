#include <stdio.h>
#include <assert.h>
#include <cstring>

bool isUnique1(char*);
bool isUnique2(char*);
bool isUnique3(char*);

void testEmpty();
void testOne();
void testDuplicate();
void testUnique();

int main() {
  testEmpty();
  testOne();
  testDuplicate();
  testUnique();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  char empty[] = "";
  assert(isUnique1(empty));
  assert(isUnique2(empty));
  assert(isUnique3(empty));
}

void testOne() {
  char one[] = "1";
  assert(isUnique1(one));
  assert(isUnique2(one));
  assert(isUnique3(one));
}

void testDuplicate() {
  char dup[] = "mdamssas";
  assert(!isUnique1(dup));
  assert(!isUnique2(dup));
  assert(!isUnique3(dup));
}

void testUnique() {
  char unique[] = "abcdefgh";
  assert(isUnique1(unique));
  assert(isUnique2(unique));
  assert(isUnique3(unique));
}
