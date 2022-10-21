class Solution {
  public:
 // are there any duplicates <= k indices away in nums ?
  
  // use a set to determine if an element is there.
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<int> S;
    for(int i = 0; i < nums.size(); ++i ) {
      if(S.find(nums[i]) != S.end())
        return true;
      S.insert(nums[i]);
      if(S.size() > k)
        S.erase(nums[i -k]);
    }
    return false;
  }
  
  // check behind us because it's easier and more readable
  bool containsNearbyDuplicateTLE(vector<int>& nums, int k) {
    //cout << "-------" << endl;
    for(int i = 0; i < nums.size(); ++i) { // start to finish
      for(int j = max(i-k, 0); j < i ; ++j ) { // indices j to 1 place behind i
        //cout << "compare["<<i<<":"<<j<<"]" << endl; 
        if(nums[i] == nums[j])
          return true;
      }
    }
    return false;
  }
  // TLE. FUCK. mmmk 
};
