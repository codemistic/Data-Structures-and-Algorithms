//question = https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int start_index = -1;
        int end_index = -1;
        while (start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]<target)
                start = mid +1;
            else if(nums[mid]>target)
                end = mid - 1;
            else{
                start_index = mid;
                end = mid - 1;
            }
        }
        start = 0;
        end = nums.length - 1;
        while (start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]<target)
                start = mid +1;
            else if(nums[mid]>target)
                end = mid - 1;
            else{
                end_index = mid;
                start = mid +1;
            }
    }
        int[] a = {start_index,end_index};
        return a;
}}