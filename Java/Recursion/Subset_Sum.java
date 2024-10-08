import java.util.*;
class Subset_Sum 
{
    static int subset(int arr[],int s, int i, int n)
    {
        if(i == n)
           return ((s == 0) ? 1 : 0);
        return subset(arr, s - arr[i], i+1, n) + subset(arr, s ,i+1, n);
    }
    public static void main(String args[])
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter the number of elements you want in the array");
        int N = I.nextInt();
        System.out.println("Enter the elements of the array");
        int a[] = new int[N];
        for(int i = 0; i < N; i++)
        a[i] = I.nextInt();
        System.out.println("Enter the value of sum, you want to check in the array");
        int sum = I.nextInt();
        System.out.println("You have " + subset(a,sum,0,N) + " subsets in the array that can yield the given sum");
        I.close();
    }   
}
