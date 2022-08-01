class Solution {
  protected:
  int rows;
  int cols;

  public:
  void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.empty())
      return;
    rows = matrix.size(); cols = matrix[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols,false));
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(visited[r][c])
          continue;
        
        visited[r][c] = true;
        if(matrix[r][c] == 0) {
          // mark this row and column
          for(int cc = 0; cc < cols; ++cc) {
            if(matrix[r][cc] != 0) {
              matrix[r][cc] = 0;
              visited[r][cc] = true;
            }
          }
          for(int rr = 0; rr < rows; ++rr) {
            if(matrix[rr][c] != 0) {
              matrix[rr][c] = 0;
              visited[rr][c] = true;
            }
          }
        }
      }
    }
  }
};
