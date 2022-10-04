import java.util.*;
public class Smallest_power_of_x_less_than_equal_to_N    // O(floor(Logx(N)))
{
    static int power(int N, int x) 
    {
        if (N < x)
            return 0;
        return 1 + power(N / x, x);
    }
    public static void main(String args[]) 
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter the Number N\nAnd the base X for which\nYou want to know smallest power P\nLess than or equal to N\n X^P <= N");
        int N = I.nextInt(), x = I.nextInt();
        System.out.println(power(N, x));
        I.close();
    }
}
