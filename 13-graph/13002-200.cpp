/*
 * leetcode 200
 * 
 */

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void dfs(vector<vector<char> >& grid, vector<vector<bool> >& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || 
                nexty < 0 || nexty >= grid.size()) {
                continue;
            }
            if (!visited[nextx][nexty] && grid[nextx][nexty]=='1') {
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty);
            }
        }
    } 
    int numIslands(vector<vector<char> >& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool> > visited = vector<vector<bool> >(n, vector<bool>(m, false));

        int res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    res++; // not visited land
                    dfs(grid, visited, i, j); // any adjacent land will be marked
                }
            }
        }
        return res;
    }
};
