from typing import List

# Solution: The idea here is to keep track the lowest price.
# Since the profit is buy low and sell high, so that the current left is the lowest price we have and the current index is used to find any higher price to find the profit then update the max_profit
# if we find any lower price than current price, we update and find the higher find next. Update current max_profit if find any profit higher
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        min_price = prices[0]
        for i in prices:
            min_price = min(i, min_price)
            profit = i - min_price
            max_profit = max(max_profit, profit)
        return max_profit