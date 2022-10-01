import java.util.Scanner;
public class evenodd {
    public static  void main(String[]args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter  the  number");
        int  num = sc.nextInt();
      // using bitwise  and operation 
      /* when we  convert  any decimal  number to binary the least  significant bit or the last  bit if it  is 0 -> then it  is
      a  even number  and  if the  last  bit  is 1 it is a odd number. */
        if((num&1) == 0){
            System.out.println("even number");
        }else{
            System.out.println("odd  number");
        }
    }
}
