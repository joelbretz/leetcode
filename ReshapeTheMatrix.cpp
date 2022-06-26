class Solution {
  int m; int n;
  public:
  // obvious solution, keep track of number of elems
  // use division and modulo to populate new array
  vector<vector<int>> matrixReshapeModDiv(vector<vector<int>>& mat, int r, int c) {
    m = mat.size();
    n = mat[0].size();

    if((n * m) != (r * c))
      return mat;

    vector<vector<int>> reshaped(r, vector<int>(c, 0));

    int count = 0;
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        reshaped[count/c][count % c] = mat[i][j];
        count++;
      }
    }
    return reshaped;

  }
  
  // solution 2.  use a queue and then populate the result.
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    m = mat.size();
    n = mat[0].size();

    if((n * m) != (r * c))
      return mat;

    queue<int> q;
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        q.push(mat[i][j]);
      }
    }
      
      
    vector<vector<int>> reshaped(r, vector<int>(c, 0));

    for(int i = 0; i < r; ++i) {
      for(int j = 0; j < c; ++j) {
        reshaped[i][j] = q.front(); 
        q.pop();
      }
    }
    return reshaped;

  }
};
