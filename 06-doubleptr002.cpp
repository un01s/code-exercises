/**
 * 344 reverse string 
 * https://leetcode.com/problems/reverse-string/
 * 
 * Write a function that reverses a string. The input string is given as an 
 * array of characters s.
 * 
 * You must do this by modifying the input array in-place with O(1) extra 
 * memory. 
 *
 * 2023-07-02
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void show(vector<char>& s) {
        cout << "{ ";
        for(int i = 0; i < s.size(); i++) {
            if (i != (s.size()-1)) {
                cout << s[i] << ",";
            } else {
                cout << s[i];
            }
        }
        cout << " }" << endl;
    }

    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        char tmp;
        while(left < right) {
            tmp = s[right];
            s[right] = s[left];
            s[left] = tmp;
            left++;
            right--; 
        }
    }
};

int main() {
    char a[] = {'h', 'e', 'l', 'l', 'o'};
    vector<char> v(a, a+sizeof(a)/sizeof(char));
    char b[] = {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> w(b, b+sizeof(b)/sizeof(char));

    Solution s;

    s.show(v);
    s.reverseString(v);
    s.show(v);

    s.show(w);
    s.reverseString(w);
    s.show(w);

    return 0;
}

