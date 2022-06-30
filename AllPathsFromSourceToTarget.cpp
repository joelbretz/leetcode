class Solution {
  
  void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& bt, int nodeNo) {
    // backtracking on bt, so push the node and pop it at the end
    bt.push_back(nodeNo);
    
    // check for end node.
    // if we found it, push the backtrack list
    if(nodeNo == graph.size() - 1) {
      paths.push_back(bt);
    }
    else {
      // continue the search on all nodes in my adjacency list
      for(auto nextNode : graph[nodeNo]) {
        dfs(graph,paths,bt,nextNode);
      }
    }
    
    // finally, do the backtrack 
    bt.pop_back();
  }
  public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> allPaths;
    vector<int> backtrack;
    dfs(graph,allPaths,backtrack,0);
    return allPaths;
  }
};
