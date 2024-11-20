import java.util.*;

public class PallindromeOfString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        int l=s.length()-1;
        int i=0;
        palindcheck(s,i,l);
    }
    static void palindcheck(String s,int i,int l)
    {
        if(i>(l-i))
        {
            System.out.println("YES");
            return;
        }
        if(s.charAt(i)==s.charAt(l-i))
        {
            palindcheck(s,i+1,l);
        }
        else
        {
            System.out.println("NO");
        }
    }
}
