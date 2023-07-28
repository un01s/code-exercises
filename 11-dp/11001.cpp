/*
 * leetcode 509
 * fib
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        vector<int> dp(N + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};

// less memory
class Solution2 {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

// recursive
class Solution3 {
public:
    int fib(int N) {
        if (N < 2) return N;
        return fib(N-1)+fib(N-2);
    }
};

int main() {

    Solution s;
    Solution2 s2;
    Solution3 s3;

    cout << "Fib(4)=" << s.fib(4) << endl;
    cout << "Fib(5)=" << s2.fib(5) << endl;
    cout << "Fib(6)=" << s3.fib(6) << endl;
    
    return 0;
}
