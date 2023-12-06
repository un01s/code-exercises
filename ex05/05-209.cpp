/*
 * leetcode 209
 * minimum length of sub array (consecutive) whose sum is greater or equal to s
 *
 * example: s = 7, nums = [2, 3, 1, 2, 4, 3]
 * answer: 2
 *
 * [4,3] is one case.
 *
 * sliding window
 *
 */


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sum = 0;
        int i = 0;
        int sublen = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                sublen = j-i+1;
                res = res < sublen? res: sublen;
                sum -= nums[i++]; // sliding window
            }
        }
        return res == INT32_MAX? 0 : res;    
    }
};

// brute force
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sum = 0;
        int sublen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= target) {
                    sublen = j-i+1;
                    res = res < sublen? res: sublen;
                    break;
                }
            }
        }
        return res == INT32_MAX? 0 : res;    
    }
};

