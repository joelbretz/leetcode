class Solution {
  protected:
  int rows, cols;
  int dr[4] = { -1, 1, 0, 0 };
  int dc[4] = { 0, 0, -1, 1 };
  
  inline bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= rows || c >= cols)
      return false;
    return true;
  }

  void dfs(vector<vector<char>>& pic, int r, int c, int& lonely) {
    
  }
  
  void printMatrix(vector<vector<char>>& M) {
    cout << "---" << endl;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        cout << M[r][c] << " ";
      }
      cout << endl;
    }
  }
  
  public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    rows = picture.size(); 
    cols = picture[0].size();
    int lonely = 0;
    
    vector<int> rowCount(rows, 0);
    vector<int> colCount(cols, 0);
    
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
       // printMatrix(picture);
        if(picture[r][c] == 'B') {
          rowCount[r]++; colCount[c]++;
        }
      }
    }
    
    // lonely cells are black with a 1 for rowCount and colCount
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(picture[r][c] == 'B' && rowCount[r] == 1 && colCount[c] == 1)
          lonely++;
      }
    }
    return lonely;  
  }
};
