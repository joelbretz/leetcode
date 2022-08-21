class Solution {
  protected:
  void backtrack(vector<int>& curr, int n, map<int,int>& counter, vector<vector<int>>& permutations) {
    if(curr.size() == n) {
      permutations.push_back(curr);
      return;
    }
   
    for(auto val : counter) {
      int num = val.first;
      int count = val.second;
      if(!count)
        continue;
      
      curr.push_back(num);
      counter[num]--;
      
      backtrack(curr, n, counter, permutations);
      
      curr.pop_back();
      counter[num] = count;
    }
  }
  
  public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> permutations;
    vector<int> current;
   
    // count number of occurences of each number
    map<int,int> counter;
    for(int n : nums) {
      counter[n]++;
    }
    
    backtrack(current, nums.size(), counter, permutations);
    return permutations;
  }
};
