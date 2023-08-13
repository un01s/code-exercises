/*
 * leetcode 2369
 * 
 */

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        dp[n-1] = false;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] == nums[i+1]) dp[i] = dp[i] || dp[i+2];
            if (i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                dp[i] = dp[i] || dp[i+3];
            }
            if (i+2 < n && (nums[i]+1 == nums[i+1]) && (nums[i+1]+1 == nums[i+2])) {
                dp[i] = dp[i] || dp[i+3];
            } 
        }
        return dp[0];
    }
};
