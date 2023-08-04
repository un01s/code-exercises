/*
 * leetcode 1143
 *
 * DP
 *
 * dp[i][j]
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        // starting from 1, ends at size()
        // [1, size()]
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    string text3 = "abc";
    string text4 = "abc";
    string text5 = "abc";
    string text6 = "def";

    Solution s;

    if (3 == s.longestCommonSubsequence(text1, text2)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (3 == s.longestCommonSubsequence(text3, text4)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (0 == s.longestCommonSubsequence(text5, text6)) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    return 0;
}
