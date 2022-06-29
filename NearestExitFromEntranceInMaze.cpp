class Solution {
  int rows; 
  int cols;

  int dr[4] = {1,-1,0,0};
  int dc[4] = {0,0,1,-1};

  bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= rows || c >= cols)
      return false;
    return true;
  }

  void printMaze(vector<vector<char>>& M){
    cout << "--------------" << endl; 
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        cout << M[r][c] << " ";
      }
      cout << endl;
    }
  }
  public:
  // stardard maze path finding problem.  use bfs
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    rows = maze.size(); cols = maze[0].size();

    queue<pair<int,int>> q;
    q.push({entrance[0],entrance[1]});
    maze[entrance[0]][entrance[1]] = 's';

    int steps = -1;
    while(!q.empty()) {
      ++steps;
      int size = q.size();
      while(size--) {
        //printMaze(maze);
        auto cell = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
          int r = cell.first + dr[i];
          int c = cell.second + dc[i];
          if(!isValid(r,c)) { // exit found!
            if(maze[cell.first][cell.second] == 's')
              continue;
            else
              return steps; 
          }
          else if(maze[r][c] == '.') {
            maze[r][c] = '+';
            q.push({r,c});
          }
        }
      }
    }
    return -1;
  }
};
