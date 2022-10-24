class Solution {
  public:
  // n color using  n pointers, single pass
  void sortColors(vector<int>& nums) {
    int p0 = 0; // right boundary of zeros
    int curr = 0; // current index
    int p2 = nums.size() - 1; // left index of twos

    while(curr <= p2) {
      if(nums[curr] == 0 )
        swap(nums[curr++], nums[p0++]);
      else if(nums[curr] == 2) 
        swap(nums[curr], nums[p2--]);
      else
        curr++;
    }
  }

  // version 1 -> bubble sort O n_squared
  void sortColorsBubble(vector<int>& nums) {
    int sz = nums.size();
    for(int i = 0; i < sz - 1; ++i) {
      for(int j = i + 1; j < sz; ++j) {
        if(nums[i] > nums[j])
          swap(nums[i],nums[j]);
      }
    }
    return ;
  }
};
