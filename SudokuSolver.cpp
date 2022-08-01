class Solution {
 protected:
  int n;
  vector<vector<int>> rows;// (9, vector<int>(10, 0));
  vector<vector<int>> cols;// (9, vector<int>(10, 0));
  vector<vector<int>> boxes;// (9, vector<int>(10, 0));

  // note that we have value d in row, col and boxNo
  void setValue(vector<vector<char>>& board, int digit, int row, int col) {
    rows[row][digit] += 1;
    cols[col][digit] += 1;
    int boxNo = (row / 3 ) * 3 + col / 3;
    boxes[boxNo][digit] += 1;
    board[row][col] = (char) (digit + '0');
  }
  // remove value d from row, col a, and boxNo
  void clearValue(vector<vector<char>>& board, int digit, int row, int col) {
    rows[row][digit] -= 1;
    cols[col][digit] -= 1;
    int boxNo = (row / 3 ) * 3 + col / 3;
    boxes[boxNo][digit] -= 1;
    board[row][col] = '.';
  }
  // printf debugging.. 
  void printBoard(vector<vector<char>>& B) {

    for(int row = 0; row < 9; ++row) {
      for(int col = 0; col < 9; ++col) {
        cout << B[row][col] << " " ;
      }
      cout << endl;
    }
  }
 
  // number is valid if it doesn't exist in the row, col or box.
  bool isValid(int num, int row, int col) {
    
    int boxNo = (row / 3 ) * 3 + col / 3;
    if((rows[row][num]) || (cols[col][num]) || (boxes[boxNo][num]))
      return false;
    
    return true;
  }
  
  bool solve(vector<vector<char>>& board, int r, int c) {
    
    if((r == n - 1) && (c == n))
      return true;
    if(c == n) {
       c = 0; r++;
    }
    
    if(board[r][c] != '.')
      return(solve(board,r,c+1));
    
    //try to place all digits
    for(int d = 1; d < n + 1; ++d) {
      if(!isValid(d,r,c))
        continue;
      
      setValue(board,d,r,c);
      
      if(solve(board,r,c+1))
        return true;
      
      clearValue(board,d,r,c);
    }
    return false;
    
  }
  
  public:
  Solution() : n(9), 
      rows (n, vector<int>(10, 0)),  cols (n, vector<int>(10, 0)), 
      boxes (n, vector<int>(10, 0)) {

  }
  
  void solveSudoku(vector<vector<char>>& board) {

    // initialize data structures
    for(int r = 0; r < n; ++r) {
      for(int c = 0; c < n; ++c) {
        char ch = board[r][c];
        if( ch != '.') {
          int d = ch - '0';
          setValue(board,d,r,c);
        } 
      }
    }
    //printBoard(board);
    solve(board,0,0);
  }
};
