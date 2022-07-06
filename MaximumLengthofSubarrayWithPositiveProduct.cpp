class Solution {
  public:
  int getMaxLen(vector<int>& nums) {
    int n = nums.size();
    int positiveLen = 0;   //Length of subarray with max sum
    int negativeLen = 0;   //Length of subarray with min sum
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(nums[i] == 0) {
        //if number is zero the length of req subarray whill be zero
        positiveLen = 0;
        negativeLen = 0;
      }
      else if(nums[i] > 0) {
        //if nums[i] is +ve the length of positiveLenitibe subarray will increase by 1
        //in case of negativeLen string if it is zero it will remain zero otherwise it will also increase by 1
        positiveLen += 1;
        if(negativeLen != 0) 
          negativeLen += 1;
      }
      else {
        //if nums[i] is negativeLenative the length of both string will swap
        //if negativeLen subarray length was zero the new positiveLen subarray will also have length zero 
        int temp = negativeLen;
        negativeLen = positiveLen + 1;
        if(temp == 0) 
          positiveLen = 0;
        else 
          positiveLen = temp + 1;
      }
      ans = max(ans,positiveLen);
    }
    return ans;
  }
};
