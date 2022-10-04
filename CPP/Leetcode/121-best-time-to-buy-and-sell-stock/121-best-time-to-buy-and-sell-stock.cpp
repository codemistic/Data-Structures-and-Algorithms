class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<low)
            {
                low=prices[i];
            }
            int cnt=prices[i]-low;
            if(cnt>profit)
            {
                profit=cnt;
            }
            
        }
        return profit;
    }
};