class Solution {
  public:
  int longestValidParentheses(string s) {
    int longest = 0;
    stack<int> stk; // indices of parens
    stk.push(-1); // place holder
    for(int i = 0; i < s.length(); ++i) {
      if(s[i] == '(') {
        stk.push(i);
      }
      else {
        stk.pop();
        if(stk.empty()) {
          stk.push(i);
        }
        else {
          longest = max(longest, i - stk.top());
        }
      }
    }
    return longest;
  }
};
