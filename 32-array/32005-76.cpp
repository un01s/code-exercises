/*
 * leetcode 76
 * minimum window subtring
 *
 * Given two strings s and t of lengths m and n respectively, return the 
 * minimum window substring of s such that every character in t (including 
 * duplicates) is included in the window. 
 * If there is no such substring, return the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 *
 * - sliding window [left, right)
 * - using unordered_map to handle the procesing
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // helper
    // helper
    void printS(string s) {
        if (s.empty()) return;

        cout << "string: ";
        for(int i = 0; i < s.size(); i++) {
            cout << s[i] << " ";
        }
        cout << endl;
        return;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        // count what is included in t
        for(int i = 0; i < t.size(); i++) need[t[i]]++;

        int left = 0, right = 0;
        int valid = 0;
        // record min substring:
        int start = 0; 
        int len = INT_MAX;
        while (right < s.size()) {
            char c = s[right]; // move into the window
            right++; // increase the window
            // update/process data in the window
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            // shrink the window?
            while(valid == need.size()) {
                if (right-left < len) {
                    start = left;
                    len = right-left;
                }
                // d is moved out
                char d = s[left];
                left++;
                // update/process the data in the window
                if (need.count(d)) {
                    if(window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    
    Solution s;
    string a1 = s.minWindow(s1, t1);
    s.printS(s1);
    s.printS(t1);
    s.printS(a1);

    return 0;
}
