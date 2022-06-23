class Solution {
public:
    int ans = 0, n, m;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = { -1, 1, 0, 0};
    void floodFill(vector<vector<int>> & grid, int x, int y) {
        // cases where we hit the boundary
        if (x >= n || y >= m || x < 0 || y < 0 || grid[x][y]) return;
        // mark visited
        grid[x][y] = 1;

        // traverse all direction
        for (int dir = 0; dir < 4; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];
            floodFill(grid, newX, newY);
        }
    }
  
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // fill the 1st row and last row with water
        for (int i = 0; i < m; i++) {
            floodFill(grid, 0, i);
            floodFill(grid, n - 1, i);
        }

        // fill the 1st column and last column with water
        for (int i = 0; i < n; i++) {
            floodFill(grid, i, m - 1);
            floodFill(grid, i, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    floodFill(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
