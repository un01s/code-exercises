/*
 * leetcode 646
 *
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // DP
        sort(begin(pairs), end(pairs));
        int N = pairs.size();
        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] >= pairs[i][0]) continue;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(begin(dp), end(dp));        
    }
};

