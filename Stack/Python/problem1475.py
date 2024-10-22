# https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

from typing import List


class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        st = [] # stack to keep track the indice
        res = prices[:]  # Initialize res with the original prices

        for i in range(len(prices)):
            while len(st) > 0 and prices[st[-1]] >= prices[i] :
                
                diff = prices[st[-1]]  - prices[i] # since the price which is not yet minus is in the stack, find until the price meet another discount then discount the last index original price
                
                print(f"{diff} {st[-1]} {prices[i]}  pos: {st[-1]}")
                res[st[-1]] = diff # update the index with new price after discount
                st.pop()

            st.append(i)
        return res
        
prices = [8,7,4,2,8,1,7,7,10,1]
solution = Solution()
print(solution.finalPrices(prices))  # Expected: [4, 2, 4, 2, 3]