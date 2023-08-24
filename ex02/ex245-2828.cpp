/*
 * leetcode 2848 easy
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int w = words.size();
        int n = s.size();
        if (n != w) return false;
        for (int i = 0; i < n; i++) {
            if (s[i] != words[i][0]) return false;
        }
        return true;
    }
};

int main() {
    string words1[] = {"alice","bob","charlie"};
    string s1 = "abc";

    Solution s;

    
    return 0;
}
