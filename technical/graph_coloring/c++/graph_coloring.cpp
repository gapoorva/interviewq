#include <vector>

// G is adjacency list
// N is number of nodes
// C is number of colors
// Assumes G.size() == N and G does not contain a null pointer
std::vector<int> graphcolor(const std::vector<std::vector<int>*>& G, const int N, const int C) {
  std::vector<int> nodes; // contains a list of colors assigned to nodes (numbered 0 to N-1)
  // dumb, trivial cases
  if (N <= 0 || C < 0) return nodes;
  nodes.push_back(-1); // color the node #0 to the "null" color
  while(!nodes.empty()) {
    if(++nodes.back() < C) {
      std::vector<int>* adjacents = G[nodes.size()-1];
      bool unique = true;
      for(auto i = adjacents->begin(); i != adjacents->end(); i++) {
        if(*i < nodes.size() && nodes[*i] == nodes.back()) {
          unique = false;
          break; // a nieghbor is already this color!
        }
      }
      // all nodes colored?
      if(unique && nodes.size() == (size_t)N) return nodes;
      // is this node a valid color? if so, pick another node to color.
      if(unique) nodes.push_back(-1);
    } else {
      // this node has exhausted all color choices. Backtrack
      nodes.pop_back();
    } 
  }
  // If while loops quits, no valid coloring exists.
  return nodes;
} 