class Solution {
  protected:
  void printMap(map<string, vector<string>>& M) {
    for(auto elem : M) {
      cout << elem.first << ": " ;
      for(auto addr : elem.second) {
        cout << addr << " ";
      }
      cout << endl;
    }
  }
  
  void dfs(map<string,vector<string>>& adjList, map<string,bool>& visited, vector<string>& merged, string email ) {
    
    visited[email] = true;
    merged.push_back(email);
    for(auto neighbor : adjList[email]) {
      if(!visited[neighbor]) {
        dfs(adjList, visited, merged, neighbor);
      }
    }
  }
  
  public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, vector<string>> adjMap;
    for(int i = 0; i < accounts.size(); ++i) {
      if(accounts[i].size() == 2) { // single entry
        auto it = adjMap[accounts[i][1]];
      }
      else {
        for(int j = 1; j < accounts[i].size() - 1; ++j ) {
          adjMap[accounts[i][j]].push_back(accounts[i][j+1]);
          adjMap[accounts[i][j+1]].push_back(accounts[i][j]);
        }
      }
    }
    //printMap(adjMap);
    vector<vector<string>> solution;
    
    // now the problem is just a connected components dfs
    map<string,bool> visited; 
    for(int i = 0; i < accounts.size(); ++i ) {
      string name = accounts[i][0];
      string email = accounts[i][1];
      if(!visited[email]) {
        vector<string> curr; curr.push_back(name);
        dfs(adjMap, visited, curr, email);
        sort(curr.begin() + 1, curr.end());
        solution.push_back(curr);
       }
    }
    return solution;
  }
};
