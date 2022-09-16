  class Solution {
    protected:
    void display(vector<int>& V) {
      for(auto v : V) 
        cout << v << " ";
      cout << endl;
    }
  public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int n = l.size();
    
    if(!n) 
      return {};
    
    vector<bool> sol(n, false);
    for(int i = 0; i < n; ++i) {
      
      vector<int> curr(nums.begin() + l[i], nums.begin() + r[i] + 1);
      sort(curr.begin(), curr.end());
      int j = 1;
      int slope = curr[j] - curr[j-1];
      while(j < curr.size()) {
        if(curr[j] - curr[j-1] != slope) {
           break;
        }
        ++j;
      }
      if(j == curr.size())
        sol[i] = true;
    }
    return sol;
  }
};
