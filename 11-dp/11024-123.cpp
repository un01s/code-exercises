/*
 * leetcode 123
 * stocks[i], at most two times allowed: once or twice!
 *
 * dp[i][0] - no trade on the i-th day
 * dp[i][1] - first hold the stock on the i-th day
 * dp[i][2] - first NOT hold the stock on the i-th day
 * dp[i][3] - second hold the stock on the i-th day
 * dp[i][4] - second NOT hold the stock on the i-th day
 *
 * dp[i][j]: ith day, j-states, max cash
 *
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int len = prices.size();
        vector<vector<int> > dp(len, vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i]);
        }
        return dp[len-1][4];
    }
};

class Solution2 {
public: 
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        vector<int> dp(5, 0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[1] = max(dp[1], dp[0]-prices[i]);
            dp[2] = max(dp[2], dp[1]+prices[i]);
            dp[3] = max(dp[3], dp[2]-prices[i]);
            dp[4] = max(dp[4], dp[3]+prices[i]);
        }

        return dp[4];
    }
};

int main() {
    return 0;
}
