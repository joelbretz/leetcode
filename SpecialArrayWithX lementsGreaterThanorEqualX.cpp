class Solution {
  public:
  int specialArray(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int left = 0, right = nums.size();
    while(left <= right){
      int mid = left + (right-left)/2;
      int c = 0;
      for(auto n : nums){
        if(n >= mid)
          c++;
      }

      if(mid == c)
        return mid ;
      else if(mid < c)
        left = mid + 1;
      else
        right = mid - 1;

    }
    return -1;
  }
};
