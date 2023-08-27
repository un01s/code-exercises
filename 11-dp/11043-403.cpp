/*
 * leetcode 403
 * frog jump
 *
 * DP
 * 
 * initially the frog is on the first stone
 * and assume that the first jump must be 1 unit
 * if the frog's last jump was k units, its next jump must be either k-1, k, or
 * k+1 units.
 * the frog can only jump in the forward direction.
 * 
 * Given a list of stones's positions (in units) in sorted ascending order
 * determine if the frog can cross the river by landing on the last stone.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int> > dp(n, vector<int>(n));
        dp[0][0] = true;

        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1) {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        
        return false;    
    }
};

int main() {
    int a[] = {0,1,3,5,6,8,12,17};
    int b[] = {0,1,2,3,4,8,9,11};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));
   
    Solution s;

    if (s.canCross(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (false == s.canCross(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
