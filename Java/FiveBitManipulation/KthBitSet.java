import java.util.*;

public class KthBitSet {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt(),k= sc.nextInt();
        /*Method 1 using left shift operator*/
        if((n & (1<<(k-1))) == 0 )
            System.out.println("NO");
        else
            System.out.println("YES");

        /*Method 2 using right shift operator*/
//        if(((n>>(k-1))&1) != 0)
//            System.out.println("YES");
//        else
//            System.out.println("NO");
    }
}
