class Solution {
  public:
  int numberOfArithmeticSlices(vector<int>& nums) {
   
    vector<int> dp(nums.size(), 0); // longest run from index
    int slices = 0; // number of slices
    // start at index 2 and look back
    for(int i = 2; i < nums.size(); ++i) {
      if(nums[i] - nums[i-1] == nums[i - 1] - nums[i - 2]) {
        dp[i] = 1 + dp[i - 1];
        slices += dp[i];
      }
    }
    return slices;
  }
};
