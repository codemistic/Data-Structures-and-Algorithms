// https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()< 2)
            return nums.size();
        int ans = 1;
        int f = -1;
        for(int i=1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                if(f==-1 || f==0) ans++;
                f = 1;
            }else if(nums[i] < nums[i-1]){
                if(f==1 || f==-1)ans++;
                f=0;
            }
        }
        return ans;
    }
};