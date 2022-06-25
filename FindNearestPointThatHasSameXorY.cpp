class Solution {
  public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

    int index = -1;
    int minDistance = INT_MAX;

    for(int p = 0; p < points.size(); ++p) { 
        if((points[p][0] == x) || (points[p][1] == y)) {
          int d = abs(points[p][0] - x) + abs(points[p][1] - y);
          if(d < minDistance) {
            index = p;
            minDistance = d;
          }
        }
      }
    return index;
  }
};
