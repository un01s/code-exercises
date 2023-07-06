/**
 * Leetcode 1047 remove all adjecent duplicates in string 
 *
 * You are given a string s consisting of lowercase English letters. 
 * A duplicate removal consists of choosing two adjacent and equal letters and 
 * removing them.
 * 
 * We repeatedly make duplicate removals on s until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made. 
 * It can be proven that the answer is unique.
 *
 * 2023-07-03
 * 
 * 
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if (st.empty() || s[i] != st.top()) {
                st.push(s[i]);
            } else {
                st.pop(); // s[i] == st.top()
            }
        }
        // get the remaining char in the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        // reverse is required
        reverse(result.begin(), result.end()); // stack: FILO

        return result;
    }
};

int main() {
    string str1 = "abbaca";
    string str2 = "azxxzy";

    Solution s;

    if ("ca" == s.removeDuplicates(str1)) {
        cout << "test1 OK\n";
    } else {
        cout << "test1 failed\n";
    }

    if ("ay" == s.removeDuplicates(str2)) {
        cout << "test2 OK\n";
    } else {
        cout << "test2 failed\n";
    }

    return 0;
}

