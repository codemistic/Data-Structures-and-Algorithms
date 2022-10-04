// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
     auto low=lower_bound(nums.begin(),nums.end(),target);
        auto upp=upper_bound(nums.begin(),nums.end(),target);
        if(low==nums.end()|| *low!=target )
        {
            ans.push_back(-1);
              ans.push_back(-1);
        }
        else
        {
            int start=low-nums.begin();
            int end=upp-nums.begin()-1;
            ans.push_back(start);
             ans.push_back(end);
        }
        return ans;
    }
};
