class Solution {
public:
    string longestCommonPrefix(vector<string>& nums) {
        
    string res="";
       for(int i=0;i<nums[0].size();i++)
       {
           for(int j=0;j<nums.size()-1;j++)
           {
               if(nums[j][i]!=nums[j+1][i])
                   return res;
           }
           res=res+nums[0][i];
           
       }
        return res;
        
    }
};