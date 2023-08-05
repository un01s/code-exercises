/*
 * leetcode 53
 * max subarray
 * Given an integer array nums, find the subarray with the largest sum, 
 * and return its sum.
 * 
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 0); // max sum of subarray ending at index i-1
        dp[0] = nums[0]; // initialization
        int res = nums[0]; // need store the max
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            if (dp[i] > res) res = dp[i]; // keep the max
        }
        return res;
    }
};

