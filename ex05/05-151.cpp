/*
 * leetcode 151
 * reverse words in a string
 *
 */

class Solution {
public:
    void reverse(string& s, int start, int end){ 
        // reverse, [] both left and right inclusive
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {
        // remove all spaces, and insert space between words
        // double-pointer: fast and slow pointers
        int slow = 0;   
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') { 
            // remove all spaces
                if (slow != 0) s[slow++] = ' ';
                // add space between words
                // slow!=0 indicates not the first word
                // add space before the word 
                while (i < s.size() && s[i] != ' ') { 
                // when there is a space, the end of word
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); // slow means how many spaces removed
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); 
        // remove extra spaces
        // only one space between words
        // and there is no space at the start and at the end
        reverse(s, 0, s.size() - 1);
        int start = 0; // removeExtraSpaces, the index of first word = 0 
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { 
            // reach a space or the end of string,
            // reverse
                reverse(s, start, i - 1); // reverse, []
                start = i + 1; // update the index for next word
            }
        }
        return s;
    }
};

void removeExtraSpaces(string& s) {
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] == s[i - 1] && s[i] == ' ') {
            s.erase(s.begin() + i);
        }
    }
    // remove spaces at the end
    if (s.size() > 0 && s[s.size() - 1] == ' ') {
        s.erase(s.begin() + s.size() - 1);
    }
    // remove spaces at the start
    if (s.size() > 0 && s[0] == ' ') {
        s.erase(s.begin());
    }
}
