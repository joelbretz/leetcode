class Solution {
  public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> pascal;
    if(rowIndex == 0)
      return {1};
    pascal.push_back({1}); // row 0
    for(int row = 1; row <= rowIndex; ++row) {
      int rowSize = row + 1;
      vector<int> currRow(rowSize, 0);
      currRow[0] = 1;
      currRow[rowSize-1] = 1;
      for(int mid = 1; mid < rowSize - 1; ++mid) {
        int val = pascal[row-1][mid-1] + pascal[row-1][mid];
        currRow[mid] = val;
      }
      pascal.push_back(currRow);
    }
    return pascal[rowIndex];
  }
};
