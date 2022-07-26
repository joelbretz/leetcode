class Solution {

  protected:
  void backtrack(int remain, int k, vector<int>& combo, int start, vector<vector<int>>& solution ) {

    // check if we have a valid combo
    if(remain == 0 && combo.size() == k) {
      solution.push_back(combo);
      return;
    }
    // or if we busted
    else if(remain < 0 || combo.size() == k) {
      return;
    }

    // otherwise iterate through the remaining numbers
    for(int i = start; i < 9; ++i) {
      combo.push_back(i + 1);
      backtrack(remain - i - 1, k, combo, i + 1, solution);
      combo.pop_back();
    }


  }

  public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> solution; // valid combos
    vector<int> combo; // current solution we are working on

    backtrack(n,k,combo,0,solution);
    return solution;

  }
};
