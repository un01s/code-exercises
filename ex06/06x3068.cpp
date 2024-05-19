/*
 * leetcode 3068
 * find the maximum sum of node values
 * 
 * tree, recursive, DP
 *
 */

class Solution {
public:
    long long f(int i, vector<int>& values, vector<vector<long long>>& dp,
                int n, int count, int k) {
        if (i == n) {
            if (count == 0) {
                return 0;
            } else {
                return INT_MIN;
            }
        }
        if (dp[i][count] != -1) {
            return dp[i][count];
        }
        long long x = (values[i] ^ k) + f(i + 1, values, dp, n, !count, k);
        long long y = values[i] + f(i + 1, values, dp, n, count, k);
        return dp[i][count] = max(x, y);
    }
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, nums, dp, n, 0, k);
    }
};

