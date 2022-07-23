class MinStack {
  protected:
  stack<int> primary;
  stack<int> minStack;
  public:
  MinStack() {

  }

  void push(int val) {
    primary.push(val);
    if(minStack.empty() || val <= minStack.top())
      minStack.push(val);
  }

  void pop() {
    int val = primary.top();
    primary.pop();
    if(minStack.top() == val)
      minStack.pop();
  }

  int top() {
    return primary.top();
  }

  int getMin() {
    return minStack.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
