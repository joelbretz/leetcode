/class BinarySearchSolution {
class Solution {
  int rows, cols;
  
  void printGrid(vector<vector<int>>& G) {
    for(int r = 0; r < G.size(); ++r) {
      for(int c = 0; c < G[r].size(); ++c) {
        cout << G[r][c] << " ";
      }
      cout << endl;
    }
  }
  public:
  int countNegatives(vector<vector<int>>& grid) {
    rows = grid.size();
    if(!rows) 
      return 0;
    cols = grid[0].size();
    //printGrid(grid); 
    int count = 0;
    int left, right, mid;
    // for each row
    for(int r = 0; r < rows; ++r) {
      //cout << "row number " << r << endl;
      left = 0; right = cols - 1 ;
      while(left <= right) {
        //mid = left + (right-left) / 2;
        mid = (left + right) / 2;
        //cout << "  l,r,mid " << left <<","<<right <<"," << mid << " : grid[r][mid] = " << grid[r][mid] << endl;
        if(grid[r][mid] < 0) 
          right = mid - 1;
        else 
          left = mid + 1;
      }
      //cout << " adding " << cols - mid ;
      count += cols - left;
      //cout << " count = "  << count << endl;
    }
    return count;
  }
};

class BruteForceSolution {
//class Solution {
  public:
  // Nested Loops, O(n^2) :(   
  int countNegatives(vector<vector<int>>& grid) {
    int count = 0;  
    int rows = grid.size(); int cols = grid[0].size();
    int total = rows * cols;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        if(grid[i][j] >= 0)
          count++;
        else
          cols = j--;
      }
    }
    return total-count;
  }
};
