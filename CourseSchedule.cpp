class Solution {
  
  void printAdj(vector<vector<int>>& adj, vector<int>& indegree) {
    for(int i = 0; i < adj.size(); ++i) {
      cout << i << ": ";
      for(int j = 0; j < adj[i].size(); ++j)
        cout << adj[i][j] << " " ;
      cout << endl;
    }
    
    cout << "indegrees: " ;
    for(auto d : indegree) 
      cout << d << " ";
    cout << endl;
    
  }
  
  static bool bySecond(pair<int,int>& a, pair<int,int>& b) {
    if(a.second < b.second)
      return true;
    else 
      return false;
  }
  
  public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    if(prerequisites.size() == 0)
      return true;
    
    vector<vector<int>> adjList(numCourses,vector<int>());
    vector<int> indegree(numCourses, 0);
    // create adjacency list and indegree count for each node 
    for(auto prereq : prerequisites) { 
      int a = prereq[0], b = prereq[1];
      adjList[b].push_back(a);   // prereq[a,b] means edge from b to a;
      indegree[a] += 1;
    }
    //printAdj(adjList, indegree);
  
    queue<int> q;
    for(int i = 0; i < numCourses; ++i) {
      if(indegree[i] == 0)
        q.push(i);
    }
    
    while(!q.empty()) {
      int node = q.front();
      q.pop();
      // order.push_back(node)
      for(auto adj : adjList[node]) {
        indegree[adj] -= 1;
        if(indegree[adj] == 0)
          q.push(adj);
      }
    }
    for(auto in : indegree) {
      if(in > 0)
        return false;
    }
    return true;
  }
};
