/*
 * leetcode 376
 * wiggle subsequence
 *
 * delete some elements to make the longest wiggle subsequence
 * Q: what element to eliminate?
 * A: one on the slope to remove, one at the peak or at the bottom 
 *    most likely to keep
 * 
 * case1: there is a flat among up and down
 * case2: head and tail
 * case3: a flat among up or down slope
 *  
 */

#include <iostream>
#include <vector>

using namespace std;

// greedy
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // empty or one-element array
        if (nums.size() <= 1) return nums.size();
        // 
        int curDiff = 0;
        int preDiff = 0;
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            curDiff = nums[i+1] - nums[i];
            // check the peak
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                count++;
                preDiff = curDiff;
            }
            //preDiff = curDiff;
        }
        return count;
    }
};

// dynamic planning
// current element if counted is either a peak or a valley
// a possible peak : nums[i] > nums[i-1]
// a possible valley: nums[i] < nums[i-1]
//
class Solution2 {
public: 
    int dp[1005][2];
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
            }
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);    
    }
};

int main() {
    return 0;
}
