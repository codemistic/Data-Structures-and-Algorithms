import java.util.*;
class Repeat_Pattern
{
    static void pattern(int n) {

        if (n == 0)
            return;
        pattern(n - 1);
        System.out.println(n);
        pattern(n - 1);
    }

    public static void main(String args[]) {
        Scanner I = new Scanner(System.in);
        System.out.println("Enter A Number\n");
        int n = I.nextInt();
        pattern(n);
        I.close();
    }
}
/* 

Input
 4

Output
1     //Nothing before 1 so nothing afterwards
2     //Everything printed before is printed afterwards
1
3     //Everything printed before is printed afterwards
1
2
1
4     //Everything printed before is printed afterwards
1
2
1
3
1
2
1

*/