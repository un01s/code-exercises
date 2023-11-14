"""
leetcode 206
python 
recursion
"""

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def recur(cur, pre):
            if not cur: return pre     # terminating condition
            res = recur(cur.next, cur) # 
            cur.next = pre             #
            return res                 #
        
        return recur(head, None)
