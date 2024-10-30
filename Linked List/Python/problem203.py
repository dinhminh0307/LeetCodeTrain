# https://leetcode.com/problems/remove-linked-list-elements/description/?envType=problem-list-v2&envId=linked-list&difficulty=EASY
# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        res = ListNode(0)
        temp = ListNode() # temp will be the start of the res
        res.next = head # res will point to the head, to check the full list from the beginning
        temp = res
        while res and res.next:
            while res.next and res.next.val == val:
                res.next = res.next.next
            res = res.next
        return temp.next
            