# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        queue = []
        queue.append(root)
        count  = 0
        while queue:
            len_size = len(queue) # process every nodes each level
            for i in range(len_size):
                node = queue.pop(0) # check the node in each level
                if node.left:
                    queue.append(node.left) # add left or right to queue
                if node.right:
                    queue.append(node.right)
            count += 1 # after finish each level, increase depth
        #until the queue is empty, return the max dept
        return count