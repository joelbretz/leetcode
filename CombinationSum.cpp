class Solution {
  protected:
  void backtrack(int remain, vector<int>& candidates, vector<int>& combo, vector<vector<int>>& solution) {
    
    // check if we're done
    if(remain == 0) {
      solution.push_back(combo);
    }
    // of if we busted
    else if(remain < 0) {
      return;
    }
    
    // otherwise try all candidates
    for(auto n : candidates) {
      if(combo.size() > 0 && n < combo.back())
        continue;
      combo.push_back(n);
      backtrack(remain - n, candidates, combo, solution);
      combo.pop_back();
    }
  }
  
  public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> solution; // all valid
    vector<int> combo; // current solution we are building

    backtrack(target, candidates, combo, solution);
    return solution;
  }
};
