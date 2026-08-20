package Binary_On_1DArray;

public class CeilAndFloor {
    public static void main(String args[])
    {
    int arr[]={1,2,3,4,5,7,8,9};
    int x=6;
    System.out.println(ceil(arr,x) + " " + floor(arr,x));
    }
    public static int ceil(int arr[],int x)
    {
        int start=0;
        int end=arr.length-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]>=x)
            {
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    public static int floor(int arr[],int x)
    {
        int start=0;
        int end=arr.length-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]<=x)
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
}
