class Solution {

  protected:
  int n ; // rows/cols
  int dr[4] = {1,-1,0,0};
  int dc[4] = {0,0,1,-1};

  int printMatrix(vector<vector<int>>& M) {
    int largest = -1; 
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c) {
        largest = max(largest, M[r][c]);
        cout << M[r][c] << " ";
      }
      cout << endl;
    }
    return largest;
  }


  // This is a dfs, except that we don't recurse unless a location is unmarked
  // or if we got there in fewer moves
  void dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c, int depth) {

    // check that r,c in bounds
    if( r < 0 || c < 0 || r >= n || c >= n)
      return;

    // check if we got to this square in fewer moves or if it's land.
    if(dp[r][c] <= depth || grid[r][c] == 1)
      return;

    dp[r][c] = depth;
    dfs(grid,dp,r+1,c,depth+1);
    dfs(grid,dp,r-1,c,depth+1);
    dfs(grid,dp,r,c+1,depth+1);
    dfs(grid,dp,r,c-1,depth+1);

  }

  public:
  // Try BFS per hint
  int maxDistance(vector<vector<int>>& grid) {
    n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n,2*n));
    queue<pair<int,int>> q;
    
    //queue all land and mark it's distance as zero
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c ) {
        if(grid[r][c] == 1) {
          q.push({r,c});
          dp[r][c] = 0;
        }
      }
    }
    
    int rv = 0;
    // visit cells.
    while(!q.empty()) {
      auto coord = q.front();
      q.pop();
      int r = coord.first;
      int c = coord.second;
      
      // go all valid directions from here.
      for(int i = 0; i < 4; ++i) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        
        if((new_r >= 0) && (new_c >= 0) && (new_r < n) && (new_c < n) && dp[new_r][new_c] == (2*n)) {
          q.push({new_r, new_c});
          dp[new_r][new_c] = dp[r][c] + 1;
          rv = max(rv,dp[new_r][new_c]);
          
        }
      }
    }
    if(rv == (2*n) || rv == 0)
      return -1;
    
    return rv;
    
  }
  
  // TLE on this. 
  int maxDistanceDFS(vector<vector<int>>& grid) {
    n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));

    // pre-initialize land squares in dp with 0 distance.
    // initialize water squares with 2*n size since the farthest
    // possible distance is 2*(n-1)
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c ) {
        if(grid[r][c] == 1)
          dp[r][c] = 0;
        else
          dp[r][c] = 2*n;
      }
    }

    // initiate a dfs on all land
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c) {
        if(grid[r][c] == 1) {
          int dist = 1;
          dfs(grid,dp,r+1,c,dist);
          dfs(grid,dp,r-1,c,dist);
          dfs(grid,dp,r,c+1,dist);
          dfs(grid,dp,r,c+1,dist);
        }
      }
    }

    int farthest = -1;
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c) {
        if(grid[r][c] == 0)
          farthest = max(farthest, dp[r][c]);
      }
    }
    if(farthest == (2*n))
      return -1;

    return farthest;
  }
};
