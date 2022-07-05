class Solution {
  
  void backtrack(vector<vector<int>>& output, vector<int>& curr, int n, int k, int first) {
    if(curr.size() == k)
      output.push_back(curr);
    
    for(int i = first; i < n + 1; ++i) {
      curr.push_back(i);
      backtrack(output,curr,n,k,i+1);
      curr.pop_back();
    }
  }
  public:
  //
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> comboList;
    vector<int> kLengthCombo;
    backtrack(comboList, kLengthCombo, n, k, 1);
    return comboList;
    
  }
};
