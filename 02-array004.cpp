/*
 * 209 https://leetcode.com/problems/minimum-size-subarray-sum/
 * 
 * Given an array of positive integers nums and a positive integer target, 
 * return the minimal length of a subarray whose sum is greater than or 
 * equal to target. If there is no such subarray, return 0 instead.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0; // starting index of the sliding window
        int subLength = 0; // the length of the sliding window
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum >= target) {
                subLength = j - i + 1;
                result = result < subLength ? result: subLength;
                sum -= nums[i++]; // change i to make the sliding window smaller
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    int a[] = {2, 3, 1, 2, 4, 3};
    int v1 = 7;
    vector<int> va(a, a + sizeof(a)/sizeof(int));

    int b[] = {1, 4, 4};
    int v2 = 4;
    vector<int> vb(b, b + sizeof(b)/sizeof(int));

    int c[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int v3 = 11;
    vector<int> vc(c, c + sizeof(c)/sizeof(int));

    Solution ans;

    if (2 == ans.minSubArrayLen(v1, va)) {
        cout << "test1 OK\n";
    } else {
        cout << "test1 failed\n";
    }

    if (1 == ans.minSubArrayLen(v2, vb)) {
        cout << "test2 OK\n";
    } else {
        cout << "test2 failed\n";
    }

    if (0 == ans.minSubArrayLen(v3, vc)) {
        cout << "test3 OK\n";
    } else {
        cout << "test3 failed\n";
    }

    return 0;
}
