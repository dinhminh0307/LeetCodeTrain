# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# def custom_compare(x, y):
#     if x < y:
#         return -1
#     elif x > y:
#         return 1
#     else:
#         return 0

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        arr = []
        tmp = head
        while head:
            arr.append(head.val)
            # delete the node whenever assign to list to save up memory
            next_node = head.next
            head.next = None
            head = next_node
            
            # tmp = tmp.ne
        arr.sort()
        res = ListNode()
        tmp = res
        for i in arr:
            tmp.next = ListNode(i)
            tmp = tmp.next
        return res.next
