from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        max_future_price = 0  # Maximum price encountered from the future

        for price in reversed(prices):
            max_future_price = max(max_future_price, price)  # Update max future price
            max_profit = max(max_profit, max_future_price - price)  # Update max profit
        
        return max_profit
