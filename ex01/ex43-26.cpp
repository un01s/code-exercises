/* 
 * leetcode 26 
 * https://github.com/Seanforfun/Algorithm-and-Leetcode/blob/master/leetcode/26.%20Remove%20Duplicates%20from%20Sorted%20Array.md
 *
 * https://github.com/Seanforfun/Algorithm-and-Leetcode/tree/master/leetcode
 *
 */

class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int index = 1;
        int pre = nums[0];
        for(int i = 1; i < nums.length; i++){
            if(nums[i] == pre) continue;
            else{
                nums[index++] = nums[i];
                pre = nums[i];
            }
        }
        return index;
    }
}

