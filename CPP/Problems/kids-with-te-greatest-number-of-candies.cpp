class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool>ans;
        int max1=INT_MIN;
        for(int i=0;i<n;i++)
        {
            max1=max(max1,candies[i]);
            
        }
        for(int i=0;i<n;i++)
        {
            if((candies[i]+extraCandies)>=max1)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
        
    }
};
