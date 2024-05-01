/*
 * leetcode 2000
 * reverse prefix of word
 *
 * string
 */

class Solution {
public:
    string reversePrefix(string word, char ch) {
        // string: find the ch first, then swap successively
        int r = word.find(ch);
        if (ch == -1)
            return word;
        int r0 = (r - 1) / 2;
        for (int i = 0; i <= r0; i++)
            swap(word[i], word[r - i]);
        return word;
    }
};

