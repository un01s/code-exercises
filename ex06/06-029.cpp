/*
 * leetcode 3
 * length of longest substring without repeasting characters
 *
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int res = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            i = max(i, m[s[j]]);
            m[s[j]] = j + 1;
            res = max(res, j-i+1);
        }
        return res;
    }
};

