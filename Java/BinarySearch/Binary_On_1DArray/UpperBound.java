package Binary_On_1DArray;
public class UpperBound {
    public static void main(String args[])
    {
        int arr[]={1,2,3,4,5,7,8,9};
        int x=6;
        System.out.println(upperBound(arr,x));
    }
    public static int upperBound(int arr[],int x)
    {
        int start=0;
        int end=arr.length-1;
        int ans=arr.length;
        while(start<=end)
        {
            int mid=(end+start)/2;
            if(arr[mid]>x)
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
}
