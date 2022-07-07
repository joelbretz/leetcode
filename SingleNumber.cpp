class Solution {
  public:
  // use bitwise xor
  int singleNumber(vector<int>& nums) {
    int val = 0;
    for(auto n : nums) 
      val ^= n;
    return val;
  } 
};
