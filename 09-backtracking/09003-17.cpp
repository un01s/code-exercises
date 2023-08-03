/**
 * Leetcode 17  
 * 
 * alphabetic combination from phone numbers
 *
 * 2023-07-20
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz",  // 9
    };
public:
    void show(vector<string>& vs) {
        cout << "[ ";
        for (int i = 0; i < vs.size(); i++) {
            cout << "\"" << vs[i] << "\" ";
        }
        cout << "]" << endl;
    }

    vector<string> res;
    string s;
    void backtracking(const string& digits, int index) {
        if(index == digits.size()) {
            res.push_back(s);
            return;
        }
        // get one digit as integer, then retrieve all letters from this num
        int digit = digits[index] - '0'; 
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]); // process one letter after another
            backtracking(digits, index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        res.clear();
        if (digits.size() == 0) {
            return res;
        }
        backtracking(digits, 0);
        return res;
    }
};

int main() {
    // test case 1
    string digits = "23";

    Solution s;

    cout << "digits = \"" << digits << "\"" << endl;
    vector<string> ans = s.letterCombinations(digits);
    s.show(ans);
/*
digits = "23"
[ "ad" "ae" "af" "bd" "be" "bf" "cd" "ce" "cf" ]
 */
 
    return 0;
}

