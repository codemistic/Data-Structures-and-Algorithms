// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        v.push_back(-1);
        return v;
        
    }
};
