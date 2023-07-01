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
        int newSize = oldSize + 3*count - 2; // two old spaces are replaced
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
};

int main() {
    string str1 = "We are happy"; // c++ string 
    
    Solution s;
    cout << str1 << endl;
    cout << "after replacement: ";
    cout << s.replaceSpace(str1) << endl;
    
    return 0;
}
