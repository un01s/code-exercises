/*
 * leetcode 53
 * max subarray
 * Given an integer array nums, find the subarray with the largest sum, 
 * and return its sum.
 * 
 */

// DP
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

// greedy
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int sum = 0; // sub sum
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > res) { // keep the max, moving it ending pos
                res = sum;
            }
            if (sum <= 0) sum = 0; // reset the starting pos
        }
        return res;
    }
};
