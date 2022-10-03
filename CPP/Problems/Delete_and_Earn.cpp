// Question Link
// https://leetcode.com/problems/delete-and-earn/
// ----------------------------------------------
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int freq[10001];
        int n = nums.size();
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int dp[10001];
        memset(dp,0,sizeof(dp));
        dp[1] = 1*freq[1];
        dp[0] = 0;
        for(int i=2;i<10001;i++){
            dp[i] = max(dp[i-2] + i*freq[i],dp[i-1]);
        }
        int ans = -1;
        for(int i=0;i<10001;i++){
            ans = max(ans,dp[i]);
        }
        return ans;              
    }
};