class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        long long int mat[n + 1][amount + 1];
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < n + 1; i++) {
            mat[i][0] = 1;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j) {
                    mat[i][j] = mat[i - 1][j] + mat[i][j - coins[i - 1]];
                }
                else {
                    mat[i][j] = mat[i - 1][j];
                }
            }
        }
        return mat[n][amount];
    }
};

// This code is using memoization / DP
// We store result of smaller query and use them for larger query
// Here is the problem description: https://leetcode.com/problems/coin-change-ii/description/
