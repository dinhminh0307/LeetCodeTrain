# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack = deque()
        l = []
        res_store = []
        # traverse the list to store into a list
        def traverse(current):
            if not current:
                return
            l.append(current.val)
            traverse(current.next)
        traverse(head)
        ## store the greate value in a stack
        for i in l:
            while stack and i > stack[-1]:
                stack.pop() # pop the smaller value when encounter
            stack.append(i) 
        res_store= list(stack)
        tmp = ListNode()
        res = ListNode()
        # create new link list to return with the value in the stack
        res = tmp
        for i in res_store:
            tmp.next = ListNode(i)
            tmp = tmp.next
        del stack
        del l
        del head
        return res.next
            
                
            
            