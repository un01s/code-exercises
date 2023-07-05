/**
 * Leetcode 394 
 * https://leetcode.com/problems/decode-string/
 *
 * 2023-07-05
 *
 * recursive and stack, two solutions
 * stack solution seems have some issues.
 *
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    // recursive
    // what if k is not single-dgigit?!
    string decodePartial(string& s, int& i) {
        string ans;
        while( i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                ans += s[i++];
            } else {
                int n = 0;
                while(i < s.size() && isdigit(s[i])) {
                    //n = n * 10 + s[i++] - '0';
                    //n = stoi(s[i]);
                    n = s[i] - '0';
                    i++;
                }
                i++; // for '['
                string t = decodePartial(s, i);
                i++; // for ']'

                //while(n-- > 0) {
                while(n > 0) {
                    ans += t;
                    n--;
                }
            } 
        }
        return ans;
    }
    string decodeString(string s) {
        int i = 0;
        return decodePartial(s, i);
    }
    // use the stack
    string decodeStringStack(string s) {
        string ans = "";
        stack<string> st;
        string number = "";
        for (int i = 0; i < s.size(); i++) {
            //string t = s[i];
            string t = string(1, s[i]);

            if (isdigit(s[i])) {
                number += s[i];
                continue;
            }
            if (s[i] == '[') {
                st.push(number);
                number.clear();
            }
            if (s[i] == ']') {
                string sTmp = "";
                while(st.top() != "[") {
                    sTmp += st.top();
                    st.pop();
                }
                
                st.pop();
                int tmp = stoi(st.top());
                st.pop();
                for(int j = 0; j < tmp; j++) {
                    ans += sTmp;
                }
                st.push(ans);
                ans.clear();
                continue;
            }
            st.push(t);
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }    
};

int main() {
    string str1 = "3[a]2[bc]";
    string str2 = "3[a2[c]]]";
    string str3 = "2[abc]3[cd]ef";

    Solution s;

    if ("aaabcbc" == s.decodeString(str1)) {
        cout << "test1 OK\n";
    } else {
        cout << "test1 failed\n";
    }

    if ("accaccacc" == s.decodeString(str2)) {
        cout << "test2 OK\n";
    } else {
        cout << "test2 failed\n";
    }

    if ("abcabccdcdcdef" == s.decodeString(str3)) {
        cout << "test3 OK\n";
    } else {
        cout << "test3 failed\n";
    }

    return 0;
}

