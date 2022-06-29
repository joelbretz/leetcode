
class Solution {
  public:

  // kadane's algorithm:
  int maxSubArray(vector<int>& nums) {
    int curr = nums[0];
    int sum = nums[0];
    for(int i  = 1; i < nums.size(); ++i) {
      auto n = nums[i];
      curr = max(n, curr + n);
      sum = max(sum,curr);
    }
    return sum;
  }

  // Plan: Use Kadane.
  // find maxSubArray sum and find max sum of circular array.
  // return which ever is larger
  int maxSubarraySumCircular(vector<int>& nums) {

    int maxSubArraySum = maxSubArray(nums);
    if( maxSubArraySum < 0)
      return maxSubArraySum;

    int arrSum = 0;
    for(int i = 0; i < nums.size(); ++i){
      arrSum += nums[i];
      nums[i] *= -1;
    }

    // sum of array - largest negative subarray sum 
    //   ( ssuming there are negative elements at all)
    int circularSum = maxSubArray(nums) + arrSum ;
    return max(circularSum, maxSubArraySum);

  }
};
