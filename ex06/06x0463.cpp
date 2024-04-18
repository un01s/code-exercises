/*
 * leetcode 463
 * island perimeter
 * DFS
 *
 */

class Solution {
    int p = 0;
    void dfs(vector<vector<int>>&grid, int i, int j) {
        // check if out of bounds or on bordering water
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == 0) {
            ++p;
            return; 
        }
        if (grid[i][j] == -1) return; 
        grid[i][j] = -1; // mark visited
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) 
            for (int j = 0; j < grid[0].size(); ++j) 
                if (grid[i][j] == 1) dfs(grid, i, j);
        return p;     
    }
};

