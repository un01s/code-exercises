"""
344 reverse string

double-pointer: left and right

"""

class Solution:
    def reverseString(self, s: List[str]) -> None:
        left = 0
        right = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

# another version

class Solution:
    def reverseString(self, s: List[str]) -> None:
        for i in range(len(s) // 2):
            s[i], s[-i - 1] = s[-i - 1], s[i]

