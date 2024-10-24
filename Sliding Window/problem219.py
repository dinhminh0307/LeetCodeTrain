from typing import List

# Solution: use a hash table to store {value, index}
# if not find the nums[i] key, append the table
# if find the value and the abs is gereater than k, pop that in the hash table and insert the new one to the window
# continue to do it to meet the condition
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        m = {}
        for i in range(len(nums)):
            if nums[i] not in m:
                m[nums[i]] = i
                
                
            else:
                if abs(m[nums[i]] - i) <= k:
                    return True
                m.pop(nums[i])
                m[nums[i]] = i
        return False
sol = Solution
sol.containsNearbyDuplicate(sol, [1,2,3,1,2,3], 2)