class Solution {
  protected:
  void backtrack(vector<int>& nums, vector<int>& combo, vector<vector<int>>& solution, int pos) {
    if(pos == nums.size())
      return;
    
    for(int i = pos; i < nums.size(); ++i) {
      // this weird looking test is how we avoid dups
      if(i > pos && nums[i] == nums[i-1])
        continue;
      
      combo.push_back(nums[i]);
      solution.push_back(combo);
      backtrack(nums,combo,solution,i + 1);
      combo.pop_back();
    }
  }
  
  
  public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> solution;
    vector<int> combo;
    solution.push_back(combo);
    sort(nums.begin(), nums.end());
    backtrack(nums, combo, solution, 0);
    return solution;
  }
};
