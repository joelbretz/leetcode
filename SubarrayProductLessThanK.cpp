class Solution {
  public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k < 2)
      return 0;
    
    int product = 1, valid = 0, left = 0, right = 0;
    for(;right < nums.size(); ++right) {
      product *= nums[right];
      while(product >=k)
        product /= nums[left++];
      valid += right - left + 1;
    }
    return valid;
  }
  
  // sliding window, version 1. TLE
  int numSubarrayProductLessThanK_TLE(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int n = nums.size();
    vector<pair<int,int>> indices;
    while(left < n) {
      int product = nums[left];
      if(product < k) {
          //cout << "left=" << left << " : product=" << product << endl;
          indices.push_back({left, right});
      }
      right = left + 1;
      while(right < n) {
        product *= nums[right];
        if(product < k) {
          //cout << "left=" << left << ", right=" << right << " : product=" << product << endl;
          indices.push_back({left, right});
          right++;
        }
        else {
          break;
        }
      }
      ++left;
    }
    return indices.size();
  }

};
