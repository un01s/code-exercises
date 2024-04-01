/*
 * leetcode 209
 *
 * sliding window
 *
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                subLength = (j-i+1);
                res = res < subLength ? res : subLength;
                sum -= nums[i++];
            }
        }    
        return res == INT_MAX ? 0 : res;
    }
};

