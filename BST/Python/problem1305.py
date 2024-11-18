# https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> List[int]:
        res = []
        ## traverse all root 1 and store in res
        if root1:
            def traverse1(root1):
                res.append(root1.val)
                if root1.left:
                    traverse1(root1.left)
                if root1.right:
                    traverse1(root1.right)
            traverse1(root1)
        ## traverse all root2 and store in res
        if root2:
            def traverse2(root2):
                res.append(root2.val)
                if root2.left:
                    traverse2(root2.left) 
                if root2.right:
                    traverse2(root2.right)
            traverse2(root2)
        
        ##sort the res and return
        res.sort()
        return res     