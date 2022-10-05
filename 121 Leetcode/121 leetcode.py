class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0
        currentMax = 0

        for i in reversed(prices):
            currentMax = max(currentMax, i)
            profit = currentMax - i
            maxProfit = max(profit, maxProfit)
        return maxProfit  