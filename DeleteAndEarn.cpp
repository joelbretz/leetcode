class Solution {
  protected:
  unordered_map<int,int> points;
  unordered_map<int,int> cache;

  /// return the max points we can gain if
  /// we only consider 0 to num
  int maxPointsR(int n) {
    if(n == 0)
      return 0;

    if(n == 1) {
      return points[1]; // if this doesn't exist it'll get created
    }

    //Otherwise, check if n is already in cache. If it is, 
    // just return cached value
    auto it = cache.find(n);
    if(it != cache.end()) {
      return it->second;
    }

    // n not in cache 
    auto val = max(maxPointsR(n - 1), maxPointsR(n - 2) + points[n]);
    cache[n] = val;
    return val;
  }

  public:
  int deleteAndEarn(vector<int>& nums) {

    int maxNo = 0; // maximum number
    // create hash map & find maximum number
    for(auto n : nums) {
      points[n] += n;
      maxNo = max(maxNo, n);
    }

    //top down / recursive version
    //return maxPointsR(maxNo);
    
    vector<int> maxPoints(maxNo + 1, 0);
    maxPoints[1] = points[1];
    
    for(int i = 2; i <= maxNo; ++i) {
      maxPoints[i] = max(maxPoints[i-1],maxPoints[i-2] + points[i]);
    }
    return maxPoints[maxNo];
  }
};
