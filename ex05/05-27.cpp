/*
 * leetcode 27
 * remove element
 *
 * double-pointer: fast and slow
 * array
 *
 */

// double-pointer
// i is the faster pointer
// slow at the end represent the number of elements in nums
// that are nor equel to val
//
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[slow++] = nums[i];
            }
        }
        return slow;
    }
};

