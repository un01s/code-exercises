/**
 * 28 find the index of the first occurrence in a string 
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 *
 * 
 * Given two strings needle and haystack, return the index of the first 
 * occurrence of needle in haystack, or -1 if needle is not part of haystack. 
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int fast = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (fast < needle.size() && haystack[i+fast] == needle[fast]) {
                fast++;
            }
            if (fast == needle.size()) {
                return i;
            }
            fast = 0;
        }
        return -1;
    }
};

int main() {
    string h = "sadbutsad";
    string n = "sad";

    Solution s;
    if (0 == s.strStr(h, n)) {
        cout << n << " occurs at 0 in " << h << endl;
    } else {
        cout << h << " has no " << n << endl;
    }

    if (-1 == s.strStr("leetcode", "leeto")) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }
    return 0;
}

