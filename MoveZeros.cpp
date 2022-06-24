class Solution {
  public:
  // use a 2 pointer and basically "bubble" (swap)
  // zeros until the end
  void moveZeroes(vector<int>& nums) {
    if(nums.size() < 2)
      return;

    int a = 0, b = 1;
    while(a < nums.size() - 1) {
      if(nums[a] == 0) {
        while(nums[b] == 0 && b < nums.size()) {
          ++b;
          if(b == nums.size()) 
            return;
        }
        swap(nums[a],nums[b]);
      }
      a++; b = a + 1;
    }
  }
};
