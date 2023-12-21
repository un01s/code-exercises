"""
leetcode 349

"""

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        table = {}
        for n in nums1:
            table[n] = table.get(n, 0) + 1

        # use set for the result
        res = set()
        for n in nums2:
            if n in table:
                res.add(n)
                del table[n]
        return list(res)

