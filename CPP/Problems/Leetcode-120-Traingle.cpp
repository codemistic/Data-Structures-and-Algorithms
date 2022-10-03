class Solution {
public:
    int dp[202][202];  
    Solution()
    {
        for(int i=0;i<202;i++)
        {
            for(int j=0;j<202;j++)
            {
                dp[i][j]=-1;
            }
        }
    } 
    int f(int i, int j, vector<vector<int>>&a ) 
    {
        if(i==a.size()-1)return a[i][j];    
        if(dp[i][j]!=-1)return dp[i][j]; 
        int d=a[i][j] + f(i+1,j,a);           
        int dg=a[i][j] + f(i+1,j+1,a);
        return dp[i][j]=min(d,dg);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return f(0,0,triangle);
    }
};