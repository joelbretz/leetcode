class Solution {
  int n;
  int dx[8] = { 1,1, 1, 0, 0,-1,-1,-1 };
  int dy[8] = { 1,0,-1, 1,-1, 1, 0,-1 };

  public:

  bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= n)
      return false;
    return true;
  }

  void printGrid(vector<vector<int>>& G) {
    int rows = G.size(), cols = G[0].size();
    cout << "---------------" << endl;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        cout << G[r][c] << " ";
      }
      cout << endl;
    }
  }
  
  // BFS because I need to practice these.
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    // setup stuff.. grid size, matrix for distances, 
    // queue for points
    n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n,n*n));
    queue<pair<int,int>> pathQ;
    dist[0][0] = 1;
    pathQ.push({0,0});

    // verify that the start and end are reachable
    if((grid[0][0] == 1) || (grid[n-1][n-1]) == 1)
      return -1;
    
    // do the bfs:
    while(!pathQ.empty()) {
      //printGrid(dist);
      
      auto p = pathQ.front();
      pathQ.pop();
      
      if((p.first == (n-1)) && (p.second == (n-1))) 
        return dist[p.first][p.second];
      
      for(int i = 0; i < 8; ++i) {
        int x = p.first + dx[i];
        int y = p.second + dy[i];
        if(isValid(x,y) && (grid[x][y] == 0))  {
          if(dist[x][y] > dist[p.first][p.second] + 1) {
            dist[x][y] = dist[p.first][p.second] + 1;
            pathQ.push({x,y});
          }
        }
      }
    }
    return -1;
  }
};
