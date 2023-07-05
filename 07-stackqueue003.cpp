/**
 * Leetcode 20 valid parentheses 
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 * 
 * - Open brackets must be closed by the same type of brackets.
 * - Open brackets must be closed in the correct order.
 * - Every close bracket has a corresponding open bracket of the same type.
 *	
 * constraints: s consists of parentheses only '()[]{}'
 *
 * inputs: s = "()"
 * output: true
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 2023-07-04
 *
 * parenthese matching is the classic problem for stack
 * there are three mismatches
 * 1. extra at left
 * 2. extra at right
 * 3. number match but type mismatch
 *
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2 != 0) return false; // number mismatch
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '{') {
                st.push('}');
            } else if (st.empty() || st.top() != s[i]) {
                return false;
            } else {
                st.pop(); 
            }
        }
        return st.empty();     
    }    
};

int main() {
    string str1 = "()[]{}";
    string str2 = "(]";

    Solution s;

    if (s.isValid(str1)) {
        cout << "test1 OK\n";
    } else {
        cout << "test1 failed\n";
    }

    if (!s.isValid(str2)) {
        cout << "test2 OK\n";
    } else {
        cout << "test2 failed\n";
    }


    return 0;
}

