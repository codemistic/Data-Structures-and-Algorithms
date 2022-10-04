import java.util.*;
class Subset_gen // Same as generating all the subsequence of a string
{ // Produces 2^N outputs
    static void subset(String s, int i, int n, String a) // Same thing you have to follow that at a time, u can either choose a character or leave it
    {
        if (i == n) 
        {
            System.out.println(a);
            return;
        }
        subset(s, i + 1, n, a + s.charAt(i));
        subset(s, i + 1, n, a);
    }

    public static void main(String args[]) 
    {
        Scanner I = new Scanner(System.in);
        System.out.println("ENTER A STRING");
        String s = I.nextLine(); // Considering all characters are distinct
        System.out.println();
        subset(s, 0, s.length(), "");
        I.close();
    }
}