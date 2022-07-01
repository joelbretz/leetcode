class Solution {
  protected:

  void dfs(vector<vector<int>>& connectList, vector<bool>& visited, int currCity) {

    if(visited[currCity] == true) {
      //cout << "  i already visited city: " << currCity << endl;
      return;
    }

    //cout << "  marking city visted: " << currCity << endl;
    visited[currCity] = true;

    for(int i = 0 ; i < connectList[currCity].size(); ++i) {
      if(connectList[currCity][i] == 1) {
        //cout << "    i am connected to city: " << i << endl;
        if(!visited[i]) {
          //cout << "  visiting city: " << i << endl;
          dfs(connectList, visited, i);
        }
      }
    }
  }

  public:
  // This is a BFS solution for this problem
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    queue<int> q;
    int provinces = 0;

    //cout << "=======================" << endl; 
    // loop over cities, starting with 0
    for(int i = 0; i < n; ++i) {
      if(!visited[i]) {
        //cout << "starting from city: " << i << endl;
        // we haven't visited this city from any city with lesser index.
        q.push(i);
        while(!q.empty()) {
          int city = q.front();
          q.pop();
          //cout << "  visiting city: " << city << endl;
          visited[city] = true;
          // check it's connect list:
          for(int j = 0; j < n; ++j) {
            if(isConnected[city][j] && !visited[j])
              q.push(j);
          }
        }
        provinces++;
      }
    }
    return provinces;
  }

  // Use DFS:
  int findCircleNumDFS(vector<vector<int>>& isConnected) {
    //cout << "=======================" << endl; 
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinces = 0;
    for(int i = 0; i < isConnected.size(); ++i) {
      if(!visited[i]) {
        //cout << "starting dfs from city: " << i << endl;
        dfs(isConnected, visited, i);
        provinces += 1;
      }
    }
    return provinces;
  }
};
