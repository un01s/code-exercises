/*
 * leetcode 53
 * max subarray
 *
 * Given an integer array nums, find the subarray with the largest sum, 
 * and return its sum.
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

// brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // subarray, no sorting
        int res = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            count = 0;
            for(int j = i; j < nums.size(); j++) {
                count += nums[j];
                res = count > res ? count : res;
            }
        }
        return res;        
    }
};


// greedy
// local max to global max
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > res) res = count; // moving the ending pos
            if (count <= 0) count = 0; // restart the starting pos
        }
        return res;
    }
};

// dp
// 
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0]; // initial, starting from 0
        // starting from 1
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]); 
            if (dp[i] > res) res = dp[i];
        }
        return res;
    }
};

int main() {
   int a[] = {-2,1,-3,4,-1,2,1,-5,4};
   vector<int> v1(a, a+sizeof(a)/sizeof(int));

   Solution3 s;

   if (6 == s.maxSubArray(v1)) {
       cout << "test1 OK" << endl;
   } else {
       cout << "test1 failed" << endl;
   }

   return 0;
}
