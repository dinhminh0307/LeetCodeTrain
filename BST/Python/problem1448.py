# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return -1
        res = 1 # the global var to keep track the number of good nodes
# using dfs go thru all the node and keep track the max node in a stack,
# if an node that greater than the max of the stack, mark as good node
# then traverse to the left and right until the end node to update the stack
# when traverse back to the root node, pop the stack to update the new path and new max node
        def dfs(root, store):
            nonlocal res
            if not root:
                return -1
            store.append(root.val) # append the current node to the stack path
            if root.left and root.left.val >= max(store):
                # check if the next node is good node
                res += 1
            dfs(root.left, store)
            if root.right and root.right.val >= max(store):
                res += 1
            dfs(root.right, store)
            # pop the stack to keep track new path 
            store.pop()
        dfs(root, [])
        return res
            