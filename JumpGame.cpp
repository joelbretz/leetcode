class Solution {
  protected:
  int n ;
  public:
  bool canJump(vector<int>& nums) {
    n = nums.size();
    if(n == 1) return true;

    vector<bool> reachable(n,false);
    reachable[0] = true;

    // look at jump length for this index
    // update reachable for every index i can get to
    for(int i = 0; i < n; ++i) {
      // verify i can get to this square:
      if(!reachable[i]) 
        return false;
      // get the number of jumps i can take from here:
      int jump = nums[i];

      // mark the squares i can jump to from here
      for(int j = 1; j <= jump; ++j) {
        if(i+j >= n)
          return true;
        reachable[i+j] = true; 
      }
    }
    return reachable[n - 1];
  }
}; 
