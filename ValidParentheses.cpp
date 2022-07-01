class Solution {
  public:
  bool isValid(string s) {

    unordered_map<char,char> M = {
      {')' , '(' },
      {']' , '[' },
      {'}' , '{' } };


    stack<char> S;
    for(auto c : s) {
      switch(c) {
        case '(' :
        case '{' : 
        case '[' :
          S.push(c);
          break;
        default:
          if(S.empty() || S.top() != M[c])
            return false;
          S.pop();
          break;
      }
    }
    return S.empty();
  }
};
