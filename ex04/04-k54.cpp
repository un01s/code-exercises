/*
 * kama54
 *
 * input: a1b2c3
 * output: anumberbnumbercnumber
 * constraint: 1 <= s.length < 10000
 *
 */

#include<iostream>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int count = 0; // count of number in the string
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            }
        }
        // resize the string: every number will be changed into number
        s.resize(s.size() + count * 5);
        int sNewSize = s.size();
        // replace from the end to the start
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] > '9' || s[j] < '0') {
                s[i] = s[j];
            } else {
                s[i] = 'r';
                s[i - 1] = 'e';
                s[i - 2] = 'b';
                s[i - 3] = 'm';
                s[i - 4] = 'u';
                s[i - 5] = 'n';
                i -= 5;
            }
        }
        cout << s << endl;
    }
}

