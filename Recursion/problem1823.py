# https://leetcode.com/problems/find-the-winner-of-the-circular-game/?envType=problem-list-v2&envId=recursion
class ListNode:
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev
#Idea: put the number in a circular linked list, and recursively traverse
# if traverse to desired location, delete that node and start from next node
# do that until there is only one node
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        head = ListNode(1)  # Initialize the head node with value 1
        tmp = head
        # put all to a cirlcular linkedlist
        for i in range(2, n + 2):
            if i == n + 1:
                tmp.next = head
                head.prev = tmp
            else:
                temp = ListNode(i)
                tmp.next = temp
                temp.prev = tmp
                tmp = tmp.next
        res = 1 # store the result
        found = False ## base case to return
        i = 1 # keep track the index
        def traverse(curr):
            nonlocal k,res, found, i
            if found: # base case return if found
                return
            # detect only node left if prev and current node is the same
            if curr.prev.val == curr.val:
                found = True
                return True
            # traverse til the desired location
            if i < k:
                i += 1
                traverse(curr.next)
            else:
                # dekete the node
                temp = curr.next
                temp.prev = curr.prev
                curr.prev.next = temp
                res = temp.prev.val
                i = 1
                traverse(temp)
        traverse(head)
        return res

            