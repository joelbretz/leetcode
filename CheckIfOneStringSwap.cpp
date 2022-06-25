class Solution {
  public:
  bool areAlmostEqual(string s1, string s2) {
    vector<int> unequal; 
    for(int i = 0; i < s1.length(); ++i) {
      if(s1[i] != s2[i])
        unequal.push_back(i);
    }
    if(unequal.size() == 0)
      return true;
    else if(unequal.size() == 2) {
      swap(s2[unequal[0]], s2[unequal[1]]);
      return(s1 == s2);
    }
    return false;
  }
};
