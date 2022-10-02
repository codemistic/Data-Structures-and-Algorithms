class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     
        vector<int> ans;
       
        int i=0;
        int slice=nums.size()/2-1;
        int j=slice+1;
        while(i<slice || j<nums.size()){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans; 
    }
};