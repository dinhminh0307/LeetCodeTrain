from typing import List
#Logic: the goal is to have 2 poiters left and right to perform the window
# if the nums[right] - nums[left] equal to 1, continue to move the right
# if it is > 1 move the left because the nums is sorted so that left must be move to right to increast
# uf it is  = 0 , continue to move the right so that nums[right] larger than the nums[left]
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        left = 0
        res = 0

    
        for right in range(len(nums)):
            if right == 0:
                continue
            print(f"{right} {left}")
            
            while right < len(nums) and left < right and nums[right] - nums[left] > 1:
                left += 1
            if  nums[right] - nums[left] == 0:
                continue  
            res = max(res, right - left + 1)  
        
        if res == 1:
            return 0
        return res
