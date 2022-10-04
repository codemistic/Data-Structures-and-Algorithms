import java.util.*;
class N_to_1 //tail Recursive
{
    static void rec(int N)
    { 
        //A label called  Start is added here, 
        //This is called Tail Call Elimination
        if(N == 0)
        return;
        System.out.print(N + " ");
        rec(N-1);                       //Modern Compiler change it to [ n -> n-1,    goto start] 
    }                                   //This makes the execution faster
    public static void main(String args[])
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter the value of N");
        int N = I.nextInt();
        rec(N);
        I.close();
    }
}