class Solution {
  protected:
  
  void printMatrix(vector<vector<int>>& M) {
    for(int i = 0; i < M.size(); ++i) {
      for(int j = 0; j < M[i].size(); ++j) {
        cout << M[i][j] << " ";
      }
      cout << endl;
    }
  }
  
  void transpose(vector<vector<int>>& M) {
    int n = M.size();
    for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
        int tmp = M[j][i];
        M[j][i] = M[i][j];
        M[i][j] = tmp;
      }
    }
  }
  
  void reflect(vector<vector<int>>& M) {
    int n = M.size();
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n / 2; ++j) {
        int tmp = M[i][j];
        M[i][j] = M[i][n - j - 1];
        M[i][n - j - 1] = tmp;
        
      }
    }
  }
  
  public:
  void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    reflect(matrix);
  }
};
