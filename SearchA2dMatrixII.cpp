class Solution {
  public:
  int rows, cols;
  
  void printMatrix(vector<vector<int>>& matrix) {
    for(int r = 0; r < cols; ++r) {
      for(int c = 0; c < rows; ++c) {
        cout << matrix[r][c] << " ";
      }
    }
    cout << endl;
  }
  
  // row min, col min, row max, col max
  bool splitMatrix(vector<vector<int>>& M, int target, int left, int up, int right, int down) {
    // check that it's valid
    if(left > right || up > down)  // boundary check
      return false;
    else if(target < M[up][left] || target > M[down][right]) // target not in this submatrix 
      return false;
    
    // find the middle col
    int mid = left + (right - left)/2;
    
    //
    int row = up;
    while(row <= down && M[row][mid] <= target) {
      if(M[row][mid] == target)
        return true;
      ++row;
    }
    return splitMatrix(M, target, left, row, mid - 1, down) || splitMatrix(M, target, mid + 1, up, right, row - 1);
  }
  
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    rows = matrix.size(); 
    if(!rows) return false;
    cols = matrix[0].size();
    //printMatrix(matrix);
    
    bool found = splitMatrix(matrix, target, 0, 0, cols - 1, rows - 1);
    
    return found;
  }
};

class SolutionSearch2d {
  public:
  // first idea: do row[0] bsearch, then a bsearch that column
  // works for martices increasing down each column and matrix[0][col + 1] > matrix[rows - 1][col];
  // which isn't this problem. :)
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int lo = 0, hi = cols - 1, row, col;
    // find the column by bsearch row:
    while(lo <= hi) {
      col = lo + (hi - lo) / 2;
      if(matrix[0][col] == target)
        return true;
      else if(matrix[0][col] < target)
        lo = col + 1;
      else
        hi = col - 1;
    }
    cout << "lo = " << lo << ", hi = " << hi << ", col = " << col << endl;

    // now find target:
    lo = 0, hi = rows - 1;
    while(lo <= hi) {
      row = lo + (hi - lo) / 2; 
      if(matrix[row][col] == target)
        return true;
      else if(matrix[row][col] < target)
        lo = row + 1;
      else
        hi = row - 1;
    }
    return false;
  }
};
