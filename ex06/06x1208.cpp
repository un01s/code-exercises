/*
 * leetcode 1208
 * get equal sustrings within budget
 *
 */

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int n = s.size();
        int l = 0, r; // 2 pointers
        int cost = 0, len = 0;

        // Initialize the window by moving r while cost<=maxCost
        for (r = 0; r < n; r++) {
            cost += abs(s[r] - t[r]);
            if (cost > maxCost) {
                cost -= abs(s[r] - t[r]);
                break;
            }
        }

        // If the initial window exceeds the whole string
        if (r == n && cost <= maxCost)
            return n;

        len = r; // initial length for the valid window

        // Sliding the window
        for (; r < n; r++) {
            cost += abs(s[r] - t[r]);
            while (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};

