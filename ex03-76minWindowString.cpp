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
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int inString(string s, char c) {
        for(int i = 0; i < s.size(); i++) {
            if (c == s[i]) {
                return i;
            }
        }
        return -1;
    }
    string minWindow(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        if (tSize <= sSize) {
            int left = 0;
            int right = sSize - 1;
            // try sliding window (double-pointer)
            while(left < right) {
                int leftPos = inString(t, s[left]);
                int rightPos = inString(t, s[right]);
                if (-1 == leftPos) {
                    left++;
                } else {
                    
                }
                
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

