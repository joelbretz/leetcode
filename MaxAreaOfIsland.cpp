class Solution {
public:
  
    void dfs(vector<vector<int>>& grid, int sr, int sc, int& area) {
   
      ++area;
      grid[sr][sc] = 0; 
      
      if(sr + 1 < grid.size() && grid[sr+1][sc] == 1)
        dfs(grid,sr+1,sc,area);
      if(sr - 1 >= 0 && grid[sr-1][sc] == 1)
        dfs(grid,sr-1,sc,area);
      
      if(sc + 1 < grid[0].size() && grid[sr][sc+1] == 1)
        dfs(grid,sr,sc+1,area);
      if(sc - 1 >= 0 && grid[sr][sc-1] == 1)
        dfs(grid,sr,sc-1,area);
    }
  
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int rows = grid.size();
      if(!rows) return 0;
      int cols = grid[0].size();
      
      int largest = 0; 
      
      for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
          if(grid[r][c] == 1) {
            int area = 0;
            dfs(grid,r,c,area);
            largest = max(largest, area);
          }
        }
      }
      return largest;
    }
};
