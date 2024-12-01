#https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=problem-list-v2&envId=backtracking&difficulty=EASY

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        res = 0
        sol = []
        def dfs(i):
            nonlocal res
            if i >= len(nums):
                # take the XOR
                result = 0
                for idx in sol:
                    result ^= idx
                    # sum up the XOR
                res += result
                return
            # case not take nums[i]
            dfs(i + 1)
            # case take nums[i]
            sol.append(nums[i])
            dfs(i+1)
            sol.pop()
        dfs(0)
        return res