/*
 * leetcode 674
 *
 * continuous substring
 *
 * dp
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// DP
class Solution {
public:
    int lengthOfiCLIS(vector<int>& nums) {
        if (nums.size() < 1) return 0;

        vector<int> dp(nums.size(), 1); // initialized to 1
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) { // continuouse and increasing
                    dp[i] = dp[i-1] + 1;
                }
                if (dp[i] > res) res = dp[i];
        }
        return res;
    }
};

// greedy
class Solution2 {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                // continuous & increasing
                count++;
            } else {
                // reset the counter
                count = 1;
            }
            if (count > res) res = count;
        }
        return res;
    }
};

int main() {
    return 0;
}
