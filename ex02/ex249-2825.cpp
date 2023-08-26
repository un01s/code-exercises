/*
 * leetcode 2825
 * using cyclic increment 'a' -> 'b', 'z'->'a'
 *
 * for python code, x = ord("h")
 * x is the integer representing the character "h"
 * the opposite function is chr
 * c = chr(65)
 * now, c is 'A'
 * that means chr take an integer and return its string eqivalent
 * 
 */

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (str1[i] == str2[j] || str1[i]+1 == str2[j] || str1[i]-25 == str2[j]) {
                j++;
            }
            i++;
        }
        return j == m;
    }
};
