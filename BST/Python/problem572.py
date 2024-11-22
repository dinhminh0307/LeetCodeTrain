# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False  # If the main tree is empty, subRoot cannot be a subtree.
        if self.isSameTree(root, subRoot):
            return True  # If the trees match, subRoot is a subtree of root.
        # Recursively check left and right subtrees.
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True  # Both trees are empty.
        if not p or not q:
            return False  # One tree is empty, and the other is not.
        if p.val != q.val:
            return False  # Values of the nodes do not match.
        # Recursively check left and right subtrees.
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
