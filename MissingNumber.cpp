class Solution {
  public:
  // O(1) space, O(n) time, only 1 loop though
  // use aritmetic sum: 1+2+3+...n = n(n+1) / 2
  // then subtract numbers that are present 
  int missingNumber(vector<int>& nums) {
    int sum = (nums.size() + 1)*(nums.size() ) / 2;
    for(auto n : nums)
      sum -= n;
    return sum;
    
  }
  // o(n) time solution in time and space 
  int missingNumberSimple(vector<int>& nums) {
    vector<int> present(nums.size() + 1, 0);
    // count the elems
    for(auto n : nums) {
      present[n] += 1;
    }
    // find missing and return it
    for(int i = 0; i <= nums.size(); ++i) {
      if(present[i] == 0)
        return i;
    }
    return -1;
  }
};
