/**
 * 
 *
 *
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // next[i] is the longest same prefix and suffix before i (including i)
    // to get a next table from a string
    // 1. initialization
    // 2. handle prefix and suffix mismatch
    // 3. handle prefix and suffix same
    void getNext(int* next, string& s) {
        // this implementation is to contruct next table as
        // all numbers in the table are minus 1.
        // so instead of 0, all the longest length -1, 
        // so the initial value of j
        // for-loop, index i starts from 1 instead of 0
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while(j >= 0 && s[i] != s[j+1]) {// prefix <> suffix
                j = next[j]; // backward
            }
            if (s[i] == s[j+1]) { // prefix == suffix
                j++; // forward
            }
            next[i] = j; // the length of prefix
        }
    }
    string strStr(string s, int k) {
        return s;
    }
};

int main() {
    string w = "aabaaf";
    Solution s;
    int next[6] = {-1};

    s.getNext(next, w);
    for (int i = 0; i < 6; i++) {
        cout << next[i] << ",";
    }
    cout << endl; // -1,0,-1,0,1,-1,

    return 0;
}

