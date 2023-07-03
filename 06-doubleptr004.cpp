/**
 * Leetcode 151 reverse words in a string 
 * https://leetcode.com/problems/reverse-words-in-a-string/
 * the same as 05-string004.cpp
 *
 * 
 * 2023-07-03
 *
 * the solution is in-place reverse the order of the words in a string
 * 1. remove unnecessary spaces: two or more spaces to one space
 * 2. reverse the whole string
 * 3. reverse each word
 * 
 * O(1)
 *
 * after the submission at leetcode
 * it suggests the following
 * 509 fibonacci number (easy)
 * 186 reverse words in a string II (hard)
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void removeExtraSpace(string& s) {
        // fast and slow pointers
        int slow = 0, fast = 0;
        // all spaces at the head of the string
        while (s.size() > 0 && fast < s.size() && s[fast]==' ') {
            fast++;
        }
        // remove extra spaces in the middle of the string
        for (; fast < s.size(); fast++) {
            if ((fast-1) > 0 && s[fast-1] == s[fast] && s[fast] == ' ') {
                continue;
            } else {
                s[slow++] = s[fast];
            }
        }
        // remove the trailing spaces at the end
        if ((slow-1) > 0 && s[slow-1] == ' ') {
            s.resize(slow-1);
        } else {
            s.resize(slow);
        }
    }
    void reverse(string& s, int start, int end) {
        int i = start;
        int j = end;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size()-1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                // at the tail or space
                reverse(s, start, i-1);
                start = i + 1; // the new start of next word
            }
        }
        return s;
    }    
};

int main() {
    string str1 = "the sky is blue";
    string str2 = "  hello  world   ";
    
    Solution s;
    cout << str1 << endl;
    cout << s.reverseWords(str1) << endl;

    cout << str2 << endl;
    cout << s.reverseWords(str2) << endl;

    return 0;
}

