class Solution {
  protected:
  void printAdj(vector<vector<int>>& A) {
    for(int u = 0; u < A.size(); ++u) {
      cout << u << ": ";
      for(int v = 0; v < A[u].size(); ++v) 
        cout << A[u][v] << " ";
      cout << endl;
    }
  }
  
  public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if(n == 0)
      return false;
    if(source == destination)
      return true;

    vector<vector<int>> adj(n, vector<int>());
    for(auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    //printAdj(adj);

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()) {
      int curr = q.front();
      q.pop();
      if(curr == destination)
        return true;
      for(int i = 0; i < adj[curr].size(); ++i) {
        int next = adj[curr][i];
        if(!visited[next]) {
          q.push(next);
          visited[next] = true;
        }
      }
    }
    return false;
  }
};
