// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int h=m;
        int j=(m+n)-1;
        int i=0;
        int k=0;
        while(i<(m+n))
        {
            if(nums1[i]<nums2[k])
            {
                i++;
            }
            else
            {
                if(nums1[h]!=0){
                nums1[h+1]=nums1[h];
                nums1[i]=nums2[k];}
                else
                {nums1[i]=nums2[k];}
                k++;
                h++;
                i++;
            }
        }
       // sort(nums1.begin(),nums1.end());
            
   
    }
};
