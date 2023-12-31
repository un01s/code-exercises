/** 
 * input : s = "We are happy."
 * output: "We%20are%20happy." 
 * 
 * 2023-06-30
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // resize the string to the target size
        // use the double-pointer to replace the space from tail to head
        // if you go from head to tail, then you have to move all elements
        // extra time
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // resize the string first, then double-pointer from tail to head
        int newSize = oldSize + 3*count - count; // two old spaces are replaced
        s.resize(newSize);
        int j = newSize - 1;
        for (int i = oldSize-1; i >= 0; i--) {
            if (s[i] != ' ') {
                s[j--] = s[i];
            } else {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
        }
        return s;
    }
    string replaceSp(string s) {
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        int newSize = oldSize + 2*count; // 3*count-count=2*count
        s.resize(newSize);
        // double pointers from tail to head
        int x = newSize - 1;
        int y = oldSize - 1;
        for (x=newSize-1, y=oldSize-1; y>=0; x--, y--) {
            cout << x << "-" << y;
            if (s[y] != ' ') {
                s[x] = s[y];
            } else {
                //s[x--] = '0';
                //s[x--] = '2';
                //s[x] = '%';
                // or
                s[x] = '0';
                s[x-1] = '2';
                s[x-2] = '%';
                x -= 2; // in the loop there is another decrement
            } 
            cout << s[y] << endl;
        }
        return s;
    }
};
/*
string replaceTest(string s) {
    int count = 0;
    int sOldSize = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    s.resize(s.size() + count * 3);
    int sNewSize = s.size();
    for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
        if (s[j] != ' ') {
            s[i] = s[j];
        } else {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i -= 2;
        }
    }
    return s;
}
*/

int main() {
    string str1 = "We are happy"; // c++ string 
    string str2 = "We are sad."; // c++ string 
    string str3 = "We are confused";

    Solution s;
    cout << str1 << endl;
    cout << "after: ";
    cout << s.replaceSpace(str1) << endl;
    
    cout << str2 << endl;
    cout << "after: ";
    cout << s.replaceSp(str2) << endl;
/*
    cout << str3 << endl;
    cout << replaceTest(str3) << endl;
*/
    return 0;
}
