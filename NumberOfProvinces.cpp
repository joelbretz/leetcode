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
  int findCircleNum(vector<vector<int>>& isConnected) {
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
