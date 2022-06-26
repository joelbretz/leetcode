class Solution {
  protected:
  int rows;
  int cols;
  
  int dr[4] = { 1, -1, 0, 0};
  int dc[4] = { 0, 0, 1, -1};
  
  void printPair(pair<int,int> & p) {
    cout << "{" << p.first <<"," << p.second <<"} ";
  }
  
  vector<vector<bool>> bfs(queue<pair<int,int>>& q, vector<vector<int>>& h) {
    vector<vector<bool>> reachable(rows, vector<bool>(cols,false));
  
     while(!q.empty()) {
       auto cell = q.front();
       q.pop();
       
       reachable[cell.first][cell.second] = true;
       for(int i = 0; i < 4; ++i) {
         int r = cell.first + dr[i];
         int c = cell.second + dc[i];
         
         // check bounds
         if(r < 0 || c < 0 || r >= rows || c >= cols)
           continue;
         // check if it's been visited
         if(reachable[r][c] == true)
           continue;
         
         // check cell height >= 
         if(h[r][c] < h[cell.first][cell.second])
           continue;
         
         q.push({r,c});
       }
     }
    return reachable;
  }
  
  public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    rows = heights.size();
    cols = heights[0].size();

    //vector<vector<int>>& heights
    // from any square ocean can you get to the other ocean? 
    //start (r < 0) || (c < 0) finish at r >= rows || c >= cols
    // you can only move to a square if it's height <= mine.
    
    // first populate the queues with squares adjacent to oceans
    queue<pair<int,int>> pacificQ;
    queue<pair<int,int>> atlanticQ;
     for(int r = 0; r < rows; ++r) {
       pacificQ.push({r,0});
       atlanticQ.push({r,cols-1});
     }
    for(int c = 0; c < cols; ++c) {
      pacificQ.push({0,c});
      atlanticQ.push({rows-1,c});
    }
    //for_each(pacificQ.begin(), pacificQ.end(), printPair); cout << endl;
    //for_each(atlanticQ.begin(), atlanticQ.end(), printPair); cout << endl;
   
    // use bfs to determine if adjacents are reachable
    vector<vector<bool>> pacificReachable = bfs(pacificQ, heights);
    vector<vector<bool>> atlanticReachable = bfs(atlanticQ, heights);
    
    // cells where both are reachable are peaks.
    vector<vector<int>> peaks;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(pacificReachable[r][c] && atlanticReachable[r][c] )
          peaks.push_back({r,c});
      }
    }
    
    return peaks;
  }
};
