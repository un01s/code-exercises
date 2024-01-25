/*
 * leetcode 20 valid parentheses
 * 
 * use the stack
 * 
 * create a char stack for the first half
 * 
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if (n%2 != 0) return false; // odd number of chars
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // case1: stack empty but no match, return false
            // case2: no match in the stack, return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() == s[i], pop the stack
        }
        // case3: traversal is complete. stack empty, matched.
        return st.empty();
    }
};

