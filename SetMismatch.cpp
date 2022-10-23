class Solution {
  public:
  vector<int> findErrorNums(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int dupe = -1, missing = 1;
    for(int i = 1 ; i < nums.size(); ++i) {
      if(nums[i] == nums[i - 1])
        dupe = nums[i];
      else if(nums[i] > nums[i - 1] + 1)
        missing = nums[i - 1] + 1;
    }
    vector<int> result;
    result.push_back(dupe);
    if(nums[nums.size() - 1] != nums.size())
      result.push_back(nums.size());
    else
      result.push_back(missing);
    return result;

  }
};
