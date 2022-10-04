/*-----------
    Problem link :  https://leetcode.com/problems/maximum-subarray/
  ------------*/   

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int cs{};
        int max_sum =INT_MIN;
        for(int i = 0;i<nums.size();i++){
            cs = cs + nums[i];
            max_sum = max(max_sum,cs);
            if(cs < 0) cs = 0;
            
        }
        return max_sum;
    }
};