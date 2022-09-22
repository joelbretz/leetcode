class Solution {
  public:
  int smallestRangeII(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // determine initial score
    int score = nums[n - 1] - nums[0];
    // scan to see if we can find a lower score
    for(int i = 0; i < n - 1; ++i) {
      int a = nums[i], b = nums[i + 1];
      int hi = max(nums[n-1] - k, a + k);
      int lo = min(nums[0] + k, b - k);
      score = min(score, hi - lo);
    }
    return score;
  }
};
