class Solution {
  public:
  // back copy. single pointer
  int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for(int j = 0; j < nums.size(); ++j) {
      if(nums[j] != val) {
        nums[i] = nums[j];
        i++;
      }
    }
    return i;
  }
    // since we CAN change the order i'll swap to the end
  int removeElement2(vector<int>& nums, int val) {
    int start = 0, end = nums.size() - 1;
    while(end == val)
      --end;
    while(start <= end) {
      if(nums[start] == val) {
        swap(nums[start], nums[end]);
        start++; end--;
       }
      else {
        start++;
      }
    }
    return start ;
    
  }
};
