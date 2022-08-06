class Solution {

  public:
  // O(n) time b/c we have to examine every element
  // O(1) space b/c it's done in place
  int minimumTotal(vector<vector<int>>& triangle) {

    int height = triangle.size();
    for(int r = height - 2; r >= 0; --r ) {
      for(int c = 0; c < triangle[r].size(); ++c) {
        triangle[r][c] += min(triangle[r+1][c], triangle[r+1][c+1]);
      }
    }

    // print graph
    #if 0
    int r = 0, c = 0;
    for(r = 0; r < height - 1; ++r) {
      for(c = 0; c < triangle[r].size(); ++c) {
        cout << triangle[r][c] << " -> " << triangle[r+1][c] << ", " << triangle[r+1][c+1] << endl;
      }
    }
    #endif
    return triangle[0][0];
  }
};
