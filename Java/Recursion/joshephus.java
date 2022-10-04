import java.util.*;
class joshephus 
{
   static int Jos(int n, int k)
   {
       if(n == 1)
        return 1;
       return (Jos(n - 1,k) + k-1) % n + 1;
   } 
   public static void main(String args[])
   {
       Scanner I = new Scanner(System.in);
       int n = I.nextInt(), k = I.nextInt();
       System.out.println(Jos(n,k));
       I.close();
   }   
}
/*when starting pos is 0
import java.util.*;
class joshephus 
{
   static int Jos(int n, int k)
   {
       if(n == 1)
        return 0;
       return (Jos(n - 1,k) + k) % n;
   } 
   public static void main(String args[])
   {
       Scanner I = new Scanner(System.in);
       int n = I.nextInt(), k = I.nextInt();
       System.out.println(Jos(n,k));
       I.close();
   }   
}

 */