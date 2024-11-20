# https://leetcode.com/problems/maximum-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        max_el = max(nums)
        root = TreeNode(max_el) ## initially assign the max of current arr to root
        
        def traverse(root, nums: List[int], max_el):
            if not root:
                return TreeNode(max_el) # assign value to current node
            idx = 0
            for i in nums:
                if i == max_el: ## find index of the max
                    break
                idx +=1
            
            if idx > 0: ## check if the element has left
                ## divde to iterate thru the left only
                tmp = nums[0: idx]
                max_el = max(tmp)
                root.left = traverse(root.left, tmp, max_el) ## assign left node
                traverse(root.left, tmp, max_el) ## traverse to next node

            ## check if the current max has right
            if idx < len(nums) - 1:
                tmp = nums[idx + 1: len(nums)]
                if tmp:
                    max_el = max(tmp)
                root.right = traverse(root.right, tmp, max_el)
                traverse(root.right, tmp, max_el)
            return root
        traverse(root, nums, max_el)
        return root

