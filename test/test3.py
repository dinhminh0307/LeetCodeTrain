from typing import List


class Solution:
    def findMiddle(self, ll: List[int]) -> int:
        return ll[len(ll) // 2]

sol = Solution
print(sol.findMiddle(sol, [1,2,3,4,5]))
print(sol.findMiddle(sol, [1,2,3,4,5,6]))
