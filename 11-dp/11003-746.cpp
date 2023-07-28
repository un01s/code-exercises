/*
 * leetcode 746
 * Min Cost Climbing Stairs
 * 
 * You are given an integer array cost where cost[i] is the cost of ith step 
 * on a staircase. Once you pay the cost, you can either climb one or two steps.
 *
 * You can either start from the step with index 0, or the step with index 1.
 *
 * Return the minimum cost to reach the top of the floor.
 *
 * 1. define dp[i]
 *    dp[i] i-th cost
 * 2. dp[i] = min(dp[i-1], dp[i-2])
 *  
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i-1]+cost[i - 1], dp[i-2]+cost[i - 2]);
            cout << "dp" << "[" << i << "]=" <<dp[i] << endl;
        }
        return dp[cost.size()];    
    }
};

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        int c;
        for (int i = 2; i < n; i++) {
            c = min(a, b) + cost[i];
            a = b;
            b = c;

            cout << ":a=" << a << endl;
            cout << ":b=" << b << endl;
        }    
        return min(a, b);
    }
};

int main() {
    int a[] = {10, 15, 20};
    int b[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> c1(a, a+sizeof(a)/sizeof(int));
    vector<int> c2(b, b+sizeof(b)/sizeof(int));

    Solution s;
    Solution2 s2;

    cout << s.minCostClimbingStairs(c1) << endl;
    cout << s.minCostClimbingStairs(c2) << endl;
    cout << s2.minCostClimbingStairs(c1) << endl;
    cout << s2.minCostClimbingStairs(c2) << endl;

    return 0;
}
