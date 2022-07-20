class Solution {
  protected:
  int rows;
  int cols;

  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= rows || c >= cols)
      return false;
    return true;
  }

  // this is the dfs way
  void findPerimeter(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int& perimeter) {
  
    visited[r][c] = true;
    for(int u = 0; u < 4; ++u) {
      int rr = r + dr[u];
      int cc = c + dc[u];
      if(isValid(rr,cc)) { 
        if(grid[rr][cc] == 0)
          perimeter++;
        else if(!visited[rr][cc]) 
          findPerimeter(grid,visited,rr,cc, perimeter);
      }
      else {
        perimeter++;
      }
    }  
  }
  
  public:
  // DFS Solution for this problem:
  int islandPerimeterDFS(vector<vector<int>>& grid) {
    rows = grid.size();
    if(!rows)
      return 0;
    cols = grid[0].size();
 
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int p = 0;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(grid[r][c] == 1) {    
          findPerimeter(grid,visited,r,c,p);
          return p;
        }
      }
    }
    return 0;
  }
  
  int islandPerimeter(vector<vector<int>>& grid) {
    rows = grid.size();
    if(!rows)
      return 0;
    cols = grid[0].size();
    
    
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int perimeter = 0;
    
    queue<pair<int,int>> q;
    // find 1st land, bfs from there
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(grid[r][c] == 1) {
          q.push({r,c});
          visited[r][c] = true;
          break;
        }
      }
    }
    
    while(!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      //cout << "visiting " << r << "," << c << endl;
      q.pop();
      for(int i = 0; i < 4; ++i) {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if(isValid(rr,cc)) {
          if(grid[rr][cc] == 0) {
            //cout << rr <<  "," << cc << " is water" << endl; 
            perimeter++;
          }
          else if(!visited[rr][cc]) {
            //cout << "adding " << rr << "," << cc << " to queue" << endl;
            q.push({rr,cc});
            visited[rr][cc] = true;
          }
        }
        else {
         // cout << rr << "," << cc << " out of bounds" << endl;
          perimeter++;
        }
      }
    }
    
    return perimeter;
  }
  
};
