// this is medium lc problem based on DP
// https://leetcode.com/problems/unique-paths/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // can be done by recursion then memoization and then tabulation...
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // think backwords
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // destination
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0;
                    int left = 0;
                    // validity
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
// Time Complexity: O(N*N)
// Reason: There are two nested loops.
// Space Complexity: O(N)

// contributed by Anish Tiwari