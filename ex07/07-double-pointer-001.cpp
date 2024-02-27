/*
 * leetcode 11
 * container with most water
 * https://leetcode.com/problems/container-with-most-water/
 *
 * let left points to 0, and right height.size()-1.
 * which side to move? Always choose the shorter one,
 * because the area is constrained by the shorter one.
 * 
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        // double-pointer
        int left = 0, right = height.size()-1;
        int tmp = 0, res = 0;
        while(left < right) {
            tmp = (right-left)*min(height[left], height[right]);
            if (tmp > res) res = tmp;
            if (height[left] >= height[right]) right--;
            else left++;
        }
        return res;
    }
};

