/*
 * leetcode 474
 * https://leetcode.com/problems/ones-and-zeroes/
 *
 * ones and zeroes
 * 
 * You are given an array of binary strings strs and two integers m and n.
 * 
 * Return the size of the largest subset of strs such that there are 
 * at most m 0's and n 1's in the subset.
 * 
 * A set x is a subset of a set y if all elements of x are also elements of y. 
 *
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] consists only of digits '0' and '1'.
 * 1 <= m, n <= 100
 *
 *
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        // initialized to zero, 2D knapsack is still a knapsack
        // that different-length strings are objects to be put into
        // dp[i][j]: max sub-set with i 0's and j 1's
 
        for (string str : strs) { // traverse all objects in strs
            int oneNum = 0, zeroNum = 0;
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }

            for (int i = m; i >= zeroNum; i--) { // reverse traversal
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

