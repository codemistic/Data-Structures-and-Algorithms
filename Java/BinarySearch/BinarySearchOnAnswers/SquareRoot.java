package BinarySearchOnAnswers;

public class SquareRoot {
    public static void main(String args[])
    {
        int n=4;
        //Approach 1 : Linear Search
        // TC : O(sqrt(n))

        for(int i=0;i<=n;i++)
        {
            if(i*i==n)
            {
                System.out.println(i);
                break;
            }
        }

        //Approach 2 : Binary Search
        // TC : O(log n)
        
        int start=1;
        int end=n;
        int ans=-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int square=mid*mid;
            if(square==n)
            {
                ans=mid;
                break;
            }
            else if(square<n)
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }

    }
}
