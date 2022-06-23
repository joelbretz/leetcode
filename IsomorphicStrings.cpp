class Solution {
  public:
  bool isIsomorphic(string s, string t) {
    
    if(s.length() != t.length())
        return false;
    
    unordered_map<char,char> isomorphism;
    unordered_set<char> set0, set1;
    for(int i = 0; i < s.length(); ++i) {
      // try to insert mapping.
      set0.insert(s[i]); set1.insert(t[i]);
      auto it = isomorphism.insert({s[i],t[i]});
      if(it.second == false) {
        // insert failed. verify mapping.
        if(isomorphism[s[i]] != t[i])
          return false;
      }
    }
    return (set0.size() == set1.size());
  
  }
};
