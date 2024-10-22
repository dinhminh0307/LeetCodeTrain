from typing import List
# https://leetcode.com/problems/validate-stack-sequences/

class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        idx = 0
        stack = []
        for i in range(len(pushed)):
            stack.append(pushed[i])
            if stack[-1] != popped[idx]:
                continue
            while stack and stack[-1] == popped[idx]:
                stack.pop()
                idx += 1
        if stack:
            return False
        return True
        

