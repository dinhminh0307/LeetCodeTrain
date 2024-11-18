## https://leetcode.com/problems/same-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        isEqual = True
        if not p and not q:
            return True
        def traverse(p,q):
            nonlocal isEqual ## global var keep track state of the trees
            ## if val is not equal or both root null, keep the state false and return
           
            if (p and not q or not p and q) or p.val != q.val:
                isEqual = False
                return False
            
             ##if p and q has left and both equal, traverse to left and keep the state true
            if p.left and q.left:
               traverse(p.left, q.left)
            elif not p.left and q.left or p.left and not q.left:
                ## if one of them dont have left, return false
                isEqual = False
                return False
            if p.right and q.right:
                traverse(p.right, q.right)
            elif not p.right and q.right or p.right and not q.right:
                ## if one of them dont have right, return false
                isEqual = False
                return False
        traverse(p,q)
        return isEqual

            


