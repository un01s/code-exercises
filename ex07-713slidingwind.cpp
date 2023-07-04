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
        // initial window [left, right), empty window, nothing there
        int result = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > k) {
                count++;
            }
        }
        if (count == nums.size()) {
            return result;
        }

        // how many subarray whose product is less than k
        for (int i = 0; i < nums.size(); i++) {
            int left = i, right = i;
            int product = 1;
            while( right < nums.size() ) {
                int a = nums[right]; // increase right to increase the window
                right++;
                // update for data in the window
                product *= a;
                if (product < k) {
                    result++;
                } 

                cout << "[" << left << "," << right << ")" << endl;
                cout << "product=" << product << endl;
                cout << "result=" << result << endl;
                // 
                while(product >= k) {
                    // have to shrink the window
                    left++;
                    int b = nums[left];
                    product = product/b;
                }
            }
        }
        return result;
    }    
};

int main() {
    int a[] = {10, 5, 2, 6};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    int k1 = 100;

    int b[] = {1, 2, 3};
    int k2 = 0;
    vector<int> w(b, b + sizeof(b)/sizeof(int));

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

    return 0;
}

