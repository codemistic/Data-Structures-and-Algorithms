package Binary_On_1DArray;
public class LowerBound {
    public static void main(String args[])
    {
        int arr[]={1,2,3,4,5,6,7,9,10};
        int x=8;
        System.out.println(lowerBound(arr,x));

    }
    public static int lowerBound(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int ans = nums.length;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
}
