class Solution {
  protected:
  int findSolution(vector<int>& coins, int remaining, vector<int>& dp) {
    if(remaining < 0)
      return -1;
    if(remaining == 0)
      return 0;
    
    if(dp[remaining - 1] != 0)
      return dp[remaining - 1];
    
    int least = INT_MAX;
    for(int c : coins) {
      int v = findSolution(coins, remaining - c, dp);
      if(v >= 0 && v < least)
        least = 1 + v;
    }
    dp[remaining - 1] = ((least == INT_MAX) ? -1 : least);
    return dp[remaining - 1];
  }
  
  public:
  int coinChange(vector<int>& coins, int amount) {
    if(amount == 0)
      return 0;
    vector<int> dp(amount, 0);
    return findSolution(coins, amount, dp);
  }
};
