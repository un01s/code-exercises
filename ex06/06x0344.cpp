/*
 * leetcode 344
 * reverse string
 *
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(), n0 = s.size() / 2;
        for (int i = 0; i < n0; i++) {
            s[i] ^= s[n - 1 - i];
            s[n - 1 - i] ^= s[i];
            s[i] ^= s[n - 1 - i];
        }
    }
};

