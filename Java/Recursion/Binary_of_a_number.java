import java.util.*;
class Binary_of_a_number
{
    static void Binary(int n) 
    {
        if (n == 0)
            return;
        Binary(n / 2);
        System.out.print(n % 2 + " ");
    }
    public static void main(String args[]) 
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter A Number");
        int n = I.nextInt();
        System.out.println("Binary Representation of the number :  ");
        Binary(n);
        I.close();
    }
}