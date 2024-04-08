/*
 * leetcode 930
 *
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> postZeros(n);

        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            postZeros[i] = count;
            if (nums[i] == 0)
                count++;
            else
                count = 0;
        }

        int j = 0, sum = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            while (j <= i || (j < n && sum < goal)) {
                sum += nums[j];
                j++;
            }

            if (sum == goal)
                ret += postZeros[j - 1] + 1;
            sum -= nums[i];
        }

        return ret;
    }
};
