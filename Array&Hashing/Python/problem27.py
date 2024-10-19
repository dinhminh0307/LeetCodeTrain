from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        count = 0
        while nums.__contains__(val):
            nums.remove(val)
        
        return len(nums)
    
nums = [0,1,2,2,3,0,4,2]
val = 2
solution = Solution()
new_length = solution.removeElement(nums, val)
print("New length:", new_length)  # Expected: 2
print("Modified array:", nums[:new_length])  # Expected: [2, 2]