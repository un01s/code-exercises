/*
 * leetcode 242
 * valid anagram
 * by rearranging the letters of a different word to form another word
 *
 */

class Solution {
public:
    int map[26] = {0};
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
          return false;
        }

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            map[idx]++;
        }

        for (int j = 0; j < t.size(); j++) {
            int idx = t[j] - 'a';
            map[idx]--;
        }

        for (int k = 0; k < 26; k++) {
            if (map[k] != 0)
                return false;
        }
        return true;    
    }
};

// hash-table in an array
// O(n) time, O(1) space complexity
//
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

