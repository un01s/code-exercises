/*
 * leetcode 643
 *
 *
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (k == nums.size()) return sum*1.0/n;

        double res = 0.0;
        for (int i = 0; i < k; i++) {
            res += nums[i];
        }
        double m = res;

        for (int i = k; i < nums.size(); i++) {
            res += nums[i] - nums[i - k];
            if (res > m) m = res;
        }
        return m*1.0/k;
    }
};
