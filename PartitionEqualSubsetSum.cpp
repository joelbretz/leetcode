class Solution {
  public:
  bool canPartition(vector<int>& nums) {
   int total = accumulate(nums.begin(), nums.end(), 0);
    if(total & 0x1 == 0x1) // odd
      return false;
    
    int subtotal = total / 2;
    int n = nums.size();
    vector<vector<bool>> dp (n + 1, vector<bool>(subtotal+1, false));
    dp[0][0] = true;
    
    for(int i = 1; i <= n; ++i) {
      int curr = nums[i - 1];
      for(int j = 0; j <= subtotal; ++j) {
        if(j < curr)
          dp[i][j] = dp[i-1][j];
        else
          dp[i][j] = dp[i-1][j] || dp[i-1][j-curr];
      }
    }
    return dp[n][subtotal];
  }
};
