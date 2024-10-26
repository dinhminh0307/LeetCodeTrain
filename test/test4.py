from typing import List


class Solution:
    def countSubset(self, arr: List[int], sum : int) -> int:
        res = {0}
        for i in arr:
            s = set()

            for el in res:
                s.add(el + i)
            res.update(s)
        return len(res)



