class Solution {
  protected:
  int rows; int cols;

  void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, int& flag) {

    // set this square to checked
    grid2[r][c] = 2;

    // make sure im a subisland
    if(grid1[r][c] == 1) 
      grid2[r][c] = 3;
    else
      flag = 0;

    if((r-1 >= 0) && (grid2[r-1][c] == 1))
      dfs(grid1,grid2,r-1,c,flag);

    if((r + 1 < rows) && (grid2[r+1][c] == 1))
      dfs(grid1,grid2,r+1,c,flag);

    if((c-1 >= 0) && (grid2[r][c-1] == 1))
      dfs(grid1,grid2,r,c-1,flag);

    if((c + 1 < cols) && (grid2[r][c+1] == 1))
      dfs(grid1,grid2,r,c+1,flag);

  }

  void printMatrix(vector<vector<int>>& grid) {
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        cout << grid[r][c] << " ";
      }
      cout << endl;
    }
  }

  public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    rows = grid1.size();
    cols = grid1[0].size();
    int count = 0;

    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        int flag = 1;
        if(grid2[r][c] == 1) { 
          dfs(grid1,grid2,r,c,flag);
          if(flag) {
            //cout << "flag at " << r << ", " << c << endl; 
            count++;
          }
        }
      }
    }
    //printMatrix(grid1);
    //cout << "-----------------" << endl;
    //printMatrix(grid2);
    return count;
  }
};
