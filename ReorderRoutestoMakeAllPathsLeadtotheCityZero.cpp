///Treat the graph as undirected. Start a dfs from the root, if you come across an edge in the forward direction, you need to reverse the edge.

class Solution {
  
  void printGraph(vector<vector<int>>& G) {
    cout << "--------------------" << endl;
    for(int i = 0; i < G.size(); ++i) {
      cout << i << ": ";
      for(int j = 0; j < G[i].size(); ++j) {
        cout << G[i][j] << " "; 
      }
      cout << endl;
    }
  }
  
  int dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    
    visited[node] = true;
    int rev = 0;
    for(auto neighbor : graph[node]) {
      if(!visited[abs(neighbor)]) {
        if(neighbor < 0) 
          rev++;
        rev += dfs(graph,visited,abs(neighbor));
      }  
    }
    return rev;
  }
  
  public:
  int minReorder(int n, vector<vector<int>>& connections) {
    //build adjacency list
    vector<vector<int>> adj(n,vector<int>());
    for(auto c : connections) {
      adj[c[0]].push_back(-c[1]); // forward
      adj[c[1]].push_back(c[0]); // reverse
    }
    //printGraph(adj);
    
    vector<bool> visited(n,false);
    int flip = dfs(adj,visited,0);
    return flip;
  }
};
