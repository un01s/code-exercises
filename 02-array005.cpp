/*
 * 59 spiral matrix II
 * https://leetcode.com/problems/spiral-matrix-ii/
 *
 * Given a positive integer n, generate an n x n matrix filled with 
 * elements from 1 to n^2 in spiral order.
 * 
 * example;
 *     1 2 3 
 *     8 9 4
 *     7 6 5
 *
 * input: n = 3,
 * output: [[1, 2, 3], [8, 9, 4], [7, 6, 5]]
 *
 * constraints: 1 <= n <= 20
 *
 * How to do the spiral?
 * Keep [left, right) in mind. Take the example of n = 3.
 * the first line from left to right: 1, 2
 * the second line from top to bottom: 3, 4
 * the third line from right to left: 5, 6
 * the fourth line from bottom to top: 7, 8
 * the fifth draw from left to right: 9 (only one number to draw, the last) 
 * 
 * n = 3, [0, n-1), every line has n-1 steps, 
 * then change the direction, the last one is a special case
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// pass by reference here
// it is different from pass by pointer
void print(vector<vector<int> > m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { // typo i++
            cout << m[i][j] << ",";
        }
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n, 0));
        int startx = 0, starty = 0; 
        int loop = n/2; // n=3, loop=1
        int mid = n/2;  // center: n=3, (1,1) is the center
			// n=5, (2,2) is the center
        int count = 1;  // assign a value to each grid of the matrix
        int offset = 1; // after each loop, the length decrements
        int i, j;
        while(loop--) {
            i = startx;
            j = starty;
            // each loop contains 4 lines
            // always keep [closes, open)
            // 1: from left to right, [left, right)
            for (j = starty; j < n-offset; j++) {
                result[startx][j] = count++;
            }
            // 2: from top to bottom, [top, bottom)
            for (i = starty; i < n-offset; i++) {
                result[i][j] = count++;
            }
            // 3: from right to left, 
            for (; j > starty; j--) {
                result[i][j] = count++;
            }
            // 4: from bottom to top
            for (; i > startx; i--) {
                result[i][j] = count++;
            }

            // when the next loop starts, the starting point increments
            // e.g. first loop [0, 0], second [1, 1], etc. 
            startx++;
            starty++;
            // offset for next loop
            offset += 1;
            // here it is increment, the length of each line is (n-offset)
            // for each loop, the steps of each line decrements.
        }
        // if n is an odd number, assign the last to the center
        if (n % 2) {
            result[mid][mid] = count;
        }
/*
        // a typo causing a runtime error, segment fault
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { // typo i++ 
                cout << result[i][j] << ",";
            }
            cout << endl;
        }
*/
        return result;
    }
};

int main() {
    Solution ans;

    print( ans.generateMatrix(3), 3);
    print( ans.generateMatrix(4), 4);
    print( ans.generateMatrix(5), 5);

    return 0;
}
