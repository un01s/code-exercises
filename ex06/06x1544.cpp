/*
 * leetcode 1544
 * make the string great
 *
 * double-pointer
 */

class Solution {
public:
    string makeGood(string s) {
        int last_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last_index and abs(s[i] - s[last_index - 1]) == 32)
                last_index--;
            else
                s[last_index++] = s[i];
        }
        return s.substr(0, last_index);
    }
};

