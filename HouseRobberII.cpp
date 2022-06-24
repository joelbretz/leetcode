class Solution {
  public:

  //  [ 7 4 1 9 3 6 5] 
  // either max obtained from [ 4 1 9 3 6 5 ] : indices [1 : len-1 ]
  // or max obtrained from   [7 4 1 9 3 6]    : indices [0 : len-2]
  
  int rob_help(vector<int>& nums, int lo, int hi) {
    
    int u = 0, v = 0;
    for(int i = lo; i <= hi; ++i) {
      int temp = u;
      int curr = nums[i];
      u = max(curr + v, u);
      v = temp;
    }
    
    return u;
  }
  
  
  int rob(vector<int>& nums) {
    int n = nums.size();  
    if(n == 0)
      return 0;

    if(n == 1)
      return nums[0];

    auto group0 = rob_help(nums, 0, n-2);
    auto group1 = rob_help(nums, 1, n-1);

    return max(group0, group1);
  }
};
