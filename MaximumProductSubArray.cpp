class Solution {
  public:

  //
  int maxProduct(vector<int>& nums) {

    if(nums.size() == 1)
      return nums[0];
    
    int currMin = nums[0], currMax = nums[0];
    int maxProd = nums[0];

    for(int i = 1; i < nums.size(); ++i) {
      int curr = nums[i];
      int localMax = max(curr, max(currMin*curr, currMax*curr));
      currMin = min(curr, min(currMin*curr, currMax*curr));
      
      currMax = localMax;
      maxProd = max(maxProd,currMax);
    }
    return maxProd;
  }
};
