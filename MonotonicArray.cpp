/*
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. 
An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
*/
class Solution {
  public:
  bool isMonotonic(vector<int>& nums) {
    int n = nums.size();
    if(n < 2)
      return true;
    
    // check first 2 non equal numbers for direction
    bool increasing = false;
    int i = 0;
    while(i < n - 1 && nums[i+1] == nums[i])
      ++i;
      
    if(i < n - 1 && nums[i] < nums[i+1])
      increasing = true;
      
    
    // check the rest
    for(; i < n - 1; ++i) {
      if(nums[i+1] == nums[i])
        continue;
      if(nums[i+1] > nums[i] && !increasing)
        return false;
      else if(nums[i+1] < nums[i] && increasing)
        return false;
    }
    
    return true;
      
  }
};
