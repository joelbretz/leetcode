class Solution {
  public:
  
  //dfs
  void fill(vector<vector<char>>& grid, int r, int c) {
    
    grid[r][c] = '0';
    if((r - 1 >= 0) && (grid[r-1][c] == '1'))
      fill(grid,r-1,c);
    if((r + 1 < grid.size()) && (grid[r+1][c] == '1'))
      fill(grid,r+1,c);
    if((c - 1 >= 0) && (grid[r][c-1] == '1'))
      fill(grid,r,c-1);
    if((c + 1 < grid[0].size() ) && (grid[r][c+1] == '1'))
      fill(grid,r,c+1);
  }
  
  int numIslands(vector<vector<char>>& grid) {
    auto rows = grid.size();
    if(!rows)
      return 0;
    auto cols = grid[0].size();
    
    int islands = 0;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(grid[r][c] == '1'){
          ++islands;
          fill(grid,r,c);
        }
      }
    }
    return islands;
  }
};
