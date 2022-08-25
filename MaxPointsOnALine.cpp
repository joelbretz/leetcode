// calculate slope between all pairs of points.
// keep track of number of pairs with the same slope
class Solution {
  protected:
  double getSlope(vector<vector<int>>& points, int a, int b) {
    // slope = rise / run
    int rise = points[b][1] - points[a][1];
    int run = points[b][0] - points[a][0];
    if(run == 0) 
      return std::numeric_limits<double>::infinity();
     
    return  rise / (double) run;
  }
  
  public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    int rv = 1;
    for(int i = 0; i < n -1 ; ++i) {
      //cout << "point " << i << ": " << points[i][0] << "," << points[i][1] << endl;
      unordered_map<double,int> slopeTable; // slope(s) between point i and 
      for(int j = i + 1; j < n; ++j) {
        //cout << "  point " << j << ": " << points[j][0] << "," << points[j][1] << endl;
        double slope = getSlope(points, i, j);
        //cout << "  has slope " << slope << endl;
        slopeTable[slope] += 1;
      }
      // get the max number of point that lie on the line with points[i] 
      for(auto elem : slopeTable) 
        rv = max(rv, elem.second + 1); 
    }
    return rv;
  }
  
};
