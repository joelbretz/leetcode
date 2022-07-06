class Solution {
  public:
  // O(n) straight up use the string as a stack, then compare.
  bool backspaceCompare(string s, string t) {
    string sFinal;
    for(auto c : s) {
      if(c != '#')
        sFinal.push_back(c);
      else if(sFinal.size())
        sFinal.pop_back();
    }
    string tFinal;
    for(auto c : t) {
      if(c != '#')
        tFinal.push_back(c);
      else if(tFinal.size())
        tFinal.pop_back();
    }
    return sFinal == tFinal;

  }
};
