class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
      if(n == 1 )
        return nums[0];
      else if(n == 2)
        return (max(nums[0], nums[1]));
     
      vector<int> dp ( nums.size(), 0);
      dp[0] = nums[0];
      dp[1] = nums[1];
      dp[2] = nums[2] + dp[0];
      int take = max(dp[2],dp[1]);

      for(int i = 3; i < nums.size(); ++i) {
        dp[i] = nums[i] + max(dp[i-3], dp[i-2]);
        take = max(take,dp[i]);
      }
      
      return take;
    }
};
