/*
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0704.二分查找.md
 *
 * binary search
 * - the array is ordered
 * - every element in the array is unique
 * its complexity is O(log n)
 *
 * there are two ways to define the range for search
 * - [left, right] 左闭右闭的区间 while (left <= right)
 * - [left, right) 左闭右开的区间 while (left < right)
 * choose one and keep it constant!
 *
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// [left, right]
// time O(log n)
// space O(1)
//
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // [left, right]
        while (left <= right) { // if left==right, [left, right] still valid, so <=
            int middle = left + ((right - left) / 2);// i.e. (left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target is in the left side，[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target in the right，[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // target found
            }
        }
        // no match
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // [left, right)
        while (left < right) {
            int middle = (left + right)/2;
            if (nums[middle] > target) {
                right = middle; // in the left side, [left, middle)
            } else if (nums[middle] < target) {
                left = middle + 1; // target in the right side, [middle+1, right) 
            } else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    int a[] = {-1,0,3,5,9,12};
    int target1 = 9;
    int target2 = 2;
    // use array to initialize a vector
    vector<int> nums(a, a + sizeof(a)/sizeof(int));
    // another way is std::vector<int> nums = {10, 20, 30};
    Solution1 ans1;
    Solution2 ans2;

    if (4 == ans1.search(nums, target1)) {
        cout << "S1: Test1 OK\n";
    } else {
        cout << "S1: Test1 failed\n";
    }

    if (-1 == ans1.search(nums, target2)) {
        cout << "S1: Test2 OK\n";
    } else {
        cout << "S1: Test2 failed\n";
    }

    if (4 == ans2.search(nums, target1)) {
        cout << "S2: Test1 OK\n";
    } else {
        cout << "S2: Test1 failed\n";
    }

    if (-1 == ans2.search(nums, target2)) {
        cout << "S2: Test2 OK\n";
    } else {
        cout << "S2: Test2 failed\n";
    }
    
    return 0;
}
