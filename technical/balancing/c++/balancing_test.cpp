#include <stdio.h>
#include <assert.h>
#include <string>

std::string balance(std::string&);

void testEmpty();
void testSingle();
void testBalanced();
void testAlternating();
void testNestedGroups();
void testWithOtherChars();

int main() {
  testEmpty();
  testSingle();
  testBalanced();
  testAlternating();
  testNestedGroups();
  // testWithOtherChars();
  printf("PASS\n");
  return 0;
}

void testEmpty() {
  std::string s;
  assert(balance(s) == "");
}

void testSingle() {
  std::string s = "(";
  assert(balance(s) == "");
  s = ")";
  assert(balance(s) == "");
}

void testBalanced() {
  std::string s = "()()((())()()())";
  std::string t = balance(s);
  assert(t == s);
}

void testAlternating() {
  std::string s = "))))((((";
  assert(balance(s) == "");
  std::string t = "(()((()(((";
  std::string u = "))()))()))";
  assert(balance(t) == "()()");
  assert(balance(u) == "()()");
}

void testNestedGroups() {  
  std::string s = "()((()))))()())))()(((";
  assert(balance(s) == "()((()))()()()");
}

void testWithOtherChars() {
  std::string phone_number = "cell: ((123) - 456 - 7890 (";
  assert(balance(phone_number) == "cell: (123) - 456 - 7890 ");
}