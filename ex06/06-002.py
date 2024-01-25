"""
leetcode 20
valid parentheses

"""

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        # key:value
        mapping = {')':'(', '}':'{', ']':'['}
        for c in s:
            if c in mapping.values():
                stack.append(c)
            elif c in mapping.keys():
                if not stack or stack.pop() != mapping[c]:
                    return false
        return len(stack)==0

