/*
 * leetcode 541
 *
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2*k)) {
            // 1. reverse the first k every 2k 
            // 2. for the remaining less than 2k but greater than or equal to
            // k, reverse the first k
            if (i + k <= s.size()) {
                reverse(s.begin()+i, s.begin()+i+k);
            } else {
                // 3. less than k, reverse all remaining
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }
};

class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
                continue;
            }
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};

