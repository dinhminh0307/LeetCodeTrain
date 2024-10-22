from typing import List

# https://leetcode.com/problems/build-an-array-with-stack-operations/submissions/1430030065/
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        stack = []
        op = []
        idx = 0
        for i in range(1, n + 1):
            stack.append(i)
            op.append("Push")
            if idx < len(target) and target[idx] != stack[-1]:
                stack.pop()
                op.append("Pop")
            else:
                idx = idx + 1
            if idx == len(target):
                break
            
        return op




            
