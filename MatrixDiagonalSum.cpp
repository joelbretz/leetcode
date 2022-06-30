class Solution {
  int n;
  public:
  //0,0 -> 1,1 -> .. -> n-1,n-1
  //n-1,0 -> n-2,1 -> n-3,2 -> ... -> 0,n-1
  // directly sum diagonals. if odd, remove duplicate of n/2,n/2
  int diagonalSum(vector<vector<int>>& mat) {
    n = mat.size();
    pair<int,int> ul = {0,0}, ur = {0,n-1},
      bl = {n-1, 0}, br = {n-1,n-1};
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      sum += mat[i][i];
      sum += mat[n-1-i][i];
    }
    if(n & 0x1 == 0x1)
      sum -= mat[n/2][n/2];
    return sum;
  }
};
