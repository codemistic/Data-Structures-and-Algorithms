
/*

Kth Missing Number
Given a sorted array arr of unique integers, return the Kth missing number starting from the leftmost number of the array.

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing numbers are [1,5,6,8,9,10,12,13,...]. The 5th missing number is 9.

Approach : Binary Search
very mid index, we can count how many numbers are missing until that index by the formula:
missingCount = arr[mid] - (mid + 1)

if missingCount < k, then we need to search in the right half of the array
else we need to search in the left half of the array

TimeComplexity: O(log n) // n is the length of the array
Space Complexity: O(1)

*/


public class KthMissingNumber {
    public static void main(String args[]){
       int arr[]={2,3,4,7,11};
       int k=5;
       int left=0;
       int right=arr.length-1;
       while(left<=right)
       {
          int mid=(left)+(right-left)/2;
          int missingCount=arr[mid]-(mid-1);
          if(missingCount<k)
          {
            left=mid+1;
          }
          else
          {
            right=mid-1;
          }
       }
        int result=left+k;
        System.out.println(result);

}

}