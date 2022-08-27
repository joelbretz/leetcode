class Solution {
  public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    // assume that we never want a empty bag
    int lo = 1;
    // find the bag with the largest number of balls
    int hi = *max_element(nums.begin(), nums.end());
    // bsearch to determine the minu
    while(lo <= hi) {
      int mid = lo + (hi-lo)/2;
      // determine the count of operations required for this limit
      int cnt = 0;
      for(auto i : nums)
        cnt += (ceil(double(i)/double(mid)) - 1);
      
      // update endpoints
      if(cnt > maxOperations) 
        lo = mid + 1;
      else 
        hi = mid - 1;
    }
    return lo;
  }
};
