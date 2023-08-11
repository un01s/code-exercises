/*
 * leetcode 242 valid anagram
 *
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash_count[26] = {0};
        
        if (s.size() != t.size()) {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++) {
            hash_count[s[i] - 'a']++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            hash_count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (hash_count[i] != 0) {
                return false;
            }
            
        }
        
        return true;
    }
};

