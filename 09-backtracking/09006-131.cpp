/**
 * Leetcode 131 
 *
 * substring
 * 
 * 2023-07-20
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // helper
    void show(vector<vector<string> >& vs) {
        cout << "[ ";
        for (int i = 0; i < vs.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < vs[i].size(); j++) {
                cout << "\"" << vs[i][j] << "\" ";
            }
            cout << "]";
        }
        cout << "]" << endl;
    }

    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
             return false;
            }
        }
        return true;
    }

    vector<vector<string> > res;
    vector<string> path;
    void backtracking(const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {
                continue; // bypass
            }
            backtracking(s, i+1); 
            path.pop_back();
        }
    }
    vector<vector<string> > computePalindrome(const string& s) {
        res.clear();
        path.clear();

        backtracking(s, 0);
        return res;
    } 
};

int main() {
    // test case
    string s = "aab";

    Solution ans;
    vector<vector<string> > v = ans.computePalindrome(s);
    ans.show(v);
    
    return 0;
}

