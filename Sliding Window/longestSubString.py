class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = ""
        max_len = 0
        for c in s:
            if c not in res:
                res += c
            else:
                idx = res.index(c)
                
                indices_to_remove = []
                # delete the index of current char that duplcate to the index 0
                while idx >= 0:
                    indices_to_remove.append(idx)
                    idx -=1
                res = ''.join([res[i] for i in  range(len(res)) if i not in indices_to_remove])
                print(res)
                res += c
            max_len = max(max_len, len(res))
        return max_len
    
sol = Solution
sol.lengthOfLongestSubstring(sol, "pwwkew")