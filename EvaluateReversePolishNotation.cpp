class Solution {
  protected:
  void getArgs(stack<int>& S, int& a, int &b) {   
    b = S.top();
    S.pop();
    a = S.top();
    S.pop();
  }
  
  public:
  int evalRPN(vector<string>& tokens) {

    stack<int> stk;
    int a,b;
    for(auto token : tokens) { 
      if(token == "+") {
        getArgs(stk,a,b);
        stk.push(a + b);
      }
      else if(token == "-") {
        getArgs(stk,a,b);
        stk.push(a - b);
      }
      else if(token == "/") {
        getArgs(stk,a,b);
        stk.push(a / b);
      }
      else if(token == "*") {
        getArgs(stk,a,b);
        stk.push(a * b);
      }
      else
        stk.push(atoi(token.c_str()));

    }
    return (int) stk.top();  
  }
};
