
// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.

//

public class PeakElement {
    public static void main(String args[])
    {
        //Approach one Linear Scan 
        //TC: 0(N)
        //SC: O(1)
        int arr[]={1,2,1,3,5,6,4};

        for(int i=0;i<arr.length;i++)
        {
            if(i==0) // first element is peak element 
            {
                  if(arr[i]>arr[i+1])
                  {
                    System.out.println("Peak Element is " + arr[i]);
                    break;
                  }


            }
            else if (i==arr.length-1)
            {
                if(arr[i]>arr[i-1])
                {
                    System.out.println("Peak Element is " + arr[i]);
                    break;
                }
            }

            else
            {
                if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                {
                    System.out.println("Peak Element is " + arr[i]);
                    break;
                }
            }

            //Approach 2 Binary Search
            //TC: O(log N)
            int start=0;
            int end=arr.length-1;
            while(start<end)
            {
                int mid=(start+end)/2;
                if(arr[mid]>arr[mid+1])
                {
                    end=mid;
                }
                else
                {
                    start=mid+1;
                }
            }
                
        
        }
    }
}
