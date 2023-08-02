/*
 * leetcode 377
 *
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // the number of permutation whose sum equals to the i
        // dp[i]. order is important!
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; i++) { // knapsack = target
            for (int j = 0; j < nums.size(); j++) { // objects = nums
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

