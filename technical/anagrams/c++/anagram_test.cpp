#include <stdio.h>
#include <assert.h>

bool isAnagram1(const char*, const char*);
void testEmpty();
void testUnequal();
void testReflexive();
void testBasic();
void testExtra();
void testLess();
void testDifferent();

int main() {
  testEmpty();
  testUnequal();
  testReflexive();
  testBasic();
  testExtra();
  testLess();
  testDifferent();
  printf("PASS\n");
}

void testEmpty() {
  char a[] = "";
  char b[] = "";
  assert(isAnagram1(a, b));
}

void testUnequal() {
  char a[] = "length";
  char b[] = "lengths";
  assert(!isAnagram1(a, b));
}

void testReflexive() {
  char a[] = "property";
  char b[] = "property";
  assert(isAnagram1(a, b));
}

void testBasic() {
  char a[] = "iceman";
  char b[] = "cinema";
  assert(isAnagram1(a, b));
}

void testExtra() {
  char a[] = "icemam";
  char b[] = "cinema";
  assert(!isAnagram1(a, b));
}

void testLess() {
  char a[] = "iceman";
  char b[] = "cineaa";
  assert(!isAnagram1(a, b));
}

void testDifferent() {
  char a[] = "icemat";
  char b[] = "cinema";
  assert(!isAnagram1(a, b));
}
