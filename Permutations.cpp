class Solution {
  public:
  void backtrack(int i, vector<int>& a, vector<vector<int>>& ans, int n){
    if(i == n){
      ans.push_back(a);
      return;
    }
    for(int j = i + 1; j < n; j++){
      swap(a[i], a[j]);
      backtrack(i + 1, a, ans, n);
      swap(a[i], a[j]);
    }
    backtrack(i + 1, a, ans, n);
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>res;
    int n = nums.size();
    backtrack(0, nums, res, n);
    return res;
  }
};
