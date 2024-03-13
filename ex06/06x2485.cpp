/*
 * leetcode 2485
 * find the pivot integer
 *
 */

class Solution {
public:
    int pivotInteger(int n) {
        double x = sqrt(n * (n + 1) / 2);
        return x == (int)x ? x : -1;
    }
};
