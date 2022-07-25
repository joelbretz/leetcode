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
   
    // sort nodes by indegree
    vector<pair<int,int>> nodeDegrees(numCourses, {0,0}); // { nodeNo, indegree}
    for(int i = 0; i < numCourses; ++i) {
      nodeDegrees[i] = {i, indegree[i]};
    }
    sort(nodeDegrees.begin(), nodeDegrees.end(), bySecond);
    
    vector<bool> visited(numCourses, false);
    // iterate through nodes with <=zero indegrees, decrement indegrees
    // of nodes they are adjacent to. if any indegree > 0 at the end. fail
    bool removed = true;
    while(removed) {
      removed = false;
      for(int i = 0; i < numCourses; ++i) { 
        //cout << "node " << i << " has indegree " << indegree[i] << ", visited=" << visited[i] << endl;
        if(indegree[i] == 0 && visited[i] == false) { 
          visited[i] = true;
          for(auto adj : adjList[i]) {
            //cout << "  reduce indegree of " << adj << endl;
            indegree[adj] -= 1;
            removed = true;
          }
        }
      }
    }
    for(auto in : indegree) {
      if(in > 0)
        return false;
    }
    return true;
  }
};
