# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        tmp = head
        v = []
        while tmp:
            v.append(tmp.val)
            tmp = tmp.next
        res = v[::-1]
        # print(res)
        if len(res) != len(v):
            return False
        for i in range(len(res)):
            if res[i] != v[i]:
                return False
            
        return True

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(2)
head.next.next.next = ListNode(1)

sol = Solution
sol.isPalindrome(sol, head)