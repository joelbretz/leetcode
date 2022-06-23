class Solution {
  public:

  int climb(int start, int end, vector<int>& dp) {
    if(start > end)
      return 0;
    if(start == end) {
      return 1;
    }
    if(dp[start] > 0) {
      return dp[start];
    }
    dp[start] = climb(start + 1, end, dp) + climb(start + 2, end, dp);
    return dp[start];
  }

  int climbStairs(int n) {
    vector<int> memo(n+1, 0);

    return climb(0,n,memo);
  }
};
