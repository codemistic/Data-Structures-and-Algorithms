//this is medium level DP problem on lc
//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        //can be done by recursion then memo and then tabu
        vector<vector<int>>dp(m,vector<int>(n,0));
        //think backwords
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                //destination
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    //validity
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
//complexities
//tc --> o(N*N)
//reason -> as we have two nested loops
//sc -> O(N) 

//contributed by Anish Tiwari