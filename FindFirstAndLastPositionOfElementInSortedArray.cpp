class Solution {
  public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> rv(2,-1);
    if(!n)
      return rv;
    
    int left = 0, right = n - 1;
    int mid;
    while(left <= right) {
      mid = (left + right) / 2; 
      if(target == nums[mid]) {
        int lower = mid, upper = mid;
        
        // find 1st / occurrences left of me
        if((mid - 1 >= 0) && (nums[mid - 1] == target)){
          lower = mid - 1;
          while((lower - 1 >= 0) && (nums[lower-1] == target)) {
            --lower;
          }
        }
        
        // find last / occurrences right of me
        if((mid + 1 < n ) && (nums[mid + 1] == target)) { 
          upper = mid + 1;
          while((upper + 1 < n ) && (nums[upper + 1] == target )) {
             ++upper;
          }
        }
        rv[0] = lower; rv[1] = upper;
        return rv;

      }
      else if(target < nums[mid]) {
        right = mid - 1;
      }
      else // ( target > nums[mid]) {
        left = mid + 1;
    }
    return rv;
  }
};
