#include <algorithm>

bool isUnique1(char* s) {
  bool map[256];
  for(int i = 0; i < 256; i++) {
    map[i] = false;
  }
  int x = 0;
  while(s[x]) {
    if(map[s[x]]) {
      return false;
    }
    map[s[x]] = true;
    x++;
  }
  return true;
}

bool isUnique2(char* s) {
  int len = 0;
  while(s[len]) len++;
  for(int i = 0; i < len-1; i++) {
    for(int j = i+1; j < len; j++) {
      if(s[i] == s[j]) {
        return false;
      }
    }
  }
  return true;
}

bool isUnique3(char* s) {
  int len = 0;
  while(s[len]) len++;
  if(len < 2) {
    return true;
  }
  std::sort(s, s+len);
  for(int i = 0; i < len-1; i++) {
    if(s[i] == s[i+1]) {
      return false;
    }
  }
  return true;
}