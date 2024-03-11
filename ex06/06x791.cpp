/*
 * leetcode 791
 * custom sort string
 *
 */

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        s.clear();
        for (auto i : order) {
            while (mp[i] > 0) {
                mp[i]--;
                s.push_back(i);
            }
        }
        for (auto i : mp) {
            while (i.second > 0) {
                s.push_back(i.first);
                i.second--;
            }
        }
        return s;
    }
};
