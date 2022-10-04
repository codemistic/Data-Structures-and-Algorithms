class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[cnt]=nums[i+1];
                cnt++;
            }
            
        }
        return cnt;
        
    }
};