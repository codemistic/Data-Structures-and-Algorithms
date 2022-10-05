class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int ans = 0;
        while(i<j)
        {
            ans += nums[j]-nums[i];
            i++;
            j--;
        }
        return ans;
    }
};