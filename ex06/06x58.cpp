/*
 * leetcode 58
 * length of last word
 * 
 * double-pointer
 *
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l, r;
        for (r = s.size() - 1; r >= 0; r--)
            if (s[r] != ' ')
                break;
        l = r;
        for (; l >= 0; l--)
            if (s[l] == ' ')
                break;
        return r - l;
    }
};

