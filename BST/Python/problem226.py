## https://leetcode.com/problems/invert-binary-tree/description/
 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root: # if there is no root, return none
            return None
        
        ## Using dfs to traverse all the left
        def traverse(currentNode):
            # if there is left child, go there
            if currentNode.left:  
                traverse(currentNode.left)
            # if there is right child, go there
            if currentNode.right:
                traverse(currentNode.right)
            # if go both left and right already, swap them and return
            # to root previous
            tmp = currentNode.right
            currentNode.right = currentNode.left
            currentNode.left = tmp
        traverse(root)
        return root