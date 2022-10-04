// Question Link
// https://leetcode.com/problems/maximum-product-subarray/
// ----------------------------------------------

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min_dp[n];
        int max_dp[n];
        min_dp[0] = nums[0];
        max_dp[0] = nums[0];
        for(int i=1;i<n;i++){
            max_dp[i] = max(max_dp[i-1]*nums[i],max(nums[i],nums[i]*min_dp[i-1]));
            min_dp[i] = min(min_dp[i-1]*nums[i],min(nums[i],nums[i]*max_dp[i-1]));
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,max_dp[i]);
        }
        return ans;        
    }
};