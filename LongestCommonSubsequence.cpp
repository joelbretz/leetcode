class Solution {
  public:
  int longestCommonSubsequence(string text1, string text2) {

    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    for(int c = text2.length() - 1; c >= 0; --c) {
      for(int r = text1.length() - 1; r >= 0; --r) {
        if(text1[r] == text2[c])
          dp[r][c] = 1 + dp[r + 1][c + 1];
        else
          dp[r][c] = max(dp[r+1][c], dp[r][c+1]);
      }
    }
    return dp[0][0];
  }
};
