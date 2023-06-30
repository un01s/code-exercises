/** 
 * 344 reverse string
 * https://leetcode.com/problems/reverse-string/
 * 
 * Write a function that reverses a string. 
 * The input string is given as an array of characters s.
 * 
 * You must do this by modifying the input array in-place with O(1) 
 * extra memory.
 * 
 * 2023-06-30
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void show(vector<char>& s) {
        for(int i = 0; i < s.size(); i++) {
            cout << s[i] << ",";
        }
        cout << endl;
    }
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--) {
            //swap(s[i], s[j]);
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }          
    }
};

int main() {
    char s1[] = {'h','e','l','l','o'};
    vector<char> v(s1, s1+sizeof(s1)/sizeof(char));
    
    Solution s;
    s.show(v);
    s.reverseString(v);
    s.show(v);

    return 0;
}
