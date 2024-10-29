class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        m = {}
        stack = []
        right = 3
        if len(s) < 3:
            return 0
        res = s[0:right]
        
        stack.append(res)
        for c in res:
            m[c] = m.get(c, 0) + 1
            if m[c] > 1:
                stack.pop()
                break
        m.clear()
        for left in range(len(s) - 3):
            left += 1
            right += 1
            
            res = s[left:right]
            stack.append(res)
            for c in res:
                m[c] = m.get(c, 0) + 1
                if m[c] > 1:
                    stack.pop()
                    break
            m.clear()
        return len(stack)

sol = Solution
sol.countGoodSubstrings(sol, "aababcabc")