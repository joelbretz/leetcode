class Solution {
  protected:
  void backtrack(vector<int>& combo, vector<vector<int>>& solution, vector<int>& nums, int remain, int curr) {
    if(remain == 0) {
      solution.push_back(combo);
      return;
    }

    // find the next candidate to add to the possible combo
    int next = curr;
    for(;next < nums.size(); ++next) {
      // check for (multiple) duplicates and skip
      if(next > curr && nums[next] == nums[next -1 ])
        continue;

      // get the next number in candidate list
      int val = nums[next];
      // discard and stop if val > remain
      if(val > remain)
        break;

      combo.push_back(val);
      backtrack(combo, solution, nums, remain - val, next + 1);
      combo.pop_back();

    }
    return;
  }

  public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> solution;
    vector<int> combo;
    sort(candidates.begin(), candidates.end());
    backtrack(combo, solution, candidates, target, 0);
    return solution;
  }
};
