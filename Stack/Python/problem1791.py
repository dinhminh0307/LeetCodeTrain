from typing import List
from collections import Counter

class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        merged_list = [item for sublist in edges for item in sublist] # convert 2D to 1D
        res = Counter(merged_list) # Make use of Python Counter which returns count of each element in the list.
        return res.most_common(1)[0][0] # simply find the most common element by using most_common() method. 

sol = Solution
