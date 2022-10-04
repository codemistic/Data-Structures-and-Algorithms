/*
 * A set up where there are 3 towers and discs of different sizes are to be transported from tower 1 to tower 3
 * Rules are Simple, solution isnt
 * Rule 1: Only one disc moves at a time,
 * Rule 2: Only the top most disc in a tower can be moved 
 * Rule 3: No larger disc can be placed on top of a smaller disc
 */
import java.util.*;

class Tower_of_Hanoi {
    // public static long step = 0; Global variable to get the number of steps, if
    // you dont know the formula

    static void TOH(int n, char a, char b, char c) // TOH(n-1, source, using, destination);
    {
        /*
         * The idea here is to get the (N - 1) discs [For the current value of N], from
         * Tower A to Tower B using the Tower C
         * Then Taking the Nth disc from Tower A to Tower C, the largest disc only moves
         * once
         * Then again getting the (N - 1) discs [For the current value of N], from Tower
         * B to Tower C using the Tower A
         */
        if (n == 0)
            return;
        // keeps switching B and C
        TOH(n - 1, a, c, b); // The idea here is to get the n-1 discs from Tower A to tower B, using tower C
        // step++;
        System.out.println(a + " " + c); // Then send the Nth disc to tower C
        TOH(n - 1, b, a, c); // Then again send the n-1 discs from tower B to Tower C using Tower A
    }

    public static void main(String args[]) {
        Scanner I = new Scanner(System.in);
        //System.out.println("Enter the number of discs you want in the tower");
        int n = I.nextInt();
        System.out.println((long) (Math.pow(2, n) - 1));
        TOH(n, '1', '2', '3');
        //System.out.println("It took: " + (long) (Math.pow(2, n) - 1) + " Steps to do the task"); // Replace step with
                                                                                                 // formula if you dont
                                                                                                 // remember it
        I.close();
    }
}
