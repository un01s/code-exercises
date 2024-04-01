/*
 * leetcode 977
 * squares of a sorted array
 *
 * double-pointer
 *
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int k = n-1;
        vector<int> res(n, 0);
        for (int i = 0, j = n-1; i <= j; ) {
            if (nums[i]*nums[i] < nums[j]*nums[j]) {
                res[k--] = nums[j]*nums[j];
                j--;
            } else {
                res[k--] = nums[i]*nums[i];
                i++;
            }
        }    
        return res;
    }
};

