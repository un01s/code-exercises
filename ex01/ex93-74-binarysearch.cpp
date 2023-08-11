/*
 * leetcode 74
 * search a 2D matrix
 * 
 * You are given an m x n integer matrix matrix with the following two 
 * properties:
 * 
 * 1) Each row is sorted in non-decreasing order.
 * 2) The first integer of each row is greater than the last integer of the 
 *    previous row.
 * 
 * Given an integer target, return true if target is in matrix or false 
 * otherwise.
 * 
 * You must write a solution in O(log(m * n)) time complexity.
 * 
 * because the values are ordered
 * treat the 2d matrix as 1D array
 * use binary search
 * 
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target)
                return true;
            else if (mid_val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

