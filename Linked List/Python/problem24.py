# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        
        temp = ListNode()
        result = ListNode()
        temp.next = head
        res = temp
        while res and res.next:
            first = res.next
            if first.next == None:
                break
            second = first.next
            # swap the first node point to next node of the second
            first.next = second.next
            # the second node will point to the first node
            second.next = first
            
            #point the prev node in previous swap to the second node (which is swapped to first)
            res.next = second
            res = res.next.next
            
        # since res just used to swap, the temp will point to it and keep the original
        return temp.next
    
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)

sol = Solution
sol.swapPairs(sol, head)