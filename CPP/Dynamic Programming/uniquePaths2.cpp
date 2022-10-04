// this is medium level DP problem on lc
// https://leetcode.com/problems/unique-paths-ii/
class Solution
{
    // private:
    //     int solve(int i, int j, int m, int n, vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
    //         //base case
    //         // if(i>=m || j>=n || obstacleGrid[i][j] == 1){
    //         //     return 0;
    //         // }
    //         // if(dp[i][j]!=-1){
    //         //     return dp[i][j];
    //         // }
    //         // if(i == m-1 && j == n-1){
    //         //     return 1;
    //         // }
    //         // return dp[i][j] =  solve(i+1,j,m,n,obstacleGrid,dp)+solve(i,j+1,m,n,obstacleGrid,dp);
    //     }
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // int m = obstacleGrid.size();
        // int n = obstacleGrid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(0,0,m,n,obstacleGrid,dp);

        // tabulation
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};