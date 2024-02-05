/*
 * leetcode 387
 * first unique char in a string
 *
 */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        //for (auto a : s) mp[a]++;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 1) {
               return i;
            }
        }
        return -1;    
    }
};

// better?
class Solution {
public:
    int firstUniqChar(string s) {
        const int alphabet_size = 26;
        vector<int> alphabet(alphabet_size);
        
        for (char ch : s) {
            alphabet[ch - 'a'] += 1;
        }

        for (int index = 0; index < s.length(); ++index) {
            char letter = s[index];
            if (alphabet[letter - 'a'] == 1) {
                return index;
            }
        }

        return -1;
    }
};

