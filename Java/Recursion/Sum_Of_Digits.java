import java.util.*; //Getting the sum of digits

class Sum_of_Digits {
    static int rec_sum(int n) 
    {
        if (n == 0)
            return 0;
        return n % 10 + rec_sum(n / 10);    //for product of digits chnge '+' with '*'
    }

    public static void main(String args[]) {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter A Number");
        int n = I.nextInt();
        System.out.println("Your Sum Of Digits is: " + rec_sum(n));
        I.close();
    }
}