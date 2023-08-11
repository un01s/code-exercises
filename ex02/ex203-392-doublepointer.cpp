/*
 * leetcode 392
 * 
 * Given two strings s and t, return true if s is a subsequence of t, or false 
 * otherwise.
 * 
 * A subsequence of a string is a new string that is formed from the original 
 * string by deleting some (can be none) of the characters without disturbing 
 * the relative positions of the remaining characters. 
 * (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * 
 * the relative order is maintained.
 * s and t consist only of lowercase English letter
 * 
 * double pointer to compare
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size()) {
            while (j < t.size() && s[i] != t[j])
                ++j;
            
            if (j == t.size())
                return false;
            ++i;
            ++j;
        }
        return true;    
    }
};

int main() {
    string s1 = "abc";
    string t1 = "ahbgdc";
    string s2 = "axc";
    string t2 = "ahbgdc";

    Solution s;
    
    if (s.isSubsequence(s1, t1) == true) {
        cout << "test1 ok" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.isSubsequence(s2, t2) == false) {
        cout << "test2 ok" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
