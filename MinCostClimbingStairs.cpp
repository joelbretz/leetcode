class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
     
      vector<int> dp(cost.size() + 1, INT_MAX);
      dp[0] = 0;
      dp[1] = min(dp[0], cost[0]);
      int step = 2;
      while(step <= cost.size()) {
        dp[step] = min(dp[step-1] + cost[step - 1], dp[step-2] + cost[step - 2]);
        ++step;
      }
      return dp[cost.size()];
      
    }
};
