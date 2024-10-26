from typing import List


class Solution:
    def checkArray(self, arr1: List[int], arr2: List[int]) -> bool:
        for i in arr1:
            if i not in arr2:
                return False
        return True

sol = Solution
print(sol.checkArray(sol, [1,2,5,4,0], [2,4,5,0,1]))
print(sol.checkArray(sol, [1,2,5], [2,4,15]))
print(sol.checkArray(sol, [1,2], [2,1,15,17]))