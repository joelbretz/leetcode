

class Solution {
  public:
  // O(n^2) Brute force. expect TLE
  int maxAreaBF(vector<int>& height) {
    int area = 0;
    for(int i = 0; i < height.size() - 1; ++i)
      for(int j = i + 1; j < height.size(); ++j) {
        area = max(area, (j-i) * min(height[i],height[j]));
      }
    return area;
  }
  
  // two pointers.  move the shorter of the 2 inwards.
  int maxArea(vector<int>& height) {
    int area = 0;
    int start = 0, end = height.size() - 1;
    
    while(start < end) {
      int currArea = (end-start) * min(height[start], height[end]);
      //cout << "[" << start << "," << end << "] = " << currArea << endl;
      area = max(area, currArea);
      
      if(height[start] <= height[end])
        start++;
      else
        end--;
    }
    return area;
  }
};
