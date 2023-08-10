/**
 * 27 remove element 
 * https://leetcode.com/problems/remove-element/
 *
 * Given an integer array nums and an integer val,
 * remove all occurences of val in nums in-place, then
 * return the number of elements in nums which are not equal to val.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElementBF(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            // brute force
            if (nums[i] == val) {
                for(int j = i+1; j < size; j++) {
                    nums[j-1] = nums[j]; // move forward after one equal value
                }
                i--;    // current index
                size--; // current array size
            }
        }
        return size;        
    }
    int removeElement(vector<int>& nums, int val) {
        // use double-pointers: fast and slow
        // fast pointer moves faster than the slow pointer
        // one for-loop to complete the work of two loops
        int slow = 0;
        // fast looks for elements in the array for new array
        // slow points at the tail of the new array
        for(int fast=0; fast<nums.size(); fast++) {
            if (val != nums[fast]) { 
                nums[slow++] = nums[fast]; 
            }
        }
        return slow;
    }
    void show(vector<int>& nums) {
        cout << "{ ";
        for(int i = 0; i < nums.size(); i++) {
            if (i != (nums.size()-1)) {
                cout << nums[i] << ",";
            } else {
                cout << nums[i];
            }
        }
        cout << " }" << endl;
    }
    int removeElement2(vector<int>& nums, int val) {
        // double pointer moving towards each other
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            // left section
            while(left <= right && nums[left]!=val) {
                left++;
            }
            // right section
            while(left <= right && nums[right]==val) {
                right--;
            }
            // 
            if (left < right) {
                nums[left++] = nums[right--];
            }
        }
        return left;
    }
};

int main() {
    int a[] = {3, 2, 2, 3};
    int b[] = {0,1,2,2,3,0,4,2};
    int val = 3;
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    Solution s;
    // test
    s.show(v);
    if (2 == s.removeElement2(v, val)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }
    s.show(v);

    vector<int> w(b, b+sizeof(b)/sizeof(int));
    s.show(w);
    if (5 == s.removeElement2(w, 2)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }
    s.show(w);

    return 0;
}

