/*
 * leetcode 9 palindrome number
 *
 * Given an integer x, return true if x is a palindrome, 
 * and false otherwise.
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r){
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        return checkPalindrome(s);
    }
};

int main() {
    int x = 121;
    int y = -121;
    int z = 10;

    Solution s;
    
    if (s.isPalindrome(x)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (!s.isPalindrome(y)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (!s.isPalindrome(z)) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    return 0;
}

