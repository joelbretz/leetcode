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
  
  public:
  
  // ok, ima do a bfs on rotten oranges and keep track of how 
  // man steps/depth before it exits.
  // ill count fresh oranges when i enqueue rotten ones
  // and check there's no fresh before bailing.
  int orangesRotting(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();

    // enqueue all the rotten fuckers.
    // count the freshies
    queue<pair<int,int>> q;
    int fresh = 0;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(grid[r][c] == 2) {
          q.push({r,c});
        }
        else if(grid[r][c] == 1)
          ++fresh;
      }
    }
    if(!fresh)
      return 0;

    int dist = -1;
    while(!q.empty()) {
      ++dist;
      int size = q.size(); 
      while(size--) {
        auto rot = q.front();
        q.pop();

        for(auto i = 0; i < 4; ++i) {
          int r = rot.first + dr[i];
          int c = rot.second + dc[i];
          if(isValid(r,c) && grid[r][c] == 1) {
            --fresh;
            grid[r][c] = 2;
            q.push({r,c});
          }
        }
      }
    }
    if(!fresh)
      return dist;
    return -1;
  }
};
