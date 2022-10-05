class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v;
        int z=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i==j) continue;
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    z=1;
                    break;
                }
            }
            if(z==1)break;
        }
        if(z==1)
        {
            return v;
            }
        else
        {
            v.push_back(-1);
            return v;
        }
        
        
    
}
};