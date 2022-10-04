class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> s;
        for(int i=1;i<nums.size();i++)
        {
            s.insert(nums[i-1]+nums[i]);
        }
        if(s.size()>=nums.size()-1) return false;
        return true;
    }
};