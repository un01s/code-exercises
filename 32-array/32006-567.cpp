/*
 * leetcode 567 permutation in string
 * 
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring 
 * of s2.
 *
 * sliding window
 *
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        // what is required
        for (int i = 0; i < s1.size(); i++) {
            need[s1[i]]++;
        }        
        // sliding window
        int left = 0;
        int right = 0;
        int valid = 0;
        while(right < s2.size()) {
            // move in, increase the window with right
            char c = s2[right];
            right++;
            // update and process the window data
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            // check if the window has to be shrinked
            while (right-left >= s1.size()) {
                // check if a valid substring is found
                if (valid == need.size()) return true;
                // move out, shrink the window
                char d = s2[left];
                left++; // shrink the window
                // update or process the window data
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false; // not found
    }
};

