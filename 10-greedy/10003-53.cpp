/*
 * leetcode 53
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count = 0;
            for (int j = i; j < nums.size(); j++) {
                count += nums[j];
                res = count > res ? count : res;
            }
        }
        return res;
    }
};

// greedy
// when -2 1 together, the start point should be 1 instead of -2
// consecutive sub-array sum
//
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > res) {
                // get the max in the accumulated range
                res = count;
            }
            if (count <= 0) count = 0; // discoard the negative
        }
        return res;
    }
};

int main() {
    return 0;
}
