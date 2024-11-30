# https://leetcode.com/problems/subsets/description/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        solution = []
        def backtrack(i):
            # base case
            if i >= len(nums):
                res.append(solution.copy()) # pass the copy not ref
                return
            # decision not pick the nums[i]
            backtrack(i + 1) # just skipp ading to solution arr

            # decision pick nums[i]
            solution.append(nums[i]) # just picking by add to solution
            backtrack(i + 1) # move to next index

            # when go full left and right of decision tree
            # go to previous decision node and pop the current node
            solution.pop() 
        backtrack(0)
        return res