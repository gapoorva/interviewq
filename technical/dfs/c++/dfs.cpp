#include <unordered_map>
#include <vector>
#include <stdio.h>

struct step {
  int node;
  step* prev;
  step(int n, step* p): node(n), prev(p) {};
};

static const int END = -1;

static void savepath(int, std::vector<int>&, const std::unordered_map<int, int>&);

std::vector<int> dfs(const bool matrix[20][20], int N, int source, int dest) {
  std::vector<int> path;
  std::unordered_map<int, int> visited;
  // Check that source and dest are in [0, N)
  if((source >= N) || (dest >= N)) {
    throw "source and destination must both be in the range [0, N)";
  }
  std::vector<int> routing;
  routing.push_back(dest);
  visited[dest] = END;
  while(!routing.empty()) {
    int next = routing.back();
    routing.pop_back();
    if(next == source) { // found it
      savepath(next, path, visited);
      return path;
    }
    // explore in sorted order
    for(int i = 0; i < N; i++) {
      // travel to peer if a connection exists and has not been visited
      if(matrix[next][i] && visited.find(i) == visited.end()) {
        routing.push_back(i);
        visited[i] = next;
      }  
    }
  }
  return path;
}

static void savepath(int start, std::vector<int>& path, const std::unordered_map<int, int>& visited) {
  do {
    path.push_back(start);
    start = visited.find(start)->second;
  } while(start != END);
}