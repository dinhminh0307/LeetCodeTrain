# https://leetcode.com/problems/find-the-difference/?envType=problem-list-v2&envId=hash-table&difficulty=EASY

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        m = {}
        m2 = {}
        for c in s:
            m[c] = m.get(c, 0) + 1

        for c in t:
            m2[c] = m2.get(c, 0) + 1
            if c not in m:
                return c
            else:
                if m2[c] > m[c]:
                    return c
        return ""