// 72. Edit Distance (LeetCode Hard)
// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    
    int solve(int i1, int i2, string word1, string word2, vector<vector<int>>&dp)
    {
        //base case
        if (i1 == -1 && i2 == -1)
        {
            return 0;
        }
        if (i1 == -1)
        {
            return i2 + 1;
        }
        if (i2 == -1)
        {
            return i1 + 1;
        }
        
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        
        //recursion
        
        if (word1[i1] == word2[i2])
        {
            return solve(i1 - 1, i2 - 1, word1, word2, dp);
        }
        
        int insert = solve(i1 - 1, i2 , word1, word2, dp);
        int del = solve(i1, i2 - 1 , word1, word2, dp);
        int replace = solve(i1 - 1, i2 - 1 , word1, word2, dp);
        
        dp[i1][i2] = 1 + min(insert, min(del, replace));
        return dp[i1][i2];
    }
    
    int minDistance(string word1, string word2) {
        
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>>dp(l1, vector<int>(l2, -1));
        
        return solve(l1 - 1, l2 - 1, word1, word2, dp);
        
    }
};