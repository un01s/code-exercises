/*
 * leetcode 121
 * greedy
 */

// brute force
// O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++){
                result = max(result, prices[j] - prices[i]);
            }
        }
        return result;
    }
};

// greedy
// O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);  // get the min price at the left
            result = max(result, prices[i] - low); // get the max profit
        }
        return result;
    }
};

