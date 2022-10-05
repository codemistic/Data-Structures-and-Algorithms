import java.util.*;
class Fibonacci // if asked for a term always use bennet's formula, open purple register
{
    static void nth_fibo(int b, int c, int n)    //better than f(n-1) + f(n-2), coz here a lot 
    {                                            //overlapping subproblems occur
        /*
              if(n < 0)
                 return 0;
              if(n < 2)
                 return n;
              return(fibo(n-1) + fibo(n-2));     //tradional 2^n solution 
        */
        if (n == 2)                      //if u say 0 is the first term, else take n == 1
        {
            System.out.println(c);
            return;
        }
        //Uncomment to print the series 
        //System.out.print(c+b + " ");
        nth_fibo(c, c + b, n - 1);           //To print use System.out.println(c+b), above this statement
    }

    public static void main(String args[]) {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter the number n, to get the nth fibonacci number");
        int n = I.nextInt();
        if (n < 3)
            System.out.println(n - 1);
        else
        {
            System.out.println("0 1 ");
            nth_fibo(0, 1, n);
        }
        I.close();
    }
}