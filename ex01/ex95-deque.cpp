/*
 * deque exercise
 *
 */

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    deque<char> q;
    string s = "string";

    for (int i = 0; i < s.size(); i++) {
        q.push_back(s[i]);
    }

    for (int i = 0; i < s.size(); i++) {
        cout << q.at(i) << " " << endl;
    }

    return 0;
}
