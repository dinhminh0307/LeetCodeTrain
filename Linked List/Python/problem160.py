# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        m = set() # the set store the pointer of the node address
        tmpA = headA
        tmpB = headB
        # store the node addrtess
        while tmpA:
            m.add(tmpA)
            tmpA = tmpA.next
        while tmpB:
            if tmpB in m: # check if node address is the same, so that is where the intersection
                return tmpB
            tmpB = tmpB.next
        return None
