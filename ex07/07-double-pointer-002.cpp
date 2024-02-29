/*
 * leetcode 26
 * array is sorted. use double-pointer: fast and slow
 * in-place
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()) {
            if (nums[j] == nums[j-1]) {
                j++;
            } else {
                i++;
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return i+1;
    }
};

