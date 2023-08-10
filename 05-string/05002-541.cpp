/** 
 * 541 reverse string II
 * https://leetcode.com/problems/reverse-string-ii/
 * 
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
        char tmp;
        for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--) {
            //swap(s[i], s[j]);
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }          
    }
    // just note c++ has its own reverse function for string
    // below is just a simple implementation
    void reverse(string& s, int start, int end) {
        // look at this for loop
        for (int i = start, j =  end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k) {
        for (int i =0; i < s.size(); i +=(2*k)) {
            // reverse the first k characters every 2k
            // and if the remaining less than 2k but greater than k, 
            // reverse the first k
            if (i+k <= s.size()) {
                reverse(s, i, i+k-1);
                continue;
            }
            // if the remaining less than k, reverse them all
            reverse(s, i, s.size()-1);
        }
        return s;
    }
};

int main() {
    char s1[] = {'h','e','l','l','o'};
    char s2[] = "hello"; // C-style string header <cstring>
    vector<char> v(s1, s1+sizeof(s1)/sizeof(char));

    string str1 = "abcdefg"; // c++ string 
    string str2 = "abcd"; // c++ string 
    string str3 = "abc"; // c++ string 
    
    Solution s;
    cout << str1 << endl;
    cout << s.reverseStr(str1, 2) << endl;
    cout << str2 << endl;
    cout << s.reverseStr(str2, 2) << endl;
    cout << str3 << endl;
    cout << s.reverseStr(str3, 2) << endl;
    
    return 0;
}
