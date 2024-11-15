# https://leetcode.com/problems/diameter-of-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = 0
        def traverse(root):
            nonlocal res # global res to keep track the curr diameter

            if not root:
                return 0 # when go to null node, return 0 to avoid opetaion
            left = traverse(root.left) # traverse all to left
            right = traverse(root.right) # traverse all to right
            res = max(res, left + right) # left + right is the diameter at that node
            # update res with the new diameter
            return 1 + max(left, right) # return lentgh from node to sub child
        traverse(root)
        return res
            