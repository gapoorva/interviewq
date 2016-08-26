#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>

// remove extra paranthesis
std::string balance(std::string& s) {
  if (!s.size()) return s;
  size_t writer = 0;
  int bal = 0;
  //std::cout << "step1\n";
  for(size_t i = 0; i < s.size(); i++) {
    if(s[i] == '(') bal++;
    if(s[i] == ')') bal--;
    //when balance goes negative, skip the character.
    if(bal < 0) bal++; // maintain the positive balance
    else s[writer++] = s[i]; // write back to string
  }
  //std::cout << "step2\n";m
  s = s.substr(0, writer);
  std::string balstr; // string will be at most writer length. (N Space worst case)
  bal = 0;
  if (!s.size()) return s; // don't keep going if the string is already empty
  for(int i = (int)writer - 1; i >= 0; i--) {
    // same thing as before, just go in reverse
    //std::cout << "doing step 2\n";
    if(s[i] == ')') bal++;
    if(s[i] == '(') bal--;
    //printf("bal: %i\n", bal);
    if(bal < 0) {
      //printf("SKIPPING\n");
      bal++;
    } else balstr.push_back(s[i]);
  }
  std::reverse(balstr.begin(), balstr.end()); // reverse the string since we inserted in reverse order
  return balstr;
}