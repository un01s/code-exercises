/**
 * string left shift k characters
 * 
 * input:  s = "abcdefg", k = 2
 * output: s = "cdefgab"
 *
 * constraints: 
 *    1 <= k <= 10000
 *
 * 2023-07-01
 *
 * solution idea:
 * 
 * if we are using extra space, then the shifting is easy
 * - find the new start, and fill all the characters one after another
 *
 * if we do not use extra space, no new string for example, it is challenging
 * - reverse the first k-char sub-string [0, k-1]
 * - reverse the substring from k to the end [k, s.size()-1]
 * - reverse the whole string
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end) {
        // use the substring, [start, end], both ends included
        // double pointer: start and end, moving toward each other
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    } 
    string leftShift(string s, int k) {
        reverse(s, 0, k-1);
        reverse(s, k, s.size()-1);
        reverse(s, 0, s.size()-1);
        return s;
    }
};

int main() {
    string str1 = "abcdefg";
    string str2 = "123456xyzuvw";
    int k1 = 2, k2 = 6;
    
    Solution s;
    cout << str1 << " left shift " << k1 << endl;
    cout << s.leftShift(str1, k1) << endl;

    cout << str2 << " left shift " << k2 << endl;
    cout << s.leftShift(str2, k2) << endl;

    return 0;
}

