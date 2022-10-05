class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
         vector<int> pos;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        vector<int> v;
        for(int i=0;i<pos.size();i++)
        {
            v.push_back(pos[i]);
            v.push_back(neg[i]);
            
        }
        return v;
        
    }
};