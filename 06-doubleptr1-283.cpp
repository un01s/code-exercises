/**
 * 283 move zeroes
 * https://leetcode.com/problems/move-zeroes/ 
 *
 * Given an integer array nums, move all 0's to the end of it while 
 * maintaining the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        // while-loop, not for-loop
        while (left < right) {
            if (nums[left] == 0) {
                for (int i = left+1; i <= right; i++) {
                    nums[i-1] = nums[i];
                }
                nums[right] = 0;
                left--;
                right--;
            } 
            left++;
            //cout << left << "-" << right << endl;
        }
    }
    void moveZeroes2(vector<int>& nums) {
        // endless loop when it reach the zeroes
        // need a condition to break the for-loop
        // if the for-loop does not change nums.size() to tail
        // endless loop
        int tail = nums.size()-1;
        for (int i = 0; i < tail; i++) {
            if (nums[i] == 0) {
                for (int j = i+1; j <= tail; j++) {
                    nums[j-1] = nums[j];
                }
                nums[tail] = 0;
                tail--;
                i--;
            } else {
                if (i == tail) {

                }
            } 
        }
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
};

int main() {
    int a[] = {0, 1, 0, 3, 12};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    Solution s;
    s.show(v);
    //s.moveZeroes(v);
    s.moveZeroes2(v);
    s.show(v);

    int b[] = {0};
    vector<int> w(b, b+sizeof(b)/sizeof(int));
    //s.moveZeroes(w);
    s.moveZeroes2(w);
    s.show(w);

    return 0;
}

