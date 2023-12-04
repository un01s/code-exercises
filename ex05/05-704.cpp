/* leetcode 704
 * binary search, array, ordered
 */

// binary search
// i = 0, j = n-1, so the range is [i, j], both ends inclusive
// so while (i <= j) {...}, it has to be <= instead of <
// because i, j both inclusive
// 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int m = i + (j-i)/2;
            if ( nums[m] < target) i = m+1;
            else if (nums[m] > target) j = m-1;
            else return m;
        }
        return -1;
    }
};

// another binary search
// this time, [i, j), left closed and right open
// this means that i is inclusive, while j is not.
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        while (i < j) {
            int m = i + (j-i)/2;
            if (nums[m] > target) {
                j = m;
            } else if (nums[m] < target) {
                i = m+1;
            } else {
                return m;
            }
        }
        return -1;
    }
};

// recursive
// [left, right]
class Solution {
public:
    int binary(vector<int>& nums, int target, int s, int e) {
        int m = s + (e-s)/2;
        if (s > e) {
            return -1;
        }
        if (nums[m] == target) {
            return m;
        }
        if (nums[m] < target) {
            return binary(nums, target, m+1,e);
        } else {
            return binary(nums, target, s, m-1);
        }
    }
    int search(vector<int>& nums, int target) {
        return binary(nums, target, 0, nums.size()-1);
    }
};
