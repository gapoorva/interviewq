#include <stdio.h>

void reverse(char* s) {
  int len = 0;
  while(s[len]) len++;
  if(len < 2) return;
  len--;
  int i = 0;
  while(i < len) {
    char tmp = s[i];
    s[i] = s[len];
    s[len] = tmp;
    i++;
    len--;
  }
}