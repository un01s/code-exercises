/*
 * leetcode 647
 * https://leetcode.com/problems/palindromic-substrings/
 * 
 * Given a string s, return the number of palindromic substrings in it.
 * 
 * A string is a palindrome when it reads the same backward as forward.
 * 
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * input: s = "abc"
 * output: 3
 * "a", "b", "c"
 *
 * input: s = "aaa"
 * output: 6
 * "a", "aa", "aaa"
 * 
 * lowercase English letters
 *
 */

class Solution {
public:
    // DP
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        int res = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { 
                        res++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    // double-pointer
    int countSubstring(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += extend(s, i, i, s.size()); // i as the mid-point
            res += extend(s, i, i+1, s.size()); // i+1 as the mid-point
        }
        return res;
    }
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i]==s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};
