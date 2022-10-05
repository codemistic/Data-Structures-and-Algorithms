// Problem link : https://leetcode.com/problems/median-of-two-sorted-arrays/description

class Solution {
public double findMedianSortedArrays(int[] nums1, int[] nums2) {
int arr[]=new int[nums1.length+nums2.length];

    int j=0;
    int i=0;
        int r=0;
    while(i<nums1.length && j<nums2.length)
    {
     if(nums1[i]<nums2[j])
     {
         arr[r]=nums1[i];
         i++;
         r++;
     }
        else if (nums1[i]>nums2[j])
        {
          arr[r]=nums2[j];
         j++;
            r++;
        }
        else
        {
            arr[r]=nums1[i];
            r++;
            arr[r]=nums2[j];
            r++;
            i++;
            j++;
        }
        
    }
    while(i<nums1.length)
    {
        arr[r]=nums1[i];
        r++;
        i++;
    }
    while(j<nums2.length)
    {
        arr[r]=nums2[j];
        r++;
        j++;
    }
    if(arr.length%2==0)
    {

      double a1= Double.valueOf(  arr[arr.length/2]);
        double a2=Double.valueOf(arr[arr.length/2-1]);
        double d= (a1+a2)/2;
    return d;
    }
    else
    {
        return Double.valueOf(arr[arr.length/2]);
    }
}
}