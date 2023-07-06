/**
 * Leetcode 438 find all anagrams in a string 
 * 
 * Given two strings s and p, return an array of all the start indices of p's 
 * anagrams in s. You may return the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a 
 * different word or phrase, typically using all the original letters exactly 
 * once.
 *
 * 2023-07-03
 * 
 * find all permutation of p in s, return their starting index of s.
 * sliding-window
 *
 * 242 if one string s contains a valid anagram of w
 * it is 04-hashtable001.cpp
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for(int i = 0; i < p.size(); i++) {
            need[p[i]]++;
        }
        // start sliding-window approach
        int left = 0;
        int right = 0;
        int valid = 0;
        vector<int> result;
        while(right < s.size()) {
            char c = s[right]; // char move into the window
            right++;
            // update data inside the window
            if (need.count(c) > 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            // should we shrink the window from left
            while((right-left) >= p.size()) {
                // found
                if (valid == need.size()) {
                    result.push_back(left);
                }
                // char to move out from the left
                char d = s[left];
                left++;
                // update data in the window
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return result;  
    }
};

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    Solution ans;
    vector<int> v = ans.findAnagrams(s, p);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ",";
    }
    cout << endl;

    return 0;
}

