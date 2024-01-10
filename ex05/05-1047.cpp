/*
 * leetcode 1047
 *
 */

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            } else {
                st.pop(); // s == st.top()
            }
        }
        string result = "";
        while (!st.empty()) { // move elements in the stack
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // reverse required
        return result;

    }
};
