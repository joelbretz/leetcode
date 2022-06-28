class Solution {
  protected:
  int rows;
  int cols;
  int dr[4] = { 1, -1, 0, 0};
  int dc[4] = { 0, 0, 1, -1}; 

  bool isValid(int r, int c) {
    if( r < 0 || c < 0 || r >= rows || c >= cols )
      return false;
    return true;
  }

  public:
  // bfs solution b/c i need to practice it. 
  // will have to come back for a dp solution. :)
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    rows = mat.size();
    cols = mat[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, rows*cols));

    queue<pair<int,int>> q;

    // initialize distance matrix for water and
    // put all water in the q
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(mat[r][c] == 0) {
          dist[r][c] = 0;
          q.push({r,c});
        }
      }
    }

    // bfs:
    while(!q.empty()) {
      auto cell = q.front();
      q.pop();
      // update neighbors and add them to the queue  
      for(int i = 0; i < 4; ++i) {
        int r = cell.first + dr[i];
        int c = cell.second + dc[i];
        if(isValid(r,c)) {
          if(dist[r][c] > dist[cell.first][cell.second] + 1) {
            dist[r][c] = dist[cell.first][cell.second] + 1;
            q.push({r,c});
          }
        }
      }
    }
    return dist;
  }
};
