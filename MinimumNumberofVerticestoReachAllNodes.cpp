class Solution {
  public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    // reverse edges and find nodes with no children
    vector<vector<int>> adjList(n,vector<int>());
    for(auto edge : edges) {
      adjList[edge[1]].push_back(edge[0]);
    }
    
    vector<int> result;
    for(int i = 0; i < n; ++i) {
      if(adjList[i].size() == 0)
        result.push_back(i);
    }
    return result;
  }
};
