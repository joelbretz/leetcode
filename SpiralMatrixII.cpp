class Solution {
  void printMatrix(vector<vector<int>>& M) {
    int sz = M.size();
    for(int r = 0; r < sz; ++r) {
      for(int c = 0; c < sz; ++c) {
        cout << M[r][c] << " ";
      }
      cout << endl;
    }
  }
  public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n,1));
    int val = 1;

    for(int spiralno = 0; spiralno < (n+1)/2; ++spiralno) {
      // -->
      for(int p = spiralno; p < n - spiralno; ++p) 
        result[spiralno][p] = val++;
      
      // go down
      for(int p = spiralno + 1; p < n - spiralno; ++p)
        result[p][n - spiralno - 1] = val++;
      
      // <---
      for(int p = n - spiralno - 2; p >= spiralno; --p)
        result[n - spiralno - 1][p] = val++;
      
      // go up
      for(int p = n - spiralno - 2; p > spiralno; --p) 
        result[p][spiralno] = val++;
    }
    //printMatrix(result);
    return result;
  }
};
