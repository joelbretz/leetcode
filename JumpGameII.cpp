class Solution {
  protected:
  int len;
  public:
  int jump(vector<int>& nums) {
    len = nums.size();
    vector<int> minJump(len, len+1); 
    minJump[0] = 0;

    // for each index, check how far i jump
    for(int i = 0; i < len; ++i) {
      int jump = nums[i];
      // mark the squares i can jump to
      for(int j = 1; j <= jump; ++j) {
        if(i + j < len)
          minJump[i+j] = min(minJump[i] + 1, minJump[i+j]);
      }
    }
    return minJump[len-1];
  }
};
