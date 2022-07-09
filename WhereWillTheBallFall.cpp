/*
Notice: 
  every cell of the grid is divided into top and bottom parts. 

If top==true this means we are in the upper part of grid[i][j].

  check which direction to move and see if it's a block
  if grid[i][j]=1
     go to the bottom part of right cell.  If that cell is out of bounds return -1.
     if grid[i][j+1] is not 1 then we cannot go further and are blocked. return -1 
 
  if grid[i][j]=-1
    go to the bottom part of left cell. If that cell is out of bounds return -1.
    if grid[i][j-1] is not 1 then we cannot go further and are blocked. return -1

(else ) top = false0 this means we are in the lower part of grid[i][j]. In such a case no matter the value of grid[i][j] we need to go down.

If we reach bottom part of last row then return column number.

*/

class Solution {
  protected:
  int rows;
  int cols;

  int drop(vector<vector<int>>& grid, int r, int c, bool top) {

    // check that we're in bounds left/right, if not return -1;
    // then check if we fell out the bottom. 
    if(c < 0 || c >= cols)
      return -1;
    else if(r >= rows)
      return c;

    if(top) {
      if(grid[r][c] == 1)  {
        // move to bottom of the cell right of us if possible
        if(c+1 >= cols || grid[r][c+1] != 1)
          return -1;

        return drop(grid,r,c+1,false);
      }
      else { // grid[r][c] == -1) {
        // move to the bottom of the cell left of us
        if(c - 1 < 0 || grid[r][c-1] != -1)
          return -1;
        return drop(grid, r, c-1, false);
      }
    }
    else {  // bottom of cell
      return drop(grid, r+1, c, true);
    }
   return -1;
  }  

public:
  vector<int> findBall(vector<vector<int>>& grid) {
    rows = grid.size();  // m 
    cols = grid[0].size(); // by n

    vector<int> result(cols, -1);
    for(int i = 0; i < cols; ++i) {
      result[i] = drop(grid, 0, i, true);
    }
    return result;
  }
};
