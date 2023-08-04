/*
 * leetcode 1035
 *
 * DP
 * the solution is exactly the same as 1143.
 *
 * dp[i][j]
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int> > dp(A.size()+1, vector<int>(B.size()+1, 0));
        // starting from 1, ends at size()
        // [1, size()]
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};

int main() {
    int a[] = {1, 4, 2};
    int b[] = {1, 2, 4};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));
    Solution s;

    if (2 == s.maxUncrossedLines(v1, v2)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}
