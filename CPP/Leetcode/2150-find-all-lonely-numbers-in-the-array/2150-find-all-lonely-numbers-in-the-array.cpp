class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==1 && mp[nums[i]-1]==0 && mp[nums[i]+1]==0) v.push_back(nums[i]);
        }
        return v;
        
    }
};