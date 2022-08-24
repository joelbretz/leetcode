class Solution {
  public:
  int findNumberOfLIS(vector<int>& nums) {
    // length of longest increasing up to current , count of sequences with current as end
    vector<pair<int,int>> dp(nums.size(), {1,1}); 
    int lis = 1; // longest increasing subsequence
    for(int i = 1; i < nums.size(); ++i) {
      //cout << "i = " << i << endl;
      for(int j = i - 1; j >= 0; --j) {
        //cout << " j = " << j << endl;
        if(nums[i] > nums[j])  {
          //cout << "  " << nums[i] << " > " << nums[j] << endl;
          //  dp[i] = max(dp[i], dp[j] + 1);
          if(dp[i].first < dp[j].first + 1 ) {
            //cout << "   lis of " << i << " < lis of " << j + 1 << endl;
            //cout << "    update lis of " << i << endl;
            dp[i].first = dp[j].first + 1;
            //cout << "    update count of sequences for " << i << " to "  << dp[j].first + 1 << endl;
            dp[i].second = dp[j].second;
          }
          else if(dp[i].first == dp[j].first + 1) {
            //cout << "   lis of " << i << " == lis of " << j + 1 << endl;
            //cout << "    increment count of sequences for " << i << " by " << dp[j].second << endl;
            dp[i].second += dp[j].second;
          }
        }
      }
      lis = max(lis, dp[i].first);
      //cout << "lis = " << lis << endl;
    }
    
    // find the number of sequences with length = lis
    int rv = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(dp[i].first == lis) 
        rv += dp[i].second;
    }
    return rv;
  }
};
