/*
 * leetcode 279
 *
 */

// complete knapsack problems
// because the numbers or objects are infinite
// use as many times as you wish
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) { // sacks = sum = n as target
            for (int j = 1; j * j <= i; j++) { // numbers unlimited as objects
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};

// different traversal order
class Solution2 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // objects
            for (int j = i * i; j <= n; j++) { // sacks
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};
