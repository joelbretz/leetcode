class Solution {

  protected:
  void dfs(vector<vector<int>>& adj, vector<bool>& visited, int cpuNum) {

    if(visited[cpuNum]) 
      return;

    //cout << "  update visited for cpu: " << cpuNum << endl;
    visited[cpuNum] = true;
    
    // if i have no connections
    if(adj.size() <= cpuNum)
      return;
    
    for(auto c : adj[cpuNum]) {
      //cout << "   i am connected to cpu: " << c << endl;
      if(!visited[c]) {
        //cout << "visiting cpu: " << c << endl; 
        dfs(adj,visited,c);
      }
    }
  }

  public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    
    //cout << "------------------" << endl;

    // check if we even need to figure this out.
    int edges = connections.size();
    if(n - 1 > edges)
      return -1;
    
    // create an adjacency list from the list of connection pairs
    vector<vector<int>> adj(n);
    for(auto c : connections) {
      adj[c[0]].push_back(c[1]);
      adj[c[1]].push_back(c[0]);
    }
    // keep track of where we have been. 
    vector<bool> visited(n, false);
    
    int subnets = 0;
    for(int i = 0; i < n; ++i) {
      if(!visited[i]) {
        //cout << "visiting cpu: " << i << endl;
        dfs(adj,visited,i);
        subnets += 1;
        //cout << " subnets = " << subnets << endl;
      }
    }
    //cout << "subnets: " << subnets << endl;
    
    return subnets - 1;
  }
};
