/*
 * leetcode 5
 * longest palindromic substring
 *
 */

class Solution {
public:
    string midToSide(string s, int left, int right) {
        while (left >= 0 && right <= s.length() - 1 && s[left] == s[right]) {
            left--; 
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        int len = s.length();
        // empty input string
        if(len == 0) return "";
        //
        string r = s.substr(0, 1);
        for (int i = 0; i <= len - 2; i++) {
            string tmp = midToSide(s, i, i);
            if (tmp.length() > r.length())
                r = tmp;
            tmp = midToSide(s, i, i + 1);
            if (tmp.length() > r.length())
                r = tmp;
        }
        return r;
    }
};
