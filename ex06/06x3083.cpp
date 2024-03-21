/*
 * leetcode 3083
 * existence of a substring in a string and its reverse
 */

class Solution {
public:
    bool isSubstringPresent(string s) {
        vector<vector<int>> v(26, vector<int>(26, 0));
        for (int i = 0; i + 1 < s.size(); i++) {
            v[s[i] - 'a'][s[i + 1] - 'a'] = 1;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (v[i][j] && v[j][i]) {
                    return true;
                }
            }
        }
        return false;
    }
};

