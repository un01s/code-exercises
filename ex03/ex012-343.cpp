/*
 * leetcode 343
 * integer break
 *
 * break it into 3 to maximize the final product
 */

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int count3 = n/3;
        int r = n%3;
        if (r == 0) {
            return pow(3, count3);
        } else if (r == 1) {
            return pow(3, count3-1)*4;
        } else {
            return pow(3, count3)*2;
        }
    }
};

