/*
 * leetcode 518
 *
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j] = combinations number to make the sum of j
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // amount = 0, dp[0] = 1
        for (int i = 0; i < coins.size(); i++) { // coins as objects
            for (int j = coins[i]; j <= amount; j++) { // amount knapsack
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

