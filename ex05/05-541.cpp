/*
 * leetcode 541
 * reveerse string II
 *
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // every 2k, reverse the first k chars
            // less than 2k but greater or equal to k, reverse the first k
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // less than k, reverse all
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
