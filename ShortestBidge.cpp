class Solution {
  protected:
  int n;

  int dr[4] = {1,-1,0,0};
  int dc[4] = {0, 0,1,-1};

  bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= n || c >= n )
      return false;
    return true;
  }

  void dfs(vector<vector<int>>& grid, int r, int c, int islandNo) {
    if(!isValid(r,c) || grid[r][c] == islandNo || grid[r][c] == 0)
      return;
    //cout << "dfs("<<r<<","<<c << "," <<islandNo << ")" << endl;
    grid[r][c] = islandNo; // mark the island.
    // dfs on neighbors
    for(int i = 0; i < 4; ++i) {
      int r1 = r + dr[i];
      int c1 = c + dc[i];
      dfs(grid,r1,c1,islandNo);
    } 
  }

  void printGrid(vector<vector<int>>& G) {
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c) {
        cout << G[r][c] << " ";
      }
      cout << endl;
    }
  }

  public:
  int shortestBridge(vector<vector<int>>& grid) {
    n = grid.size();

    // use dfs to enumerate the second island (first one found.)
    int numIslands = 2;
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c) {
        if(grid[r][c] == 1) {
          grid[r][c] = numIslands;
          for(int i = 0; i < 4; ++i) {
            int r1 = r + dr[i];
            int c1 = c + dc[i];
            dfs(grid,r1,c1,numIslands);
          }
          numIslands++;
        }
      }
    }
    // ok the islands will be enumerated/marked with 2 or 3.

    // enqueue all of either island and then use a bfs to
    // find the min distance between them.
    //vector<vector<int>> dist(n, vector<int>(n, n*n));
    queue<pair<int,int>> cells;
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c) {
        if(grid[r][c] == 2) { 
          cells.push({r,c});
        }
      }
    }

    // ok all land from island designation #2 is enqueued, with dist = 0
    // look at the dist surrounding it and it's
    // dist is the min of it's current distance and my dist + 1
    int depth = -1;
    while(!cells.empty()) {
      ++depth;
      int size = cells.size();
      while(size--) {
        auto cell = cells.front();
        cells.pop();
        for(int i = 0; i < 4; ++i) {
          int r = cell.first + dr[i];
          int c = cell.second + dc[i];
          if(isValid(r,c)) {
            if(grid[r][c] == 0) {
              grid[r][c] = 1; // mark it as visited.
              cells.push({r,c});
            }
            else if(grid[r][c] == 3)
              return depth;
          }
        }
      }
    }
    return -1; 
  }
};
