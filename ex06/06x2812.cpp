/*
 * leetcode 2812
 * find the safest path in a grid
 *
 */

class Solution {
public:
    bool verify(vector<vector<int>>& grid, int m) {
        int n = grid.size();
        map<pair<int, int>, int> vis;
        if (m > grid[0][0])
            return (false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[{0, 0}]++;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i == n - 1 && j == n - 1)
                return (true);
            int c[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for (int k = 0; k < 4; k++) {
                int i1 = i + c[k][0];
                int j1 = j + c[k][1];
                if (i1 >= 0 && j1 >= 0 && j1 < n && i1 < n &&
                    vis.count({i1, j1}) == 0 && grid[i1][j1] >= m) {
                    vis[{i1, j1}]++;
                    q.push({i1, j1});
                }
            }
        }
        return (false);
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return (0);
        vector<vector<int>> dis(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int l = 1;
        while (!q.empty()) {
            int s = q.size();
            while (s) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                int c[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
                for (int k = 0; k < 4; k++) {
                    int i1 = i + c[k][0];
                    int j1 = j + c[k][1];
                    if (i1 >= 0 && j1 >= 0 && j1 < n && i1 < n &&
                        dis[i1][j1] == -1) {
                        dis[i1][j1] = l;
                        q.push({i1, j1});
                    }
                }
                s--;
            }
            l++;
        }
        int s = 0, e = 1e9, ans = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (verify(dis, m)) {
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return (ans);
    }
};

