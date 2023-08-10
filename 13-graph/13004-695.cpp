/*
 * leetcode 695
 *
 */

class Solution {
private:
    int count;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 4 directions
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // over the boundary, pass
            if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) { // not visited land

                visited[nextx][nexty] = true;
                count++;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    count = 1;  // not visited land
                    visited[i][j] = true;
                    dfs(grid, visited, i, j); // mark adjacent land as true
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};

