# https://leetcode.com/problems/reverse-linked-list/description/?envType=problem-list-v2&envId=linked-list&difficulty=EASY
# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = ListNode()
        tmp = ListNode()
        res = tmp
        temp = head
        while temp and temp.next:
                
            if temp.next.next == None:
                res.next = temp.next
                temp.next = None
                temp = head
                res = res.next
            else:
                temp = temp.next
        if temp and temp.next == None:
            res.next = temp
        return tmp.next


            