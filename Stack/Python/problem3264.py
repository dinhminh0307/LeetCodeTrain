from typing import List
# https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        while k > 0:
            min_val = min(nums)
            idx = nums.index(min_val)
            nums[idx] = min_val * multiplier
            k = k - 1
        return nums