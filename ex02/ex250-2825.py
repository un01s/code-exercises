"""
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
"""

class Solution:
    def canMakeSusequence(self, str1: str, str2: str) -> bool:
        m, n = len(str1), len(str2)
        i = j = 0;
        while i < m and j < n:
            # check if both match
            if str1[i] == str2[j] or (ord(str1[i])+1 == ord(str2[j])) or (ord(str1[i])+1-26 == ord(str2[j])):
                i, j = i+1, j+1
            else:
                i += 1
        return j == n

