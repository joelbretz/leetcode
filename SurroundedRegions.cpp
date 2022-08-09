class Solution {
  protected:
  int rows;
  int cols;

  bool surrounded(vector<vector<char>> &board, int r, int c) {

    cout << "  surrounded(..., " << r << ", " << c << ")" << endl;
    // check for edge
    if(r == 0 || r == rows-1 || c == 0 || c == cols-1) {
      cout << "  board[" << r << "]["  << c << "] is an edge." << endl;
      return false;
    }

    if(board[r-1][c] == 'X' && board[r+1][c] == 'X' && 
       board[r][c-1] == 'X' && board[r][c+1] == 'X')
      return true;

    return false;
  }

  void printBoard(vector<vector<char>>& B) {
    cout << "----------------------------" << endl;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        cout << B[r][c] << " ";
      }
      cout << endl;
    }
  }

  void dfs(vector<vector<char>>& board, int r, int c) {

    if(board[r][c] != 'O') {
      return;
    }
    board[r][c] = 'E'; 

    // we got here because we are either a border cell marked 'O'
    // OR we are connected to a border cell marked 'O'

    if(r < rows - 1)
      dfs(board, r+1, c);
    if(r > 0)
      dfs(board, r-1, c);
    if(c < cols - 1) 
      dfs(board, r, c+1);
    if(c > 0) 
      dfs(board,r, c-1);

    return;
  }

  void updateFinalStates(vector<vector<char>>& board) {
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(board[r][c] == 'O')
          board[r][c] = 'X';
        if(board[r][c] == 'E')
          board[r][c] = 'O';
      }
    }
  }

  public:
  // BFS version
  void solve(vector<vector<char>>& board) {
    rows = board.size();
    if(!rows)
      return;
    cols = board[0].size();

    //printBoard(board);

    // BFS starts on edges and does the same thing
    // as DFS
    queue<pair<int,int>> q;
    for(int r = 0; r < rows; ++r) {
      q.push({r,0}); q.push({r,cols-1});
    }
    for(int c = 0; c < cols; ++c) {
      q.push({0,c}); q.push({rows-1,c});
    }
    while(!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      if(board[r][c] == 'O') {
        board[r][c] = 'E';
        if(r > 0)
          q.push({r-1,c});
        if(c > 0)
          q.push({r,c-1});
        if(r < rows - 1)
          q.push({r+1,c});
        if(c < cols - 1)
          q.push({r,c+1});
      }
    }
    //printBoard(board);
    updateFinalStates(board);
    //printBoard(board);
    
  }

  // DFS Solution:
  void solveDFS(vector<vector<char>>& board) {

    rows = board.size();
    if(!rows)
      return;
    cols = board[0].size();

    // printBoard(board);

    // dfs will start from the edges of the board
    vector<pair<int,int>> borders;
    for(int r = 0; r < rows; ++r) {
      borders.push_back({r, 0});
      borders.push_back({r, cols-1});
    }
    for(int c = 0; c < cols ; ++c) {
      borders.push_back({0, c});
      borders.push_back({rows-1, c});
    }

    // mark surrounded cells via dfs
    for(auto cell : borders) {
      dfs(board, cell.first, cell.second);
    }
    //printBoard(board);      

    // update states post dfs
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(board[r][c] == 'O')
          board[r][c] = 'X';
        if(board[r][c] == 'E')
          board[r][c] = 'O';
      }
    }
    //printBoard(board);      

    return;
  }
};
