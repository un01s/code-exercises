/*
 * leetcode 1020
 *
 */

class Solution {
private:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 4 directions
    int count; // land count
    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        count++;
        for (int i = 0; i < 4; i++) { // 4 directions
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // over the boundary
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            // not matched
            if (grid[nextx][nexty] == 0) continue;

            dfs (grid, nextx, nexty);
        }
        return;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // to the mid
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);
        }
        // to the mid
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);
            if (grid[n - 1][j] == 1) dfs(grid, n - 1, j);
        }
        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) dfs(grid, i, j);
            }
        }
        return count;
    }
};
