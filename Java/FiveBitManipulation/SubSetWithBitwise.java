import java.util.*;

public class SubSetWithBitwise {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        int i,k,n,n1;
        int l=s.length();
        n=(int)Math.pow(2.0,l);
        System.out.print(" ");
        for(i=0;i<n;i++)
        {
            n1=n;
            k=0;
            while(n1!=0)
            {
                if(((i>>k)&1) == 1)
                    System.out.print(s.charAt(k));
                k++;
                n1/=2;
            }
         System.out.println();
        }
    }
}
