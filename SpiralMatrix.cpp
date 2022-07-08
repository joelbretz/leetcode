class Solution {

  public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // current boundaries
    int up = 0, left = 0, right = cols - 1, down = rows - 1;

    vector<int> spiral;
    while(spiral.size() < rows * cols) {
      // move right
      for(int col = left; col <= right; ++col)
        spiral.push_back(matrix[up][col]);

      // move down
      for(int row = up + 1; row <= down; ++row) 
        spiral.push_back(matrix[row][right]);

      // check row index, then move left
      if(up != down)
        for(int col = right - 1; col >= left; --col)
          spiral.push_back(matrix[down][col]);

      // check col, then move up
      if(left != right)
        for(int row = down - 1; row > up; --row)
          spiral.push_back(matrix[row][left]);

      right--; down--; left++; up++;
    }
    return spiral;
  }
};
