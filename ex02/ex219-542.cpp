/*
 * leetcode 542
 * 0 1 matrix
 *
 * BFS
 *
 * this code looks easier to understand
 *
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> visiteed(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!mat[i][j]) {
                    q.push(make_tuple(i, j, 0));
                    visiteed[i][j] = 1;
                }
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty())
        {
            int x, y, dis;
            tie(x, y, dis) = q.front(); q.pop();
            dist[x][y] = dis;
            for(int i = 0; i < 4; ++i) {
                int nx, ny;
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx < n && nx >= 0 && ny < m && ny >= 0 && !visiteed[nx][ny]) {
                    q.push({make_tuple(nx, ny, dis+1)});
                    visiteed[nx][ny] = 1;
                }
            }
        }
        return dist;
    }
};

