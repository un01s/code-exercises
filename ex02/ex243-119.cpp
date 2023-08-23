/*
 * leetcode 119
 *
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }
        if (rowIndex == 1) {
            return {1, 1};
        }
        vector<int> p(rowIndex+1, 1);
        for (int i = 2; i < rowIndex + 1; i++) {
            for (int j = i - 1; j; j--) {
                p[j] += p[j - 1];
            }
        }
        return p;
    }
};

