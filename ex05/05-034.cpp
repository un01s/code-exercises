/*
 * leetcode 34
 * binary search
 * array
 *
 */

class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1; // [i, j]
        while (i <= j) {
            int m = i + (j-i)/2;
            if (nums[m] < target) i = m+1;
            else j = m-1;
        }
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binarySearch(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = binarySearcj(nums, target+1)-1;
        return {start, end};
    }
};

