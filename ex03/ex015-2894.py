"""
"""

class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        a, b = 0, 0
        for n in range(1,n+1):
            if n%m == 0:
                b += n
            else:
                a += n
        return a-b
