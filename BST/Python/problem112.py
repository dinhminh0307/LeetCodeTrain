# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right and root.val == targetSum:
            return True
        # if root.val == targetSum:
        #     return False
        stack = deque()
        isFound = False
        def dfs(curr):
            nonlocal targetSum, isFound
            if not curr or isFound:
                return
            stack.append(curr.val)
            print(stack)
            # if targetSum > 0 and sum(stack) > targetSum or targetSum < 0 and sum(stack) < targetSum:
            #     stack.pop()
            #     return
            if not curr.left and not curr.right and sum(stack) == targetSum:
                isFound = True
                return
            
            dfs(curr.left)
            if isFound:
                return
            dfs(curr.right)
            stack.pop()
        dfs(root)
        return isFound