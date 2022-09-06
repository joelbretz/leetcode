class NumArray {
  protected:
  vector<int> sum;
  
  public:
  NumArray(vector<int>& nums) : sum(nums.size() + 1) {
    for(int i = 0; i < nums.size(); ++i)
      sum[i + 1] = sum[i] + nums[i];
  }

  int sumRange(int left, int right) {
    return sum[right + 1] - sum[left];
  }
};
