class Solution {
  protected:
  int findDistance(vector<int>& points, int origin = 0) {
    int d = 0;
    for(auto p : points) 
      d += abs(p - origin);
   return d;
  }
  
  vector<int> collectRows(vector<vector<int>>& grid) {
    vector<int> rows;
    for(int r = 0; r < grid.size(); ++r) {
      for(int c = 0; c < grid[r].size(); ++c) {
        if(grid[r][c] == 1)
          rows.push_back(r);
      }
    }
    return rows;
  }
  
  vector<int> collectCols(vector<vector<int>>& grid) {
    vector<int> cols;
    for(int c = 0; c < grid[0].size(); ++c) {
      for(int r = 0; r < grid.size(); ++r) {
        if(grid[r][c] == 1)
          cols.push_back(c);
      }
    }
    return cols;
  }
  
  public:
  int minTotalDistance(vector<vector<int>>& grid) {
    auto rows = collectRows(grid);
    auto cols = collectCols(grid);
    
    int row = rows[rows.size() / 2];
    int col = cols[cols.size() / 2];
    int d = findDistance(rows, row) + findDistance(cols, col);
    return d;
  }
};
