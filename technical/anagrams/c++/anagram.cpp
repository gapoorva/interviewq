#include <stdio.h>

// how many fewer lines can I make it??
bool isAnagram1(const char* a, const char* b) {
  int counts[256];
  for(int i = 0; i < 256; ++i) counts[i] = 0;
  while(*a) counts[*a++]++; // lol
  while(*b) counts[*b++]--; // lolol
  for(int i = 0; i < 256; ++i) if (counts[i]) return false;
  return true;
}