"""
leetcode 001
two sum
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # sorting
        nums_sorted = sorted(nums)
        
        # double pointer
        left = 0
        right = len(nums_sorted) - 1
        while left < right:
            current_sum = nums_sorted[left] + nums_sorted[right]
            if current_sum == target:
                left_index = nums.index(nums_sorted[left])
                right_index = nums.index(nums_sorted[right])
                if left_index == right_index:
                    right_index = nums[left_index+1:].index(nums_sorted[right]) + left_index + 1
                return [left_index, right_index]
            elif current_sum < target:
                left += 1
            else:
                right -= 1
