// [1,2,1] --> [2,-1,2]
// [1,2,3,4,3] --> [2,3,4,-1,4]

class Solution {
  public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nextGreater(n); // return value, as required 
    stack<int> stk; // stack holds the INDEX of the next greater number
    
    // loop over array twice from back to front
    for(int i = 2 * n; i >= 0; --i) {
      // pop elements off that that are less than the current val
      while(!stk.empty() && nums[stk.top()] <= nums[i % n])
        stk.pop();
      
      // if we found a greater value, save it. otherwise mark it as not having one.
      if(stk.empty())
        nextGreater[i % n] = -1;
      else
        nextGreater[i % n] = nums[stk.top()];
      // place this element on the stack
      stk.push(i % n);
    }
    return nextGreater;
  }
};
