import java.util.*;
class one_to_N     //Head Recursion
{
    static void rec(int N)    //No other variable needed 
    {
        if(N == 0)
        return;
        rec(N-1);
        System.out.print(N + " ");
    } 
    /* //Tail Recursion alternative
       static void rec(int N, int i)    //No other variable needed 
       {
            if(i == N)
            return;
            System.out.print(N + " ");
            rec(N,i+1);
       } //Will be called using rec(N,0);
    */
    public static void main(String args[])
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter the value of N");
        int N = I.nextInt();
        rec(N);
        I.close();
    }
}
