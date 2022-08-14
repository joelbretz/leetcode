class Solution {
  public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

    vector<vector<int>> intervals;
    int a = 0, b = 0; // indices
    while(a < firstList.size() && b < secondList.size()) {
      // check for intersection
      int left = max(firstList[a][0], secondList[b][0]);
      int right = min(firstList[a][1], secondList[b][1]);
      
      if(left <= right)
        intervals.push_back({left,right});
      
      // remove interval with smallest right edge
      if(firstList[a][1] < secondList[b][1])
        a++;
      else 
        b++;
    }
    return intervals;
  }
};
