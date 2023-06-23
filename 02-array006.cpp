/*
 * 54 spiral matrix
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * https://leetcode.com/problems/spiral-matrix/
 *
 * this is a gneralized form of nxn matrix.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res(row*col, 0);

        int startx = 0, starty = 0;
        int loop = min(row, col)/2; // n=3, loop=1
        int midx = col/2;
        int midy = row/2;
        int count = 0;  // assign a value to each grid of the matrix
        int offset = 1; // after each loop, the length decrements
        int i, j;
        while(loop--) {
            i = startx;
            j = starty;
            // each loop contains 4 lines
            // always keep [closes, open)
            // 1: from left to right, [left, right)
            for (j = starty; j < col-offset; j++) {
                res[count++] = matrix[startx][j];
            }
            // 2: from top to bottom, [top, bottom)
            for (i = startx; i < row-offset; i++) {
                res[count++] = matrix[i][j];
            }
            // 3: from right to left,
            for (; j > starty; j--) {
                res[count++] = matrix[i][j];
            }
            // 2x2 case the last element is missed here
            // 2x3 case is good
            // 4: from bottom to top
            for (; i > startx; i--) {
                res[count++] = matrix[i][j];
            }

            // when the next loop starts, the starting point increments
            // e.g. first loop [0, 0], second [1, 1], etc.
            startx++;
            starty++;
            // offset for next loop
            offset += 1;
        }
        // special cases
        // - no loops at all for the matrix such as 1xn or mx1
        // - just one loop with nothing left such as 2x2, 2x3, 3x2
        // - after loops with remaining element left such as 3x3
        if (count == 0) {
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    res[count++] = matrix[i][j];
                }
            }
        } else if (count <= row*col) {
            // the remaining could be one element, one row, or one column
            cout << "startx = " << startx << endl;
            cout << "starty = " << starty << endl;
            cout << "offset = " << offset << endl;
            cout << "row = " << row << endl;
            cout << "col = " << col << endl;
            if ((col-offset)==1 && (row-offset)==1) {
                // one element only
                res[count] = matrix[startx][starty];
            }
            if ((col-offset)==1 && (row-offset)>1) {
                // one row only
                for(i = startx; i <= (row-offset); i++) {
                    res[count++] = matrix[i][starty];
                }
            }
            if ((col-offset)>1 && (row-offset)==1) {
                // one column only
                for(j = starty; j <= (col-offset); j++) {
                    res[count++] = matrix[startx][j];
                }
            }
        }

        // debug
        for (int i = 0; i < row*col; i++) {
            cout << res[i] << ",";
        }
        cout << endl;

        return res;    
    }
};

int main() {
    Solution ans;

    int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int> > v(3, vector<int> (3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v[i][j] = a[i][j];
        }
    }
    ans.spiralOrder(v);

    int b[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<vector<int> > w(3, vector<int> (4, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            w[i][j] = b[i][j];
        }
    }
    ans.spiralOrder(w);

    // special cases
    // [[1]]
    vector<vector<int> > x(1, vector<int>(1, 1));
    ans.spiralOrder(x);

    // [[1, 2, 3]]
    vector<vector<int> > y(1, vector<int>(3, 0));
    for (int j = 0; j < 3; j++) {
        y[0][j] = j+1;
    }
    ans.spiralOrder(y);

    // [[1, 2], [3, 4]]
    int c[2][2] = {{1, 2}, {3, 4}};
    vector<vector<int> > z(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            z[i][j] = c[i][j];
        }
    }
    ans.spiralOrder(z);
    
    return 0;
}
