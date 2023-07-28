/*
 * leetcode 125 valid palindrome
 * the same when reversed after removing non-alphanumeric
 *
 * two pointers
 *
 */

class Solution {
public:
    bool isAlphanumeric(char c) {
        if((c >= 'a' && c <= 'z') || ( c>= 'A' && c<='Z') || (c>='0' && c<='9')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        string t;
        // remove all non-alphanumerics
        for (int i = 0; i < s.size(); i++) {
            if (isAlphanumeric(s[i])) {
                t.push_back(tolower(s[i]));
            }
        }
        //
        if (t.size() == 0) {
            return true;
        }
        int left = 0;
        int right = t.size()-1;
        int mid = (left+right)/2;
        for(int i = 0; i <= mid; i++) {
            if (t[left++]!=t[right--]) {
                return false;
            }
        }
        return true;
    }
};
