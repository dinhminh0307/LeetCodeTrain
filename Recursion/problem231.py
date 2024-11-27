#https://leetcode.com/problems/power-of-two/?envType=problem-list-v2&envId=recursion

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        power = 0
        if n > 1 and n % 2 is not 0: # if n not divided by 2, mean that false
            return False
        # idea: recursively power the exponent until n
        # if the 2 power of exponent equal to n, return True
        # if the 2 power of exponent larger than n mean that false
        def recursion(n):
            nonlocal power
            if 2 ** power == n:
                return True
            if 2 ** power > n:
                return False
            power += 1
            return recursion(n)
        return recursion(n)