class Solution {
  int rows;
  int cols;
  protected:

  bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= rows || c >= cols)
      return false;
    return true;
  }

  bool dfs(vector<vector<char>>& board, string word, int r, int c, int pos) {

    if(pos == (word.length() - 1) && (board[r][c] == word[pos]))
      return true;

    if(board[r][c] != word[pos]) {
      return false;
    }

    char temp = board[r][c];
    board[r][c] = '?';
    bool found = false;
    if(r > 0)
      found |= dfs(board, word, r-1, c, pos+1);
    if(c > 0)
      found |= dfs(board, word, r, c-1, pos+1);
    if(r + 1 < rows)
      found |= dfs(board, word, r+1, c, pos+1);
    if(c + 1 < cols)
      found |= dfs(board, word, r, c+1, pos+1);

    board[r][c] = temp;
    return found;
  }

  public:
  bool exist(vector<vector<char>>& board, string word) {
    rows = board.size();
    cols = board[0].size();

    // find the first letter, then dfs from there.
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(board[r][c] == word[0] && dfs(board, word, r, c, 0))
          return true;
      }
    }
    return false;                
  }
};
