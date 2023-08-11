/*
 * 2810 faulty keyboard
 * whenever "i", the string before it is reversed.
 *
 * constraints:
 * s[0] != 'i'
 * s contains only lowercase English letter
 *
 * stack is not a good idea. deque better perhaps.
 * but the reverse is the easiest.
 *
 */

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

// 
class Solution2 {
public:
    string reverseStr(string s) {
        int n = s.size();
        if (n == 0) return "";
        for (int l = 0; l <= n/2; l++) {
            char t = s[n-l-1];
            s[n-l-1] = s[l];
            s[l] = t;
        }
        return s;
    }
    string finalString(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'i') {
                reverseStr(res);
            } else {
                res += s[i];
            }
        }
        return res;
    }
};


