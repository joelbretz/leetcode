class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
     
      int rows = dungeon.size();
      int cols = dungeon[0].size();
      // array for dp
      vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
      // temp variables for help.
      int curr, rt, dwn, next;
      
      // start at bottom right and work up and left
      for(int r = rows - 1; r >= 0; --r) {
        for(int c = cols - 1; c >= 0; --c) {
          curr = dungeon[r][c]; // curr cell value
          
          // check down
          if(r + 1 >= rows)
            dwn = INT_MAX;
          else
            dwn = max(1, dp[r+1][c] - curr);
          
          // check right
          if(c + 1 >= cols)
            rt = INT_MAX;
          else
            rt = max(1, dp[r][c + 1] - curr);
          
          // save smaller value or 1
          next = min(rt,dwn);
          if(next == INT_MAX)
            dp[r][c] = curr >= 0 ? 1 : 1 - curr;
          else
            dp[r][c] = next;
          
        }
      }
      return dp[0][0];
    }
};
