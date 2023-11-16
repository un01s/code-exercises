/*
 * leetcode 11
 * container with most water
 *
 * double-pointer
 * the left starts at the index of 0
 * the right starts at the index of n-1, where n = height.size()
 * every time, move the shorter one so that it is possible to maximize
 * the area
 *
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int area = 0;
        while (left < right) {
            if (height[left] >= height[right]) {
                area = max(area, (right-left)*height[right]);
                right--;
            } else {
                area = max(area, (right-left)*height[left]);
                left++;
            }
        }   
        return area;
    }
};

