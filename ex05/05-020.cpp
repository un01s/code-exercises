/*
 * leetcode 20
 * valid parenthese
 *
 */

class Solution {
public:
    bool isValid(string s) {
        // the length must be an even number
        if (s.size() % 2 != 0) return false; 
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // when the stack is empty, so the right does not have the matched left
            // not found in the stack
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top()== s[i]
        }
        return st.empty();
    }
};
