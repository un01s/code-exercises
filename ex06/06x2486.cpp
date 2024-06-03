/*
 * leetcode 2486
 */

class Solution {
public:
    int appendCharacters(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        int j = 0;
        for (int i = 0; i < len1; i++) {
            if (s[i] == t[j]) {
                j++;
            }
        }
        return len2 - j;
    }
};

