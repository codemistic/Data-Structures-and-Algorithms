/* Binary Search is an sorting algorithm to  traverse the array in a divide and conquer method.
      It works efficiently if the array or the list is sorted.
      Divide and conquer refers to the approch of dividing the list into 2 halves and the performing the search based on the middle element.
      In an asscendind ordered list..
        If the element is in the middle element, then the middle element is returned.
        If the element is less than the middle element, then divide and narrow the interval to the left side of the list.
        If the element is greater than the middle element, then divide and narrow the interval to the right side of the list.
        Repeat the iteration till the element is found or the list becomes empty.
        If the element is not found in the list return -1.
      Best case Time Complexity for Binary Search is : O(1) i.e the element is found on the first iteration.
      Average and Worst case Time Complexity for Binary Search is: O(log n) i.e dividing the list till there is one element in the list or the list becomes empty */
        
        
        
public class BinarySearch {
    public static void main(String[] args) {
    
        int arr[]={-21,-12,-3,0,4,5,12,32,46,57,78};
        
        int target=12;
        
        int result=binarysearch(arr,target);  // passes the the given array(arr) and the element to be searched as the arguments
        
        // The element and index is displayed in the specified format using "printf".
        
        System.out.printf("The element %d is found in the index of %d",target,result);
    }

     static int binarysearch(int[] arr, int target) {
        int start=0;
        int end=arr.length-1;
       
        while(start<=end){ // iteration using while loop.
        
            int mid=start + (end-start)/2;
            
            if(arr[mid]>target)  // the target element is on the left side of the list.
                end=mid-1;
                
            else if(arr[mid]<target) // the target element is on the right side of the list.
                start=mid+1;
                
            else
                return mid; // the element is in the middle.
        }
        return -1; // return -1, if the target element is not found in the list.
    }
}
