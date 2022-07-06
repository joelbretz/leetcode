class Solution {
  public:
  // O(n) single pass, use string as a stack
  string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
      return "";
    else if(strs.size() == 1)
      return strs[0];
    
    string lcp(strs[0]);
    // check each string
    for(int i = 1; i < strs.size(); ++i) {
     // use the end index of the shorter of the two as a place to start 
      // then check backwards;
      while(strs[i].length() < lcp.length())
        lcp.pop_back();
      for(int j = lcp.length() - 1; j >= 0; --j) {
        if(strs[i][j] != lcp[j]) {
          lcp = lcp.substr(0,j);
        }
      }
    }
    return lcp;
  }
}
