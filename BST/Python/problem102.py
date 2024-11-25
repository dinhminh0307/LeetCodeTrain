# Definition for a binary tree node.

# https://leetcode.com/problems/binary-tree-level-order-traversal/description/
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        m = {}
        if not root:
            return res
        ## dfs to find the leve of nodes, then group the nodes with same level in a list
        ## store the list in a hash table with level is the key
        def dfs(root, length):
            if not root:
                return
            dfs(root.left, length + 1)
            dfs(root.right, length + 1)
            tmp_res = []
            tmp_res.append(root.val)
            
            if length in m:
                m[length].extend(tmp_res)
            else:
                m[length] = tmp_res
        dfs(root, 1)
        # loop thru the hash table to group to ressult
        m = dict(sorted(m.items())) ## sort the hash table base on ascending key
        # print(m)
        for i in m:
            res.append(m[i])
        #res.reverse()
        # now the res is in the ascending level by level order
        return res
