class Solution {
  public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // add all the numbers to hash
    unordered_map<int,int> valueToIndex;
    for(int i = 0; i < nums.size(); ++i ) {
      valueToIndex[nums[i]] = i;
    }

    // for each number, look for its mate
    int value;
    for(int i = 0; i < nums.size(); ++i) {
      value = target - nums[i];
      auto j = valueToIndex.find(value);
      if(j != valueToIndex.end() && j->second != i)
        return { i , j->second };
    }

    return {} ;
  } 
};
