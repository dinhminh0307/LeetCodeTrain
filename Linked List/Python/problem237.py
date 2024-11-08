# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        #assign the val of the node next to to the current node: 4 - 1 - 1- 9
        node.val = node.next.val
        # delete the node next to current node
        node.next = node.next.next
        