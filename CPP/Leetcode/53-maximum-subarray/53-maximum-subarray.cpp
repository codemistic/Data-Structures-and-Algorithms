class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=-1e4;
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
         }
        return maxi;
    }
};