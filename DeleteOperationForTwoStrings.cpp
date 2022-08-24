class Solution {
  protected:
  int lcs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
    if(!i || !j)
      return 0;
    if(dp[i][j] != 0)
      return dp[i][j];
    
    if(s1[i-1] == s2[j-1])
      dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);
    else
      dp[i][j] = max(lcs(s1, s2, i - 1, j, dp),lcs(s1, s2, i, j - 1, dp));
    
    return dp[i][j];                 
                     
  }
  
  public:
  //dp[i][j] is used to store the result for the function call lcs(s1,s2,i,j).
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));  
    auto dist = word1.length() + word2.length() - 
      2 * lcs(word1, word2, word1.length(), word2.length(), dp);
    return dist;
  }
};
