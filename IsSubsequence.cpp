class Solution {
  public:

  bool isSubsequence(string s, string t) {
    // 2 pointer solution. for each char in s, it will exist
    // in t.
    int i = 0, j = 0;
    // find each char in s
    while( i < s.length() && j < t.length()) {
      if(s[i] == t[j]) {
        ++i; ++j;
      }
      else {
        ++j;
      }
    }
    
    return (i == s.length() && j <= t.length());
  }
};
