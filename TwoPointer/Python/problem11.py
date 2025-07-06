class Solution:
    def maxArea(self, heights: List[int]) -> int:
        res = []
        r = 0
        l = len(heights) - 1

        while r < l:
            if heights[r] <= heights[l]:
                res.append(heights[r] * (l - r))
                r += 1
            elif heights[r] > heights[l]:
                res.append(heights[l] * (l - r))
                l -= 1
        return max(res)
            