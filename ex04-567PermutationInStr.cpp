/**
 * 567 permutation in string
 * https://leetcode.com/problems/permutation-in-string/
 * 
 * Given two strings s1 and s2, return true if s2 contains a permutation of 
 * s1, or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the 
 * substring of s2.
 *
 * 2023-07-02 TODO in progress
 *
 * sliding window 
 *
 * input: s1 = "ab", s2 = "eidbaooo"
 * output: true
 * s2 contains one permutation of s1 ("ba")
 * 
 * input: s1 = "ab", s2 = "eidboaoo"
 * output: false
 * s2 contains no permutation of s1 ("ab" or "ba")
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string t, string s) {
        // does s have a permutation of t?
        unordered_map<char, int> need, window;
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }
         
        // try sliding-window
        int left = 0, right = 0; // window = [left, right)
        int valid = 0;
        // record if substring as one permuation of t exists
        int start = 0;
        //int len = INT_MAX; // no need for length
        while (right < s.size()) {
            // increase the window to find the solution
            char c = s[right];
            // increase right to enlarge the window,
            // until the chars inside the window has all chars of t
            //
            right++;
            if (need.count(c) > 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            // then stop increasing right, start to shrink the window
            // by increase left until all the chars inside the window
            // do not have all chars of t.
            //           
            //while(valid == need.size()) {
            while((right-left) >= t.size()) { // permutation has the same size
                // if substring found?
                if (valid == need.size()) return true;
                // update the window
                char d = s[left]; // move out of the window
                left++;
                // update for data inside the window 
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                } 
            }
        }
        return false; 
    }
};

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    string s3 = "eidboaooo";
    
    Solution ans;
    if (ans.checkInclusion(s1, s2)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }

    if (!ans.checkInclusion(s1, s3)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }
    return 0;
}

