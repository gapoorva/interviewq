#include <stdio.h>
#include <assert.h>
#include "hashmap.h"

void testEmpty();
void testPut();
void testDel();

int main() {
  testEmpty();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  HashMap<int> map;
  assert(map.size() == 0);
  assert(!map.find("hello"));
}

void testPut() {
  HashMap<int> map;
  map.put("hello", 5);
  map.put("world", 5);
  map.put("code", 4);
  // no resize yet
  assert(map.size() == 3);
  assert(map.find("hello"));
  assert(map.find("world"));
  assert(map.find("code"));

  // cause a resize with this
  map.put("begin", 5);

  assert(map.find("hello"));
  assert(map.find("world"));
  assert(map.find("code"));
  assert(map.find("begin"));

  assert(map.size() == 4);

  assert(map.get("hello") == map.get("world"));
  assert(map.get("hello") == map.get("begin"));
  assert(!map.find("undefined"));
}

void testDel() {
  HashMap<int> map;
  map.put("hello", 5);
  map.put("world", 5);
  map.put("code", 4);
  assert(map.size() == 3);

  map.del("world");

  assert(map.size() == 2);
  assert(!map.find("world"));
  
  try {
    map.get("world");
    assert(0); // expected exception here
  } catch (...) {}

  map.put("world", 7);
  assert(map.get("world") == 7);
  assert(map.size() == 3);
}