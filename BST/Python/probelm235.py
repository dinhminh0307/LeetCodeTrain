#https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        store = [p.val, q.val]
        res = None
        # compare the current node with p and q
        #if current node in range from p to q in acs order, the current node is root of p and q
        #if current node > (p,q), mean (p,q) is left side of curr, just traverse to left
        # if curr node < (p,q) mean (p,q) is on right side
        #recursively traverse until current node is in range(p,q)
        def dfs(root):
            nonlocal res # global var to store the result
            if not root:
                return -1
            if res: #if detect the res, no need to traverse any more
                return
            if not res and root.val in store: #handle case root is in range (p,q)
                res = root
                return
            # case where p and q is in both side of current node
            if not res and root.val in range(min(store), max(store)):
                res = root
                return
            # traverse to left when (p,q) on the left of current node
            if root.val > max(store):
                dfs(root.left)
            # traverse to right when (p,q) on the right of current node
            if root.val < min(store):
                dfs(root.right)
        dfs(root)
        return res
