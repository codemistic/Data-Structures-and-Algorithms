// 516. Longest Palindromic Subsequence (Leetcode)

class Solution {
public:
    //THIS IS THE TABULATION/BOTTOM-UP SOLUTION SINCE MEMOIZATION IS HAVING (M*N + (M+N) -> AUXILIARY) SPACE COMPLEXITY AND HENCE GIVES NEEDS TO BE SPACE-OPTIMIZED!!
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        //copying the base case
        for(int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        //copying the recurrence relation
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
};
