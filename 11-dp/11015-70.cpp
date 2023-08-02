/*
 * leetcode-70
 * 
 */

//
// the problem is changed to the following:
// 1 step, 2 steps, ..., or m steps a time
// then how many ways to reach stairs of n steps.
//
// this makes it a complete knapsack problem
//
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) { // knapsack
            for (int j = 1; j <= m; j++) { // objects: max m steps one time
                if (i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};

// two ways to climb: either 1 step or 2 steps a time
// fibonaci dp
class Solution2 {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
