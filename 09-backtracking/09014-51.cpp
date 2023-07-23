/**
 * Leetcode 51 
 * 
 *
 * 2023-07-23
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string> > res;
    void backtracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            res.push_back(chessboard);
            return;
        }
        // 
        for(int col = 0; col < n; col++) {
            if(isValid(row, col, chessboard, n)) {
                chessboard[row][col] = 'Q';
                backtracking(n, row+1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        // column
        for(int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 45 degree
        for(int i = row-1, j = col-1; i >=0 && j>=0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 135 degree
        for(int i = row-1, j = col+1; i >=0 && j<n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    vector<vector<string> > solveNQueens(int n) {
        res.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard); // row after row
        return res;
    }    
};

int main() {
    
    return 0;
}

