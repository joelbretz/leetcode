class Solution {
  public:
  // a less than or equal to b less than or ..  c
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    // after sorting start with largest values for c (i+2)
    for(int i = nums.size() - 3; i >= 0; --i) {
      if(nums[i] + nums[i+1] > nums[i+2])
        return nums[i] + nums[i+1] + nums[i+2];
    }
    return 0;
  }
};
