class Solution {
public:
    int solvetab(vector<int> &nums)
    {
         vector<vector<int>> dp(nums.size()+3,vector<int>(nums.size()+3,0));
        for(int curr= nums.size()-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                    
                    int inc=0;
                    //include
                    if(prev==-1||nums[curr]>nums[prev])
                    {
                        inc= 1+dp[curr+1][curr+1];
                    } 
                    int excl=dp[curr+1][prev+1];
                    dp[curr][prev+1]=max(inc,excl);

            }
        }
        return dp[0][0];
    }
    int solve(vector<int> &nums,int i,int prev,vector<vector<int>> &dp)
    {
        //base condition
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        //exclude
        int excl=solve(nums,i+1,prev,dp);
        int inc=0;
        //include
        if(prev==-1||nums[i]>nums[prev])
        {
            inc= 1+solve(nums,i+1,i,dp);
        }
        
        return dp[i][prev+1]=max(inc,excl);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size()+3,vector<int>(nums.size()+3,-1));
        // return solve(nums,0,-1,dp);
        return solvetab(nums);
        
    }
};