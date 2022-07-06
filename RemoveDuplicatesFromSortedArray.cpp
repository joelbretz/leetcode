class Solution {
  public:
  int removeDuplicates(vector<int>& nums) {

    int k = nums.size();
    if(k <= 1)
      return k;

    int a = 0, b = 1;
    for(; b < nums.size(); ++b ) {
      if(nums[a] != nums[b]) {
        ++a;
        nums[a] = nums[b];
      }
    }
    return a + 1;
  }
};
