class Solution {
  public:
  // use hash.  O(n) time and space. 
  int majorityElement(vector<int>& nums) {
    unordered_map<int,int> elems;
    pair<int,int> majority = { -1, -1 };
    for(auto n : nums) {
      elems[n]++;
      if(elems[n] > majority.second) {
        majority.first = n;
        majority.second = elems[n];
      }
    }
    return majority.first;
  }
};
