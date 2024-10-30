# https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/?envType=problem-list-v2&envId=linked-list

# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = ListNode()
        # temp is a pointer (or reference) used to iterate through the list. As you traverse the linked list, 
        # you keep moving temp forward (temp = temp.next). By the end of the loop, temp is pointing to the last node in the list, not the head of the list anymore.

        # eanwhile, head remains pointing to the original starting node of the linked list. head is unchanged, so it still correctly references the beginning of the list.
        temp = head
        while temp and temp.next:
            if temp.val == temp.next.val:
                temp.next = temp.next.next
            else:
                temp = temp.next
        return head