# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return None
        m = {}
        def traverse(root):
            ## traverse thru the tree to store the freq of node in hash table
            m[root.val] = m.get(root.val, 0) + 1
            if root.left:
                traverse(root.left)
            if root.right:
                traverse(root.right)
        traverse(root)
        max_key = max(m, key=lambda k : m[k]) # get the key with most freq
        res = []
        for i in m:
            # loop thr the map, store the nodes with most freq (the same ) to the list
            if m[i] >= m[max_key]:
                res.append(i)
        return res