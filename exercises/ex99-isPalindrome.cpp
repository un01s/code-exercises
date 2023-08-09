/*
 * check if palindrome
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right++;
        }
        return true;
    }
};

int main() {
    string s1 = "aba";
    string s2 = "abba";

    Solution s;
 
    if (true == s.isPalindrome(s1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (true == s.isPalindrome(s2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
