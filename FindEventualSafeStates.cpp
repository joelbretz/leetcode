class Solution {

  int n;
  protected:
  bool dfs(vector<vector<int>>& graph, vector<int>& color, int node) {
  
    // check if this node has been visited,
    // return false if it's grey, true if it's black
    if(color[node] > 0) {
      return (color[node] == 2);
    }
    
   // change this node to grey (entry)
    color[node] = 1;
    // check neighbors
    for(auto neighbor : graph[node]) {
      // if the neighbor is black, continue on to the next.
      if(color[neighbor] == 2) 
        continue;
      // if it's grey return false if every node around it
      // is grey, (a cycle)
      if((color[neighbor] == 1) || !dfs(graph,color,neighbor))
        return false;
    }
    color[node] = 2; // color node black on exit
    return true;
  }
  public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    n = graph.size();
    vector<int> color(n,0);
    vector<int> safe;
    
    for(int i = 0; i < n; ++i) {
      if(dfs(graph,color,i))
         safe.push_back(i);
    }
    return safe;
  }
};
