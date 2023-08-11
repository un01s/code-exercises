/*
 * leetcode 387
 *
 */

// brute force
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        for(int i = 0; i < s.length(); i++) {
            if(m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

// without using map
// use the array as the hash-table
//
class Solution2 {
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
