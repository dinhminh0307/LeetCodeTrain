# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        isBalance = True
        def traverse(root):
            nonlocal isBalance ## variable to keep track the state of tree
            if not root:
                return 0 # return immediately if reach the base case
            left_h = traverse(root.left) ## recursively traverse to left to get height of left
            if left_h == -1:
                return -1 # if detect unbalanced, return back to root
            right_h = traverse(root.right)
            if right_h == -1:
                return -1 # return imbalanced in left
            if abs(left_h - right_h) > 1: # base case
                isBalance = False
                return -1 # condition to check if left or right difference more than 1
            return max(left_h, right_h) + 1 # return the length of previous node
        res = traverse(root)
        return isBalance

