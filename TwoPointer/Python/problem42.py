class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        sum_res = 0
        res = []
        max_l = height[l]
        max_r = height[r]
        while l < r:
            if height[l] < height[r]:    
                area = max_l - height[l]
                max_l = max(max_l, height[l])
                l += 1
            else:
                area = max_r - height[r]
                max_r = max(max_r, height[r])
                r -= 1
            if area < 0:
                res.append(0)
            else:
                res.append(area)
            
        # sum up the res to get the result
        for n in res:
            sum_res += n
        return sum_res