/*
 * 
 *
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "8245"; // assume all digits in the string
    int num = 0;
    cout << "string: " << s << endl;
    for (int i = 0; i < s.size(); i++) {
        num =  10*num + (s[i]-'0');
    }
    cout << "num: " << num << endl;
    return 0;
}
