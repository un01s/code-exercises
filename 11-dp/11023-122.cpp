/*
 * leetcode 122
 * stocks[i], multiple times allowed
 *
 * dp[i][0] - the cash with stock on the i-th day
 * dp[i][1] - the max cash w/o stock on the i-th day
 *
 * dp[i][0] has two previous states:
 * 1) dp[i-1][0]
 * 2) dp[i-1][1]-prices[i] (buying stock)
 *
 * dp[i][1] has two previous states:
 * 1) dp[i-1][1]  (no stock trading)
 * 2) dp[i-1][0]+prices[i] (selling stock)
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int> > dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
        }
        return dp[len-1][1];
    }
};

int main() {
    return 0;
}
