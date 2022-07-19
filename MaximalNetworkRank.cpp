class Solution {
  
  int networkRank(vector<vector<int>>& adj, int i, int j) {
    unordered_set<int> connected_cities;
    for(int u = 0; u < adj[i].size(); ++u) {
      connected_cities.insert(adj[i][u]);
    }
    for(int v = 0; v < adj[j].size(); ++v) {
      connected_cities.insert(adj[j][v]);
    }
    return connected_cities.size();
  }
  
  public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    // build adjacency list sets
    vector<set<int>> adjSet(n);
    for(auto r : roads) {
      adjSet[r[0]].insert(r[1]);
      adjSet[r[1]].insert(r[0]);
    }
    int maximal = 0;
    for(int i = 0; i < n - 1; ++i) {
      for(int j = i + 1; j < n; ++j) {
        int roadsBetween = adjSet[i].size() + adjSet[j].size();
        if(adjSet[i].find(j) != adjSet[i].end())
          roadsBetween -= 1;
        maximal = max(maximal, roadsBetween);
      }
    }
    return maximal;
  }
};
