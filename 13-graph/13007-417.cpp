/*
 * leetcode 417
 *
 */

// DFS: time
class Solution {
private:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) return;

        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;
            if (heights[x][y] < heights[nextx][nexty]) continue; // only flow from high to low

            dfs (heights, visited, nextx, nexty);
        }
        return;
    }
    bool isResult(vector<vector<int>>& heights, int x, int y) {
        vector<vector<bool>> visited = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size(), false));

        // depth first search: start from (x, y), mark all points reached
        dfs(heights, visited, x, y);
        bool isPacific = false;
        bool isAtlantic = false;

        // check if start from (x,y), it can reach both pacific and atlantic
        for (int j = 0; j < heights[0].size(); j++) {
            if (visited[0][j]) {
                isPacific = true;
                break;
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            if (visited[i][0]) {
                isPacific = true;
                break;
            }
        }
        for (int j = 0; j < heights[0].size(); j++) {
            if (visited[heights.size() - 1][j]) {
                isAtlantic = true;
                break;
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            if (visited[i][heights[0].size() - 1]) {
                isAtlantic = true;
                break;
            }
        }
        if (isAtlantic && isPacific) return true;
        return false;
    }
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        // traverse every point to check if it can reach both pacific and atlantic
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (isResult(heights, i, j)) result.push_back({i, j});
            }
        }
        return result;
    }
};

// better
// start from pacific to reach all point it can go, mark
// then start from atlantic to reach all points it can go, mark
// now, the points marked by both pacific and atlantic are the answer
//
class Solution2 {
private:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 4 dir

    // traverse from low to high
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) { // 4 dir
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // over boundary
            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;
            // height does not work: from low to high
            if (heights[x][y] > heights[nextx][nexty]) continue;

            dfs (heights, visited, nextx, nexty);
        }
        return;

    }

public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int n = heights.size();
        int m = heights[0].size(); 

        // start from pacific
        vector<vector<bool>> pacific = vector<vector<bool>>(n, vector<bool>(m, false));

        // start from atlantic
        vector<vector<bool>> atlantic = vector<vector<bool>>(n, vector<bool>(m, false));

        // traverse from top and bottom
        for (int i = 0; i < n; i++) {
            dfs (heights, pacific, i, 0); //
            dfs (heights, atlantic, i, m - 1); //
        }

        // from top and bottome
        for (int j = 0; j < m; j++) {
            dfs (heights, pacific, 0, j); //
            dfs (heights, atlantic, n - 1, j); //
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // both
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};

