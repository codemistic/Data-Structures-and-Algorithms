// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Buy and sell stock 2

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int buy = INT_MAX , profit = 0, curr_profit = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (prices[i] > buy)
            {
                curr_profit += prices[i] - buy; 
            }
            
            else if (prices[i] < buy)
            {
                profit += curr_profit;
                curr_profit = 0;
            }
            buy = prices[i];
        }
        profit += curr_profit;
        return profit;
    }
};