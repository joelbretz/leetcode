class Solution {
  public:
  bool validateRow(vector<vector<char>>& board, int r) {
    // check for no repeats
    unordered_set<char> S;
    for(int c = 0; c < board[0].size(); ++c) {
      if(board[r][c] == '.')
        continue;
      auto it = S.insert(board[r][c]);
      if(it.second == false)
        return false;
    }
    return true;
  }

  bool validateColumn(vector<vector<char>>& board, int c)  {
    unordered_set<char> S;
    for(int r = 0; r < board.size(); ++r) {
      if(board[r][c] == '.')
        continue;
      auto it = S.insert(board[r][c]);
      if(it.second == false)
        return false;
    }
    return true;
  }
 
  bool validateSubBox(vector<vector<char>>& board, int r, int c) {
    
    unordered_set<char> S;
    for(int i = r; i < r + 3; ++i) {
      for(int j = c; j < c + 3; ++j) {
        if(board[i][j] == '.')
          continue;
        auto it = S.insert(board[i][j]);
        if(it.second == false)
          return false;
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < board.size(); ++i) {
      bool valid = validateRow(board,i);
      //cout << "row " << i << " , valid = " << valid << endl;
      if(!valid)
        return false;
    }
    for(int i = 0; i < board[0].size(); ++i) {
      bool valid = validateColumn(board, i);
      //cout << "col " << i << " , valid = " << valid << endl;
      if(!valid)
        return false;
    }
    for(int r = 0; r < 9; r += 3) {
      for(int c = 0; c < 9; c+= 3) {
        bool valid = validateSubBox(board,r,c);
        if(!valid)
          return false;
      }
    }
    return true;
  }
};
