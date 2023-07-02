/**
 * implementation of KMP algorithm 
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
    void getNextMinus1(int* next, string& s) {
        // this implementation is to contruct next table as
        // all numbers in the table are minus 1.
        // so instead of 0, all the longest length -1, 
        // so the initial value of j
        // for-loop, index i starts from 1 instead of 0
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while(j >= 0 && s[i] != s[j+1]) {// prefix <> suffix
                j = next[j]; // backward, next[j] is before j+1
            }
            if (s[i] == s[j+1]) { // prefix == suffix
                j++; // move j forward together with i (i is in the loop)
            }
            next[i] = j; // the length of prefix
        }
    }
    // strStr1() uses getNextMinus1()
    // all the values in the next table minus 1
    // i.e. all the initial position is -1
    int strStr1(string s, string w) {
        if(w.size() == 0) {
            return 0; // empty string of w to match
        }
        // construct the next table for w
        int next[s.size()];
        getNextMinus1(next, w);

        int j = -1; // next has -1 as its initial position
        // i starts from 0, i, j as two pointers, j before i
        for(int i = 0; i < s.size(); i++) {
            while (j >= 0 && s[i] != w[j+1]) { // no match, back
                j = next[j]; // j back to its position before, matched before
            }
            if (s[i] == w[j+1]) { // matched
                j++; // move j and i forward together, i is in the for-loop
            }
            if (j == (w.size()-1)) {
                return (i-w.size()+1);
            }
        }
        return -1;
    }
    // next table w/o all values minus 1
    void getNext(int* next, string& s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            // not match
            while(j > 0 && s[i] != s[j]) {
                j = next[j-1]; // back, j has to be greater than 0
            }
            // match
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    // look for w in s
    // strStrs() uses getNext()
    // all the values in the next table 
    // i.e. all the initial position is 0
    int strStr(string s, string w) {
        if(w.size() == 0) {
            return 0; // empty string of w to match
        }
        // construct the next table for w
        int next[s.size()];
        getNext(next, w);
        // search process
        int j = 0; // j pointer and length
        for (int i = 0; i < s.size(); i++) {
            // check w and s
            while(j > 0 && s[i] != w[j]) { // no match
                j = next[j-1]; // j-1 is before j, backtracing
            }
            if (s[i] == w[j]) { // match
                j++; // j forward one step together with i (at the end of loop)
            }
            if (j == w.size()) {
                return (i - w.size() + 1);
            }
        }
        return -1;
    }
};

int main() {
    string w = "aabaaf";
    string s = "aabaabaafa";

    Solution ans;
    int next1[6] = {-1};
    int next[6] = {0};

    ans.getNextMinus1(next1, w);
    for (int i = 0; i < 6; i++) {
        cout << next1[i] << ",";
    }
    cout << endl; // -1,0,-1,0,1,-1,

    ans.getNext(next, w);
    for (int i = 0; i < 6; i++) {
        cout << next[i] << ",";
    }
    cout << endl; // 0,1,0,1,2,0,

    // tests
    cout << ans.strStr(s, w) << endl; 		// 3
    cout << ans.strStr("hello", "ll") << endl;	// 2
    cout << ans.strStr("aaaaa", "ba") << endl; 	// -1

    cout << ans.strStr1(s, w) << endl; 		// 3
    cout << ans.strStr1("hello", "ll") << endl;	// 2
    cout << ans.strStr1("aaaaa", "ba") << endl; // -1

    return 0;
}

