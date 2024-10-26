from typing import List


class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        res = [0] * len(code)

        if k == 0:
            return res
        for i in range(len(code)):
            curr = 0
            if k > 0:
                # This loop structure ensures you're summing the k consecutive elements starting from the next position after i
                # , and using the modulo (% n) ensures that when i + j exceeds the list length, it wraps around to the beginning.
                # When j = 1, you're accessing code[(i + 1) % n] (the element just after the current one).
                # When j = 2, you're accessing code[(i + 2) % n], and so on.
                for j in range(1, k + 1):
                    curr += code[(i + j) % len(code)]
            elif k < 0:
                # move backward to sum all the k element before the current index i
                for j in range(1, abs(k) + 1):
                    curr += code[(i - j) % len(code)]
            res[i] = curr
        return res
    
sol = Solution
sol.decrypt(sol, [5,7,1,4], 3)
