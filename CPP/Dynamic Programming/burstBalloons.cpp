// this is hard level DP problem on lc
// https://leetcode.com/problems/burst-balloons/

// both memoization and tabulation approaches
class Solution
{
    // private:
    //     int solve(int i, int j, vector<int>&nums,vector<vector<int>>&dp){
    //         //base case
    //         if(i>j){
    //             return 0;
    //         }
    //         if(dp[i][j]!=-1){
    //             return dp[i][j];
    //         }
    //         int ans = INT_MIN;
    //         for(int ind = i;ind<=j;ind++){
    //             //think in terms as we are bursting last balloon
    //             int cost = nums[ind]*nums[i-1]*nums[j+1] + solve(i,ind-1,nums,dp) + solve(ind+1,j,nums,dp);
    //             ans = max(ans,cost);
    //         }
    //         return dp[i][j] = ans;
    //     }
public:
    int maxCoins(vector<int> &nums)
    {
        // mcm as we are given according to ordering and maxi so use dp
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        //[1,3,1,5,8,1]
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solve(1,n-2,nums,dp);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // think in terms of reverse of memo
        for (int i = n - 2; i >= 1; i--)
        {
            for (int j = 1; j <= n - 2; j++)
            {
                if (i > j)
                {
                    continue;
                }
                int ans = INT_MIN;
                for (int ind = i; ind <= j; ind++)
                {
                    int cost = nums[ind] * nums[i - 1] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    ans = max(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n - 2];
    }
};