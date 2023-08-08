/*
 * leetcode 27
 * given an array nums and an integer val, remove val from the array
 * return the length of the array after removal.
 *
 * O(1), do not change the order of the array
 * 
 */

class Soltuion {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0; 
        int slow = 0;
        while (fast < nums.size()) {
            if(nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

