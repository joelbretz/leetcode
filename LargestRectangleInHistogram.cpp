class Solution {
  public: 
  int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    stk.push(-1);
    int maxArea = 0;
    
    for(int i = 0; i < heights.size(); ++i) {
      while(stk.top() != -1 && heights[stk.top()] >= heights[i]) {
        int height = heights[stk.top()];
        stk.pop();
        int width = i - stk.top() - 1;
        maxArea = max(maxArea, height*width);
      }
      stk.push(i);
    }
    while(stk.top() != -1) {
      int height = heights[stk.top()];
      stk.pop();
      int width = heights.size() - stk.top() - 1;
      maxArea = max(maxArea, height*width);
    }
    return maxArea;
  }
};


// This gets 90+ % of the way there. 
class Solution1 {
  protected:
  // calculate the max area in the current stack 
  int stackMax(stack<int>& stk) {
    int maxArea = 0;
    int stackMin = INT_MAX, width = 0;
    
    while(!stk.empty()) {
      int top = stk.top();
      stk.pop();
      stackMin = min(stackMin, top);
      width++;
      maxArea = max(maxArea, stackMin * width);
    }   
    return maxArea;
  }
  
  public:
  // monotomically increasing stack, classic problm
  int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int area, maxArea;
    if(std::count(heights.begin(), heights.end(), 0)) 
       maxArea = 0; 
    else 
      maxArea = heights.size(); // * 1
    int localmin = INT_MAX, width = 0;
    //cout << "-------------------" << endl; 
    for(int i = 0; i < heights.size(); ++i) {
      // maintain increasing stack
      if(stk.empty() || heights[i] >= stk.top()) {
        stk.push(heights[i]);
        //cout << "pushed " << heights[i] << endl;
      }
      else {
        maxArea = max(maxArea, stackMax(stk));
      }
    }
    if(!stk.empty())
      maxArea = max(maxArea, stackMax(stk));
    
    return maxArea;
  }
};
