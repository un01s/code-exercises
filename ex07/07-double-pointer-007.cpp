/*
 * leetcode 209
 * minimum size subarray sum
 * 
 * all elements are positive.
 *
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i = 0;
        int j = 0;
        int sum = 0;
        int len = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            if (sum < target)
                continue;
            else {
                while (sum >= target) {
                    len = min(len, j - i + 1);
                    sum -= nums[i];
                    i++;
                }
            }
        }

        if (len == INT_MAX)
            len = 0;

        return len;
    }
};

