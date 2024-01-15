"""
leetcode 144
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.data_list = []

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []

        if root:
            self.data_list.append(root.val)
        if root.left:
            self.preorderTraversal(root.left)
        if root.right:
            self.preorderTraversal(root.right)
        
        return self.data_list

