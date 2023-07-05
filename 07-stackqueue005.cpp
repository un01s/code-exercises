/**
 * Leetcode 150 reverse Polish notation
 *
 * polish notation is always put the operator at the end
 * 
 * (1 2 +) (2 3 *) + 
 * 9
 *
 * 2023-07-04
 * 
 * 
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // why long long? long should be enough!
        stack<long> st;
        for(int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" ||
                tokens[i] == "-" ||                    
                tokens[i] == "*" ||
                tokens[i] == "/") {
                long num1 = st.top();
                st.pop();
                long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                // here stoll convert string to long long
                // should use stol
                st.push(stol(tokens[i]));
            }
        }
        // get the remaining char in the stack
        int result = st.top();
        st.pop();
        return result;
    }
};

int main() {
    string a[] = {"2", "1", "+", "3", "*"};
    vector<string> v(a, a + sizeof(a)/sizeof(string));

    Solution s;

    if (9 == s.evalRPN(v)) {
        cout << "test1 OK\n";
    } else {
        cout << "test1 failed\n";
    }

    return 0;
}

