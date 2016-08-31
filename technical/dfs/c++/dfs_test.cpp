#include <stdio.h>
#include <assert.h>
#include <vector>

std::vector<int> dfs(const bool[20][20], int, int, int);

void testSingleNode();
void testTwoNode();
void testLinkedList();
void testFullyConnected();
void testSparselyConnected();
void testUnconnected();

int main() {
  testSingleNode();
  testTwoNode();
  testLinkedList();
  testFullyConnected();
  testSparselyConnected();
  testUnconnected();
  printf("PASS\n");
  return 0;
}

void testSingleNode() {
  bool graph[20][20] = {{1}};
  int size = 1, source = 0, dest = 0;
  std::vector<int> path = dfs(graph, size, source, dest);
  assert(path.size() == size);
  assert(path.back() == dest);
}

void testTwoNode() {
  bool graph[20][20] = {
    {0, 1},
    {1, 0}
  };
  int size = 2, source = 0, dest = 1;
  std::vector<int> path = dfs(graph, size, source, dest);
  assert(path.size() == size);
  assert(path.back() == dest);
  assert(path.front() == source);
}

void testLinkedList() {
  bool graph[20][20] = {
    {0, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0}
  };
  int size = 6, source = 0, dest = 5;
  std::vector<int> path = dfs(graph, size, source, dest);
  assert(path.size() == size);
  for(size_t i = 0; i < size; i++) {
    assert(path[i] == i);
  }
}

void testFullyConnected() {
  bool graph[20][20] = {
    {0, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 0}
  };
  int size = 6, source = 0, dest = 1;
  std::vector<int> path = dfs(graph, size, source, dest);
  assert(path.size() == 2);
  assert(path[0] == source);
  assert(path[1] == dest);
}

void testSparselyConnected() {
  bool graph[20][20] = {
    {0, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 1},
    {0, 1, 0, 1, 1, 0},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0}
  };
  int size = 6, source = 0, dest = 4;
  std::vector<int> path = dfs(graph, size, source, dest);
  assert(path.size() == 4);
  assert(path[0] == source);
  assert(path[1] == 1);
  assert(path[2] == 2);
  assert(path[3] == dest);
}

void testUnconnected() {
  bool graph[20][20] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0}
  };
  int size = 6, source = 0, dest = 5;
  std::vector<int> path = dfs(graph, size, source, dest);
  assert(path.empty());
}