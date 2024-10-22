# https://leetcode.com/problems/largest-rectangle-in-histogram/

from typing import List
#Solution: 
#1. use stack to keep track to store the current height and the storing index
# if the current bar larger than the top, push to the stack
# if the current bar smaller than top, calculate the area in the top index and pop it
# The remaing in the stack is the bars can be expanded further
# loop thru every elements in the stack left and calculate the area
#update the largest if needed
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [] 
        largest = 0
        
        # Handle edge case: empty list
        if len(heights) == 0:
            return 0
        
        if len(heights) == 1:
            return heights[0]
        
        # Main loop through the histogram
        for i in range(0, len(heights)):
            start = i
            area = 0
            
            # Pop from stack if the current height is less than the stack's top
            while stack and stack[-1][1] > heights[i]:
                tmp = stack.pop()
                area = (i - tmp[0]) * tmp[1]
                start = tmp[0]  # Move the start back to the index of the popped item
                if area > largest:
                    largest = area 
            
            # Push current bar with the updated start index
            stack.append((start, heights[i]))
        
        # Final pass to clear the stack and calculate remaining areas
        while stack:
            val = stack.pop()
            print(f"index: {val[0]} value: {val[1]}")
            area = (len(heights) - val[0]) * val[1]  # Use the full width up to the end of the histogram
            if area > largest:
                largest = area

        print(largest)
        return largest
        


   
sol = Solution 
heights = [5,5,1,7,1,1,5,2,7,6]
sol.largestRectangleArea(sol,heights)