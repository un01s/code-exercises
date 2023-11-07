"""
leetcode 1

"""
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            c = target - nums[i]
            if c in nums[i+1:]:
                return [i, nums[i+1:].index(c)+i+1]

# brute force
#
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i, x in enumerate(nums):
            for j in range(i+1, len(nums)):
                if x + nums[j] == target:
                    return [i, j]


#
# hash table
#
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        idx = {};
        for j, x in enumerate(nums):
            if target-x in idx:
                return [idx[target-x], j]
            idx[x] = j

