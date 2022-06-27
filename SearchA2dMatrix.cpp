class Solution {
  protected:
  int m;
  int n;
public:
    // treat the m x n matrix as a single array of m x n length:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
      m = matrix.size(); 
      if(!m) return 0;
      n = matrix[0].size();  
      int a = 0, b = (m * n)- 1;
      int mid, value;
      
      while(a <= b) {
        mid = (a + b) / 2;
        value = matrix[mid / n][mid % n];
        if(value == target)
          return true;
        else if(target < value) 
          b = mid - 1;
        else // value > target
          a = mid + 1;
      }
      return false;
    }
      // binary search rows, then cols .
    bool searchMatrixNested(vector<vector<int>>& matrix, int target) {
      m = matrix.size(); n = matrix[0].size();  
      int a = 0, b = m;
      int c;
      
      bool found = false;
      while(a <= b) {
        c = (a + b) / 2;
        if(target > matrix[c][n-1]) {
          //cout << "value after row " << c << endl;
          a = c + 1;
          continue;
        }
        else if(target < matrix[c][0]) { 
          //cout << "value before row " << c << endl;
          b = c - 1;
          continue;
        }
        else {
          //cout << "value in row " << c << endl;
          int u = 0, v = n; int w;
          while(u <= v) {
            w = (u + v) / 2;
            if(matrix[c][w] == target)
              return true;
            else if(matrix[c][w] < target)
              u = w + 1;
            else
              v = w - 1;
          }
          return false;
        }
      }
      return false;
    }
};
