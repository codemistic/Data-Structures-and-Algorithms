class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1;
        int count1=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]>nums[i])
            {count++;
            count1=max(count,count1);}
            else
                count=1;

        }
        return count1;
        
    }
};
