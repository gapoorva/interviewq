#include <stdio.h>

void remove(char* s) {
  // constant space solution
  int len = 0;
  int dups = 0;
  while(s[len]) {
    len++;
  }
  if(len < 2) {
    return;
  }
  // n^2 marking
  for(int i = 0; i < len-1; i++ ) {
    for(int j = i + 1; j < len; j++) {
      if(s[j] && s[i] == s[j]) {
        s[j] = 0;
        dups++;
      }
    }
  }
  int seek = 0;
  for(int i = 0; i < len - dups; i++, seek++) {
    while(seek < len && !s[seek]) {
      seek++;
    }
    s[i] = s[seek];
  }
  s[len-dups] = 0;
}