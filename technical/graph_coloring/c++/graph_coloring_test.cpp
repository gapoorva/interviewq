#include <stdio.h>
#include <assert.h>
#include <vector>

std::vector<int> graphcolor(const std::vector<std::vector<int>*>&, const int, const int);

void testSingleNode();
void testSingleNodeManyColors();
void testCompleteGraph3NodeWith2Colors();
void testCompleteGraph3NodeWith3Colors();
void testLinkedList2Colors();
void testOddCycle2Colors();

int main() {
  testSingleNode();
  testSingleNodeManyColors();
  testCompleteGraph3NodeWith2Colors();
  testCompleteGraph3NodeWith3Colors();
  testLinkedList2Colors();
  testOddCycle2Colors();
  printf("PASS\n");
  return 0;
}

void testSingleNode() {
  std::vector<int> connections; // empty vector
  std::vector<std::vector<int>*> graph;
  graph.push_back(&connections); // Node #0 has no connections
  std::vector<int> colorMap = graphcolor(graph, 1, 1);
  assert(colorMap.size() == 1);
  assert(colorMap[0] == 0);
}

void testSingleNodeManyColors() {
  std::vector<int> connections; // empty vector
  std::vector<std::vector<int>*> graph;
  graph.push_back(&connections); // Node #0 has no connections
  std::vector<int> colorMap = graphcolor(graph, 1, 10);
  assert(colorMap.size() == 1);
  assert(colorMap[0] == 0);
}

void testCompleteGraph3NodeWith2Colors() {
  std::vector<std::vector<int>*> graph;
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>()); // 3 nodes
  graph[0]->push_back(1);
  graph[0]->push_back(2);
  graph[1]->push_back(0);
  graph[1]->push_back(2);
  graph[2]->push_back(0);
  graph[2]->push_back(1);
  std::vector<int> colorMap = graphcolor(graph, 3, 2);
  assert(colorMap.size() == 0);
  for(auto i = graph.begin(); i != graph.end(); i++) delete *i;
}

void testCompleteGraph3NodeWith3Colors() {
  std::vector<std::vector<int>*> graph;
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>()); // 3 nodes
  graph[0]->push_back(1);
  graph[0]->push_back(2);
  graph[1]->push_back(0);
  graph[1]->push_back(2);
  graph[2]->push_back(0);
  graph[2]->push_back(1);
  std::vector<int> colorMap = graphcolor(graph, 3, 3);
  assert(colorMap.size() == 3);
  assert(colorMap[0] == 0);
  assert(colorMap[1] == 1);
  assert(colorMap[2] == 2);
  for(auto i = graph.begin(); i != graph.end(); i++) delete *i;
}

void testLinkedList2Colors() {
  std::vector<std::vector<int>*> graph;
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>()); // 5 nodes
  graph[0]->push_back(1);
  graph[1]->push_back(0);
  graph[1]->push_back(2);
  graph[2]->push_back(1);
  graph[2]->push_back(3);
  graph[3]->push_back(2);
  graph[3]->push_back(4);
  graph[4]->push_back(3);
  std::vector<int> colorMap = graphcolor(graph, 5, 2);
  assert(colorMap.size() == graph.size());
  for(size_t i = 0; i < graph.size(); i++) {
    assert(colorMap[i] == i%2); // evens are 0, odds are 1
  }
  for(auto i = graph.begin(); i != graph.end(); i++) delete *i;
}

void testOddCycle2Colors() {
  std::vector<std::vector<int>*> graph;
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>());
  graph.push_back(new std::vector<int>()); // 5 nodes
  graph[0]->push_back(1);
  graph[1]->push_back(0);
  graph[1]->push_back(2);
  graph[2]->push_back(1);
  graph[2]->push_back(3);
  graph[3]->push_back(2);
  graph[3]->push_back(4);
  graph[4]->push_back(3);
  graph[4]->push_back(0);
  std::vector<int> colorMap = graphcolor(graph, 5, 2);
  assert(colorMap.size() == 0);
  for(auto i = graph.begin(); i != graph.end(); i++) delete *i;
}
