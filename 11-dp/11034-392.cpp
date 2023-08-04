/*
 * leetcode 392
 *
 * dp
 *
 * editing distance
 *
 * t = "ahbgdc"
 * s = "abc"
 *
 *DP * a h b g d c
 * * 0 0 0 0 0 0 0 
 * a 0 1 1 1 1 1 1
 * b 0 0 0 2 2 2 2
 * c 0 0 0 0 0 0 3
 *
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int> > dp(s.size()+1, vector<int>(t.size()+1, 0));

        for (int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= t.size(); j++) {
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = dp[i][j-1];
            }
        }

        if (dp[s.size()][t.size()] == s.size()) return true;

        return false;
    }
};
