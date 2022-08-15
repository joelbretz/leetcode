class Solution {
  public:

  vector<vector<int>> output;
  vector<int> subset;

  void subs(vector<int>& nums, int current_index) {
    // base case
    if(current_index >= nums.size()){
      output.push_back(subset);
      return;
    }

    //include it, if its safe
    subset.push_back(nums[current_index]);
    // recurse on others
    subs(nums, current_index+1);

    // backtracking
    subset.pop_back();
    subs(nums, current_index+1);
  }



  vector<vector<int>> subsets(vector<int>& nums) {
    subs(nums, 0);

    return output;
  }
};
