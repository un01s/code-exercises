/*
 * leetcode 494
 * https://leetcode.com/problems/target-sum/
 * 
 * You are given an integer array nums and an integer target.
 * 
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the integers.
 *
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1".
 * 
 * Return the number of different expressions that you can build, which 
 * evaluates to target.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// backtracking
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    void backtracking(vector<int>& nums, int target, int sum, int startIndex) {
        if (sum == target) {
            res.push_back(path);
        }
        // if sum + nums[i] > target, stop
        for (int i = startIndex; i < nums.size() && sum+nums[i]<= target; i++) {
            sum += nums[i];
            path.push_back(nums[i]);
            backtracking(nums, target, sum, i+1);
            sum -= nums[i];
            path.pop_back();
        } 
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (S > sum) return 0; // no way to solve
        if ((S + sum)%2) return 0; // no way
        int bagSize = (S+sum)/2;

        res.clear();
        path.clear();
  
        sort(nums.begin(), nums.end()); // required
        backtracking(nums, bagSize, 0, 0);
        return res.size();
    }
};

// dp - 0/1 knapsack
// if the sum of all numbers is x, then with all minus signs, 
// the sum becomes sum-x
// x - (sum-x) == target
// so x = (target+sum)/2
// so the problem is transformed into the following:
// to fill the knapsack of volume of x, how many ways to do it 
// with given numbers, use either plus or minus sign (in or out)
// 
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (S > sum) return 0; // no way to solve
        if ((S + sum)%2) return 0; // no way
        // 0/1-knapsack
        int bagSize = (S+sum)/2;
        vector<int> dp(bagSize+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[bagSize];
    }
};

int main() {
    return 0;
}
