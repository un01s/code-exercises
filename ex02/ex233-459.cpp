/*
 * leetcode 459
 * repeated substring pattern
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if (len <= 1) return false;

        int slow = 0, fast = 1;
        while (fast < len)
        {
            while (fast < len && s[fast]!=s[slow])
                fast++;

            if (fast == len) return false;
            int tmp = fast;
            if (len%tmp == 0)
            {
                while (fast < len && s[fast++]==s[slow++]) ;
                if (s[fast-1] == s[slow-1]) return true; 
            }
            slow = 0;
            fast = tmp + 1;
        }
        return false;    
    }
};

int main() {
    string s1 = "abab";
    string s2 = "aba";
    string s3 = "abcabcabcabc";

    Solution s;

    if (s.repeatedSubstringPattern(s1) == true) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.repeatedSubstringPattern(s2) == false) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (s.repeatedSubstringPattern(s3) == true) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    return 0;
}
