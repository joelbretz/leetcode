class Solution {

  public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1); // length of longest increasing up to current
    for(int i = 1; i < nums.size(); ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] > nums[j]) 
          dp[i] = max(dp[i], dp[j] + 1);
        
      }
    }
    int longest = 0;
    for(auto val : dp) {
      longest = max(longest, val);
    }
    return longest;
  }
};
