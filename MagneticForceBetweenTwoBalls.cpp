class Solution {
  protected:
  inline int dist(int x, int y) const {
    return abs(x-y);
  }

  public:
  int maxDistance(vector<int>& pos, int m) {

    // need to sort the array for this approach to work
    sort(pos.begin(), pos.end());
    int n = pos.size();
    // find the initial end points
    int lo = 0, hi = pos[n-1];
    int mid, best = 0;
   
    //cout << "-----------------------" << endl; 
    // use binary search to find the gap
    while(lo <= hi) {
      // update gap (mid) based on endpoints.
      int mid = lo + (hi-lo)/2;
      //cout << "trying: " << mid << endl;
      // place 1st ball at position 0, count num balls placed
      int prev = 0; 
      int nballs = 1;
      //cout << "  placed ball at " << pos[0] <<  ", nballs = " << nballs << endl;
      // iterate over array and see if we can place at gaps of >= mid
      for(int curr = 1; curr < n && nballs < m ; ++curr) {
        // if the dist >= mid, update prev pointer and increment number of placed balls
        if(pos[curr] - pos[prev] >= mid) {
          prev = curr;
          nballs += 1;
          //cout << "  placed ball at " << pos[prev] << ", nballs = " << nballs << endl;
        }
      }
      if(nballs >= m) {
        //cout << " placed all balls. prev best = " << best << ", next best = " << mid << endl;
        // we were able to place all balls at this minimum interval
        best = mid;
        lo = mid + 1;
      }
      else {
        // we were not able to place all.  reduce interval.
        hi = mid - 1;
        //cout << " unable to place all balls.  reduced hi to " << hi << endl;
      }
    }
    return best;

  }
};
