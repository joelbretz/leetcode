class Solution {
  
  void printLists(vector<vector<int>>& l1){
    for(int i = 0; i < l1.size(); ++i) {
      cout << i << ": " ;
      for(int j = 0; j < l1[i].size(); ++j) {
        cout << l1[i][j] << " ";
      }
      cout << endl;
    }
  }
  
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      // represent as adjacency list
      vector<vector<int>> reqs(numCourses, vector<int>());
      // keep track of the indegree of every node
      vector<int> indegree(numCourses,0); 
      for(auto p : prerequisites) {
        reqs[p[1]].push_back(p[0]);
        indegree[p[0]]++;
      }
      //printLists(reqs);
      
      // manage courses in order of indegree
      queue<int> q;
      for(int i = 0; i < numCourses; ++i) {
        if(indegree[i] == 0)
          q.push(i);
      }
      // solution vector
      vector<int> order;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        // iterate over my neighbors
        for(int i = 0; i < reqs[node].size(); ++i ) {
          int neighbor = reqs[node][i];
          if(--indegree[neighbor] == 0) {
            q.push(neighbor);
          }
        }
      }
      if(order.size() == numCourses)
        return order;
      
      return {};
    }
};
