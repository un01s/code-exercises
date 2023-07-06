/**
 * Leetcode 
 * replace every space in a string with "%20"
 * input: s = "We are happy"
 * output: "We%20are%20happy"
 *
 * this is the same as [05-string003.cpp](https://github.com/un01s/code-exercises/blob/main/05-string003.cpp).
 * at that time, to the newSize correct
 * this time, use the double-pointer correctly at the first try.
 *
 * 2023-07-03
 *
 * double-pointer, in-place replacement, no extra space required
 * 1. find out how many spaces in the input string
 * 2. resize the string to the new size with the replacement
 * 3. replace from tail to head
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string& s) {
        cout << s << "->";
        int sSize = s.size();
        int count = 0;
        for (int i = 0; i < sSize; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        int newSize = sSize + 2*count; // 3*count - count
        s.resize(newSize); // important
        // i is the pointer at the tail of the new array
        // j is the pointer at the tail of the old array 
        for (int i = newSize-1, j = sSize-1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j]; 
            } else {
                s[i--] = '0';
                s[i--] = '2';
                s[i] = '%'; // both i and j decrease in the loop
            }
        } 
        cout << s << endl;
        return s;
    }    
};

int main() {
    string str1 = "we are happy";

    Solution s;
    s.replaceSpace(str1);

    return 0;
}

