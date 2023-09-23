/*
 * leetcode 1048
 *
 */

class Solution {
public:
    static bool cmp(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        unordered_map<string, int> mp;
        int ans = 0;
        for(string w : words) {
            int longest = 0;
            for (int i = 0; i < w.size(); i++) {
                string sub = w;
                sub.erase(i, 1);
                longest = max(longest, mp[sub]+1);
            }
            mp[w] = longest;
            ans = max(ans, longest);
        }
        return ans;
    }
};


