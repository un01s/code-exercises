/*
 * leetcode 516
 *
 * DP
 * use two dimension to do comparison one forward, the other backward
 *
 * 
 * dp[i][j] = max length of palindromic within substring in [i, j] of input
 * 
 * if s[i] == s[j], dp[i][j] = dp[i+1][j-1]+2;
 * if s[i] != s[j], dp[i][j] = max(dp[i+1][j], dp[i][j-1])
 *
 * one char's palindromic substring is 1
 *
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // initialize
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1; 
        // one char's palindrome is itself, so the length is 1.
        // traverse order is important
        // one from the end, the other from opposite direction
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};


