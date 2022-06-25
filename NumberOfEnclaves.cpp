class Solution {
  bool closed = true;
  int rows;
  int cols;
  int area;

  void dfs(vector<vector<int>>& grid, int r, int c)
  {
    if (grid[r][c] == 0 || grid[r][c] == 2)
      return;
    if (r + 1 >= rows || c + 1 >= cols || r - 1 < 0 || c - 1 < 0)
      closed = false;
    grid[r][c] = 2;
    area++;
    if (r + 1 < rows)
      dfs(grid, r + 1, c);
    if (c + 1 < cols)
      dfs(grid, r, c + 1);
    if (r - 1 >= 0)
      dfs(grid, r - 1, c);
    if (c - 1 >= 0)
      dfs(grid, r, c - 1);
  }
  public:
  int numEnclaves(vector<vector<int>>& grid) {
    int count = 0;
    rows = grid.size();
    cols = grid[0].size();
    area = 0;
    for (int i = 1; i < grid.size() - 1; i++) {
      for (int j = 1; j < grid[0].size() - 1; j++) {
        if (grid[i][j] == 1 ) { 
          dfs(grid, i, j);
          if (closed){
            count += area;
          }
          area = 0;
          closed = true;
        }
      }
    }
    return count;
  }
};
