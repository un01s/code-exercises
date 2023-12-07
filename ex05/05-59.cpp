/*
 * leetcode 59
 * matrix generation
 * clockwise rotated
 *
 */

class Solution {
public: 
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int loop = n/2;
        int mid = n/2;
        int count = 1, offset = 1;
        int i, j;

        while(loop--) {
            i = startx;
            j = starty;
            // always [), left to right
            for (j = starty; j < n-offset; j++) {
                res[startx][j] = count++;
            }
            // top to bottom
            for (i = startx; i < n-offset; i++) {
                res[i][j] = count++;
            }
            // right to left
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // from bottom to top
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // for next loop
            startx++;
            starty++;
            offset += 1;
        }
        if (n%2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
