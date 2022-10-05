import java.util.*;

class Checking_the_palindrome 
{
    static boolean palin(String s, int l, int i) 
    {
        if (i == l / 2)
            return true;
        boolean x = (s.charAt(i) == s.charAt(l - 1 - i)); // Boolean data can be used as 0 and 1
        return (x && palin(s, l, i + 1)); // In java booleans can be multiplied using relational operators only
    }

    public static void main(String args[]) 
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter a String you want to check");
        String s = I.nextLine();
        System.out.print("The String is PalinDrome? ");
        if (palin(s, s.length(), 0))
            System.out.print("YES");
        else
            System.out.print("NO");
        I.close();
    }
}
