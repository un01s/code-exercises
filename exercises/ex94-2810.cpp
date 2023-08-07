/*
 * 2810 faulty keyboard
 * whenever "i", the string before it is reversed.
 *
 * constraints:
 * s[0] != 'i'
 * s contains only lowercase English letter
 *
 * stack is not a good idea. deque perhaps
 */

// use the stack, but it is difficult to deal with two adjacent 'i'
class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'i') {
                reverse(res.begin(), res.end());
            } else {
                res += s[i];
            }
        }
        return res;
    }
};

// double-pointer
// left and right
// find the position of all "i" in the string
// check if these "i" adjacent
// 
class Solution2 {
public:
    string finalString(string s) {
        int left = 0; 
        int right = s.size()-1;
        string res = "";
        while(left <= right) {
        
        }
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != 'i') {
                st.push(s[i]);
            } else {
                while (!st.empty()) {
                    res += st.top();
                    st.pop();
                }
            }
        }
        
        return res;
    }
};
