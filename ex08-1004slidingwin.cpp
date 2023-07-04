/**
 * Leetcode 1004 max consecutive ones III
 *
 * Given a binary array nums and an integer k, return the maximum number of 
 * consecutive 1's in the array if you can flip at most k 0's.
 *
 * 2023-07-04
 *
 * input : nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * output: 6
 * flip two zeros around the second 1's group, got 6 consecutive 1.
 *
 * where to flip zero to make the longest consecutive 1?
 * count the longest consecutive 1 can be implemented with sliding window
 * 
 * the idea is using the sliding-window approach,
 * but count both zero and one along the way at the same time
 * key: maintain the window so that the zero count is always k
 * along with this condition, make 1 consrcutive within the window
 *
 * when to increase the window? adding new element, what to update?
 * when to shrink the window? removing element, what to update?
 * when to update the result? increase the window or shrink the window?
 *
 * TODO: 340, 424, 485
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if (nums.size() == k) {
            return k;
        } // special case

        int left = 0, right = 0;
        int zeroes = 0, invalidZero = 0;
        int result = 0; // longest consecutive 1 if k 0 flipped
        while(right < nums.size()) {
            int a = nums[right];
            right++; // increase the window [left, right)
            if (a == 0) {
                zeroes++;
                //cout << "1:zeroes = " << zeroes << endl;
                if (zeroes > k) {
                    invalidZero = 1;
                }
            }
            //
            //cout << "[" << left << "," << right << ")-" << invalidZero << endl;
            while(invalidZero == 1) {
                // shrink the window
                int b = nums[left];
                left++;
                if (b == 0) {
                    zeroes--;
                    //cout << "2:zeroes = " << zeroes << endl;
                    if (zeroes <= k) {
                        invalidZero = 0;
                    }
                }
            }
            //cout << "[" << left << "," << right << ")-" << invalidZero << endl;
            // update the result
            result = max(result, right-left);
        }
        return result;
    }    
};

int main() {
    int a[] = {1,1,1,0,0,0,1,1,1,1,0};
    int k1 = 2;
    vector<int> u(a, a + sizeof(a)/sizeof(int));
  
    int b[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k2 = 3;
    vector<int> v(b, b + sizeof(b)/sizeof(int));

    int c[] = {0,0,1,1,0,0,1,1,1,0,1,1};
    int k3 = 12;
    vector<int> w(c, c + sizeof(c)/sizeof(int));

    Solution s;
    
    // test 1
    if (6 == s.longestOnes(u, k1)) {
        cout << "test1 OK\n";
    } else {
        cout << "test1 failed\n";
    }

    // test 2
    if (10 == s.longestOnes(u, k2)) {
        cout << "test2 OK\n";
    } else {
        cout << "test2 failed\n";
    }

    // test 3
    if (12 == s.longestOnes(w, k3)) {
        cout << "test3 OK\n";
    } else {
        cout << "test3 failed\n";
    }

    // test 4
    int d[] = {1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1};
    vector<int> x(d, d + sizeof(d)/sizeof(int));
    // test 4
    if (25 == s.longestOnes(x, 8)) {
        cout << "test4 OK\n";
    } else {
        cout << "test4 failed\n";
    }

    return 0;
}

