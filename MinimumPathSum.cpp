class Solution {
  protected:
  int rows; 
  int cols;
  
  void dfs(vector<vector<int>>& grid, int r, int c, int cur, int& minsum) {
    if((r >= rows) || (c >= cols))
      return;
    cur += grid[r][c];
    
    if((r == rows - 1) && (c == cols - 1)) {
      minsum = min(cur, minsum);
    }
    else {
      dfs(grid, r + 1, c, cur, minsum);
      dfs(grid, r, c + 1, cur, minsum);
    }
    
  }
  
  public:
  int minPathSumBF(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    
    int cur = 0; //grid[0][0];
    int sum = INT_MAX;
    dfs(grid,0,0,cur,sum);
    return sum;
  }
  
  // use DP, start from the bottom right and move to the top left
  int minPathSum(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
    for(int r = rows - 1; r >= 0; --r) {
      for(int c = cols - 1; c >= 0; --c) {
        // on a bottom edge
        if(r == rows - 1 && c != cols - 1)
          dp[r][c] = grid[r][c] + dp[r][c + 1];
        // on a right edge
        else if(r != rows - 1 && c == cols - 1)
          dp[r][c] = grid[r][c] + dp[r + 1][c];
        // no edge
        else if( r != rows - 1 && c != cols - 1)
          dp[r][c] = grid[r][c] +min(dp[r + 1][c], dp[r][c + 1]);
        else
          dp[r][c] = grid[r][c];
      }
    }
    return dp[0][0];
  }
};
