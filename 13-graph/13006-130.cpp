/*
 * leetcode 130
 */

class Solution {
private:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 4 directions
    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = 'A';
        for (int i = 0; i < 4; i++) { // to four directions
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // over boundary
            if (nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()) continue;
            // no matched stop
            if (board[nextx][nexty] == 'X' || board[nextx][nexty] == 'A') continue;
            dfs (board, nextx, nexty);
        }
        return;
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(); 
        // traverse
        // from left and right to the mid
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
        }

        // from top and bottom to the mid
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[n - 1][j] == 'O') dfs(board, n - 1, j);
        }
        // change
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};
