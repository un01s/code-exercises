/*
 * leetcode 977
 * the square of an ordered array
 * maintain the orderness
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int i = 0; // double-pointer, i left, j right
        int j = n-1;
        int k = n-1; // need this index for result
        for(; i <= j; ) {
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];
            if (a > b) {
                res[k--] = a;
                i++;
            } else {
                res[k--] = b;
                j--;
            }
        }
        return res;
    }
};

