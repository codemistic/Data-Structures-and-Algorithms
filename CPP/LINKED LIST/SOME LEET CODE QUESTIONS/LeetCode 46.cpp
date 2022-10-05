class Solution {
public:
    int perm(vector<int> nums, vector<vector<int>> &ans, vector<int> &smallAns)
    {
        if(smallAns.size()==nums.size())
        {
            ans.push_back(smallAns);
            return 1;
        }
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=-11)
            {
                int temp=nums[i];
                nums[i]=-11;
                vector<int> tem = smallAns;
                tem.push_back(temp);
                count+=perm(nums,ans,tem);
                nums[i]=temp;
            }
        }
        return count;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> smallAns;
        int s=perm(nums,ans,smallAns);
        return ans;
    }
};