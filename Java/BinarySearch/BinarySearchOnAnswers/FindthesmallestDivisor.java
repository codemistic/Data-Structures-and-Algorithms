
/*

Find the Smallest Divisor Given a Threshold
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and
divide all the elements of the array by it and sum the division results. Find the smallest divisor such that
the result is less than or equal to threshold.

Input: nums = [1,2,5,9], threshold = 6
Output: 5

Approach : Binary Search
To find the smallest divisor, we can use binary search on the range of possible divisors.
Time Complexity: O(n log m) // n is the length of the array, m is the maximum element in the array
Space Complexity: O(1)




*/



public class FindthesmallestDivisor {
    public static void main(String args[])
    {
        int[] nums={1,2,5,9};
        int threshold=6;
        int result=findSmallestDivisor(nums,threshold);
        System.out.println("The smallest divisor is : "+result);

    }
    public static int findSmallestDivisor(int[] nums, int threshold) {
        int left=1;
        int right=0;
        for(int num:nums)
        {
            right=Math.max(right,num);
        }
        int answer=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossible(nums,threshold,mid))
            {
                answer=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return answer;
    }
    public static boolean isPossible(int[] nums,int threshold,int divisor)
    {
        long sum=0;
        for(int num:nums)
        {
            sum+=Math.ceil((double)num/divisor);
        }
        return sum<=threshold;
    }
}
