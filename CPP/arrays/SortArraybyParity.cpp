class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1)
        {return nums;}
        
        int i = 0,j=0;
        while(i<n)
        {
            if(nums[i]%2!=0)
            {
                ++i;
            }
            else
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
        return nums;
    }
};