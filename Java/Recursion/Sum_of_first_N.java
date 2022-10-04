import java.util.*;
class Sum_of_first_N // Sum of first N natural numbers
{
    public static int sum; // Global variable
    static void summation(int n)    //n+1 system calls
    {
        if (n <= 0)
            return;
        sum += n;
        summation(n - 1);
    }
    public static void main(String args[]) 
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter the Number N");
        int n = I.nextInt();
        summation(n);
        System.out.println("The sum of first N number is : " + sum);
        I.close();
    }
}