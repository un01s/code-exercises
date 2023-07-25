/*
 * leetcode 122
 *
 * You are given an integer array prices where prices[i] is the price of a 
 * given stock on the ith day.
 *
 * On each day, you may decide to buy and/or sell the stock. You can only hold 
 * at most one share of the stock at any time. 
 * However, you can buy it then immediately sell it on the same day.
 *
 * Find and return the maximum profit you can achieve.
 * 
 * Solution:
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// greedy: collect all positive profit every day as many as possible
// time O(n), space O(1)
// 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};

int main() {
    return 0;
}
