class Solution {
  protected:
  int rows; 
  int cols;
  
  public:
  int maximalSquare(vector<vector<char>>& matrix) {
    rows = matrix.size();
    if(!rows) return 0;
    cols = matrix[0].size();
    
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    
    int largest = 0;
    for(int r = 1; r <= rows; ++r) {
      for(int c = 1; c <= cols; ++c) {
        if(matrix[r-1][c-1] == '1') {
          dp[r][c] = min(dp[r][c-1], min(dp[r-1][c], dp[r-1][c -1])) + 1;
          largest = max(largest, dp[r][c]);
        }
      }
    }
    return largest * largest;
  }
};
