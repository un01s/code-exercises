/*
 * kama 55
 *
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int len = s.size(); // get the length

    reverse(s.begin(), s.end()); // reverse all
    reverse(s.begin(), s.begin() + n); // reverse the first n
    reverse(s.begin() + n, s.end()); // reverse the other

    cout << s << endl;

} 
