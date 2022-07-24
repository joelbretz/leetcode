class Solution {
  public:
  int calculate(string s) {
    int len = s.length();
    if(len==0)
      return 0;
    stack<int> stk;
    int n = 0;
    char op = '+';
    for(int i = 0; i < len; ++i) {
      char c = s[i];
      if(isdigit(c))
        n = (n * 10) + (c - '0');
      if(!isdigit(c) && !iswspace(c) || i == len-1) {
        if(op == '+')
          stk.push(n);
        else if(op == '-')
          stk.push(-n);
        else if(op == '*') {
          int x = stk.top();
          stk.pop();
          stk.push(x * n);
        }
        else if(op == '/') {
          int x = stk.top();
          stk.pop();
          stk.push(x / n);
        }
        op = c;
        n = 0;
      }
    }
    int output = 0;
    while(!stk.empty()) {
      output += stk.top();
      stk.pop();
    }
    return output;
  }
};
