/*
 * leetcode 343
 * integer break
 * 
 * Given an integer n, break it into the sum of k positive integers, 
 * where k >= 2, and maximize the product of those integers.
 * 
 * Return the maximum product you can get.
 * 
 * 2 <= n <= 58
 *
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(int n,vector<int> &dp){
        if( n==0 ) return 1;
        if( dp[n]!=-1 ) return dp[n];
        int ans = n;
        for(int i = 1; i <= n; i++){
            ans=max(ans,i*helper(n-i,dp));
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        if( n<4 ) return n-1;

        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};

/*
 * start from 1 to j, then there are two ways to get dp[i]
 * 1) j * (i-j)
 * 2) j * dp[i-j]
 * so dp[i] = max(dp[i], max((i-j)*j, dp[i-j]*j));
 * 
 * there is no meaning of dp[0] or dp[1]
 * dp[2] = 1 because 2 = 1 + 1, 1*1 = 1
 *
 
 */
class Solution2 {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0); // dp[i] max product after breaking i
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for(int j = 1; j <= i/2; j++) {
                dp[i] = max(dp[i], max((i-j)*j, dp[i-j]*j));
            } 
        }
        
        return dp[n];
    }
};

int main() {
    int n1 = 2;
    int n2 = 10;

    Solution2 s;
    if (1 == s.integerBreak(n1)) {
        cout << "test 1 OK" << endl;
    } else {
        cout << "test 1 failed" << endl;
    }

    if (36== s.integerBreak(n2)) {
        cout << "test 2 OK" << endl;
    } else {
        cout << "test 2 failed" << endl;
    }

    return 0;
}
