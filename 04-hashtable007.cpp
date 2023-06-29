/**
 * 383 ransom note
 * https://leetcode.com/problems/ransom-note/
 * 
 * Given two strings ransomNote and magazine, return true if ransomNote 
 * can be constructed by using the letters from magazine and false otherwise.
 * 
 * Each letter in magazine can only be used once in ransomNote.
 * 
 * constraints:
 * 1. 1 <= ransomNote.length, magazine.length <= 10^5
 * 2. ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

// brutal force
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                if (magazine[i] == ransomNote[j]) {
                    ransomNote.erase(ransomNote.begin() + j); // erase
                    break;
                }
            }
        }
        if (ransomNote.length() == 0) {
            return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()) {
            // only little letters, one letter used once only
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i]-'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            record[ransomNote[i]-'a']--;
            if (record[ransomNote[i]-'a'] < 0) {
                // magazine has no the letter in ransomNote 
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s1 = "a";
    string s2 = "b";
    Solution s;
    if (false == s.canConstruct(s1, s2)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    string a = "aa";
    string b = "ab";
    Solution2 ans;
    if (false == ans.canConstruct(a, b)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    string ransom = "aa";
    string magazine = "aab";
    if (true == ans.canConstruct(ransom, magazine)) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }
    return 0;
}
