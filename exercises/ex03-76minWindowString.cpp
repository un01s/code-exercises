/**
 * 76 minimum window substring
 * https://leetcode.com/problems/minimum-window-substring/ 
 *
 * Given two strings s and t of lengths m and n respectively, return 
 * the minimum window substring of s such that every character in t 
 * (including duplicates) is included in the window. 
 * If there is no such substring, return the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * 2023-07-02 TODO in progress
 *
 * order is not important, find out the occurrence, the set, hash-table
 *  
 * idea???
 * use the array, double pointer
 * 
 * find all the substrings of s which have every letter of t at least once
 * then return the shortest substring, the order of letters of t is 
 * not important
 * 
 * set, map(k, v), hash-table
 *
 * solution:
 *
 * use double-pointers: left and right
 * move left at the first char of s that is one of t
 * move right at the last char of s that is one t
 * then find the rest of t inside (left, right)
 * if the number of t char is two, then this is a double-pointer problem.
 * if there are more, the double-pointer becomes more.
 *
 * instead we should have a map which has every char of t as its key, 
 * its location (or index in s) as its value.
 *  
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }
         
        // try sliding window (double-pointer)
        int left = 0, right = 0; // window = [left, right)
        int valid = 0;
        // record minSubstring info
        int start = 0;
        int len = INT_MAX;
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
            while(valid == need.size()) {
                // after find the solution,
                // optimize the solution, minimum length here 
                // update the window
                if ((right-left) < len) {
                    start = left;
                    len = right - left;
                }
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
        return len==INT_MAX ? "" : s.substr(start, len); 
    }

    // brute force
    string minWindowBF(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = i+1; j < s.size(); j++) {
                // if s[i:j] has all chars of t
                // update
            }
        }
        return "";
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution ans;
    if ("BANC" == ans.minWindow(s, t)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }

    string str1 = "a";
    string t1 = "aa";
    if ("" == ans.minWindow(str1, t1)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }
    return 0;
}

