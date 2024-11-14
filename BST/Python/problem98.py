# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # Initialize the upper and lower bounds for the root node
        upper = float('inf')
        lower = float('-inf')
        
        # Define a helper function to traverse the tree recursively
        def traverse(curr, min_inf, max_inf):
            # Assume the current subtree is valid initially
            check_left = True
            check_right = True
            
            # If there is a left child, validate it
            if curr.left:
                # The left child's value must be less than the current node's value
                # and greater than the minimum allowed value (min_inf)
                if not (curr.left.val < curr.val and curr.left.val > min_inf):
                    # If the left child violates the BST property, return False
                    return False
                # Recursively traverse the left subtree with updated bounds
                # The new upper bound for the left subtree is the current node's value
                check_left = traverse(curr.left, min_inf, curr.val)
            
            # If the left subtree is invalid, no need to check further
            if not check_left:
                return False
            
            # If there is a right child, validate it
            if curr.right:
                # The right child's value must be greater than the current node's value
                # and less than the maximum allowed value (max_inf)
                if not (curr.right.val > curr.val and curr.right.val < max_inf):
                    # If the right child violates the BST property, return False
                    return False
                # Recursively traverse the right subtree with updated bounds
                # The new lower bound for the right subtree is the current node's value
                check_right = traverse(curr.right, curr.val, max_inf)
            
            # If the right subtree is invalid, return False
            if not check_right:
                return False
            
            # If both left and right subtrees are valid, return True
            return True
        
        # Start the traversal from the root with the initial bounds
        res = traverse(root, lower, upper)
        
        # Return the final result indicating whether the tree is a valid BST
        return res
