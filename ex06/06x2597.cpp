/*
 * leetcode 2597
 * the number of beautiful subsets
 *
 *
 */

class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int k, int i, int n) {
        if (i == n)
            return 0;

        int take = 0;

        int notTake = helper(nums, dp, k, i + 1, n);

        if (binary_search(dp.begin(), dp.end(), nums[i] - k) == 0) {
            dp.push_back(nums[i]);
            take = 1 + helper(nums, dp, k, i + 1, n);
            dp.pop_back();
        }

        return take + notTake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp;

        return helper(nums, dp, k, 0, n);
    }
};

