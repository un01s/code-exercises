/*
 * leetcode 2812
 * https://www.youtube.com/@wisdompeak
 *
 */

using PII pair<int, int>;

class Solution {
    vector<PII> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int maximumSafenessFactor(vector<vector<int> >& grid) {
        int n = grid.size();
        queue<PII> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]==1) q.push({i, j});

        // DFS
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto [x, y] = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int i = x+dir[k].first;
                    int j = y+dir[k].second;
                    if (i<0 || i>=n || j<0 || j>=n) continue;
                    if (grid[i][j]!=0) continue;
                    grid[i][j] = grid[x][y]+1;
                    q.push({i, j});
                }
            }
        }

        // binary search
        int left = 0;
        int right = 2*n;
        while (left < right) {
            int mid = right - (right-left)/2; 
            if (isOK(mid, grid)) left = mid;
            else right = mid-1;
        }
        return left;
    }

    bool isOK(int d, vector<vector<int> >& grid) {
        int n = grid.size();
        vector<vector<int> > visited(n, vector,int>(n, 0));

        if (grid[0][0] <= d) return false;

        queue<PII> q;
        q.push({0, 0});
        visited[0][0] = 1;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k <4; k+=) {
                int i = x+dir[k].first;
                int j = y+dir[k].seocond;
                if (i<0 || i>=n || j<0 || j >=n) continue;
                if (vistied[i][j] != 0) continue;
                if (grid[i][j] <= d) continue;

                if (i == n-1 && j == n-1) return true;

                visited[i][j] = 1;
                q.push({i, j}); 
            }
        }
        return false;
    }
};
