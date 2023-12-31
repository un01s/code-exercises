/*
 * leetcode 518
 * coin change II
 *
 * all values of coins are unique.
 * 
 * Input: amount = 5, coins = [1,2,5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        
        sort(coins.begin(),coins.end());
        
        dp[0]=1;
        for(int i=0;i<coins.size();i++)
        {
             for(int j=coins[i];j<=amount;j++)
            { 
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

