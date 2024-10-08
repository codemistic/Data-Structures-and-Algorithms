import java.util.*; 
class FactorialN
{
    public static int f;      //Global variable
    static void fct(int n)    //Tail recursive version
    {
        if (n <= 1)
            return;
        f *= n;
        fct(n-1);             //All Set and done
    }
    /*
    static int fct(int n)    //Head recursive version
    {
        if (n <= 1)
            return 1;
        return (n * fct(n-1));
        // this n,  makes the function here head recursive, as the function
        // will have to return to its parent to do the multiplication, 
        // hence tail elimination cant be used 
    }
    */
    public static void main(String args[]) 
    {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter A Number");
        int n = I.nextInt();
        f = 1;
        fct(n);
        System.out.println("Your factorial is: " + f);
        I.close();
    }
}