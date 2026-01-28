/*

Time Complexity : 0(N log M) where N is number of flowers and M is the maximum bloom day
Space Complexity : O(1)

Problem Description :
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and
can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the
garden. If it is impossible to make m bouquets return -1.


*/


public class MinimumNoOfDaysToMakeBouquets {
    public static void main(String args[])
    {
        int bloomDay[]={1,10,3,10,2};
        int m=3;
        int k=1;
        int result=minDays(bloomDay,m,k);
        System.out.println("Minimum days to make bouquets is : "+result);

    }
    public static int minDays(int[] bloomDay, int m, int k) {
        int left=1;
        int right=0;
        for(int day:bloomDay)
        {
            right=Math.max(right,day);
        }
        int answer=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(canMakeBouquets(bloomDay,m,k,mid))
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
    public static boolean canMakeBouquets(int[] bloomDay, int m, int k, int mid) {
        int bouquets=0;
        int flowers=0;
        for(int day:bloomDay)
        {
            if(day<=mid)
            {
                flowers++;
            }
            else
            {
                bouquets+=flowers/k;
                flowers=0;
            }
        }
        bouquets+=flowers/k;
        return bouquets>=m;
    }
}
