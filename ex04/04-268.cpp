/*
 * leetcode 268
 *
 * xor twice
 *
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // range: [0, n]
        int k=0;
        for (int i=0; i<=nums.size(); i++)
            k = k^i;
        for (int i=0; i<nums.size(); i++)
            k = k^nums[i];
        return k;            
    }
};

