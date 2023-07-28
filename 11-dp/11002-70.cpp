/*
 * leetcode 70
 * climbing stairs
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways 
 * can you climb to the top?
 * 
 * 1. dp[i]: how many ways to get the i-th stair
 * 2. dp[i] = dp[i-1] + dp[i-2];
 *    to arrive the i-th stair, either 1 step from (i-1)th or 
 *    2 steps from (i-2)th.
 * 3. dp[1] = 1, dp[2] = 2; N is a positive integer!
 * 4. the order is from stair 1 to stair N
 * 5. dp[0] has no meaning in this case.
 * 
 * this looks just another fibonacci.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }       
        return dp[n];
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        return climbStairs(n-1)+climbStairs(n-2);        
    }
};

int main() {
    Solution s;
    cout << "ways to climb to 3th stair : " << s.climbStairs(3) << endl;
    cout << "ways to climb to 4th stair : " << s.climbStairs(4) << endl;
    cout << "ways to climb to 5th stair : " << s.climbStairs(5) << endl;
    return 0;
}

