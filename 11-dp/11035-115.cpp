/*
 * leetcode 115
 *
 * Given two strings s and t, return the number of distinct subsequences
 * of s which equals t.
 * 
 * The test cases are generated so that the answer fits on a 32-bit signed 
 * integer.
 *
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 *
 * [    r a b b i t
 *   [1 0 0 0 0 0 0 ]
 * r [1 1 0 0 0 0 0 ]
 * a [1 1 1 0 0 0 0 ]
 * b [1 1 1 1 0 0 0 ]
 * b [1 1 1 2 1 0 0 ]
 * b [1 1 1 3 3 0 0 ]
 * i [1 1 1 3 3 3 0 ]
 * t [0 1 1 3 3 3 3 ]]
 *
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 *
 * dp[i][j] = number of subsequence of s ending at i-1 occurs t ending at j-1
 * notes: i-1, and j-1
 *
 * s[i-1] == t[j-1]
 * or not equal
 * dp[i][j] = either dp[i-1][j-1] or dp[i-1][j]
 *
 * how many t in s, not how many s in t !!
 *
 * DP - b a g
 *  - 1 0 0 0
 *  b 1 1 0 0  
 *  a 1 1 1 0
 *  e 1 1 1 0
 *  g 1 1 1 1
 *  g 1 1 1 2
 *
 * [ - b a g
 *- [1 0 0 0 ]
 *b [1 1 0 0 ]
 *a [1 1 1 0 ]
 *b [1 2 1 0 ]
 *g [1 2 1 1 ]
 *b [1 3 1 1 ]
 *a [1 3 4 1 ]
 *g [0 3 4 5 ]]
 *  
 */

class Solution {
public:
    void print(vector<vector<uint64_t> >& v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << "[";
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << "]";
        }
        cout << "]" << endl;
    }

    // DP
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
        for (int i = 0; i < s.size(); i++) dp[i][0] = 1;
        for (int j = 1; j < t.size(); j++) dp[0][j] = 0;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];    
    }
};
