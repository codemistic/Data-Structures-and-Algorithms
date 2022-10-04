// https://leetcode.com/problems/bitwise-xor-of-all-pairings/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
     int n1=nums1.size(),n2=nums2.size();
        if((n1%2==0)&&(n2%2==0)){
            return 0;
        }
         if((n1%2==0)){
             int ans=0;
            for(auto x:nums1)ans^=x;
             return ans;
        }
        if((n2%2==0)){
             int ans=0;
            for(auto x:nums2)ans^=x;
             return ans;
        }
          int ans=0;
            for(auto x:nums2)ans^=x;
        for(auto x:nums1)ans^=x;
        return ans;
    }
};
