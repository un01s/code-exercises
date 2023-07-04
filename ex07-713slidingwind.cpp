/**
 * Leetcode 713 subarray product less than K
 * https://leetcode.com/problems/subarray-product-less-than-k/ 
 * 
 * Given an array of integers nums and an integer k, return the number of 
 * contiguous subarrays where the product of all the elements in the subarray 
 * is strictly less than k.
 *
 * 2023-07-03
 * 
 * continuous subarrays = substring
 * 
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // special case
        if (k <= 1) return 0;

        // initial window [left, right), empty window, nothing there
        int result = 0;
        // how many subarray whose product is less than k
        int left = 0, right = 0;
        int product = 1;
        while( right < nums.size() ) {
            int a = nums[right]; // increase right to increase the window
            right++;
            // update for data in the window
            product *= a;

            //cout << "[" << left << "," << right << ")" << endl;
            //cout << "product=" << product << endl;
            //cout << "result=" << result << endl;
            // 
            while(left <= right && product >= k) {
                // have to shrink the window
                // how to shrink enough?
                int b = nums[left];
                product = product/b;
                left++;
            }

            // the window [left, right)
            // not permutation of every element inside the window
            // instead, the subarray alwasy has the rightest element
            // for example, 5, 2, 6
            // the subwarray are [5,2,6], [2,6], and [6]
            // why this way? we are always counting the new subarray
            // because the sliding window moves by incrementing the right 
            result += right - left;
            //cout << "[" << left << "," << right << ")" << endl;
            //cout << "product=" << product << endl;
            //cout << "result=" << result << endl;
        }
        return result;
    }
    int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            while (left <= i && prod >= k) prod /= nums[left++];
            res += i - left + 1;
        }
        return res;
    }    
};

int main() {
    int a[] = {10, 5, 2, 6};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    int k1 = 100;

    int b[] = {1, 2, 3};
    int k2 = 0;
    vector<int> w(b, b + sizeof(b)/sizeof(int));

    int c[] = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    int k3 = 19;
    vector<int> x(c, c+sizeof(c)/sizeof(int));
    // expected answer = 18 instead of 29

    Solution s;

    if (8 == s.numSubarrayProductLessThanK(v, k1)) {
        cout << "OK\n";
    } else {    
        cout << "failed\n";
    }

    if (0 == s.numSubarrayProductLessThanK(w, k2)) {
        cout << "OK\n";
    } else {    
        cout << "failed\n";
    }

    if (18 == s.numSubarrayProductLessThanK(x, k3)) {
        cout << "OK\n";
    } else {    
        cout << "failed\n";
    }

    return 0;
}

