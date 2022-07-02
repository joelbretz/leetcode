class MyQueue {

  protected:
  stack<int> stack1;
  stack<int> stack2; 
  public:

  /* enQueue(q, x): 

While stack1 is not empty, push everything from stack1 to stack2.
Push x to stack1 (assuming size of stacks is unlimited).
Push everything back to stack1.
Here time complexity will be O(n) */
  /* deQueue(q): 

If stack1 is empty then error
Pop an item from stack1 and return it
Here time complexity will be O(1) */

  MyQueue() {

  }

  void push(int x) {
    // we are going to make enqueue more costly
    while(!stack1.empty()) {
      int n = stack1.top();
      stack1.pop();
      stack2.push(n);
    }
    stack1.push(x);
    while(!stack2.empty()) {
      int n = stack2.top();
      stack2.pop();
      stack1.push(n);
    }
  }
  void push2(int x) {
  }
  int pop() {

    if(!stack1.empty()) {
      int n = stack1.top();
      stack1.pop();
      return n;
    }
    return -1;
  }

  int peek() {
    int n = stack1.top();
    return n;
  }

  bool empty() {
    return stack1.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
