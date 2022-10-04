
import java.util.ArrayList;

import java.util.Arrays;
 
// Given two integers a and b. The task is to print
// sum of all the digits appearing in the
// integers between a and b

public class AMAN {
 

    // Memoization for the state results

    static long dp[][][] = new long[20][180][2];
 

    // Stores the digits in x in a vector digit

    static void getDigits(long x, ArrayList<Integer> digit)

    {

        while (x != 0) {

            digit.add((int)(x % 10));

            x /= 10;

        }

    }
 

    // Return sum of digits from 1 to integer in

    // digit vector

    static long digitSum(int idx, int sum, int tight,

                         ArrayList<Integer> digit)

    {

        // base case

        if (idx == -1)

            return sum;
 

        // checking if already calculated this state

        if (dp[idx][sum][tight] != -1 && tight != 1)

            return dp[idx][sum][tight];
 

        long ret = 0;
 

        // calculating range value

        int k = (tight != 0) ? digit.get(idx) : 9;
 

        for (int i = 0; i <= k; i++) {

            // calculating newTight value for next state

            int newTight

                = (digit.get(idx) == i) ? tight : 0;
 

            // fetching answer from next state

            ret += digitSum(idx - 1, sum + i, newTight,

                            digit);

        }
 

        if (tight != 0)

            dp[idx][sum][tight] = ret;
 

        return ret;

    }
 

    // Returns sum of digits in numbers from a to b.

    static int rangeDigitSum(int a, int b)

    {

        // initializing dp with -1

        for (int i = 0; i < 20; i++)

            for (int j = 0; j < 180; j++)

                for (int k = 0; k < 2; k++)

                    dp[i][j][k] = -1;
 

        // storing digits of a-1 in digit vector

        ArrayList<Integer> digitA

            = new ArrayList<Integer>();

        getDigits(a - 1, digitA);
 

        // Finding sum of digits from 1 to "a-1" which is

        // passed as digitA.

        long ans1

            = digitSum(digitA.size() - 1, 0, 1, digitA);
 

        // Storing digits of b in digit vector

        ArrayList<Integer> digitB

            = new ArrayList<Integer>();

        getDigits(b, digitB);
 

        // Finding sum of digits from 1 to "b" which is

        // passed as digitB.

        long ans2

            = digitSum(digitB.size() - 1, 0, 1, digitB);
 

        return (int)(ans2 - ans1);

    }
 

    // driver function to call above function

    public static void main(String[] args)

    {

        int a = 123, b = 1024;

        System.out.println("digit sum for given range : "

                           + rangeDigitSum(a, b));

    }
}
