class Solution {
  protected:
  int rows, cols;
  int dr[4] = {-1, 1,  0, 0};
  int dc[4] = {0,  0, -1, 1};
  
  void printMatrix(vector<vector<int>>& M) {
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        cout << M[r][c] << " ";
      }
      cout << endl;
    }
  }
  
  bool isValid(int r, int c) {
    if(r < 0 || r >= rows || c < 0 || c >= cols) 
      return false;
    return true;
  }
  
  int dfs(vector<vector<int>>& M, vector<vector<int>>& dp, int r, int c ) {
    // check if we have already solved this sub problem
    if(dp[r][c] != 0)
      return dp[r][c];
    
    // initiate dfs in all directions
    for(int i = 0; i < 4; ++i) {
      int rr = r + dr[i], cc = c + dc[i];
      if(isValid(rr,cc) && M[rr][cc] > M[r][c]) {
        dp[r][c] = max(dp[r][c], dfs(M, dp, rr, cc));
      }
    }
    return ++dp[r][c];
  }
  
  public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {

    rows = matrix.size(); 
    if(!rows) return 0;
    cols = matrix[0].size();
    // use dp matrix for both memoization and "visited"
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    
    int longest = 0, curr;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        curr = dfs(matrix, dp, r, c);
        longest = max(longest, curr);
      }
    }
    return longest;
  }
};
