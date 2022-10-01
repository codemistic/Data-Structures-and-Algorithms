class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while(i<n1 and j<n2){
            if(nums1[i] <= nums2[j]){
                nums.push_back(nums1[i++]);
            }
            else{
                nums.push_back(nums2[j++]);
            }
        }
        cout<<i<<j;
        while(i<n1){
            nums.push_back(nums1[i++]);
        }
        while(j<n2){
            nums.push_back(nums2[j++]);
        }
        cout<<i<<j;
        int n = nums.size()/2;
        cout<<nums.size();
        if(nums.size()%2 == 0){
            cout<<(nums[n-1]+nums[n]);
            return (double)(nums[n-1]+nums[n])/2;
        }
        else return (double)(nums[n]);
    }
};
