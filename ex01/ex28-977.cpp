/*
 * leetcode 977
 * 
 * sorted squares of an array
 * two pointers
 * 
 *
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // find the min of the absolute value from nums
        int small = 0;
        for (int i = 1; i < nums.size(); i++) {
            if(abs(nums[i]) < abs(nums[small])) {
                small = i;
            }
        }
        cout << small << endl;
        // two pointers starting from small and its neighbor
        vector<int> r(nums.size(), 0); // result
        int index = 0;
        int left = small, right = small+1;
        //while (left >= 0 && right < nums.size()) {
        //    if (abs(nums[left]) > abs(nums[right])) {
        while (left >= 0 || right < nums.size()) {
            if (left < 0 || right < nums.size() && abs(nums[left]) > abs(nums[right])) {
                r[index] = nums[right]*nums[right];
                right++;
            } else {
                r[index] = nums[left]*nums[left];
                left--;
            }
            index++;
        }
        return r;
    }
};


