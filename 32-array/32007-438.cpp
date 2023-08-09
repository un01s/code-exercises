/*
 * leetcode 438
 * find all anagrams in a string
 * 
 * permutation
 * 
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 */

// return an array of all the start indices of p's anagrams in s
// that is
// find the p's permutation in s, return the starting index of all these
// substrings
//
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;

        // sliding window
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res; // result

        while (right < s.size()) {
            char c = s[right];
            right++;
            // process and update
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) 
                    valid++;
            }
            // shrink from the left?
            while (right - left >= p.size()) {
                // match
                if (valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;
                // process and update
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res;        
    }
};
