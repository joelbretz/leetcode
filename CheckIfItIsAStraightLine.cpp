class Solution {

  public:
  // obv brute force soln
  bool checkStraightLineBruteF(vector<vector<int>>& coordinates) {
    int len = coordinates.size();
    if(len < 2) 
      return false;
    else if(len == 2 )
      return true;

    // [[x,y] [x y] [x y]]
    int dy = coordinates[1][1] - coordinates[0][1]; //dy / dx
    int dx = coordinates[1][0] - coordinates[0][0];
    float slope = dy / (float) dx;
    //cout << "initial slope = " << slope << endl;
    for(int i = 2; i < len; ++i) {
      dy = coordinates[i][1] - coordinates[i-1][1]; //dy / dx
      dx = coordinates[i][0] - coordinates[i-1][0];
      if( (dy/(float)dx) != slope)
        return false;
    }
    return true;
  }
  
  bool checkStraightLine(vector<vector<int>>& c) 
			{
				int len = c.size();
				int dx = (c[1][0]-c[0][0]);
				int dy = (c[1][1]-c[0][1]);
				for(int i = 2; i < len; ++i)
				{
          // current dx * dy == curr dy * dx
          if( (c[i][0]-c[i-1][0])*dy !=  (c[i][1]-c[i-1][1])*dx)
            return false;
				}
				return true;
			}
  
};
