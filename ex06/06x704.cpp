/*
 * leetcode 704 binary search in an array (vector)
 *
 * array, binary search
 * keep the range an invariant
 * either [left, right] or [left, right)
 * 
 * the solution below is using [left, right)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r-l)/2;
            if (nums[m] > target) {
                r = m;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                return m;
            }
        }    
        return -1;
    }
};

