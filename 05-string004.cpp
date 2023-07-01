/**
 * 151 reverse words in a string
 * https://leetcode.com/problems/reverse-words-in-a-string/
 * 
 * Given an input string s, reverse the order of the words.
 * 
 * A word is defined as a sequence of non-space characters. The words in s 
 * will be separated by at least one space.
 * 
 * Return a string of the words in reverse order concatenated by a single space.
 *
 * reverse the order of the words in a strings
 *
 * the correct solution is as follows:
 * 1. remove extra spaces, leave only exact one space between words
 * 2. reverse the whole string
 * 3. reverse each word to make it correct
 *
 * no extra space and it is O(1).
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void removeExtraSpace(string& s) {
        int slow = 0; // slow pointer
        // the index in the following for-loop is the fast pointer
        cout << s.size() << "-";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') { // handle non-space only, i.e. remove all spaces
                if (slow != 0) { // not the first word, add a space before
                    s[slow++] = ' '; // then add space manually here
                }
                while(i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        cout << slow << endl;
        s.resize(slow); // correct size after remvoing extra spaces
    }
    // the sub range is [], both start and end included
    void reverse(string& s, int start, int end) {
        //cout << s << "-";
        for (int i = start, j = end; i < j; i++, j--) {
            //char tmp = s[i];
            //s[j] = s[i];
            //s[i] = tmp;
            swap(s[i], s[j]);
        }
        //cout << s << endl;
    }
    string reverseWords(string s) {
        cout << s << endl;
        removeExtraSpace(s);
        // reserse the whole string
        reverse(s, 0, s.size()-1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i]==' ') {
                // have a space or reach the end
                reverse(s, start, i-1); 
                start = i+1; // update start to the start index of next word
            }
        }
        cout << s << endl;
        return s;        
    }
};

int main() {
    string str1 = "the sky  is  blue";
    string str2 = " birds  are  flying ";

    Solution ans;
    //ans.removeExtraSpace(str1);
    //ans.removeExtraSpace(str2);
    ans.reverseWords(str1);
    ans.reverseWords(str2);

    return 0;
}

