class Solution {
  int rows;
  int cols;
  
  bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= rows || c >= cols)
      return false;
    return true;
  }
  
  public:
  // Recursion
  int uniquePathsR(int m, int n) {
    if(m == 1 || n == 1 )
      return 1;
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
  }
                  
  // DP
  int uniquePaths(int m, int n) {
    rows = m; cols = n;
    // table for dp
    // pre-populate r = 0, c = 0 with 1's since there's only 1 way to get there
    vector<vector<int>> dp(m, vector<int>(n,1));
   
    // iterate over all inner cells
    for(int r = 1; r < m; ++r) {
      for(int c = 1; c < n; ++c) {
        dp[r][c] = dp[r][c-1] + dp[r-1][c];
      }
    }
    return dp[m-1][n-1];
  }
};
