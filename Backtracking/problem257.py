# https://leetcode.com/problems/binary-tree-paths/submissions/1466717193/?envType=problem-list-v2&envId=backtracking&difficulty=EASY
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    #idea: backtracking all the path to a stack, when reach the end node,
    # concat the stack to a string and store to res list
    # recursively do over again until traverse all the tree
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res = [] # store the string result
        sol = deque() # stack to store the node and "->"
        IS = root.val # store the initial start
        sol.append(str(root.val)) # add the root to the stack
        def backtracking(curr):
            if not curr: # base case
                return
            # skip adding the root to avoid duplicate in stack
            if curr.val is not IS:
                #add current node and "->" to stack later concat to string
                sol.append("->")
                sol.append(str(curr.val))

            #dfs algorithm
            backtracking(curr.left)
            backtracking(curr.right)
            if not curr.left and not curr.right:
                # case the end node in the tree, convert stack to string and
                #store in res list then pop the elements just traversed
                str_res = ''.join(sol)
                res.append(str_res)
                if len(sol) > 2:
                    sol.pop()
                    sol.pop()
                return
            ## when return back to prev node, pop the current node and "->"
            # in the stack
            if len(sol) > 2:
                sol.pop()
                sol.pop()
            return
        backtracking(root)
        return res
                