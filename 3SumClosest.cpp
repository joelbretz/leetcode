class Solution {
  public:
  // Two pointers approach, still O(n^2 though)
  int threeSumClosest(vector<int>& nums, int target) {
    // this approach requires that nums be sorted
    sort(nums.begin(), nums.end());
    // save the array size for convenience
    int n = nums.size();
    // keep track of the minimum distance 
    int diff = INT_MAX;
    // loop over every element
    for(int i = 0; i < n; ++i) {
      // doing a start/end pointer search for target
      int p1 = i + 1; int p2 = n - 1;
      while(p1 < p2) {
        // find the sum
        int sum = nums[i] + nums[p1] + nums[p2];
        // calculate the difference between the target and the current sum
        int d = abs(target - sum);
        // update diff
        if( d < abs(diff)) 
          diff = target - sum;
        //cout << "[" << i << "," << p1 << "," << p2 << "]: "
        //  << "sum = " << sum << ", d = " << d << ", diff = " << diff << endl;
        if(sum < target)
          p1++;
        else
          p2--;
      }
      if(diff == 0)
        break;
    }
    return target - diff;
  }
};
