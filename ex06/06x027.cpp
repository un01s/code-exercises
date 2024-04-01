/*
 * leetcode 027
 * remove element
 * double-pointer: fast and slow pointers
 *
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (val != nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }    
        return slow;    
    }
};

