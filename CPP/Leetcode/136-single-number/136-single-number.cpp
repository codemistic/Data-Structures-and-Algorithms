class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            k=k^nums[i];
        }
        return k;
        
    }
};