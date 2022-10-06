//question = https://leetcode.com/problems/find-in-mountain-array/
class Solution {
    public int peakIndexInMountainArray(MountainArray arr) {
        int start = 0;
        int end = arr.length() - 1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr.get(mid)>arr.get(mid+1)){
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return start;
        
}
    public int findInMountainArray(int target, MountainArray arr) {
        int start = 0;
        int end = peakIndexInMountainArray(arr);
        
        while(start<=end){
            int mid = start + (end-start)/2;
            int x = arr.get(mid);
            if(x>target)
                end = mid - 1;
            else if(x<target)
                start = mid + 1;
            else
                return mid;
        }
        
        start = peakIndexInMountainArray(arr);
        end = arr.length() - 1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            int x = arr.get(mid);
            if(x>target)
                start = mid + 1;
            else if(x<target)
                end = mid -1;
            else
                return mid;
        }
        
        return -1;
        
}}