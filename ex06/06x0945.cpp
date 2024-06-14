/*
 * leetcode 945
 * minimum increment to make array unique
 *
 */

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // Initialize a counter variable to keep track of the number of
        // increments needed
        int cnt = 0;

        // Traverse the sorted array from index 1
        for (int i = 1; i < nums.size(); i++) {

            // If the current element is less than or equal to the previous
            // element
            if (nums[i] <= nums[i - 1]) {

                // Increment the counter by the difference between the previous
                // element and the current element, plus 1
                cnt += nums[i - 1] - nums[i] + 1;

                // Set the current element to be one more than the previous
                // element
                nums[i] = nums[i - 1] + 1;
            }
        }

        // Return the total number of increments needed
        return cnt;
    }
};

