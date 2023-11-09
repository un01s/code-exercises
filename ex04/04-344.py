"""
leetcode 344
reverse string

double-pointer

pay attention to some pythonic features

"""

#
# double pointer: left and right
#
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
        
#
# use stack
#
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        stack = []
        for char in s:
            stack.append(char)
        for i in range(len(s)):
            s[i] = stack.pop()

#
# use range
#
class Solution:
    def reverseString(self, s: List[str]) -> None:
        n = len(s)
        for i in range(n//2): # // instead of / in python
            s[i], s[n-i-1] = s[n-i-1], s[i]

