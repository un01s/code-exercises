/*
 * leetcode 75 sort colors
 * 
 * Given an array nums with n objects colored red, white, or blue, 
 * sort them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, 
 * white, and blue, respectively.
 * 
 * You must solve this problem without using the library's sort function.
 *
 * solution:
 * to make it in-place, try three pointers
 * int left = 0;
 * int mid = 0;
 * int right = nums.size()-1;
 * 
 * move the mid pointer, when it comes across 2, swap with the right pointer
 * when it meets 1, continue. when 0, swap with the left pointer.
 *  
 */

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        
        while (mid<=right)
        {
            if (nums[mid]==2)
            {
                swap(nums[mid],nums[right]);
                right--;
            }
            else if (nums[mid]==0)
            {
                // both left and mid pointers have the same initial position
                // when they are different it is because 1 occurs between them
                // that is when swapping left and mid, left pointer to mid must
                // be 1 instead of 0
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }
            else
            {
                mid++;
            }
        }
        
    }
};

