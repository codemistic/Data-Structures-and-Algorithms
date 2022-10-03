class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int solve(int n, int k, int sum){
        if(n == 0 && sum == 0)return 1;
        if(n == 0 || sum <= 0)return 0;
        
        if(dp[n][sum] != -1)return dp[n][sum];
        
        long long ans = 0;
        for(int i = 1; i <= k ; i++){
            if(sum >= i){
                ans += (solve(n-1,k,sum-i)%mod);
                ans%=mod;
            }
        }
        return dp[n][sum] = (int)ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(n,k,target);
    }
};
