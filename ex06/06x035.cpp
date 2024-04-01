/*
 * leetcode 035
 * search insert position
 *
 * array + binary search
 *
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        // use the range: [left, right]
        while (left <= right) { // if left==right，[left, right] is tsill valid
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1; // target in the left,[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target at right，[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        
        return right + 1;    
    }
};
