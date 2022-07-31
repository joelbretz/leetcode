class Solution {
  public:
  // 2-pointer approachle
  int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int trapped = 0;
    while(left < right) {
      int leftHeight = height[left], rightHeight = height[right];
      if(leftHeight < rightHeight) {
        if(leftHeight >= leftMax)
          leftMax = leftHeight;
        else
          trapped += leftMax - leftHeight;
        left++;
      }
      else {
        if(rightHeight > rightMax)
          rightMax = rightHeight;
        else
          trapped += rightMax - rightHeight;
        right--;
      }
    }
    return trapped;
  }
};
