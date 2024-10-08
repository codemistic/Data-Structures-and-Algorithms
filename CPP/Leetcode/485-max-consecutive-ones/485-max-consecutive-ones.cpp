class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int m=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) cnt++;
            if(nums[i]==0 || i+1==nums.size())
            {
                m=max(m,cnt);
                cnt=0;
            }
        }
        return m;
        
    }
};