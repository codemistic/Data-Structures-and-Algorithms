class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<int> profit_after_buying(k + 1, -1e9), profit_after_selling(k + 1, 0);

        for (int i = 0; i < prices.size(); ++i) {
            int cur_price = prices[i]; 
            for (int j = k; j >= 1; --j) {
                profit_after_buying[j] = max(profit_after_buying[j], profit_after_selling[j-1] - cur_price);
                profit_after_selling[j] = max(profit_after_selling[j], profit_after_buying[j] + cur_price);
            }
        }
        return profit_after_selling[k];
    }

};