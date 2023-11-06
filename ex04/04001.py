"""
leetcode 1

"""
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            c = target - nums[i]
            if c in nums[i+1:]:
                return [i, nums[i+1:].index(c)+i+1]

